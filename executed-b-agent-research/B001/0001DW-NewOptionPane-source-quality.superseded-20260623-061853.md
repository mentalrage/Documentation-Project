** TARGET-REPORT-UID:0001DW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 0001DW NewOptionPane Source-Quality Report

## Assignment And Scope

- Agent: B001.
- Assignment ID: `B001-goal2-new-option-pane-source-quality-0001DW-20260623`.
- Target UID/path: [UID:0001DW] `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`.
- Starting score/metadata: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:000097`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000097`, blank formal C++.
- Required report path: `tools/leaser/Agents/Agent-B001/research/0001DW-NewOptionPane-source-quality.md`.
- Report-only pass: no by-* docs, generated files, project-level files, IDA DB/tool state, or `-coverage-report.md` files were edited.

## Evidence Sources Checked

- Current target/support docs:
  - `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`
  - `by-class/NewOptionPane.md`
  - `by-file/OptionPane.md`
  - `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md`
  - exact helper pages `0x00540db0`, `0x00540ea0`, `0x00540ef0`, `0x00540f50`, `0x00540ff0`, `0x00541040`
  - paint helper pages `0x00541660` and `0x005416d0`
  - `by-global/SendOptionPacket11B_540E50.md`, `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`, ScrollVolumePane/SoundManager support pages.
