*** UID:0000VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:79 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StartupWindow Unmodeled Notice Helpers 0x005815b0-0x00581b7f

## Status

- Confidence: strong that this is startup notice code; medium-high for raw-start identity; medium for exact function ends.
- Entity kind: raw-code helper/boundary issue
- Likely owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Main memory doc: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Rebuild handling: `source-authored` startup/update-notice helper code. Marked reconstructable and attached to the StartupWindow file parent, but C++ remains blank because the raw helper starts are tracked canonically by the aggregate until exact child function pages and final source names exist.
- Canonical evidence: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) is the detailed aggregate for this raw island; this by-item page stays as the boundary-debt tracker.
- Current tracker role: non-canonical reminder item for the unmodeled raw helper family. The source-owned address evidence lives in [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), and the exact curl callback child is [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md).

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

## Canonical Evidence Map

| Evidence page | Score | Role |
| --- | ---: | --- |
| [UID:0000O5][StartupWindow](by-file/StartupWindow.md) | `86/80` | Source-file owner for the startup/update notice window and private helper family. |
| [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | `84/86` | Authoritative address-range inventory, raw helper starts, caller/xref evidence, touched globals, and padding boundaries. |
| [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) | `74/86` | Exact nested callback child inside the startup update aggregate; only referenced from the two `RunUpdateCheck` libcurl write-callback setup sites. |
| [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md) | `75/88` | Confirms the `brm_*.pcx` notice assets and update-notice resource role. |

## Current Split Status

| Address span | Current documentation state | Next useful action |
| --- | --- | --- |
| `0x005815b0-0x00581657` | Raw helper-shaped accept/close handler inside [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md); starts with security-cookie frame and posts the update/close result message. | Create an exact child page after IDA/Wave data can supply or confirm a stable function boundary and caller relationship. |
| `0x00581660-0x005817dd` | IDA-modeled notice accessor/reset/set/hit-test helpers already inventoried by the aggregate page. | These are not the main blocker; final source names and whether they deserve separate child pages can be handled after the raw-start split. |
| `0x005817e0-0x00581853` | Raw reset-all/invalidate-both helper; valid prologue and rectangle invalidation behavior are recorded only at the aggregate/tracker level. | Promote to a precise by-memory child when exact callers/end are rechecked. |
| `0x00581860-0x005818c0` | Raw indexed one-button invalidation helper; computes one rectangle and invalidates the notice HWND. | Promote with `0x005817e0` if a shared button-state helper family is confirmed. |
| `0x005818d0-0x005819c9` | Raw notice asset-loader helper for `brm_main.pcx`, `brm_st_a/b/c.pcx`, and `brm_ex_a/b.pcx`, matching [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md). | Candidate for the first exact child split because the resource role is already well documented. |
| `0x005819d0-0x00581b7f` | Raw alternate notice setup helper that builds `WNDCLASSEXA` using `StartupWindow::UpdateCheckWindowProc`; caller path and exact end remain the weakest claims. | Recheck before child creation; this remains the largest confidence cap for the tracker. |
| `0x00581b80-0x00581ce6` | Exact callback child already documented as [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md). | No longer a tracker blocker except for final C++/string-buffer names. |

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 79 | The page identifies every known raw helper start, observed behavior, impact, follow-up work, canonical aggregate evidence, file owner, exact nested curl callback child, and the current split status for modeled, raw, and already-childed spans. It remains below high completion because most raw starts have not been promoted into exact function pages or finalized source names. |
| Confidence | 84 | Existing IDA-backed docs provide enough evidence to attach the tracker to [UID:0000O5][StartupWindow](by-file/StartupWindow.md), keep the source-owned bytes under the [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) aggregate, and separate the exact curl callback child from the remaining raw-start blockers. Confidence is capped because IDA still lacks formal function objects for the raw helper starts and `0x005819d0` has the weakest caller/end evidence. |
| Reconstructable | true | The bytes are source-authored startup notice helper code, but reconstructed C++ is intentionally blank until boundaries and names become final-source quality. |

## Impact

Generated `class_StartupWindow.cpp` currently inlines or omits parts of this helper family. Source migration should not rely only on IDA function records for this range, because several real helper bodies are currently unmodeled.

## Follow-Up

- Decide whether to create explicit function boundaries for the raw starts in Wave3 data after the program work resumes.
- Reconcile the generated `UpdateCheckWindowProc` first-paint asset-load body with the raw `0x005818d0` helper.
- Recheck whether `0x005819d0` is dead/alternate startup notice setup or a missed caller path.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-03 canonical-evidence consistency pass:
  - What existed before: this boundary-debt tracker was scored `70/80`, while the canonical [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) page already carried stronger written IDA evidence at `84/86`; the exact [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) child was not called out in the evidence map.
  - Changed to: scores `76/82`, explicit non-canonical tracker role, cross-link to [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), and score rationale that keeps final C++ blocked on exact child pages for the remaining raw starts.
  - Summary/evidence: current review of [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), [UID:0000DZ][StartupWindow](by-class/StartupWindow.md), [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md), and `wave3_data_issues.md` confirms the raw helper family is already anchored to StartupWindow with written IDA evidence. Live IDA MCP was unavailable, so no new raw helper child pages or reconstructed C++ were created.
- 2026-06-07 A009 split-status pass:
  - What existed before: the page listed the raw starts but did not separate current modeled helper spans, raw-start child candidates, and the already-split curl callback child in a direct work queue.
  - Changed to: scores `79/84` and a current split-status table identifying which spans are modeled, which need exact child pages, and why `0x005819d0` remains the confidence cap.
  - Summary/evidence: existing [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md) pages support the split map. No C++ was emitted and no child pages were created because the raw function ends/callers still need a live IDA or approved new-file workflow pass.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with low-to-moderate completion and medium confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed the unmodeled helper starts are valid code but still lack IDA function records. The score stays conservative because exact helper ends, caller paths, and how the raw helpers relate to the generated `UpdateCheckWindowProc` body remain unresolved.
- 2026-06-02: Raised from `50/75` to `70/80` and attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) using the now-complete [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) aggregate as canonical evidence. C++ remains blank because raw helper boundaries and source names are still not final.
