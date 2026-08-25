** TARGET-REPORT-UID:0001DW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 0001DW NewOptionPane Source-Quality Report

## Assignment And Scope

- Agent: B001.
- Assignment ID: `B001-report-new-option-pane-source-quality-0001DW-mcp-20260623`.
- Target UID/path: [UID:0001DW] `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`.
- Starting score/metadata: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:000097`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000097`, blank formal C++.
- Required report path: `tools/leaser/Agents/Agent-B001/research/0001DW-NewOptionPane-source-quality.md`.
- Report-only pass: no by-* docs, generated files, project-level files, IDA DB/tool state, or `-coverage-report.md` files were edited.
- Mandatory MCP provenance: current active IDB session `ff68e691` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Evidence Sources Checked

- Current assignment source: `tools/leaser/Agents/Agent-B001/goal.md`.
- Project workflow/reference source: `ntk-b-agent-workflow` and `by-structure.md`.
- Current target/support docs:
  - `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`
  - `by-class/NewOptionPane.md`
  - `by-file/OptionPane.md`
  - `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md`
  - exact helper pages `0x00540ea0`, `0x00540ef0`, `0x00540f50`, `0x00540ff0`, `0x00541040`
  - paint helper pages `0x00541660` and `0x005416d0`
  - `by-global/SendOptionPacket11B_540E50.md`
  - `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`
  - `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` as an ownership-rejection support page.
- Prior B001 executed report was used as a lead only:
  - `tools/leaser/Agents/Agent-B001/research/executed/0001DW-NewOptionPane-source-quality.md`.