- Current mandatory IDA MCP evidence from endpoint `http://127.0.0.1:13337/mcp`.
  - Supervisor-provided stale sessions `15216dde` and `0f0b38fb` were discarded after restart.
  - Final evidence was collected against active IDB session `0b5e057e` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health` reported module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `get_bytes`, `insn_query`, `disasm`, `find`, `find_bytes`, `find_regex`, `search_text`, `entity_query`, and `get_global_value`.
- Numeric conversions were checked with `tools/int_convert.py` for `0x1b`, `0x98`, `0x17c`, `0x178`, `0x18c`, `0x12b9`, `0x12bc`, `0x12c0`, `0x28de54`, `0x28de4c`, `0x28de73`, `0x28de72`, `0x28de70`, `0x28de75`, `0x28de48`, `0x63`, and `0x011b`.

## Current IDA MCP Findings

`lookup_funcs` on active session `0b5e057e` confirms the main modeled NewOptionPane map:

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
| `0x00540910` | `sub_540910`, size `0x427`, mouse click dispatch. |
| `0x00540d37`, `0x00540d39` | Not functions; trailing return/alignment and switch data. |
| `0x00540db0` | `sub_540DB0`, size `0x9b`, server-option callback. |
| `0x00540e50` | `sub_540E50`, size `0x41`, shared `0x011b` packet sender. |
| `0x00540ea0` | Not a function in current active IDB; raw function-shaped body. |
| `0x00540ef0` | Not a function in current active IDB; raw function-shaped body. |
| `0x00540f50` | Not a function in current active IDB; raw function-shaped body. |
| `0x00540ff0` | Not a function in current active IDB; raw function-shaped body. |
| `0x00541040` | `sub_541040`, size `0xd4`, low/high display-mode packet helper. |
| `0x005411b0` | `sub_5411B0`, size `0x85`, option-entry setup. |
| `0x00541240` | `sub_541240`, size `0x411`, option initialization. |
| `0x00541660` | `sub_541660`, size `0x70`, section-header paint helper. |
| `0x005416d0` | `sub_5416D0`, size `0x183`, option-button paint helper. |
| `0x00541a20` | `sub_541A20`, size `0x69`, page change. |
| `0x00541a90` | `sub_541A90`, size `0x9b`, slider visibility. |
| `0x00541b2b` | Not a function; padding boundary. |
| `0x00541b30` | `sub_541B30`, successor `IntegrateMacroDialog`. |
| `0x005a8c60` | `sub_5A8C60`, size `0x87`, discontiguous option packet sender. |

Important correction: the current active IDB does not retain the documented C001 neutral function records for `0x00540ef0`, `0x00540f50`, or `0x00540ff0`. The byte bodies remain recoverable and source-shaped, but current documentation should distinguish historical C001 observations from the active `0b5e057e` IDB state.

## Positive Evidence

- Constructor ownership is direct: `xrefs_to 0x0053ff90` returns a single code caller at `0x004b8549` inside `sub_4B83D0`, the `GeneralPurposePanel` construction path already documented.
- Vtable/RTTI ownership is direct for `NewOptionPane`: `search_text NewOptionPane` in the target range shows constructor/destructor stores to `??_7NewOptionPane@@6B@` and adjusted vtables at `+0xa0` and `+0xa4`; raw pointer search for `0x006210a4` found hits at `0x0053ffd1`, `0x005401cd`, and `0x00542894`.
- `xrefs_to` confirms `0x00540600`, `0x00540910`, and `0x00540db0` are routed through data/vtable/callback slots `0x006210e8`, `0x006210f8`, and `0x00621104`.
- `OnPaint` calls only the local option paint helpers and frame renderer: callees are `0x004b9980`, `0x00541660`, and `0x005416d0`.
- Paint helper caller sets are option-local:
  - `0x00541660` has four code refs: `0x00540639`, `0x0054064c`, `0x0054065f`, `0x00540672`, all inside `sub_540600`.
  - `0x005416d0` has five code refs: `0x0054068b`, `0x005406aa`, `0x005406be`, `0x005406ea`, `0x005407fd`, all inside `sub_540600`.
- `OnMouseClick` caller/callee evidence remains option-specific:
  - callees include hit-test helper `0x004b7e80`, page change `0x00541a20`, shared packet sender `0x00540e50`, discontiguous packet sender `0x005a8c60`, queue send `0x00574bb0`, low/high display helper `0x00541040`, group-marker helpers `0x005adc20`/`0x005adc70`, and `ApplyVolumeSettings` `0x005403b0`.
  - decompilation shows `sub_540E50(5)`, `sub_540E50(6)`, `sub_540E50(9)`, `sub_540E50(4)`, and `sub_5A8C60(7)`, `sub_5A8C60(3)`, `sub_5A8C60(1)` from option-click cases.
- `0x00540e50` is shared, not a `NewOptionPane` method: xrefs are four NewOptionPane mouse-click refs at `0x00540a0b`, `0x00540a23`, `0x00540a46`, `0x00540a90` and two `SelfLookPane` neighborhood refs at `0x005690a4`, `0x00569164`.
- `0x00541040` is a file-level option/config helper called only from `OnMouseClick` at `0x00540ba9` and `0x00540bbe`. Decompilation writes `dword_67A7C8 + 0x28de58/+0x28de5e/+0x28de5c`, compares `+0x28de72/+0x28de73`, and sends through `dword_67A7EC`/`0x00574bb0`.
- `0x005a8c60` is real project code and option-routed: `lookup_funcs` reports `sub_5A8C60` size `0x87`; xrefs/code-ref search returns exactly `0x00540a58`, `0x00540aa2`, and `0x00540ab4`, all inside `OnMouseClick`. Decompilation writes packet bytes `0x1b` / decimal `27` (Verified with int_convert.py), `0x01`, selector, and `selector == 0`, then sends four bytes via `dword_67A7EC`.
- `SetOptionEntry` and paint helpers validate the option-entry layout:
  - stride `0x98` / decimal `152` (Verified with int_convert.py).
  - label storage at entry `+0xf8`.
  - action/type byte at entry `+0x178` / decimal `376` (Verified with int_convert.py).
  - rectangle at entry `+0x17c` / decimal `380` (Verified with int_convert.py).
  - page/visibility byte at entry `+0x18c` / decimal `396` (Verified with int_convert.py).
- `InitializeOptions` calls `SetOptionEntry` for indices `0..26`, matching the 27-entry mouse/paint scans and loop bound `0x1b` / decimal `27` (Verified with int_convert.py).
- `ApplyVolumeSettings` reads pane-local fields and writes persisted config volume scalars:
  - `dword_67A7C8 + 0x28de54` / decimal `2678356` (Verified with int_convert.py).
  - `dword_67A7C8 + 0x28de4c` / decimal `2678348` (Verified with int_convert.py).
  - SoundManager callees `0x0057a340` and `0x0057a6d0` consume the scaled values.
- `OnVolumeChanged` remains exactly the ScrollVolumePane callback target: `0x00540490` returns when old/new values match, writes nonzero `volumeType` changes to `this+0x12bc` / decimal `4796` and zero `volumeType` changes to `this+0x12c0` / decimal `4800` (Verified with int_convert.py), then calls `ApplyVolumeSettings`.
- Boundary bytes are stable:
  - `0x0053ff8d-0x0053ff90` is `0xcc` padding before the constructor.
  - `0x00540d39-0x00540d9c` contains little-endian branch targets, not executable code.
  - `0x00541b2b-0x00541b30` is `0xcc` padding before `0x00541b30`.

## Negative Evidence

- Current `lookup_funcs` on session `0b5e057e` reports `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as `Not a function`.
- `xrefs_to` and `find` for `code_ref`, `data_ref`, and `immediate` return zero hits for all four raw starts: `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`.
- Raw VA little-endian `find_bytes` found zero hits for `a0 0e 54 00`, `f0 0e 54 00`, `50 0f 54 00`, and `f0 0f 54 00`. This rejects direct pointer/table/global routes to the four raw helper starts in the active IDB.
- `find_bytes` found zero literal pointer hits for `0x005a8c60`, `0x00541660`, and `0x005416d0`; their current routes are direct code calls, not pointer tables.
- `find_regex`/`search_text` found RTTI/string evidence for `NewOptionPane` and `FittingRoomDownloadControlPane`, but no current IDB strings or listing references for `DrawSectionHeader` or `DrawOptionButton`. Those names remain generated/source-facing lead names, not binary-proven original names.
- `search_text FittingRoomDownloadControlPane` over the NewOptionPane target range found no fitting-room listing hits. Fitting-room RTTI exists elsewhere, but there is no direct caller/callee route from the paint helpers to fitting-room code.
- No import route supports source ownership for NewOptionPane helpers. `entity_query imports` for relevant source/helper names found no matching imports other than unrelated `OffsetRect`.
- Current IDB facts reject the stale assumption that the three C001-promoted helpers are currently modeled functions. Their byte bodies remain source-shaped, but current docs should not say the active IDB has retained those function records.

