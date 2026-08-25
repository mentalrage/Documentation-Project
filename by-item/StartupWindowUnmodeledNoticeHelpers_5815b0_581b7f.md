*** UID:0000VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StartupWindow Unmodeled Notice Helpers 0x005815b0-0x00581b7f

## Status

- Confidence: strong that this is startup notice code and for the corrected return-inclusive raw helper ends; medium-high for raw-start identity because the raw starts still have no direct start refs or IDA function objects.
- Entity kind: raw-code helper/boundary issue
- Likely owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Main memory doc: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Rebuild handling: non-emitting tracker only. The raw helper bytes are source-authored, but the source-bearing bodies now live on exact by-memory child pages; this by-item page keeps the boundary-debt inventory and no-function/no-xref proof.
- Canonical evidence: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) is the detailed aggregate for this raw island; this by-item page stays as the boundary-debt tracker.
- Current tracker role: non-canonical reminder item for the unmodeled raw helper family. The source-owned address evidence lives in [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), and the exact curl callback child is [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md).

## Finding

IDA currently models `StartupWindow::UpdateCheckWindowProc` through `0x005815aa`, then resumes function records at `0x00581660`. Raw disassembly shows additional valid helper bodies in the gap and later raw region:

| Raw span | Proposed source-facing role | Observed behavior |
| --- | --- | --- |
| `0x005815b0-0x0058165a` | [UID:0004CU][0x005815b0-0x0058165a.StartupNoticePostButtonResult](by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md) | Handles update/close button action, updates visual state, and posts `WM_USER + 11`; corrected range includes final `ret 4`. |
| `0x005817e0-0x00581854` | [UID:0004CZ][0x005817e0-0x00581854.StartupNoticeInvalidateButtons](by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md) | Invalidates both button rectangles; corrected range includes final `ret`. |
| `0x00581860-0x005818c3` | [UID:0004D0][0x00581860-0x005818c3.StartupNoticeInvalidateButton](by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md) | Direct B003-covered source-ready child at `88/91`: exact `0x63` / 99-byte raw helper, 30 instructions, no IDA function/decompile/direct start route, indexed `m_buttons[buttonIndex].rect`, `m_noticeWindow`, `InvalidateRect(..., FALSE)`, and corrected final `ret 4`. |
| `0x005818d0-0x005819cc` | [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) | Lazily loads `brm_main.pcx`, `brm_st_a/b/c.pcx`, `brm_ex_a/b.pcx`, then initializes button bounds; corrected range includes final `ret 4`. |
| `0x005819d0-0x00581b75` | [UID:0004D2][0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw](by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md) | Direct B006-covered source-bearing child at `88/90`: builds/registers a notice window class using the StartupWindow WndProc, uses `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT` fallback x/y until desktop rect lookup succeeds, creates the 500x430 notice window, stores `HWND` at `this + 0x0c`, and has no direct start ref. |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- IDA still has no function objects at raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, or `0x005819d0`.
- Raw disassembly at each start begins with valid function-shaped prologue/setup code, not padding: `0x005815b0`, `0x005817e0`, and `0x00581860` use security-cookie frames; `0x005818d0` begins with a normal `this`/state check; `0x005819d0` builds a larger stack frame and loads `lpClassName`.
- Current `simroot_v2/class_StartupWindow.cpp` still maps the update-check window procedure around `0x00581100` and includes the `brm_main.pcx`, `brm_st_a/b/c.pcx`, and `brm_ex_a/b.pcx` load behavior. Treat this as a generated-source lead only; IDA raw starts above are the boundary evidence.

Rechecked on 2026-06-14 with live IDA MCP session `b001_0002bd`:

- `server_health` reports active `NexusTK.exe.i64`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirms the modeled StartupWindow/update-check neighborhood: constructor `0x005807d0` size `0x3c`, `RunUpdateCheck` `0x00580870` size `0x88d` / 2189 bytes (Verified with int_convert.py), WndProc `0x00581100` size `0x4aa` / 1194 bytes (Verified with int_convert.py), modeled helper run `0x00581660`, `0x00581670`, `0x00581730`, and `0x005817a0`, callback `0x00581b80` size `0x166` / 358 bytes (Verified with int_convert.py), and successor string helper `0x00581cf0`.
- The same `lookup_funcs` call reconfirms no IDA function object at raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, or `0x005819d0`.
- `xrefs_to` reconfirms zero direct xrefs to those five raw starts, two data xrefs to WndProc `0x00581100` (`0x005808e4` in `RunUpdateCheck` and raw `0x005819fc`), and two callback-pointer refs to `0x00581b80` (`0x00580c6f` and `0x00580efb` in `RunUpdateCheck`).
- `get_bytes` reconfirms the byte boundaries: six `0xcc` bytes before raw `0x005815b0`, padding before raw `0x005817e0`, padding before raw `0x00581860`, padding before raw `0x005818d0`, padding before raw `0x005819d0`, and padding before the exact callback child at `0x00581b80`.
- `callees` reconfirms `RunUpdateCheck` owns window registration/creation, libcurl setup/perform/cleanup, update/minimap string parsing, MD5/minimap calls, and message dispatch; WndProc owns PCX load/draw, button helper calls, cursor/update/paint calls, invalidation, and `ShellExecuteA`. No IDA database function split or name change was made because the raw starts still lack direct xrefs and source-quality function boundaries.