- Coverage/state references checked without editing:
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`.
- MCP tools used against `ff68e691`: `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `xrefs_to`, `find`, `find_bytes`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `find_regex`, `search_text`, `imports_query`, and `int_convert`.
- MCP health was checked before and after the pass. `server_health` reported `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- One broad whole-listing `search_text DrawSectionHeader` request timed out after 60 seconds. This was not treated as MCP unavailability because follow-up `server_health` was immediately `ok`; narrower `find_regex`, scoped `search_text`, and import checks supplied the negative name evidence.

## Current MCP Function And Range Evidence

`lookup_funcs` and `entity_query` in current session `ff68e691` confirm the modeled NewOptionPane range and the same raw-helper state as the prior accepted pass:

| Address | Current MCP result |
| --- | --- |
| `0x0053ff90` | `sub_53FF90`, size `0x204`, constructor-shaped. |
| `0x005401a0` | `sub_5401A0`, size `0x92`, destructor-shaped. |
| `0x00540240` | `sub_540240`, size `0x4d`. |
| `0x00540290` | `nullsub_45`, size `0x1`. |
| `0x005402a0` | `sub_5402A0`, size `0x108`. |
| `0x005403b0` | `sub_5403B0`, size `0xd6`, volume/config apply helper. |
| `0x00540490` | `sub_540490`, size `0x37`, volume callback. |
| `0x005404d0` | `sub_5404D0`, size `0xe6`. |
| `0x005405c0` | `sub_5405C0`, size `0x37`. |
| `0x00540600` | `sub_540600`, size `0x210`, paint. |
| `0x00540880` | `sub_540880`, size `0x87`, key handling/page changes. |
| `0x00540910` | `sub_540910`, size `0x427`, mouse-click dispatch. |
| `0x00540d37`, `0x00540d39` | Not functions; trailing return/alignment and mouse-click switch data. |
| `0x00540db0` | `sub_540DB0`, size `0x9b`, server-option callback/error helper. |
| `0x00540e50` | `sub_540E50`, size `0x41`, shared `0x011b` packet sender. |
| `0x00540ea0` | Not a function; raw function-shaped `0x011b/0x63` packet body. |
| `0x00540ef0` | Not a function; raw function-shaped visible-option hit-test body. |
| `0x00540f50` | Not a function; raw function-shaped server-option apply body. |
| `0x00540ff0` | Not a function; raw function-shaped volume-display refresh body. |
| `0x00541040` | `sub_541040`, size `0xd4`, low/high display-mode option sender. |
| `0x005411b0` | `sub_5411B0`, size `0x85`, option-entry setup helper. |
| `0x00541240` | `sub_541240`, size `0x411`, option initialization. |
| `0x00541660` | `sub_541660`, size `0x70`, section-header paint helper. |
| `0x005416d0` | `sub_5416D0`, size `0x183`, option-button paint helper. |
| `0x00541a20` | `sub_541A20`, size `0x69`, page change. |
| `0x00541a90` | `sub_541A90`, size `0x9b`, slider visibility. |
| `0x00541b2b` | Not a function; padding boundary. |
| `0x00541b30` | `sub_541B30`, successor `IntegrateMacroDialog`. |
| `0x005a8b80`, `0x005a8c20` | Not functions; raw no-route option-size setters near the discontiguous helper. |
| `0x005a8c60` | `sub_5A8C60`, size `0x87`, discontiguous option-packet sender. |

`entity_query` over `0x0053ff80-0x00541b40` returned 22 functions, starting at `0x0053ff90` and ending with successor `0x00541b30`. `entity_query` over `0x005a8b70-0x005a8d00` returned only modeled functions `0x005a8c60` and `0x005a8cf0`; the two preceding setter starts are still raw/no-function bytes.

## Positive Evidence

- Constructor ownership remains direct. `xrefs_to 0x0053ff90` returns one code caller at `0x004b8549` inside `sub_4B83D0`, the `GeneralPurposePanel` construction path.
- Vtable ownership remains direct. `xrefs_to 0x006210a4` returns data refs from `0x0053ffcf`, `0x005401cb`, and `0x00542892`, matching constructor/destructor/scalar-destructor vtable stores. Raw VA bytes `a4 10 62 00` also occur at `0x0053ffd1`, `0x005401cd`, and `0x00542894`.
- Data/vtable slots still route core virtuals: `xrefs_to 0x00540600` -> `0x006210e8`; `xrefs_to 0x00540910` -> `0x006210f8`; `xrefs_to 0x00540db0` -> `0x00621104`.
- `OnPaint` decompilation calls only `0x004b9980`, `0x00541660`, and `0x005416d0`. It draws the `OPTION.PAL` background, four section headers when `this+0x12b9` is zero, previous/next page entries, and the option-entry loop.
- Paint helper caller sets remain option-local:
  - `0x00541660` refs: `0x00540639`, `0x0054064c`, `0x0054065f`, `0x00540672`, all inside `sub_540600`.
  - `0x005416d0` refs: `0x0054068b`, `0x005406aa`, `0x005406be`, `0x005406ea`, `0x005407fd`, all inside `sub_540600`.
- `OnMouseClick` decompilation still performs an inline visible-entry scan over 27 candidate slots. It computes `entry = base + 0x98 * index`, compares entry `+0x18c` to active page `this+0x12b9` or `0xff`, hit-tests rectangle `+0x17c` through `0x004b7e80`, and returns `-1` on no hit.
- `OnMouseClick` option dispatch calls `sub_540E50(5)`, `sub_540E50(6)`, `sub_540E50(9)`, `sub_540E50(4)`, `sub_5A8C60(7)`, `sub_5A8C60(3)`, `sub_5A8C60(1)`, `sub_541040(0)`, and `sub_541040(1)`.
- `0x00540e50` remains shared rather than a `NewOptionPane` method: current xrefs are four NewOptionPane mouse-click sites at `0x00540a0b`, `0x00540a23`, `0x00540a46`, `0x00540a90`, plus two `SelfLookPane`-neighborhood sites at `0x005690a4` and `0x00569164`.
- `0x00541040` remains file-level option/config packet support. Current xrefs are `0x00540ba9` and `0x00540bbe`, both in `OnMouseClick`. Decompilation writes `g_pConfig` offsets `0x28de58`, `0x28de5e`, and `0x28de5c`, compares `0x28de72` and `0x28de73`, builds a packet beginning with `0x1b`, and queues through `g_packetSender` / `0x00574bb0`.
- `0x005a8c60` remains real discontiguous option-packet helper code. Current xrefs are exactly `0x00540a58`, `0x00540aa2`, and `0x00540ab4`, all inside `OnMouseClick`. Decompilation writes bytes `0x1b`, `0x01`, selector, and `selector == 0`, sets a local-only terminator, and sends length `4` through `g_packetSender` / `0x00574bb0`.
- `SetOptionEntry` decompilation confirms the option-entry record layout:
  - record stride `0x98` / decimal `152`;
  - label storage at entry `+0xf8`;
  - type/action byte at entry `+0x178` / decimal `376`;
  - rectangle at entry `+0x17c` / decimal `380`;
  - page/visibility byte at entry `+0x18c` / decimal `396`.
- Current `0x00541240` decompilation corrects an old shorthand: it has 25 explicit `sub_5411B0` calls, not 27. The initialized indices are `0, 1, 14, 9, 2, 3, 4, 18, 5, 7, 10, 12, 11, 13, 8, 19, 20, 21, 22, 16, 17, 23, 24, 25, 26`. The 27-slot scan/switch domain is still valid, but indices `6` and `15` are logical holes/default cases.
- `ApplyVolumeSettings` decompilation writes five-times-scaled local values to config offsets `0x28de54` and `0x28de4c`, then calls SoundManager-like helpers `0x0057a340` and `0x0057a6d0`.
- `OnVolumeChanged` decompilation still returns when `oldValue == newValue`; nonzero `volumeType` writes the new value to `this+0x12bc`, zero writes to `this+0x12c0`, then it calls `ApplyVolumeSettings` and invalidates through vtable slot `+0x20`.
- Current raw bytes confirm boundaries:
  - `0x0053ff8d-0x0053ff90` are `0xcc` bytes before the constructor.
  - `0x00540d39-0x00540d9c` is little-endian jump-table data, not code.
  - `0x00540e91-0x00540ea0`, `0x00540eeb-0x00540ef0`, `0x00540fdf-0x00540ff0`, and `0x0054103a-0x00541040` are alignment/padding between helper bodies.
  - `0x00541b2b-0x00541b30` is `0xcc` padding before `IntegrateMacroDialog`.
  - `0x005a8b80`, `0x005a8c20`, and `0x005a8c60` are padding-separated bodies; only `0x005a8c60` is a current function.

## Negative Evidence

- Current `lookup_funcs` reports `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as `Not a function`.
- Current `xrefs_to`, `find type=code_ref`, `find type=data_ref`, and `find type=immediate` return zero inbound routes for `0x00540ea0`, `0x00540ef0`, `0x00540f50`, `0x00540ff0`, `0x005a8b80`, and `0x005a8c20`.
- Current little-endian VA pointer searches return zero hits for `a0 0e 54 00`, `f0 0e 54 00`, `50 0f 54 00`, `f0 0f 54 00`, `80 8b 5a 00`, and `20 8c 5a 00`.
- Current little-endian VA pointer searches also return zero hits for `0x005a8c60`, `0x00541660`, and `0x005416d0`; their known routes are direct code calls, not pointer tables.
- `find_regex` found RTTI strings for `FittingRoomDownloadControlPane`, `LivingObjectPane`, and `NewOptionPane`, but no strings for `DrawSectionHeader`, `DrawOptionButton`, `SendOptionPacket1BSelector`, `VisibleOptionHitTest`, `ApplyServerOptions`, or `RefreshVolumeDisplay`.
- Scoped `search_text FittingRoomDownloadControlPane` over `0x0053ff90-0x00541b2b` found zero hits. This rejects fitting-room source ownership for the target range and paint helpers.
- `imports_query` did not find relevant helper-name imports. It returned ordinary imports such as DirectDraw/WinMM/WSOCK32 entries, not option helper symbols.
- `xrefs_to` and pointer searches reject a current LivingObjectPane route for `0x005a8c60`. Its only direct callers are NewOptionPane mouse-click cases, and the body sends option bytes rather than local-player movement/entity data.