## Helper And Split Reanalysis

The existing split strategy remains mostly correct, but the wording needs correction for current active IDB state.

| Range | Current conclusion |
| --- | --- |
| `0x00540db0-0x00540e4b` | Real callback/helper, IDA-modeled, class-owned `NewOptionPane` server-option error path. Keep as exact child; no formal C++ yet because callback block type and message helper names are not final. |
| `0x00540e50-0x00540e91` | Real shared file-level packet helper; keep under OptionPane/global packet docs, not `NewOptionPane` method, because of the two `SelfLookPane` callers. |
| `0x00540ea0-0x00540ee8` | Raw function-shaped file-level option packet helper; body sends `0x011b` / decimal `283` plus fixed `0x63` / decimal `99` and two caller bytes (Verified with int_convert.py). Current IDB still has no function record, xrefs, pointer hits, or caller route. Existing exact child is valid, but current docs should emphasize raw/no-route state. |
| `0x00540ef0-0x00540f4d` | Raw function-shaped `NewOptionPane` hit-test helper in current IDB; scans 27 entries, stride `0x98`, page byte at `+0x18c`, active page at `this+0x12b9`, rectangle at `+0x17c`, returns index or `-1`. Existing exact child is useful, but "IDA-promoted" wording is stale for active session `0b5e057e`. |
| `0x00540f50-0x00540fdf` | Raw function-shaped class helper in current IDB; writes server payload bytes to config offsets `+0x28de73`, `+0x28de72`, `+0x28de70`, `+0x28de75`, `+0x28de48`, calls `ApplyVolumeSettings`, and invalidates via vtable slot `+0x20`. Existing exact child is useful; active-IDB function promotion wording is stale. |
| `0x00540ff0-0x0054103a` | Raw function-shaped class helper in current IDB; refreshes local volume display fields from config offsets `+0x28de54/+0x28de4c`, calls `ApplyVolumeSettings`, and invalidates. Existing exact child is useful; active-IDB function promotion wording is stale. |
| `0x00541040-0x00541114` | Real modeled file-level low/high display-mode helper, direct callers from `OnMouseClick`. Keep exact child and OptionPane file-level route. |
| `0x00541660-0x005416d0` | Real modeled paint helper; all direct callers in `OnPaint`; current best source-facing names remain `DrawSectionHeader` or file-local equivalent, not binary-proven original names. |
| `0x005416d0-0x00541853` | Real modeled paint helper; all direct callers in `OnPaint`; current best source-facing names remain `DrawOptionButton` or file-local equivalent, not binary-proven original names. |
| `0x005a8c60-0x005a8ce7` | Real modeled discontiguous option packet helper; direct callers only from `OnMouseClick`; not LivingObjectPane. Current docs mention it, but there is no exact by-memory page at the linked filename. This is a follow-up split/documentation gap outside the target range. |