Rechecked on 2026-06-16 with live IDA MCP session `c001_midiplayer_rdata_20260615`:

- `lookup_funcs` again reports no IDA function objects at raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`, while preserving the modeled helper run at `0x00581660-0x005817dd` and callback/string/destructor helpers after `0x00581b80`.
- `xrefs_to` again reports zero direct xrefs to the five raw starts, two WndProc data refs (`0x005808e4` and raw `0x005819fc`), two callback-pointer refs to `0x00581b80`, and WinMain-only code callers for the constructor/update-check pair.
- `get_bytes` reconfirmed six `0xcc` bytes before `0x005815b0`, padding before `0x005817e0`, `0x00581860`, `0x005818d0`, `0x005819d0`, padding before callback `0x00581b80`, and two `0xcc` bytes before successor `0x00582070`.
- A PE-section-mapped scan of `NexusTK.exe` found zero absolute-VA pointer hits, zero RVA pointer hits, and zero direct `E8`/`E9` branch hits to all five raw starts. The scan did find only the expected direct calls to the modeled constructor/update-check pair and WndProc pointer stores, so the remaining blocker is exact raw-helper source shape, not an unsearched direct reference.

Rechecked on 2026-06-21 through B010 local PE/Capstone source-quality research:

- The raw starts remain source-shaped StartupWindow helper bodies, but the exact half-open spans should include return bytes and exclude padding: `0x005815b0-0x0058165a`, `0x005817e0-0x00581854`, `0x00581860-0x005818c3`, `0x005818d0-0x005819cc`, and `0x005819d0-0x00581b75`.
- Padding after those bodies is now explicit: `0x0058165a-0x00581660`, `0x00581854-0x00581860`, `0x005818c3-0x005818d0`, `0x005819cc-0x005819d0`, and `0x00581b75-0x00581b80`.
- Local reference scanning found no rel32, absolute-VA, or RVA start refs to any of the five raw starts. This validates the no-direct-start-route caveat; it does not mean the code is padding or a false positive.
- `0x005819d0-0x00581b75` is best described as an alternate raw create-window/setup helper: it builds `WNDCLASSEXA`, uses the StartupWindow WndProc pointer plus the notice class/title pointers, registers the class, creates a centered 500x430 notice HWND, and stores the handle on the StartupWindow object. Do not promote it into a public source API until a caller/source route is proven.
- The separately discovered `0x00580810-0x00580870` destructor-like body is outside this by-item page's `0x005815b0-0x00581b7f` scope and is tracked on [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), not absorbed here.

## Canonical Evidence Map

| Evidence page | Score | Role |
| --- | ---: | --- |
| [UID:0000O5][StartupWindow](by-file/StartupWindow.md) | `88/86` | Source-file owner for the startup/update notice window and private helper family. |
| [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | `86/88` | Authoritative address-range inventory, corrected raw helper spans, caller/xref evidence, touched globals, and padding boundaries. |
| [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) | `86/90` | Exact nested callback child inside the startup update aggregate; only referenced from the two `RunUpdateCheck` libcurl write-callback setup sites. |
| [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md) | `75/88` | Confirms the `brm_*.pcx` notice assets and update-notice resource role. |

## Current Split Status

| Address span | Current documentation state | Next useful action |
| --- | --- | --- |
| `0x005815b0-0x0058165a` | Exact child [UID:0004CU][0x005815b0-0x0058165a.StartupNoticePostButtonResult](by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md); starts with security-cookie frame, posts the update/close result message, and includes the final `ret 4`. | Applied by B008 callback; this tracker should not emit the body. |
| `0x00581660-0x005817dd` | IDA-modeled notice accessor/reset/set/hit-test helpers already inventoried by the aggregate page. | These are not the main blocker; final source names and whether they deserve separate child pages can be handled after the raw-start split. |
| `0x005817e0-0x00581854` | Exact child [UID:0004CZ][0x005817e0-0x00581854.StartupNoticeInvalidateButtons](by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md); valid prologue and rectangle invalidation behavior preserved with final `ret`. | Applied by B008 callback; this tracker should not emit the body. |
| `0x00581860-0x005818c3` | Exact child [UID:0004D0][0x00581860-0x005818c3.StartupNoticeInvalidateButton](by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md); direct B003 callback now documents current MCP session `ddf5b602`, exact `0x63` / 99-byte range, 30-instruction body, no function/decompile/direct start route, indexed button rectangle from the `0x20`-stride notice array, `m_noticeWindow`, `InvalidateRect(..., FALSE)`, sibling comparison, and generated output already present. | Applied by B008 callback and direct B003 source-quality callback; this tracker should not emit the body. |
| `0x005818d0-0x005819cc` | Exact child [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md); loads `brm_main.pcx`, `brm_st_a/b/c.pcx`, and `brm_ex_a/b.pcx`, matching [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md), with corrected final `ret 4`. B004 direct callback now documents current MCP session `13191102`, exact `0xfc` range, no function/decompile, no direct start/end route, no pointer-pattern route, and score `88/91`. | Applied by B008 callback and direct B004 source-quality callback; this tracker should not emit the body. |
| `0x005819d0-0x00581b75` | Exact child [UID:0004D2][0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw](by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md); B006 direct callback now documents current MCP session `13191102`, exact `0x1a5` / 421-byte range, 135 instructions, no function/decompile, no direct start route, class/title/WndProc/atom refs, corrected `CS_CLASSDC` and `WS_POPUP | WS_CLIPCHILDREN`, `CW_USEDEFAULT` fallback coordinate handling, and source-facing `StartupNoticeCreateWindow` formal C++. | Applied by B008 callback and direct B006 source-quality callback; this tracker should not emit the body. |
| `0x00581b80-0x00581ce6` | Exact callback child already documented as [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md). | No longer a tracker blocker except for final C++/string-buffer names. |

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page identifies every known raw helper start, corrected return-inclusive range, observed behavior, padding after each helper, impact, follow-up work, canonical aggregate evidence, file owner, exact child pages, and split status for modeled/raw/already-childed spans. It remains below high completion because original helper/member names, raw caller/source routes, and some child-specific confidence caps remain exact-child concerns rather than tracker-owned source bodies. |
| Confidence | 90 | Current live IDA evidence, byte checks, PE-mapped reachability scanning, B010 local PE/Capstone end-range validation, and existing docs provide strong evidence for StartupWindow ownership and exact raw-helper physical boundaries. Confidence is still capped below final-source quality because IDA lacks function objects and direct xrefs for the raw helper starts, while exact children such as UID0004D1 and UID0004D2 now carry per-helper source C++ and direct current-session caveats. |
| Reconstructable | false | This by-item page is now only a noncanonical tracker. Source-bearing raw helper bodies emit from exact by-memory child pages through [UID:0000O5][StartupWindow](by-file/StartupWindow.md); the tracker keeps formal C++ blank to avoid duplicate broad emission. |

## Impact

Generated `class_StartupWindow.cpp` currently inlines or omits parts of this helper family. Source migration should not rely only on IDA function records for this range, because several real helper bodies are currently unmodeled.

## Follow-Up

- Decide whether to create explicit function boundaries for the raw starts in Wave3 data after the program work resumes.
- Reconcile the generated `UpdateCheckWindowProc` first-paint asset-load body with the raw `0x005818d0` helper.
- Keep `0x005819d0` documented as a source-bearing alternate notice setup helper with no direct start route; future work should only change that caveat if a caller/source route is proven.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-07-04 B003 UID0004D0 callback:
  - Tracker metadata unchanged at `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Updated UID0004D0 finding/split-status notes with direct B003 evidence: MCP session `ddf5b602`, exact `0x00581860-0x005818c3` / `0x63` / 99-byte range, 30-instruction helper body, no IDA function/decompile/direct start route, field roles, sibling comparison, generated output state, and child score `88/91`.