## Helper And Split Reanalysis

| Range | Current conclusion |
| --- | --- |
| `0x00540db0-0x00540e4b` | Real IDA-modeled callback/helper, data-routed from `0x00621104`; class-owned NewOptionPane context is correct. |
| `0x00540e50-0x00540e91` | Real IDA-modeled shared `0x011b` packet sender. Keep file/global option-protocol support; do not make it a `NewOptionPane` method because of two `SelfLookPane` callers. |
| `0x00540ea0-0x00540ee8` | Raw no-function body that sends `0x011b`, fixed `0x63`, and two caller bytes with length `5`. Keep exact child useful but no-route/no-C++ state. |
| `0x00540ef0-0x00540f4d` | Raw no-function visible-option hit-test body. Current `OnMouseClick` has an inline equivalent scan; no direct call/pointer route to this helper exists. |
| `0x00540f50-0x00540fdf` | Raw no-function server-option apply body. It writes server payload bytes to config offsets `0x28de73`, `0x28de72`, `0x28de70`, `0x28de75`, and `0x28de48`, then refreshes/invalidate. No direct route exists. |
| `0x00540ff0-0x0054103a` | Raw no-function volume display refresh body. It reads config offsets `0x28de54` and `0x28de4c`, divides by five, writes `this+0x12bc` and `this+0x12c0`, then refreshes/invalidate. No direct route exists. |
| `0x00541040-0x00541114` | Real IDA-modeled file-level low/high display-mode helper called by NewOptionPane mouse-click cases. |
| `0x00541660-0x005416d0` | Real IDA-modeled paint helper; all direct callers are `OnPaint`. `DrawSectionHeader` is a good descriptive name, but not a binary-proven original name. |
| `0x005416d0-0x00541853` | Real IDA-modeled paint helper; all direct callers are `OnPaint`. `DrawOptionButton` / `DrawOptionButtonItem` remains descriptive, not original-name proof. |
| `0x005a8b80-0x005a8c16` | Raw no-route option-size setter. Keep with `OptionPaneLegacySizeWordTable_66DECC` future split work, not this aggregate C++. |
| `0x005a8c20-0x005a8c5c` | Raw no-route option-size setter. Same disposition as `0x005a8b80`. |
| `0x005a8c60-0x005a8ce7` | Real modeled discontiguous option-packet helper. It is ready for an exact future child page if assigned, but should not be emitted inside the overbroad `0001DW` aggregate. |