Exact child splits are still needed before any full C++ pass. The raw helper bodies are byte-recovered, but the aggregate source currently mixes modeled class methods, raw/no-route helper bodies, file-level packet helpers, file-level paint helpers, a jump table, and a discontiguous packet helper dependency.

## Field, Layout, And Naming Reanalysis

- `NewOptionPane::OptionEntry` or `NewOptionPaneOptionEntry` is the best descriptive layout name for the `0x98`-byte entry records. Do not finalize exact original spelling yet.
- Recommended descriptive fields:
  - `m_label` at entry `+0xf8`.
  - `m_action` / `m_type` at entry `+0x178`; `m_action` is better for click dispatch, `m_type` is better for paint switch. A final source pass should pick one based on broader source style.
  - `m_rect` at entry `+0x17c`.
  - `m_page` / `m_visiblePage` at entry `+0x18c`; `0xff` means visible on all pages.
- Pane fields:
  - `this+0x12b9`: `m_activePage` / active option page index.
  - `this+0x12bc` and `this+0x12c0`: local volume display/slider values. Current evidence proves nonzero `volumeType` writes `+0x12bc` and zero writes `+0x12c0`; exact music-versus-sound original field spelling remains unresolved because support docs do not fully settle `+0x28de54/+0x28de4c` ordering.
- Config fields:
  - `+0x28de48` is already documented by `g_pConfig` as sound-effects enablement.
  - `+0x28de54/+0x28de4c` are persisted volume scalars used by NewOptionPane and SoundManager; use descriptive `persisted volume` wording until Config field names are finalized.
  - `+0x28de72/+0x28de73` are low/high display-mode comparison bytes in `0x00541040` and server-applied option bytes in `0x00540f50`.
- Packet/global names:
  - `dword_67A7EC` should be referred to as `g_packetSender` only when linking to the established global docs; avoid generated `g_pCashShopRequest` pollution.
  - `dword_67A7C8` should be referred to as `g_pConfig` only with the global docs; raw IDA offset evidence should remain visible for source-quality review.
- Helper names:
  - `NewOptionPane::DrawSectionHeader` and `NewOptionPane::DrawOptionButton` are useful provisional source-facing names because generated `class_NewOptionPane.cpp` uses them and current IDA callers are all `OnPaint`.
  - The direct code owner remains safer as `OptionPane.cpp` file-local helper unless a final class declaration pass decides to make them private/static `NewOptionPane` methods.
  - `SendOptionPacket11BSubcommand63`, `VisibleOptionHitTest`, `ApplyServerOptions`, `RefreshVolumeDisplay`, `SendLowHighDisplayModeOption`, and `SendOptionPacket1BSelector` are descriptive names. They should not be treated as proven original spellings.

