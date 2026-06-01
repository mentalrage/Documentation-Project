*** UID:0000VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StartupWindow Unmodeled Notice Helpers 0x005815b0-0x00581b7f

## Status

- Confidence: strong that this is startup notice code; medium for exact function boundaries.
- Entity kind: raw-code helper/boundary issue
- Likely owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Main memory doc: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Rebuild handling: `source-authored` startup/update-notice helper code. Marked reconstructable, but parent attachment and C++ are blank because exact helper boundaries and caller paths remain unresolved.

## Finding

IDA currently models `StartupWindow::UpdateCheckWindowProc` through `0x005815aa`, then resumes function records at `0x00581660`. Raw disassembly shows additional valid helper bodies in the gap and later raw region:

| Raw start | Observed behavior |
| --- | --- |
| `0x005815b0` | Handles update/close button action, updates close-button state, and posts `WM_USER + 11`. |
| `0x005817e0` | Invalidates both button rectangles. |
| `0x00581860` | Invalidates one indexed button rectangle. |
| `0x005818d0` | Lazily loads `brm_main.pcx`, `brm_st_a/b/c.pcx`, `brm_ex_a/b.pcx`, then initializes button bounds. |
| `0x005819d0` | Builds/registers a window class using `StartupWindow::UpdateCheckWindowProc`; exact owner and end are unresolved. |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- IDA still has no function objects at raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, or `0x005819d0`.
- Raw disassembly at each start begins with valid function-shaped prologue/setup code, not padding: `0x005815b0`, `0x005817e0`, and `0x00581860` use security-cookie frames; `0x005818d0` begins with a normal `this`/state check; `0x005819d0` builds a larger stack frame and loads `lpClassName`.
- Current `simroot_v2/class_StartupWindow.cpp` still maps the update-check window procedure around `0x00581100` and includes the `brm_main.pcx`, `brm_st_a/b/c.pcx`, and `brm_ex_a/b.pcx` load behavior. Treat this as a generated-source lead only; IDA raw starts above are the boundary evidence.

## Impact

Generated `class_StartupWindow.cpp` currently inlines or omits parts of this helper family. Source migration should not rely only on IDA function records for this range, because several real helper bodies are currently unmodeled.

## Follow-Up

- Decide whether to create explicit function boundaries for the raw starts in Wave3 data after the program work resumes.
- Reconcile the generated `UpdateCheckWindowProc` first-paint asset-load body with the raw `0x005818d0` helper.
- Recheck whether `0x005819d0` is dead/alternate startup notice setup or a missed caller path.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with low-to-moderate completion and medium confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed the unmodeled helper starts are valid code but still lack IDA function records. The score stays conservative because exact helper ends, caller paths, and how the raw helpers relate to the generated `UpdateCheckWindowProc` body remain unresolved.