Exact child splits are still needed before any full NewOptionPane C++ pass. The aggregate currently spans class methods, a compiler switch table, file-level helpers, raw no-route helper bodies, and a discontiguous helper dependency. That is strong documentation evidence, but not a clean single source-emission unit.

## Field, Layout, And Naming Reanalysis

- `OptionEntry` / `NewOptionPaneOptionEntry` remains the best descriptive name for the `0x98`-byte entry records. Do not claim exact original spelling yet.
- Entry fields:
  - `+0xf8`: wide label storage.
  - `+0x178`: type/action byte; paint treats it as a type, click dispatch treats it as action category.
  - `+0x17c`: hit/draw rectangle.
  - `+0x18c`: page/visibility byte; `0xff` means all pages.
- Pane fields:
  - `this+0x12b9`: active page index.
  - `this+0x12bc` and `this+0x12c0`: local volume display/slider values. The callback polarity is proven, but exact music/sound field names remain unresolved.
- Config/global names:
  - `dword_67A7C8` may be described as `g_pConfig` only when linked to established global docs; keep raw offsets visible in by-memory evidence.
  - `dword_67A7EC` may be described as `g_packetSender`; reject generated `g_pCashShopRequest`-style pollution for this option route.
- Source-facing helper names:
  - Strong descriptive names: `DrawSectionHeader`, `DrawOptionButton`, `VisibleOptionHitTest`, `ApplyServerOptions`, `RefreshVolumeDisplay`, `SendLowHighDisplayModeOption`, `SendOptionPacket11BSubcommand63`, and `SendOptionPacket1BSelector`.
  - Current MCP does not prove these exact original spellings through strings, listing names, imports, or source metadata.

## Ownership And Source-Placement Alternatives