- 2026-07-04 B004 UID0004D1 callback:
  - Tracker metadata unchanged at `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Updated the UID0004D1 split-status row and score rationale to reflect direct child coverage: [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) is now refreshed to `88/91` with MCP session `13191102`, exact `0xfc` range, no function/decompile, no start/end xrefs, no pointer-pattern route, and preserved source-bearing helper body, while this tracker remains non-emitting.
- 2026-07-04 B006 UID0004D2 callback:
  - Tracker metadata unchanged at `88/90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Updated the UID0004D2 finding/split-status row and follow-up wording to reflect direct child coverage: [UID:0004D2][0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw](by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md) is now refreshed to `88/90` with MCP session `13191102`, exact `0x1a5` range, no function/decompile, no direct start route, corrected `CS_CLASSDC` and `WS_POPUP | WS_CLIPCHILDREN` constants, source-facing `StartupNoticeCreateWindow` formal C++, and preserved no-public-API caveat, while this tracker remains non-emitting.
- 2026-07-01 B008 accepted StartupWindow implementation:
  - Changed from reconstructable/emitting tracker to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0001IO`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Five raw helper bodies now live on exact child pages linked above; this page preserves the no-IDA-function/no-direct-xref proof and the note that `0x00580810-0x00580870` belongs to the broader [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) split, not this tracker.
- 2026-06-03 canonical-evidence consistency pass:
  - What existed before: this boundary-debt tracker was scored `70/80`, while the canonical [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) page already carried stronger written IDA evidence at `84/86`; the exact [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) child was not called out in the evidence map.
  - Changed to: scores `76/82`, explicit non-canonical tracker role, cross-link to [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), and score rationale that keeps final C++ blocked on exact child pages for the remaining raw starts.
  - Summary/evidence: current review of [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), [UID:0000DZ][StartupWindow](by-class/StartupWindow.md), [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md), and `wave3_data_issues.md` confirms the raw helper family is already anchored to StartupWindow with written IDA evidence. Live IDA MCP was unavailable, so no new raw helper child pages or reconstructed C++ were created.
- 2026-06-07 A009 split-status pass:
  - What existed before: the page listed the raw starts but did not separate current modeled helper spans, raw-start child candidates, and the already-split curl callback child in a direct work queue.
  - Changed to: scores `79/84` and a current split-status table identifying which spans are modeled, which need exact child pages, and why `0x005819d0` remains the confidence cap.
  - Summary/evidence: existing [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md) pages support the split map. No C++ was emitted and no child pages were created because the raw function ends/callers still need a live IDA or approved new-file workflow pass.
- 2026-06-14 C001 live-evidence refresh:
  - Before: score was `79/84`; the page had a useful split-status map but only older live-IDA evidence and no current no-xref/no-function reconfirmation for each raw start.
  - Changed to: score `85/87`; classification, owner, emitter, and blank reconstruction C++ are unchanged.
  - Summary/evidence: live IDA MCP session `b001_0002bd` reconfirmed modeled StartupWindow/update-check function sizes, no IDA function objects or direct xrefs at raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`, WndProc data refs at `0x005808e4`/`0x005819fc`, callback refs at `0x00580c6f`/`0x00580efb`, byte-level padding around the raw starts and callback child, and the `RunUpdateCheck`/WndProc callee surfaces. No IDA DB changes or final C++ were made because source-quality raw function boundaries and names remain unresolved.
