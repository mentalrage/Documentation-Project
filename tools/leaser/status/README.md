# Agent Status Workflow

The status tool gives the supervisor one prioritized view of agent state. It is
an event and heartbeat channel, not a progress log and not proof that work or a
report passed validation.

Run commands from `source-3/project-documentation`:

`python .\tools\leaser\status\status.py <command>`

Agent IDs are one uppercase letter followed by exactly three digits, such as
`A001`, `B002`, or `C003`.

## Required Agent Reporting

The supervisor owns agent registration and online/offline state. Agents use
`-report`; they must not add, online, offline, or clear themselves.

An agent must report:

- `working` immediately after it begins or resumes useful work. A fresh
  `working` report means the agent is progressing and does not need supervisor
  help.
- `working` again after each 15 minutes of uninterrupted active work, or after
  a meaningful phase change if that happens first. Do not report every command,
  file read, edit, or small action, and do not repeat the same update more often
  than this unless the state or supervisor-relevant detail changed.
- `complete` immediately before returning an assigned report, implementation
  callback, requested checkpoint, or finished task to the supervisor. Include
  the artifact path or completed checkpoint and the next supervisor action.
- A supervisor-action state as soon as it applies; do not wait for the next
  heartbeat.

Use the state that most accurately tells the supervisor what to do:

| Status | Use when | Detail message must include |
| --- | --- | --- |
| `working` | Progress is active and no help is needed. | Current target and phase. |
| `complete` | The assigned return point is ready for supervisor review or follow-up. | Artifact/checkpoint and requested next action. |
| `needs-supervisor` | Only the supervisor can make the required decision or perform the next action. | Exact action/decision and why it is required. |
| `blocked` | Work cannot continue until a blocker is resolved. | Blocker, evidence, and what would unblock it. |
| `error` | A failure stopped or materially disrupted the work. | Failed operation, concise error, and recovery attempted. |
| `issue` | A problem needs attention, but non-conflicting work can continue. | Problem, impact, and work that is continuing. |
| `waiting` | A transient non-supervisor dependency is pending. | Dependency and next retry/check. Use `needs-supervisor` when waiting on the supervisor. |
| `idle` | The online agent has no eligible assigned work. | Why no work is available or that assignment is needed. |
| `starting` | Optional short-lived setup before useful work has begun. | Assignment being initialized. Replace it promptly with `working` or an actionable state. |

Examples:

`python .\tools\leaser\status\status.py -report working B007 "Researching UID 0000JA ownership; no help needed"`

`python .\tools\leaser\status\status.py -report complete B007 "Report research/0000JA-FieldMapPane-file-source-quality.md is ready for Gate 1"`

`python .\tools\leaser\status\status.py -report needs-supervisor B007 "Gate 1 callback is required before implementation can begin"`

`python .\tools\leaser\status\status.py -report blocked A003 "Lease held by A001 on by-file/Foo.md; retry after lease expiry 18:40Z"`

If `-report` says the agent does not exist or is offline, stop trying to mutate
the registry and return the exact error to the supervisor through the normal
agent channel. The supervisor must register or online the agent.

## Required Supervisor Triage

Before assigning or resuming an agent, ensure it is registered and online:

- `python .\tools\leaser\status\status.py -list-agents`
- `python .\tools\leaser\status\status.py -add-agent B007`
- `python .\tools\leaser\status\status.py -online B007`

Run `python .\tools\leaser\status\status.py -status` at the start of every
supervision cycle and immediately after each wait. The output is already sorted
by supervisor priority. Handle it in this order:

1. `needs-supervisor` and `error`.
2. `complete`, `blocked`, and `idle`.
3. `issue` and `waiting`.
4. Stale or missing reports.
5. Fresh `starting` and `working` reports require no individual query.

A `working` report no older than 15 minutes means no help is needed. Do not
interrupt that agent merely to ask for status. A newly assigned online agent
that has not reported within 2 minutes, or any online agent whose latest report
is older than 15 minutes, needs a stale-agent check. Actionable states should
normally be handled before they can become stale, but they are not exempt:

1. Check the actual worker/runtime state; status data does not prove the worker
   is still running.
2. Use `-history AGENTID` to understand recent transitions when useful.
3. Send one focused check-in asking the same agent to report its current state.
4. Continue/restart the same agent and folder under the normal workflow if it
   stopped; do not create a duplicate worker.

An actionable status is a notification to perform the normal supervisor
workflow. For example, `complete` triggers artifact review and the applicable
validation gates; it does not prove completion or acceptance. `needs-supervisor`
does not authorize the agent to cross a supervisor-owned role boundary.

Use `-offline AGENTID` for intentionally paused, retired, or unloaded agents so
they disappear from `-status` while retaining history. Use
`-clear-agent AGENTID` only when the agent record and all of its history are
intentionally being deleted. Each agent retains its newest 100 updates.
