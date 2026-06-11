# Leaser

`leaser.py` is a small coordination tool for documentation agents. It lets an
agent reserve one or more files before editing so other agents can avoid working
on the same documents at the same time.

Lease duration is controlled by `lease_seconds` in `lease.json`; the current
configuration uses 300 seconds. Expired leases are removed automatically the
next time any agent runs a leaser command. When current lease report-file
generation is enabled, `leaser.py` also writes `current_leases.md` into each
configured report folder whenever lease state is created, removed, or expired.

## Commands

Run commands from this directory:

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser
```

Lease one file:

```powershell
python leaser.py AgentID lease E:\path\to\file.md
```

Lease multiple files:

```powershell
python leaser.py AgentID lease E:\path\to\file1.md E:\path\to\file2.md E:\path\to\file3.md
```

Release one file early:

```powershell
python leaser.py AgentID unlease E:\path\to\file.md
```

Release all files owned by an agent:

```powershell
python leaser.py AgentID unlease
```

List the active leases owned by an agent, when info commands are enabled:

```powershell
python leaser.py AgentID leases
```

List all active leases, when info commands are enabled:

```powershell
python leaser.py AgentID leases all
python leaser.py leases
```

Show help:

```powershell
python leaser.py --help
```

## Output

Every `lease` or `unlease` command reports the result for each requested file.

Example:

```text
E:\docs\file1.md: Rejected[File not found]
E:\docs\file2.md: Success
E:\docs\file3.md: Rejected[Already has lease]
```

`leases` reports the files currently owned by that agent, when each lease was
created, when it expires, and the remaining time, unless report-file mode has
disabled info commands.

`leases all` and `python leaser.py leases` report all current leases from all
agents, unless report-file mode has disabled info commands.

When `disable_info_commands_when_report_file_enabled` is true and
`enable_current_lease_reporting_file_generation` is true, info commands are
rejected. Agents should read the configured `current_leases.md` report instead.

## Current Lease Report

Report generation is configured in `lease.json`:

```json
{
  "enable_current_lease_reporting_file_generation": true,
  "lease_seconds": 300,
  "paths": [
    "E:\\NTK\\GhidraBridge\\source-3\\project-documentation\\tools\\leaser\\Agents"
  ],
  "lease_reporting_filename": "current_leases.md",
  "disable_info_commands_when_report_file_enabled": true
}
```

`paths` accepts either a single path string or a list of path strings. For each
configured folder, `leaser.py` writes the configured report filename in place.
The report contains:

```text
AgentID | lease path | time created | expiration
```

Do not edit generated current lease reports or per-agent symlinks to them.

## Rules For Agents

- Always lease a documentation file before editing it.
- Do not edit a file if `leaser.py` rejects the lease request for that file.
- Read `current_leases.md` for current lease status when report-file mode is
  enabled.
- Use the same `AgentID` when leasing and unleasing files.
- Never send commands as another agent.
- Use `leaser.py` only to add or remove leases when info commands are disabled.
- Release leases early with `unlease` when work is done.
- If a lease expires before editing is finished, run `lease` again before
  continuing.
- Treat `lease.json` and `lease.lock` as private leaser state.
- Do not read, edit, delete, copy, or manually repair `lease.json` or
  `lease.lock`.
- Use only `leaser.py` commands to inspect or change lease state.
- If `lease.json` appears invalid or the tool reports a store error, stop and
  report the tool error instead of editing the JSON directly.

## Concurrency

`leaser.py` serializes access with `lease.lock`, so multiple agents can run it at
the same time. Only one process can update `lease.json` at a time, which prevents
two agents from successfully leasing the same file in the same moment.

## Runtime Files

The tool creates these runtime files beside `leaser.py`:

- `lease.json`: current active lease state.
- `lease.lock`: lock file used for concurrent access control.

The tool may also create `current_leases.md` in configured report folders.

These files are generated state, not agent-editable documentation.