1. [UID:000097] `NewOptionPane` direct owner/emitter for target aggregate: keep accepted.
   - Evidence for: constructor/vtable/destructor refs are class-specific; the target is primarily the class method cluster; the class clears the strict parent gate; `OptionPane.cpp` remains the file root.
   - Evidence against: the range also references file-level helpers, raw no-route helper bodies, and a discontiguous helper. This blocks aggregate C++ but not class ownership.
2. [UID:0000M7] `OptionPane.cpp` file root: keep as source root/support, not direct target owner.
   - Evidence for: old/new option panes, packet helpers, paint helpers, option-size table, and `0x005a8c60` all fit the option/settings source family.
   - Evidence against: the target page's primary executable surface is class methods and class vtables, so direct by-memory ownership should remain class-specific.
3. File-local helper ownership for `0x00540e50`, `0x00540ea0`, `0x00541040`, `0x00541660`, `0x005416d0`, and `0x005a8c60`: accepted where each helper page/document explains it.
   - Evidence for: some helpers have no `this`, shared callers, or only draw context/text arguments. Exact helper C++ should live on helper pages once source declarations are synchronized.
   - Evidence against: paint helpers and `0x005a8c60` are NewOptionPane-only by current direct caller set; that supports NewOptionPane contextual docs but does not force class-method ownership.
4. `FittingRoomDownloadControlPane` owner for paint helpers: rejected.
   - Evidence for: stale generated owner pollution and RTTI string elsewhere.
   - Evidence against: no target-range listing hits, no current fitting-room callers, and all current direct callers are NewOptionPane paint sites.
5. `LivingObjectPane` owner for `0x005a8c60` and nearby setters: rejected for the live `0x005a8c60` helper.
   - Evidence for: address neighborhood near broad LivingObjectPane local-player extension ranges.
   - Evidence against: `0x005a8c60` has only NewOptionPane mouse-click callers and sends option UI packet bytes. The two preceding setters remain no-route option-size/table candidates, not movement or local-player packet code.
6. Socket/protocol ownership for packet helpers: rejected as implementation owner.
   - Evidence for: helpers send through `g_packetSender` and `QueueAndSendPacket`.
   - Evidence against: option packet semantics and caller context are UI/settings-specific; the network sender is a dependency, not source owner.
7. No-owner/non-emitting target aggregate: rejected.
   - Evidence for: mixed helper shapes and raw helper starts.
   - Evidence against: class owner, source root, boundaries, and caller/callee evidence are strong enough for a reconstructable class aggregate with blank C++.

## Open Questions With Attempted Resolution

- Are exact child splits needed before C++? Yes. Existing child pages are useful, but the aggregate still mixes multiple source shapes; `0x005a8c60` lacks an exact by-memory page, and four server-option helpers are current raw no-function/no-route bodies.
- Did current MCP change the raw-helper state? No. Session `ff68e691` still reports `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as `Not a function`, with no xrefs/code refs/data refs/immediates/pointer hits.
- Did current MCP change `InitializeOptions` evidence? Yes. It corrects the old "27 SetOptionEntry calls" shorthand. There are 25 explicit calls, for all logical slots except `6` and `15`; the scan/switch domain remains 27 entries.
- Can source-facing names be inferred? Descriptive names are strong enough for prose, but not original spelling. Current strings/listing/import checks do not prove helper names.
- Can `this+0x12bc/+0x12c0` be finalized as music/sound? Not safely in this pass. The write polarity is known; final member spelling and ordering should wait for a synchronized Config/SoundManager pass.
- Is `0x005a8c60` OptionPane/NewOptionPane or LivingObjectPane? Current MCP closes it as OptionPane/NewOptionPane support; LivingObjectPane ownership is rejected.
- Should `0x005a8c60` receive an exact child? Yes, as future split work if assigned. It should not be emitted in the broad `0001DW` aggregate.

## Score And Metadata Recommendation

- Keep target metadata unchanged:
  - `COMPLETION:86`
  - `CONFIDENCE:86`
  - `CANONICAL_OWNER:000097`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000097`
  - blank formal C++