## Ownership And Source-Placement Alternatives

1. [UID:000097] `NewOptionPane` direct owner/emitter for target aggregate: accepted.
   - Evidence for: target is primarily the class method cluster; constructor/destructor/vtable/RTTI refs are class-specific; `NewOptionPane` class clears the strict gate; file root [UID:0000M7] `OptionPane` remains the parent source file.
   - Evidence against: the physical range also references file-level helpers and raw/no-route helper bodies; this blocks formal aggregate C++ but not ownership.
2. [UID:0000M7] `OptionPane.cpp` file root: accepted as source root/support, not direct aggregate owner.
   - Evidence for: old and new option panes are sibling source-family code; file-level packet and paint helpers fit the module.
   - Evidence against: the target page's primary executable surface is class methods and vtables, so making the target direct owner a file page would lose class-specific ownership.
3. File-local helper ownership for `0x00540e50`, `0x00540ea0`, `0x00541040`, `0x00541660`, `0x005416d0`, and `0x005a8c60`: accepted where documented.
   - Evidence for: these helpers are packet/paint/config helpers, not all class-method-shaped; some have shared callers or no `this` pointer.
   - Evidence against: direct callers for paint and `0x005a8c60` are NewOptionPane-only; this supports contextual NewOptionPane documentation but not mandatory class-method ownership.
4. `FittingRoomDownloadControlPane` owner for paint helpers: rejected.
   - Evidence for: stale generated owner and RTTI/name presence elsewhere.
   - Evidence against: zero direct callers from fitting-room code in current IDB, all observed paint-helper callers inside `OnPaint`, and no target-range listing hits for `FittingRoomDownloadControlPane`.
5. `LivingObjectPane` owner for `0x005a8c60`: rejected.
   - Evidence for: physical neighborhood near LivingObjectPane-related broad ranges.
   - Evidence against: direct callers are all NewOptionPane mouse-click cases; body sends option packet `0x1b`, not movement/local-player data.
6. Protocol/network/socket ownership for packet helpers: rejected as implementation owner.
   - Evidence for: helpers use `g_packetSender`/`QueueAndSendPacket`.
   - Evidence against: packet shape and option state are UI option-specific; network sender is a dependency, not source owner.
7. No-owner/non-emitting target aggregate: rejected.
   - Evidence for: mixed helper shapes and raw no-route children.
   - Evidence against: class owner and source root are already strong; no-owner would hide useful class ownership.

## First-Draft C++ Recommendation

- Eligible for draft C++: not for this aggregate.
- Recommended code: keep formal `RECONSTRUCTION_CPP` blank for [UID:0001DW].
- Reason code should remain blank:
  - Current active IDB reports `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` as non-functions with no direct xrefs or pointer hits.
  - The aggregate spans many class methods plus a jump table and delegates to exact helper children. A single by-memory C++ block would either duplicate child pages or collapse class/file helper boundaries.
  - Exact source declarations are not synchronized for `NewOptionPane`, `OptionEntry`, `ScrollVolumePane`, shared `Pane` callbacks, `GrafPort`/Surface helpers, packet-buffer helpers, Config fields, and SoundManager volume APIs.
  - The paint helper names are good provisional source names but not binary-proven original names.
  - Partial helper-only C++ inside this aggregate would create polluted pseudo-source because the helper bodies belong on exact children or file/class support docs, not the aggregate.
- Exact no-code proof: current MCP proves class ownership and byte behavior, but also proves no function/xref/pointer route for the raw server-option helpers in the active IDB. Until exact helper splits/source declarations are synchronized, aggregate C++ would be less faithful than blank C++ plus documented evidence.

## Final Recommendation