- 2026-06-16 A001 low-confidence StartupWindow support refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter remain [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and final C++ remains blank.
  - Evidence: live IDA reconfirmed no function objects or direct xrefs for the five raw starts, byte padding before raw/callback/successor boundaries, WndProc/callback refs, WinMain-only constructor/update-check callers, and PE-section-mapped zero VA/RVA/direct-branch hits to the raw starts. No IDA DB function creation was made because the current evidence still does not prove final source-quality boundaries or names.
- 2026-06-21 B010 Rule 26 raw-helper range correction:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`; several raw spans stopped before return bytes and the alternate setup end still used the broad `0x00581b7f` padding-inclusive endpoint.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`; owner/emitter and blank C++ remain unchanged.
  - Evidence: local PE/Capstone reanalysis confirmed corrected helper spans `0x005815b0-0x0058165a`, `0x005817e0-0x00581854`, `0x00581860-0x005818c3`, `0x005818d0-0x005819cc`, and `0x005819d0-0x00581b75`, plus no direct start refs and explicit padding after each helper.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with low-to-moderate completion and medium confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP raw-disassembly verification on 2026-05-31 reconfirmed the unmodeled helper starts are valid code but still lack IDA function records. The score stays conservative because exact helper ends, caller paths, and how the raw helpers relate to the generated `UpdateCheckWindowProc` body remain unresolved.
- 2026-06-02: Raised from `50/75` to `70/80` and attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) using the now-complete [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) aggregate as canonical evidence. C++ remains blank because raw helper boundaries and source names are still not final.