- Reason not higher:
  "
- Reason not lower:
  - session `ff68e691` reconfirms exact method map, constructor/vtable/callback refs, helper caller sets, option-entry layout, packet/config behavior, boundary bytes, and source root through [UID:000097] -> [UID:0000M7].
- Support metadata recommendation:
  - [UID:000097] `by-class/NewOptionPane.md`: keep current `86/87`, owner/emitter [UID:0000M7], blank C++.
  - [UID:0000M7] `by-file/OptionPane.md`: keep current `91/85`.
  - [UID:0001DX] helper island: keep current `88/88`, `RECONSTRUCTABLE:FALSE`, no emitter.
  - Child helper pages: keep current metadata unless a future child-specific pass promotes exact C++ or creates `0x005a8c60`.

## C++ Recommendation

- Do not add formal C++ to [UID:0001DW].
- Current no-code proof:
  - the target is an aggregate over many class methods, a jump table, exact helper children, and file-level/discontiguous helpers;
  - current IDB state has four raw no-function/no-route helper bodies inside [UID:0001DX];
  - source declarations are not synchronized for `NewOptionPane`, `OptionEntry`, `ScrollVolumePane`, render helpers, packet-buffer helpers, Config fields, SoundManager, and packet sender globals;
  - helper names remain descriptive, not original-name proof;
  - a partial helper-only C++ block in `0001DW` would duplicate child pages and create polluted pseudo-source.
- Future C++ should be child-first:
  - exact modeled helpers such as `0x00540e50`, `0x00541040`, `0x00541660`, `0x005416d0`, and a future exact `0x005a8c60-0x005a8ce7` page are the correct places for first-draft helper C++ once their individual gates and declarations are ready;
  - raw/no-route helpers `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` should remain blank until caller/source visibility and declarations are stronger.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`.
- Apply current MCP provenance:
  - add a `2026-06-23 B001 MCP Recheck` note for session `ff68e691`;
  - state that the prior `0b5e057e` pass remains historical/previously accepted, while `ff68e691` is the current evidence pass.
- Preserve current score/metadata and blank C++.
- Incorporate at report-level detail:
  - current function map and boundary bytes;
  - current no-function/no-route state for `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`;
  - current `OnMouseClick` packet route and discontiguous `0x005a8c60` callers/body;
  - current paint-helper caller sets and no original-name proof;
  - current `OnVolumeChanged` and `ApplyVolumeSettings` volume-field behavior;
  - corrected `InitializeOptions` fact: 25 explicit `SetOptionEntry` calls for all 27 logical slots except `6` and `15`; the hit-test/paint switch domain remains 27.
- Replace or amend the stale line:
  - old: "Live decompile of `0x00541240` confirms 27 `SetOptionEntry` calls for indices `0` through `26`..."
  - new: "Live decompile of `0x00541240` in session `ff68e691` confirms 25 explicit `SetOptionEntry` calls for logical indices `0,1,2,3,4,5,7,8,9,10,11,12,13,14,16,17,18,19,20,21,22,23,24,25,26`; the draw/input scan domain still covers 27 candidate slots, with indices `6` and `15` left as default/hole cases."

## Recommended Support Doc Changes

- `by-class/NewOptionPane.md`
  - Add the current `ff68e691` MCP recheck as the active evidence refresh.
  - Preserve current owner/source root and blank C++ rationale.
  - Add the 25 explicit setup-call correction if mentioning initialization completeness.
- `by-file/OptionPane.md`
  - Add current `ff68e691` provenance for `0x005a8c60`, raw helper state, and the future exact split.
  - Keep `0x005a8c60` as OptionPane/NewOptionPane support and reject LivingObjectPane.
- `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md`
  - Add the current `ff68e691` helper-state refresh: modeled `0x00540db0`, `0x00540e50`, `0x00541040`; raw/no-function `0x00540ea0`, `0x00540ef0`, `0x00540f50`, `0x00540ff0`; zero xrefs/code refs/data refs/immediates/pointer hits.
  - Keep container non-emitting at `88/88`.
- Exact raw-helper child pages:
  - `by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md`
  - `by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md`
  - `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`
  - `by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md`
  - Add `ff68e691` as current evidence if supervisor wants all prior `0b5e057e` statements refreshed; behavior/metadata/C++ conclusions do not change.
- Modeled helper/paint pages:
  - `by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md`
  - `by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md`
  - `by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md`
  - Add current xref/decompile/no-name refresh if the implementation callback includes support sync.
- `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`
  - No required change. Current text already records the direct `0x005a8c60` NewOptionPane route and no-route status for `0x005a8b80`/`0x005a8c20`.
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
  - No required change. Current text already rejects the `0x005a8b80-0x005a8c60` area as LivingObjectPane deferred work.

## Supervisor-Owned Coverage Text

The target and helper-island rows in `by-memory/-coverage-report.md` are stale relative to current by-* metadata. B001 must not edit coverage during this report-only pass. If the supervisor accepts coverage synchronization, use these replacement rows:

```text
    - [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md) 0x0053ff90-0x00541b2b | class-cluster | NewOptionPane : reconstructable : 86% : strong : B001 2026-06-23 MCP recheck in session `ff68e691` reconfirms the page-based options pane aggregate: exact modeled method map, constructor/vtable/destructor refs, mouse-click jump table, option-entry layout, 25 explicit setup calls over a 27-slot scan domain with logical holes `6` and `15`, raw/no-route server-option helper bodies in [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md), paint helper caller sets, volume/config fields, discontiguous `0x005a8c60` option-packet helper, and target-specific blank-C++ rationale; remaining blockers are current raw/no-function helper starts, no direct xref/pointer routes, unresolved original helper/member names, missing exact `0x005a8c60` split, and unsynchronized class/helper/packet/render declarations.
    - [UID:0001DX][0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers](by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md) 0x00540db0-0x00541114 | helper-island | NewOptionPaneServerOptionHelpers : not_reconstructable : 88% : strong : Reviewed non-emitting OptionPane/NewOptionPane helper-island container; current MCP session `ff68e691` confirms modeled children `0x00540db0`, `0x00540e50`, and `0x00541040`, raw/no-function bodies `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`, zero xref/code-ref/data-ref/immediate/pointer routes to the raw starts, exact packet/config/visible-hit/volume-display behavior on child pages, and padding between bodies; exact child pages carry source-bearing ownership while this island remains non-emitting to avoid duplicate aggregate C++.
