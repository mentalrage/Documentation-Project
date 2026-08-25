# Agent-B011 Current Assignment

- Use the project-level `ntk-b-agent-workflow` skill for all general B-agent instructions.
- Agent identity: `B011`.
- Required runtime/provenance for this assignment: `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **`.
- Current supervisor cap/spec override: maintain 5 active B-agent workstreams using GPT 5.5 xHigh as the standing requirement.
- You are not alone in the codebase. Do not revert edits made by others.

Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## Current Assignment

- Mode: implementation callback after supervisor Gate 1 pass.
- Target: [UID:00029U] `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`.
- Accepted report: `tools/leaser/Agents/Agent-B011/research/00029U-SurfacePixelFormatFlags-source-quality.md`.
- Accepted report SHA256: `F2B805C007979E6AA4999A62249A633E2B3D971FFA44F274E12AA7FE4E030165`.
- Gate 1 audit: `tools/leaser/Agents/b-report-validation-audit.md`, entry `2026-07-08T18:25:00-04:00 - B011 UID00029U Current Artifact Gate 1 Audit`, state `GATE1_PASSED`.
- Required return: implement the accepted report details, update the report ledger/checklist, run scoped validators for edited by-* files, then stop with `READY_FOR_SUPERVISOR_EXECUTE`.

## Accepted Implementation Scope

Use the report's `Claim And Incorporation Ledger`, `Recommended Target Doc Changes`, `Recommended Support Doc Changes`, and `Implementation Tracking Checklist`.

Target page:

- Edit `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`.
- Change metadata to `COMPLETION:88`, `CONFIDENCE:93`.
- Preserve `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC`.
- Set `EMITTER_POSITION_OPTIONAL:9`.
- Replace stale `ff ff ff ff` / all-`ff` raw-byte current-state wording with current MCP zero-byte wording while preserving historical stale/all-`ff` evidence as rejected or historical when useful.
- Incorporate the report facts at report-level detail: current MCP session `b001-0002wl-readonly`, zero image bytes, D4 seven refs, D5 sixteen refs, D6/D7 zero refs, no IDA names, D4 setter/read behavior, D5 RGB565 polarity, predecessor/successor boundaries, generated `Surface.cpp` empty-marker state, rejected stale names, and padding proof.
- Insert the exact formal `RECONSTRUCTION_CPP CODE` block content from the report:

```cpp
static bool g_surfaceUses32BitPresentation;
bool g_surfaceUsesRgb565Pixels;
```

Support docs:

- Edit support docs only where the accepted report's facts are missing, stale, or lower detail. Do not make broad unrelated rewrites.
- Required support-scope checks:
  - `by-file/Surface.md`: ensure UID00029U is described as source-ready with `g_surfaceUses32BitPresentation` and `g_surfaceUsesRgb565Pixels`, current zero image bytes, and alignment before UID00029V.
  - `by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md`: replace raw-only `byte_69B3D4` / `byte_69B3D5` wording where needed with source-facing names plus raw aliases and add 32-bit/24-bit/16-bit green-mask write rules if missing.
  - `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`: replace or qualify `byte_69B3D4` with `g_surfaceUses32BitPresentation` / raw alias and state it gates the 32-bit presentation copy/conversion path.
  - `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: historicalize or correct all-`ff` neighborhood byte statements for adjacent UID00029U context, add D4/D5 source names in adjacent flag prose, and retain callback-table no-code status.
  - `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md`: record the UID00029U fresh MCP zero-byte context for `0x0069b3d8-0x0069b3df` only if doing so does not require changing that page's formal `-1` initializer; if formal-code conflict is larger than this callback, document it in the report as separate UID00029V follow-up instead of forcing a broad support change.
  - `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md` and `by-meta/client_new_rendering_mode.md`: no required edit if same-or-greater D5 polarity and rejected product-level naming detail is already present; record `already-present` in the report ledger/checklist.

Report update:

- Update `tools/leaser/Agents/Agent-B011/research/00029U-SurfacePixelFormatFlags-source-quality.md` after edits.
- For every accepted ledger row C1-C11, update verification state to `applied`, `already-present`, `historicalized`, `not-applicable`, or `excluded-with-reason`.
- Check off the implementation callback checklist items that are actually complete.
- Record changed files, leases used/released, validator commands/results, command IDs/timestamps, exit code, `ok` count, warnings, and generated-refresh state.
- If a support recommendation is deliberately not applied because the current doc already has same-or-greater detail or because the issue belongs to UID00029V/future scope, record the exact reason.

## Validation

Run scoped file validation from `source-3/project-documentation` for every edited by-* file. At minimum, run:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md --apply --queue-timeout 240
```

If generated output freshness matters after validation, check generated `auto-generated/NexusTK/render/Surface.cpp` metadata. The expected result is that UID00029U no longer appears as an empty emitter marker and emits before UID00029V position `10`.

## Boundaries

- Lease only files you need to edit and release leases immediately after edits.
- Do not edit generated files, coverage reports, supervisor ledgers, validator state, queue files, lock files, archives, lifecycle files, IDA DB files, or unrelated docs.
- Do not run `execute_report`, dry-run/probing execute variants, registry lifecycle/archive commands, manual report moves, archive moves, or equivalent lifecycle commands.
- Do not start, stop, restart, or kill IDA/MCP.
- If validators or MCP fail transiently, retry briefly. If they remain blocked, stop and return the exact blocker.

## Return Condition

Return only when the callback is complete with:

- `READY_FOR_SUPERVISOR_EXECUTE`
- report path and new SHA256
- changed files
- leases used and released
- validator commands/results including command IDs/timestamps, exit codes, `ok` counts, warnings, and generated-refresh observations
- confirmation that no generated files, coverage reports, supervisor ledgers, validator state, lifecycle/archive files, manual report moves, or `execute_report` variants were touched