- Keep target metadata unchanged:
  - `COMPLETION:86`
  - `CONFIDENCE:86`
  - `CANONICAL_OWNER:000097`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000097`
  - blank formal C++
- Do not raise above `86/86` in this pass. Current MCP adds useful evidence, but it also shows that the active IDB does not retain the prior C001 helper function records, and there is still no exact by-memory page for the live discontiguous `0x005a8c60` helper.
- Update target/support docs to record the current `0b5e057e` IDB state and preserve the older C001 observations as historical/superseded or session-specific rather than current active facts.
- Keep source placement through [UID:000097] `NewOptionPane` -> [UID:0000M7] `OptionPane.cpp`.
- Keep exact child ownership decisions as-is unless a later split-specific implementation creates the missing `0x005a8c60` page.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`.
- Incorporate these facts:
  - Current MCP session `0b5e057e` active IDB evidence and stale-session discard (`15216dde`, `0f0b38fb`).
  - Current function map, especially current `Not a function` status for `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`.
  - Current xref/call evidence for constructor, vtable/callback slots, paint helpers, packet helpers, and discontiguous `0x005a8c60`.
  - Correct the C001 helper-state wording: the current active IDB does not show neutral function records for `0x00540ef0/0x00540f50/0x00540ff0`; the raw bodies remain byte-recovered and exact child pages remain useful.
  - Record current raw-byte/padding evidence for `0x00540d39-0x00540d9c`, `0x00540e90-0x00541040`, and `0x00541b2b-0x00541b30`.
  - Add the target-specific no-code proof above.
- Metadata/score/owner/emitter/reconstructable/C++ changes: none.

## Recommended Support Doc Changes

- `by-class/NewOptionPane.md`
  - Add the current `0b5e057e` MCP recheck.
  - Correct the current helper-state summary to say all four `0x00540ea0/0x00540ef0/0x00540f50/0x00540ff0` starts are currently not functions and have zero xrefs/code refs/data refs/immediate refs.
  - Preserve the class owner/emitter route and blank C++ rationale.
- `by-file/OptionPane.md`
  - Add the current `0x005a8c60` evidence: modeled `sub_5A8C60`, size `0x87`, exactly three direct `OnMouseClick` callers, packet bytes `0x1b`, `0x01`, selector, `selector == 0`, length 4 through `g_packetSender`.
  - Keep it as OptionPane/NewOptionPane support, not LivingObjectPane.
  - Note that no exact by-memory page currently exists at the linked `0x005a8c60-0x005a8ce7.NewOptionPaneSendOptionPacket1BSelector.md`; recommend a later split-specific pass if supervisor wants exact coverage.
- `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md`
  - Update the current active-IDB helper state: `0x00540ef0`, `0x00540f50`, and `0x00540ff0` are not currently functions in session `0b5e057e`; prior C001 promotion wording is historical/superseded for this active IDB.
  - Preserve exact raw helper body evidence and child split policy.
- Exact child pages:
  - `0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md`
  - `0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`
  - `0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md`
  - Replace "IDA-promoted current function" wording with "raw function-shaped body in current active IDB; historically observed/promoted in an older C001 pass, but not retained in active `0b5e057e`."
  - Keep behavior, ownership, and no-C++ conclusions.
- Paint helper pages `0x00541660` and `0x005416d0`
  - Optionally add the current caller/code-ref refresh and `search_text` no-name result for `DrawSectionHeader`/`DrawOptionButton`.
  - No metadata change required.

## Score And Metadata Recommendation