```

No class/file coverage-row text is required for this target pass unless the supervisor also wants to refresh prose to mention session `ff68e691`.

## Validators Expected After Implementation

If the supervisor accepts the recommended by-* doc updates, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0001DW-NewOptionPane-source-quality-removed.md](0001DW-NewOptionPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child/helper support pages are changed during callback, also validate each changed child page with the same scoped command.

## Confidence

- Recommendation confidence: high for unchanged target score/metadata and blank aggregate C++.
- Evidence confidence: high for current MCP function/xref/decompile/byte evidence; medium-high for final source-facing helper/member names.
- Remaining uncertainty: original helper spellings, exact Config/SoundManager field names, whether no-route raw helper bodies survive in original source, and whether `0x005a8c60` should be split before the next C++ pass.

## Implementation Tracking Checklist

Report-only pass:
- [x] Supervisor acceptance received for implementation. Proof: supervisor callback assigned `B001-implement-new-option-pane-source-quality-0001DW-mcp-20260623` and accepted this report for non-coverage by-* implementation.
- [x] Target doc updated with `ff68e691` current MCP provenance, function map, xrefs, bytes, no-route helper state, `0x005a8c60` route, 25-call initialization correction, score rationale, and no-code proof. Proof: `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` now has a current `ff68e691` evidence section, preserves `0b5e057e` as historical, corrects `InitializeOptions` to 25 explicit setup calls over the 27-slot domain with holes `6` and `15`, records raw-helper no-route checks, boundary/padding/successor evidence, paint helper caller/no-name evidence, volume-field behavior, and keeps `86/86` with blank aggregate C++.
- [x] `by-class/NewOptionPane.md` updated or marked already-present at same-or-greater detail. Proof: support doc now records `ff68e691` as current evidence, preserves `0b5e057e` as historical, documents raw/no-function helper state, `0x005a8c60` OptionPane/NewOptionPane route and LivingObjectPane rejection, paint caller/no-name facts, 25-call correction, volume behavior, unchanged `86/87`, and blank C++ rationale.
- [x] `by-file/OptionPane.md` updated or marked already-present at same-or-greater detail. Proof: support doc now records current `ff68e691` provenance for the helper island, `0x005a8c60`, raw helper state, LivingObjectPane rejection, missing exact `0x005a8c60` child split, corrected 25-call initialization fact, volume behavior, and child-first/blank aggregate C++ direction while keeping file metadata unchanged.
- [x] `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md` updated or marked already-present at same-or-greater detail. Proof: helper-island container now records current `ff68e691` modeled helpers `0x00540db0`, `0x00540e50`, `0x00541040`, raw/no-function bodies `0x00540ea0`, `0x00540ef0`, `0x00540f50`, `0x00540ff0`, zero inbound route matrix, unchanged packet/config/hit-test/volume behavior, padding/boundaries, and unchanged `88/88` non-emitting container disposition.
- [x] Exact raw-helper child pages updated or explicitly marked not needed for this callback. Proof: `by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md`, `by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md`, `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`, and `by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md` now name `ff68e691` as current evidence, keep `0b5e057e`/C001 as historical where applicable, preserve zero-route proof, byte behavior, ownership/source placement, and blank-C++ rationale.
- [x] Modeled helper/paint pages updated or explicitly marked not needed for this callback. Proof: `by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md` now records current `ff68e691` callers/config/packet behavior and file-level placement; `by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md` and `by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md` now record current `ff68e691` caller sets, callee sets, no pointer/table route, no original helper-name proof, and fitting-room owner rejection.
- [x] No metadata/owner/emitter/reconstructable change applied unless supervisor changes accepted disposition. Proof: target remains `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:000097`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000097`; support docs retain their accepted metadata/dispositions.
- [x] Formal C++ kept blank for [UID:0001DW] with target-specific proof. Proof: target reconstruction notes now keep blank formal C++ because the aggregate spans class methods, jump table/data, file-level helpers, raw no-route helper bodies, and discontiguous `0x005a8c60`; future C++ is explicitly child-first after class/helper/packet/render/Config/SoundManager declarations and exact helper splits are synchronized.
- [x] No by-* docs, generated/project-level files, IDA DB/tool state, or `-coverage-report.md` files edited during report-only pass. Proof: this statement remains true for the original report-only pass. During the accepted implementation callback, only listed support by-* docs plus this report were manually edited; no `-coverage-report.md` file, IDA DB/tool state, or unrelated by-* doc was manually edited. Scoped validators produced their normal validator-owned state/autogen/stat output and no coverage report was edited by B001.
- [x] If implementation is accepted, scoped validators run for every changed by-* doc and results recorded here. Proof: all commands below were run from `E:\NTK\GhidraBridge\source-3\project-documentation` and the batch exited `0`; each scoped file validator reported `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0053ff90-0x00541b2b.NewOptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\NewOptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\OptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00541040-0x00541114.SendLowHighDisplayModeOption.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- [x] Supervisor-owned coverage replacement rows above applied by supervisor if accepted; B001 does not edit coverage reports. Proof: no `-coverage-report.md` file was manually edited; target/helper coverage text remains in this report for supervisor-owned application.
- [x] Leases used only during an implementation callback, immediately before editing and released after the edit/validator batch. Proof: B001 leased exactly the eleven changed by-* docs immediately before editing; after validators, `unlease` reported `Rejected[No active lease]` for each because the leases had already expired, and `tools/leaser/Agents/current_leases.md` showed `No active leases`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; accepted non-coverage items were applied to the target/support docs or recorded as not applicable/already covered by current support docs, and no blocker remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001DW-NewOptionPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0001DW"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001DW-NewOptionPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001DW-NewOptionPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001DW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
