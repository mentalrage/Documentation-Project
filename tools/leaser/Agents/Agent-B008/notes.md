# Agent-B008 Notes

Use `goal.md` for agent identity/current overrides and `$ntk-b-agent-workflow` for the general B-agent workflow.

## UID00039Q Pause Checkpoint

- Current assignment: report-only research for `UID00039Q`, target `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`.
- Required report path when resumed: `tools/leaser/Agents/Agent-B008/research/00039Q-SurfaceFlipSurfaces-source-quality.md`.
- Current supervisor state: MCP-heavy work is paused while MCP usage is throttled. Do not finalize the report until explicit MCP resume.
- Scope while paused: local doc/archive review only. No by-* edits, generated edits, coverage-report edits, validator state edits, lifecycle/archive commands, or `execute_report`.
- MCP requirement on resume: redo or refresh MCP-dependent evidence against the live session before finalizing; do not rely on fallback-only or stale MCP-unavailable work.
- Local evidence already identified as relevant leads: target doc, `Surface.md`, `ScreenPane.md`, `DirectX.md`, parent `SurfacePresentation`, sibling UID00039R restore report/doc, UID00039W minimap initializer, UID0002GJ activation caller report, and UID0000OC Surface family report.
- Working hypothesis to verify under MCP before report finalization: UID00039Q appears to be the setup/presentation side of the DirectDraw restore flag lifecycle, currently Surface-routed but likely ScreenPane-shaped because it writes `this+0x110/+0x111` and uses ScreenPane surface/dimension fields.