- Current target score/metadata: `86/86`, `CANONICAL_OWNER:000097`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000097`, blank C++.
- Recommended target score/metadata: unchanged `86/86`, same owner/emitter/reconstructable fields, blank C++.
- Reason not higher:
  - active IDB currently has four raw/no-function helper starts in the server-option island;
  - the no-xref/no-pointer/no-immediate route remains for those starts;
  - exact source-facing names for helper bodies and option/config fields are still inferred/descriptive;
  - `0x005a8c60` is live and option-routed but lacks an exact by-memory page;
  - formal C++ remains unsafe for the aggregate.
- Reason not lower:
  - main method map, constructor/vtable/callback refs, helper caller sets, option-entry layout, packet/config behavior, and source root are strongly revalidated by current MCP.

## Open Questions With Attempted Resolution

- Are exact child splits needed before C++? Yes. Existing helper children are useful, but current active IDB still treats several starts as raw/non-functions and `0x005a8c60` lacks an exact page.
- Can exact source names be inferred?
  - Strong descriptive names can be used in prose: `DrawSectionHeader`, `DrawOptionButton`, `VisibleOptionHitTest`, `ApplyServerOptions`, `RefreshVolumeDisplay`, `SendLowHighDisplayModeOption`, `SendOptionPacket1BSelector`.
  - Exact original spellings remain unresolved; no current IDB string/listing/source route proves them.
- Can `this+0x12bc/+0x12c0` be named as music/sound? Not safely as final names in this pass. The callback polarity is known; config/SoundManager support does not fully settle final source member spelling for both persisted volume offsets.
- Is `0x005a8c60` OptionPane/NewOptionPane or LivingObjectPane? Current evidence resolves it to OptionPane/NewOptionPane support; LivingObjectPane is rejected.
- Is C++ safe as an aggregate skeleton? No. It would require synchronized class/member/helper declarations and would otherwise emit pseudo-source.

## Exact Supervisor-Owned Coverage Text

- No coverage-report edit is recommended for this report.
- Reason: target score/metadata stay `86/86`, and this pass recommends documentation corrections/support updates rather than a coverage-row score or range change.
- If a later supervisor assignment creates an exact `0x005a8c60-0x005a8ce7` page, that separate split should supply its own exact `by-memory/-coverage-report.md` text.

## Follow-Up Actions

- Supervisor: validate whether to accept the target/support doc corrections with no score change.
- Future B-agent split pass: consider creating an exact by-memory page for `0x005a8c60-0x005a8ce7` and reconciling the stale link in `OptionPaneLegacySizeWordTable_66DECC.md`.
- Future C++ pass: synchronize `NewOptionPane`, `OptionEntry`, Config, PacketBuffer, GrafPort/Surface, ScrollVolumePane, and SoundManager declarations before adding aggregate or child C++.

## Confidence

- Recommendation confidence: high for no score/metadata change and no-code decision.
- Score confidence: medium-high; the target remains well evidenced but cannot move up while current IDB raw-helper state and no-route blockers remain.
- Remaining uncertainty: original helper names, exact Config/member field spellings, and whether the raw no-route helpers are retained source bodies or optimized/unreferenced duplicates.

## Validator Results

- Report-only pass: no validators were run because no by-* docs were edited.
- Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* updates:
  - `python .\tools\validator.py --mode file --file by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class/NewOptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file/OptionPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- Validator-owned side effects reported:
  - First target validator reported `stats_row_update: 3` for [UID:0001DW] rows in `project-level/-auto-completion-stats.md`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Subsequent scoped validators reported `projected_stats_update: 1` and `autogen_registry_rebuild: 1`.
  - All scoped validators reported existing unrelated `autogen_cpp_conflict: 5`, `autogen_registry_stale: 2`, `autogen_children_fallback_insert: 8`, `autogen_children_marker_missing: 8`, and `autogen_report_noop: 7`; these were not target-specific failures.
  - No `-coverage-report.md` file was edited by B001.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001DW-NewOptionPane-source-quality.md`
- Modified by B001 implementation callback:
  - `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`
  - `by-class/NewOptionPane.md`
  - `by-file/OptionPane.md`
  - `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md`
  - `by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md`
  - `by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md`
  - `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`
  - `by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md`
  - `by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md`
  - `by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md`
  - `tools/leaser/Agents/Agent-B001/research/0001DW-NewOptionPane-source-quality.md`
- Validator-owned generated/project-level side effects reported during validation: `project-level/-auto-completion-stats.md` and `tools/validator.ini`.
- Leaser-state side effect from cleanup: `tools/leaser/Agents/current_leases.md`; release check found no active B001 lease entries for the NewOptionPane paths.
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and assigned `B001-goal2-new-option-pane-source-quality-0001DW-20260623-implementation`.
- [x] Target/support docs to update: target, class, file, helper island, four exact raw-helper child pages, and two paint helper pages were updated or confirmed with callback details.
- [x] Current target state and actual evidence checked recorded. Proof: report body records B001 MCP evidence session `0b5e057e`, function map, xrefs, callees, disassembly/bytes, strings/names, pointer/code/data/immediate searches, and int conversions; implementation docs now describe `0b5e057e` as the accepted evidence session because current MCP was later restarted to `b880584f`.
- [x] Metadata/score changes to apply: none. Proof: target remains `86/86`; all accepted support pages kept existing metadata.
- [x] Owner/emitter/reconstructable changes to apply: none. Proof: target remains `CANONICAL_OWNER:000097`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000097`; support page owners/emitters unchanged.
- [x] Split/rename/new-child changes to apply: none. Proof: no new `0x005a8c60-0x005a8ce7` child page was created; it is documented as future split work.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: by-* docs were updated only; no IDA DB edits, renames, comments, types, or source files were changed.
- [x] First-draft C++ or no-code proof to apply. Proof: target and child pages keep formal C++ blank; target/class/file/helper docs now include target-specific no-code proof about raw/no-route helpers, missing `0x005a8c60` exact page, and unsynchronized declarations.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: docs now include no-function/no-xref helper state, raw helper behavior, option-entry layout, packet/config paths, paint helper caller/no-name refresh, discontiguous `0x005a8c60` route, and source-placement alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: docs preserve C001 promotion as historical/session-specific, reject FittingRoom and LivingObjectPane ownership, reject protocol/socket implementation ownership, and preserve aggregate-C++ rejection.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: docs identify Wave2/Wave3/generated names as lead material only and preserve generated FittingRoom owner pollution as rejected.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: helper original names, final Config/volume field names, exact `0x005a8c60` split, and aggregate C++ readiness remain documented with score/C++ impact.
- [x] Validators to run: scoped validators for every changed by-* doc after implementation callback. Proof: all ten changed by-* docs validated with exit `0`, `ok: 1`.
- [x] Supervisor-owned coverage-report/tracker text to apply: none for this report. Proof: no score/metadata/range change and no `-coverage-report.md` edit recommended or performed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: accepted in the callback assignment for `B001-goal2-new-option-pane-source-quality-0001DW-20260623-implementation`.
- [x] All accepted target/support doc details incorporated at report-level detail: target/class/file/container/exact helper/paint helper pages now carry the accepted evidence, source-placement reasoning, helper-state correction, no-code rationale, and rejected alternatives.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: no metadata, owner, emitter, split, rename, new child, or C++ changes were accepted; docs now state why `86/86`, owner/emitter, and blank C++ remain unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: C001 helper function promotion is historical/session-specific; FittingRoom, LivingObjectPane, protocol/socket ownership, generated-name authority, and aggregate C++ are rejected with evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: helper original names, `this+0x12bc/+0x12c0` final sound/music names, Config field spellings, `0x005a8c60` exact split, and aggregate C++ readiness remain documented unresolved with concrete blockers.
- [x] Validators run and results recorded: all required scoped validators and exact helper/paint validators ran from project root with exit `0`, `ok: 1`; validator-owned stats/registry side effects are recorded above.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: confirmed unchanged/none; no `-coverage-report.md` file edited.
- [x] Remaining unapplied accepted items listed with exact blocker: none. The only future work is out of scope for this callback: optional exact `0x005a8c60-0x005a8ce7` split and later synchronized C++ pass.
- [x] Leases released or confirmed clear: final `B001 unlease` check reported `Rejected[No active lease]` for every NewOptionPane path, and `current_leases.md` has no B001/NewOptionPane entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001DW-NewOptionPane-source-quality.superseded-20260623-061853.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0001DW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
