** TARGET-REPORT-UID:0001FX **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0001FX RightButtonMenuPaneCore Source-Quality Report

## Finalized Report / Current Recommendation

UID0001FX is correctly attached to `RightButtonMenuPane` ownership, but the current by-memory page is a source-quality aggregate over eleven separate methods/helpers plus internal jump-table data and alignment. The best implementation is split-first: keep the current page as the reviewed non-emitting container/index for `0x00554b40-0x0055577b`, create exact by-memory children for each function body and the event jump-table island, and route those reconstructable children through [UID:0000C0] `RightButtonMenuPane`.

Do not insert aggregate C++ into UID0001FX. By-structure limits by-memory C++ to the page's own source range; this page currently spans many child functions. The current `RECONSTRUCTION_CPP CODE` block should remain blank and, after the child pages are created, UID0001FX should be changed to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and a container score of `COMPLETION:90`, `CONFIDENCE:92`. If the supervisor accepts only a non-split callback, leave `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C0`, and blank C++ in place rather than emitting unsafe aggregate code.

Implementation repair status after Gate 2 source-emitter review: UID0001FX remains a blank-C++ non-emitting container. Child pages `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` now carry first-draft formal C++ in their own formal blocks. Child pages `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` now have blank `EMITTER_UIDS` plus child-specific no-code proof. Child `0004FA` remains `RECONSTRUCTABLE:FALSE`, blank-emitter generated switch data.

The earlier named blockers are now resolved into implementation-ready outcomes:

- Final row labels are confirmed as Look, Trade, Whisper, Group, and Info.
- Useful field names are supported: `m_isPressed` at adjusted `this+88`, `m_hoverItem` at adjusted `this+89`, parent/object-space equivalents `this+248` and `this+249`, `m_targetId` at `this+252`, and `m_targetName[33]` at `this+256`.
- `OnEvent` action dispatch is mapped far enough to document: Look opens a look/info object pane and removes the menu object lookup; Trade sends a 6-byte packet beginning with `0x4a`; Whisper opens a whisper dialog for the target name; Group sends a dot-prefixed name command packet; Info calls MapPane-owned `sub_50F4D0` / `MapPaneSendObjectAction43Packet`.
- The adjacent packet helpers at `0x00555780` and `0x005557e0` remain separate and have no direct xrefs; they must not be used as proof that UID0001FX directly calls those bodies.

## Supporting Research

Read current docs:

- `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`
- `by-class/RightButtonMenuPane.md`
- `by-file/RightButtonMenuPane.md`
- `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`
- `by-memory/0x00622f54-0x006230c8.RegionMenuPaneReadOnlyData.md`
- `by-memory/0x00622f64-0x00622ff4.RightButtonMenuPaneVtableData.md`
- `by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md`
- `by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md`
- `by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md`
- `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp`
- `by-structure.md`

Archived report search and relevant results:

- Search terms used included `0001FX`, `RightButtonMenuPaneCore`, `RightButtonMenuPane`, `0x00554b40`, `0x0055577b`, `0x00555780`, `RightButtonMenuPacketHelpers`, and `sub_50F4D0`.
- `executed-b-agent-research/B015/00023Q-RightButtonMenuPacketHelpers-source-quality.md` resolves the adjacent packet helper island as file-local helpers but keeps no-direct-xref negative evidence.
- `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md` identifies `sub_50F4D0` as MapPane-owned `MapPaneSendObjectAction43Packet`, called from UID0001FX at `0x00554ee3`.
- `executed-b-agent-research/B003/0002LR...votemenupane-source-quality.md` supports the VoteMenuPane relation for `0x005552a0` and `Pane::MarkForDeletion`/`sub_544690`.

Live IDA MCP evidence was refreshed after MCP restore using session `1fc4a5a7` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Target

- UID: `0001FX`
- Target path: `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`
- Current subject: `RightButtonMenuPane` constructor/destructor/event/cancel/paint/background/border/row-rect/hit-test cluster.
- Current owner route: `CANONICAL_OWNER:0000C0`, `EMITTER_UIDS:0000C0`.
- Current source root: [UID:0000N7] `by-file/RightButtonMenuPane.md`, `NexusTK/ui/menu/RightButtonMenuPane.cpp`.

## Current Target State

Historical pre-callback metadata was `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000C0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C0`, blank formal C++. The pre-callback item summary described a right-click context menu core and recorded final-C++ blockers, but the covered-range table still held eleven functions in one by-memory item instead of exact child pages. Generated `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp` contained UID00023Q packet-helper code, while UID0001FX/UID0000C0 markers were empty.

Current implemented state after the split and Gate 2 source-emitter repair: UID0001FX is `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. Exact child pages `0004F7` through `0004FI` exist. Code-ready children `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` emit first-draft formal C++; constructor/destructor/OnEvent/OnPaint/background/border children use blank emitters with child-specific no-code proof; the jump-table child remains generated data.

The current target text says the adjacent packet helpers are no longer a passive blocker, but still lists row action names, field names, and exact `OnEvent` dispatch calls as blockers. This report resolves those blockers enough to drive a split and support-doc sync, but the correct source-quality action is not to paste all child methods into the parent page.

## Heuristic / Inference Reanalysis And Validation

The prior blocker state was too broad. The live MCP pass shows the row/action and field model is substantially recoverable:

- The menu is definitely five rows. `sub_5556F0` iterates item indices `0..4`; item `>=5` returns `-1`.
- `sub_5556A0` computes row rects from fixed geometry: left `0`, top `16 * index + 22`, right `79`, bottom `16 * index + 38`; index `-1` maps to all `-1`.
- `OnPaint` draws the target name centered at y `21`, then draws labels at y `37`, `53`, `69`, `85`, and `117`. It double-draws each label at x `center - 24` and `center - 23` for shadow/bold effect.
- The row labels are exactly Look, Trade, Whisper, Group, Info. The string at `0x0061537c` decodes as UTF-16LE `Whisper`, followed by `Group`; the command-string child at `0x00623084` only covers Look/Trade/Info because Whisper/Group come from another string cluster.
- Adjusted event-handler state writes show `this+88`/`this+89` in the secondary-base view and parent-object offsets `this+248`/`this+249` in paint/constructor. The source-facing fields should be documented as pressed/selected state and hover row, not left as anonymous bytes.
- `sub_5552C0` proves target metadata layout: 32-bit target id at `this+252` and `wcscpy_s((wchar_t *)(this+256), 0x21, Source)`, so the buffer is 33 wide characters.
- `OnEvent` row dispatch uses a second five-way switch after release. The mapping is behavior-backed: case 0 constructs a look pane and clears an object lookup; case 1 builds a 6-byte packet with first byte `0x4a`; case 2 constructs a `0x208`-byte whisper/dialog object with target name; case 3 converts target name to CP_ACP and sends a dot-prefixed packet; case 4 calls MapPane's object action helper at `0x0050f4d0`.

The remaining reason not to add C++ to UID0001FX is structural, not ignorance: the current page is an aggregate containing many separate source functions. Split children are required before formal method C++ can be emitted at correct by-memory granularity.

## Evidence Standards Used

- IDA MCP was treated as authoritative for function boundaries, xrefs, decompilation, disassembly windows, bytes, and session identity.
- Existing by-* docs and executed reports were treated as leads unless confirmed by the current MCP pass or stable UID support docs.
- Generated C++ was treated as lead material only; it currently omits UID0001FX source and still contains historical wrong-owner artifacts.
- `by-structure.md` was used for the C++ disposition: aggregate by-memory pages must not contain C++ for child functions outside the page's own source representation.
- Inference labels in this report separate direct facts from source-facing naming recommendations.

## Evidence Checked

MCP availability/current session:

- JSON-RPC `initialize`, id `1`: success, protocol `2025-06-18`.
- `tools/list`, id `2`: success, 65 tools; relevant schemas included `server_health`, `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `get_bytes`, `xrefs_to`, `find_regex`, `search_text`, `idb_list`.
- `idb_list`, id `3`: active session `1fc4a5a7`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker_pid `12060`.
- `server_health`, id `4`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis/Hex-Rays/string cache ready.

MCP function/helper evidence:

- `decompile(0x005552a0)`, id `5`: if `unk_69BA38` exists, calls `sub_544690(unk_69BA38)`, then calls `sub_544690(this)`.
- `decompile(0x005552c0)`, id `6`: writes `*(DWORD *)(this+252)=targetId`, then `wcscpy_s((wchar_t *)(this+256), 0x21, Source)`.
- `decompile(0x005556a0)`, id `7`: row rectangle helper as `(-1,-1,-1,-1)` for `-1`, else `(0, 16*i+22, 79, 16*i+38)`.
- `decompile(0x005556f0)`, id `8`: hit-test loops five rows, calls `sub_4B7C50`/`sub_4B7E80`, returns row index or `-1`.
- `decompile(0x00554b40)`, id `9`: constructor calls `sub_544460(this,1)`, stores singleton `unk_69B4F0`, initializes bytes `this+248=0`, `this+249=-1`, installs three `RightButtonMenuPane` vtables at offsets `0`, `160`, `164`.
- `decompile(0x00554ba0)`, id `10`: destructor restores vtables, clears `dword_67A764+260` object through `sub_53B1B0`, calls pane teardown helpers, clears `unk_69B4F0`.
- `decompile(0x00554f90)`, id `11`: cancel/adjustor handler closes `g_pVoteMenuPane` if present and calls `sub_544690(this-160)`.
- `decompile(0x005552f0)`, id `12`: background slot loads resource via `dword_67A744`, `off_610B74`, tile index `8`, sets byte `this+112=1`, shrinks bounds by one pixel, draws using `off_610B8C`.
- `analyze_function(0x00555370)`, id `13`: border slot draws SUBWIN border from tile indices `0..7`, using 7x7 rects and repeated horizontal/vertical loops.
- `analyze_function(0x00554fc0)`, id `14`: paint routine calls vtable slots at `+72` and `+76`, draws target name, labels Look/Trade/Whisper/Group/Info, and selected row outline depending on byte `this+248`.
- `search_text("Whisper", 0x00620000-0x00624000)`, id `16`: no hit in that rdata window, rejecting the assumption that all labels live in `0x00623084`.
- `disasm(0x00554fc0, offset 100)`, id `18`: label operands show Look at `0x00623084`, Trade at `0x00623090`, Whisper via `aWh` at `0x0061537c`, Group at `0x0061538c`.
- `get_bytes(0x0061537c, 48)`, id `20`: decodes `Whisper\0Group\0Clan...` in UTF-16LE.
- `analyze_function(0x00554c40)`, id `21`: event handler has event-type switch cases 0, 1, 3, 4 and a five-way action switch after mouse release.
- `disasm(0x00554c40, offset 80)`, id `23`: action cases 0/1/2/3 setup; row 1 builds `0x4a` packet; row 2 constructs object with target name.
- `disasm(0x00554c40, offset 135)`, id `22`: row 3 CP_ACP/dot-prefixed name packet; row 4 calls `sub_50F4D0` at `0x00554ee3`; event case 4 outside-hit path uses `sub_4B7E80` and dismisses on miss.
- `lookup_funcs`, id `24`: confirms exact function starts/sizes for eleven UID0001FX functions; `0x00555780` and `0x005557e0` are not IDA functions; `0x0050f4d0` is a separate 0x5a-byte function.
- `get_bytes`, id `25`: confirms `0xCC` padding around most child functions and identifies `0x00554f59-0x00554f83` as event jump-table data, not padding.
- `xrefs_to`, id `26`: confirms no xrefs to `0x00555780`/`0x005557e0`; `0x0050f4d0` is called from `0x00554ee3`; helper xrefs match UID0001FX internals and known external menu callers.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0001FX should become a reviewed non-emitting aggregate/container only after exact child pages exist. | `lookup_funcs` id `24`; by-structure aggregate C++ rule; function inventory. | Target page metadata/status. | incorporate | applied: child pages [UID:0004F7] through [UID:0004FI] created and parent set `90/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++. |
| Direct semantic owner remains [UID:0000C0] `RightButtonMenuPane`; source root remains [UID:0000N7]. | Constructor/vtable/singleton evidence id `9`; class/file support docs. | Target/class/file docs. | incorporate | applied: parent and reconstructable child pages use `CANONICAL_OWNER:0000C0`; code-ready children `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` route through `EMITTER_UIDS:0000C0`; no-code children intentionally blank `EMITTER_UIDS`; class/file docs updated. |
| `0x00554f59-0x00554f83` is event jump-table data, not padding, and must be documented or split as child support data. | `get_bytes` id `25`; event switch comments id `21`. | Target range/split section and proposed child inventory. | incorporate | applied: new [UID:0004FA] jump-table child created as non-emitting source-declared/generated-binary data and parent padding map distinguishes `0x00554f83-0x00554f90` alignment. |
| Five labels are Look, Trade, Whisper, Group, Info; Whisper/Group are not in UID0003CZ command-string child. | Paint analysis id `14`, disasm id `18`, bytes id `20`, search miss id `16`. | Target behavior/evidence and class method notes. | incorporate | applied: parent, [UID:0004FC] OnPaint child, class page, and [UID:0003CZ] command-string support document the five-label split and Whisper/Group pooled literal addresses. |
| Field offsets support pressed/hover state and target metadata names. | Constructor id `9`, paint id `14`, event id `21`, setter id `6`. | Target field/helper table and child docs. | incorporate | applied: parent field/helper table and child pages record full/adjusted offsets for pressed, hover, target id, and target name buffer. |
| Adjacent packet helpers remain separate; no direct xrefs to `0x00555780`/`0x005557e0`. | `lookup_funcs` id `24`; `xrefs_to` id `26`; B015 report. | Target negative evidence and support docs. | incorporate | applied: parent negative evidence, [UID:0004F9] OnEvent child, and [UID:00023Q] packet-helper support preserve no-direct-xref caveat. |
| Info action calls MapPane-owned `sub_50F4D0`, not a RightButtonMenuPane-owned packet helper. | `disasm` id `22`; `xrefs_to` id `26`; B001 report. | Target action table and rejected owner alternatives. | incorporate | applied: parent and [UID:0004F9] row/action mapping record Info as MapPane-owned helper consumption and reject local ownership. |
| Current parent should not receive formal C++; exact child pages can receive code or no-code proof as their own ranges. | by-structure C++ rule; aggregate inventory; Gate 2 source-emitter repair. | First-draft C++ recommendation. | incorporate | applied: UID0001FX C++ remains blank and non-emitting; formal C++ was inserted into `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI`; `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` have blank emitters plus target-specific no-code proof; `0004FA` remains generated data. |
| Empty emitting child pages are not acceptable over the code-entry gate. | Gate 2 repair finding; workflow eligible-emitter rule. | Child pages, report ledger/checklist, validators. | incorporate | applied: no child page now has `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS`, over-gate scores, and a blank formal C++ block without proof; code-ready children emit code and not-ready children blank emitters with proof. |

## Positive Evidence Summary

- Constructor/destructor evidence directly ties this range to `RightButtonMenuPane`: three vtable writes to `RightButtonMenuPane` vtables, singleton publish/clear through `0x0069b4f0`, and class teardown helpers.
- Vtable references point to the target functions: `OnPaint` at vtable data `0x00622fac`, border slot at `0x00622fb4`, and event slot at `0x00622fc0`.
- The event/paint/hit-test helpers share the same five-row geometry and state fields. Paint uses byte `this+249` for selected/hover row and byte `this+248` for alternate outline color; event uses adjusted offsets `this+89` and `this+88`, matching the secondary-base offset by `0xa0`.
- The setter `0x005552c0` and paint routine agree on target-name storage at `this+256`; event row actions read target id/name from `this+92`/`this+96` in the adjusted view, matching `this+252`/`this+256` in the full object view.
- External callers support class role without changing ownership: `0x005552c0` is called by compact display/menu-open code at `0x00507707`; `0x005552a0` is called by VoteMenuPane mouse handling at `0x00555a3d` as shared dismissal behavior.

## Negative Evidence Summary

- No direct xrefs target adjacent raw packet helpers `0x00555780` or `0x005557e0`; they are not IDA functions in session `1fc4a5a7`. Do not claim UID0001FX directly calls them.
- `0x00554f59-0x00554f83` is not compiler padding; it contains jump-table entries for the event switch and action switch. Treating the whole gap as padding would drop live switch metadata.
- The generated `BulletinSession::HitTestMenuItem` owner remains contradicted by xrefs: `0x005556f0` is called only from `RightButtonMenuPane::OnEvent` at `0x00554c95` and `0x00554d27`.
- `g_pVoteMenuPane` checks do not make `VoteMenuPane` the owner of UID0001FX. They are consumer/coordination checks in right-click menu cancel/dismiss paths.
- `sub_50F4D0` is not owned by this target. It is a MapPane helper with calls from MapPane and RightButtonMenuPane; UID0001FX is one consumer at `0x00554ee3`.
- The command-string child at `0x00623084` is not a complete five-label owner; Whisper/Group are separate pooled literals at `0x0061537c` and `0x0061538c`.

## Ranked Ownership Analysis

1. [UID:0000C0] `RightButtonMenuPane` class: strongest and recommended. Constructor/destructor/vtable/singleton evidence, method map, row geometry, target metadata, and support docs all point here.
2. [UID:0000N7] `RightButtonMenuPane.cpp` file: correct source root/emitter chain, but not the direct canonical owner for class methods. Use as final file root through the class.
3. Proposed exact child by-memory pages under UID0001FX: required for emission granularity. These children should carry reconstructable method/helper ownership after creation.
4. [UID:00023Q] adjacent packet-helper island: same source file and class/file locality, but separate range and no direct xrefs. It supports row action interpretation but should not absorb UID0001FX.
5. [UID:0000P6]/[UID:0000FX] `VoteMenuPane`: rejected as direct owner. It calls a right-click dismissal helper and shares popup state, but UID0001FX constructor/vtable/paint/event state is RightButtonMenuPane.
6. MapPane / `sub_50F4D0`: rejected as direct owner. It owns the Info action helper consumed by row 4 only.
7. BulletinSession: rejected. The current generated hit-test owner is stale/generated pollution; live xrefs point back only to UID0001FX.

## Source Placement

Source placement remains `NexusTK/ui/menu/RightButtonMenuPane.cpp` through [UID:0000N7], with direct class owner [UID:0000C0]. The child method names should use ordinary class methods for constructor/destructor/event/cancel/paint/background/border and file-local or private static helpers for row rectangle/hit-test only if local style requires it. The packet island [UID:00023Q] stays adjacent/file-local in the same source file, but its no-xref caveat must remain.

## Range / Split / Padding / Reclassification Analysis

Recommended split plan:

| Proposed child range | Proposed subject | Reconstructable | Notes |
| --- | --- | --- | --- |
| `0x00554b40-0x00554b96` | `RightButtonMenuPane::RightButtonMenuPane()` | TRUE | Constructor; vtables/singleton/state init. |
| `0x00554b96-0x00554ba0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x00554ba0-0x00554c33` | `RightButtonMenuPane::~RightButtonMenuPane()` | TRUE | Destructor/teardown. |
| `0x00554c33-0x00554c40` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x00554c40-0x00554f59` | `RightButtonMenuPane::OnEvent(...)` | TRUE | Event/action handler. |
| `0x00554f59-0x00554f83` | `RightButtonMenuPane` event jump tables | TRUE or source-declared/generated-binary child | Live jump table data; bytes include event/action switch targets. |
| `0x00554f83-0x00554f90` | alignment | FALSE/ignored | trailing `0xCC` after jump tables. |
| `0x00554f90-0x00554fb3` | `RightButtonMenuPane::OnCancel(...)` | TRUE | Adjusted cancel handler. |
| `0x00554fb3-0x00554fc0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x00554fc0-0x00555298` | `RightButtonMenuPane::OnPaint()` | TRUE | Paint labels and selected-row outline. |
| `0x00555298-0x005552a0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x005552a0-0x005552ba` | `RightButtonMenuPane::CloseRightClickAndVoteMenus()` | TRUE | Tiny dismissal helper. |
| `0x005552ba-0x005552c0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x005552c0-0x005552e4` | `RightButtonMenuPane::SetTargetNameAndId(int, const wchar_t *)` | TRUE | Target id/name setter. |
| `0x005552e4-0x005552f0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x005552f0-0x00555361` | `RightButtonMenuPane::DrawSubwinBackground()` | TRUE | Background fill slot. |
| `0x00555361-0x00555370` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x00555370-0x00555692` | `RightButtonMenuPane::DrawSubwinBorder()` | TRUE | Border tiling slot. |
| `0x00555692-0x005556a0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x005556a0-0x005556ed` | `RightButtonMenuPane::GetMenuItemRect(int, RECT *)` | TRUE | Fixed row geometry. |
| `0x005556ed-0x005556f0` | alignment | FALSE/ignored | `0xCC` bytes. |
| `0x005556f0-0x0055577b` | `RightButtonMenuPane::HitTestMenuItem(int, int)` | TRUE | Five-row hit-test. |
| `0x0055577b-0x00555780` | trailing alignment | FALSE/ignored | `0xCC` bytes before UID00023Q. |

The existing parent UID0001FX range should remain as a documentation container for the above split and link to children once created.

## Function / Child Inventory

Live `lookup_funcs` under MCP session `1fc4a5a7`:

| Address | IDA name | Size | Current role |
| --- | --- | --- | --- |
| `0x00554b40` | `sub_554B40` | `0x56` | Constructor. |
| `0x00554ba0` | `sub_554BA0` | `0x93` | Destructor. |
| `0x00554c40` | `sub_554C40` | `0x319` | Event/action handler. |
| `0x00554f90` | `sub_554F90` | `0x23` | Cancel/adjusted handler. |
| `0x00554fc0` | `sub_554FC0` | `0x2d8` | Paint routine. |
| `0x005552a0` | `sub_5552A0` | `0x1a` | Cross-menu dismissal helper. |
| `0x005552c0` | `sub_5552C0` | `0x24` | Target id/name setter. |
| `0x005552f0` | `sub_5552F0` | `0x71` | SUBWIN background. |
| `0x00555370` | `sub_555370` | `0x322` | SUBWIN border. |
| `0x005556a0` | `sub_5556A0` | `0x4d` | Menu item rect. |
| `0x005556f0` | `sub_5556F0` | `0x8b` | Menu item hit-test. |

Adjacent/non-child checks:

- `0x00555780` and `0x005557e0` are not functions in IDA and have no direct xrefs.
- `0x005558d0` starts the neighboring VoteMenuPane region, not UID0001FX.
- `0x0050f4d0` is a separate MapPane helper called by row 4/Info.

## First-Draft C++ Recommendation

Do not add formal C++ to UID0001FX as it currently exists. The page is an aggregate over multiple method/helper bodies and jump-table data; adding all method code to the parent would violate by-structure's by-memory C++ scope rule and would make generated output harder to verify.

After split creation and Gate 2 source-emitter repair, child-specific C++ disposition is:

- Formal C++ inserted: `0004FB` `RightButtonMenuPane::OnCancel()`, `0004FD` `RightButtonMenuPane::CloseRightClickAndVoteMenus()`, `0004FE` `RightButtonMenuPane::SetTargetNameAndId(int, const wchar_t *)`, `0004FH` `RightButtonMenuPane::GetMenuItemRect(int, RECT *)`, and `0004FI` `RightButtonMenuPane::HitTestMenuItem(int, int)`.
- No-code with blank emitters: `0004F7` constructor waits on synchronized base constructor/member declaration shape; `0004F8` destructor waits on teardown helper/client-slot names; `0004F9` `OnEvent` waits on event enum/UI helper/action wrapper names; `0004FC` `OnPaint` waits on drawing surface/text/font/resource helper names; `0004FF` background and `0004FG` border wait on SUBWIN resource/draw primitive helper names.
- Generated data: `0004FA` remains non-reconstructable/non-emitting because it is compiler-generated switch/jump-table data tied to `OnEvent`.

Any later expansion of constructor/destructor/OnEvent/OnPaint/background/border C++ should be inserted only into those exact child formal `RECONSTRUCTION_CPP CODE` blocks after the unresolved API/member names are synchronized. UID0001FX itself should never receive aggregate method C++.

## Recommended Target Doc Changes

For `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`:

- After child pages are created, set `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000C0`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and keep formal C++ blank.
- Rewrite status to identify the page as a reviewed non-emitting container/index over exact `RightButtonMenuPane` child methods and jump-table data.
- Add the split table from this report, including internal `0x00554f59-0x00554f83` jump-table data and `0x00554f83-0x00554f90` trailing padding.
- Add the field/helper table:
  - `this+248` / adjusted `this+88`: pressed/active-click state.
  - `this+249` / adjusted `this+89`: hover/selected row, initialized to `-1`.
  - `this+252` / adjusted `this+92`: target id.
  - `this+256` / adjusted `this+96`: `wchar_t targetName[33]`.
  - `sub_4B7C50`: rect initializer.
  - `sub_4B7E80`: point-in-rect test.
  - `sub_544690`: pane close/mark-for-deletion.
  - `sub_50F4D0`: MapPane-owned object action helper, not a local helper.
- Replace generic final-C++ blocker wording with the structural no-code proof and child split plan.
- Add row/action evidence table:
  - 0 Look: opens look/object pane, queries/removes target object through `dword_67A764`.
  - 1 Trade: sends 6-byte packet beginning with `0x4a` and target id payload.
  - 2 Whisper: constructs `0x208`-byte whisper/dialog object from target name.
  - 3 Group/name command: CP_ACP converts target name and sends dot-prefixed name command.
  - 4 Info: calls MapPane-owned `sub_50F4D0` with target id.
- Preserve negative evidence: no xrefs to `0x00555780`/`0x005557e0`, generated BulletinSession hit-test owner is rejected, VoteMenuPane and MapPane are consumers/adjacent owners only.

If supervisor chooses not to split during callback, make only text/evidence updates and leave metadata at `85/88`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C0`, blank C++.

## Recommended Support Doc Changes

For `by-class/RightButtonMenuPane.md`:

- Update UID0001FX method-map row from a monolithic core row to a split-ready container plus exact child method list once child UIDs exist.
- Add the field offset table and row/action table.
- Update evidence notes to say B005 MCP session `1fc4a5a7` resolved row labels, target field layout, event row mapping, and the structural no-code reason.
- Keep [UID:00023Q] packet helper island separate and preserve no-direct-xref caveat.

For `by-file/RightButtonMenuPane.md`:

- Update proposed contents so UID0001FX is a non-emitting split container after child creation. Code-ready children `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` emit through [UID:0000C0]; child pages `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` remain blank-emitter no-code children pending class/API name synchronization.
- Add `0x00554f59-0x00554f83` as event jump-table data tied to UID0001FX's split.
- Preserve source root `NexusTK/ui/menu/RightButtonMenuPane.cpp`.

For `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`:

- Optional support sync only if stale: add that B005 confirmed no direct xrefs from current session `1fc4a5a7`; row 1 and row 3 behavior in `OnEvent` match packet shapes, but direct helper calls remain unproven.

For `by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md`:

- Optional support sync if stale: clarify that this child owns Look/Trade/Info only; Whisper/Group literals are at `0x0061537c` and `0x0061538c`.

For vtable/read-only data docs:

- Optional text-only slot sync if stale: record that `0x00554fc0`, `0x00555370`, and `0x00554c40` are confirmed live slots under MCP session `1fc4a5a7`; no metadata change required.

Do not edit generated files or any manual/generated `-coverage-report.md` file during callback.

## Score And Metadata Recommendation

Primary accepted path after split creation:

- UID0001FX before: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000C0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C0`, blank C++.
- UID0001FX after split: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000C0`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Child metadata after Gate 2 source-emitter repair:
  - `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI`: keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000C0`, and carry nonblank formal C++.
  - `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG`: keep `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, keep formal C++ blank, and include child-specific no-code proof.
  - `0004FA`: keep `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and explicit generated switch-data proof.

Rationale: documentation confidence improves because current MCP resolved the named blockers and exposed the jump-table/padding structure. Reconstructable becomes `FALSE` only for the parent container because its exact children carry the real source methods. This is not a downgrade of the underlying code; it is a source-shape repair.

Fallback if no split is approved: keep current metadata and C++ blank, but incorporate the resolved evidence. Do not raise the target above `85/88` while it remains a reconstructable aggregate emitter with no child pages.

## Open Questions With Attempted Resolution

- Exact original field names: no PDB/source symbol proof exists, but behavior supports source-quality names. Use documented inferred names such as `m_isPressed`, `m_hoverItem`, `m_targetId`, and `m_targetName`; mark as inferred.
- Exact UI helper names for `sub_4B9600`, `sub_4B9660`, `sub_4B9680`, `sub_4B98F0`, `sub_4BAB70`, `sub_4BA6B0`, and tile/resource helpers remain broader UI-library naming work. This is resolved for this callback by blanking emitters and adding no-code proof to `0004FC`, `0004FF`, and `0004FG`; it no longer leaves an empty emitting page.
- Exact event type enum names remain inferred from behavior: case 0 hover/move, case 1 press/down, case 3 release/action, case 4 outside/cancel or hit-test cancellation. The switch behavior is documented enough for `OnEvent` child notes, and the remaining C++ blocker is resolved for this callback by blanking `0004F9`'s emitter and adding no-code proof.
- Constructor/destructor declaration-level shape remains unresolved: base constructor call, initializer ordering, teardown helper names, and client object slot names need synchronization before formal constructor/destructor C++. This is resolved for this callback by blanking `0004F7`/`0004F8` emitters and adding child-specific no-code proof.
- Whether rows 1 and 3 call UID00023Q directly remains unresolved by negative evidence: current session finds no xrefs to `0x00555780` or `0x005557e0`. The safe wording is behavior matches packet shapes, direct helper calls unproven.
- Exact child UIDs are supervisor/validator-owned because new by-memory pages do not exist yet. Use `[TMP:"..."]` or validator UID assignment in implementation; do not invent UIDs in this report.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report edit is requested from B005. If the supervisor needs tracker text before validator refresh, use this exact note:

`UID0001FX B005 Gate 1 recommendation: split current RightButtonMenuPaneCore aggregate into exact method/helper/jump-table children; convert UID0001FX to non-emitting reviewed container after child creation; direct owner remains UID0000C0; no aggregate C++. MCP session 1fc4a5a7 resolved row labels, field offsets, action mapping, packet-helper negative xrefs, and jump-table/padding boundaries.`

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`.

All final scoped file validators exited `0` with `scanned markdown files: 1`, warning count `0`, and error count `0`.

| File | command_id | command_timestamp | Exit | Notes |
| --- | --- | --- | ---: | --- |
| `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md` | `000000005118` | `2026-07-03T07:26:24-04:00` | `0` | clean |
| `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md` | `000000005119` | `2026-07-03T07:26:26-04:00` | `0` | clean |
| `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | `000000005120` | `2026-07-03T07:26:27-04:00` | `0` | clean |
| `by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md` | `000000005121` | `2026-07-03T07:26:29-04:00` | `0` | clean |
| `by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md` | `000000005122` | `2026-07-03T07:26:31-04:00` | `0` | clean |
| `by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md` | `000000005123` | `2026-07-03T07:26:33-04:00` | `0` | clean |
| `by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md` | `000000005124` | `2026-07-03T07:26:35-04:00` | `0` | clean |
| `by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md` | `000000005125` | `2026-07-03T07:26:37-04:00` | `0` | clean |
| `by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | `000000005126` | `2026-07-03T07:26:38-04:00` | `0` | clean |
| `by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | `000000005127` | `2026-07-03T07:26:40-04:00` | `0` | clean |
| `by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md` | `000000005128` | `2026-07-03T07:26:42-04:00` | `0` | clean |
| `by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md` | `000000005129` | `2026-07-03T07:26:44-04:00` | `0` | clean |
| `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md` | `000000005136` | `2026-07-03T07:27:10-04:00` | `0` | clean after rerun |
| `by-class/RightButtonMenuPane.md` | `000000005131` | `2026-07-03T07:26:48-04:00` | `0` | clean |
| `by-file/RightButtonMenuPane.md` | `000000005132` | `2026-07-03T07:26:50-04:00` | `0` | clean |
| `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md` | `000000005133` | `2026-07-03T07:26:52-04:00` | `0` | clean |
| `by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md` | `000000005134` | `2026-07-03T07:26:54-04:00` | `0` | clean |
| `by-memory/0x00622f64-0x00622ff4.RightButtonMenuPaneVtableData.md` | `000000005135` | `2026-07-03T07:26:55-04:00` | `0` | clean |

Intermediate note: parent validator command `000000005130` initially reported `missing_ref_uid 0003CZ` because the support command-string file had not yet been scanned in this batch; after validating [UID:0003CZ], parent rerun `000000005136` cleared the diagnostic.

Generated freshness: all file validators reported `generated_refresh: deferred` with matching generated refresh command IDs. `python .\tools\validator.py --queue-status` returned command `000000005137` at `2026-07-03T07:27:23-04:00`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 16`, and `processing generated refresh jobs: 1`. A later queue check, command `000000005139` at `2026-07-03T07:28:48-04:00`, still had no foreground jobs pending and showed deferred generated refresh progress at `queued generated refresh jobs: 6`, `processing generated refresh jobs: 1`.

Gate 2 focused repair on 2026-07-03: added concise target-specific `Item Summary` metadata to each new child page [UID:0004F7] through [UID:0004FI]. Scoped validators were rerun from `source-3/project-documentation`; each exited `0`, scanned one markdown file, and reported warning count `0` and error count `0`.

| Repair file / UID | command_id | command_timestamp | Exit | Warnings | Errors | Generated refresh |
| --- | --- | --- | ---: | ---: | ---: | --- |
| [UID:0004F7] `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md` | `000000005163` | `2026-07-03T07:31:42-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004F8] `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md` | `000000005165` | `2026-07-03T07:31:44-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004F9] `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | `000000005167` | `2026-07-03T07:31:46-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FA] `by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md` | `000000005168` | `2026-07-03T07:31:49-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FB] `by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md` | `000000005169` | `2026-07-03T07:31:59-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FC] `by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md` | `000000005171` | `2026-07-03T07:32:09-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FD] `by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md` | `000000005172` | `2026-07-03T07:32:18-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FE] `by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md` | `000000005173` | `2026-07-03T07:32:27-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FF] `by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | `000000005174` | `2026-07-03T07:32:37-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FG] `by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | `000000005175` | `2026-07-03T07:32:46-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FH] `by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md` | `000000005176` | `2026-07-03T07:32:56-04:00` | `0` | `0` | `0` | deferred |
| [UID:0004FI] `by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md` | `000000005177` | `2026-07-03T07:33:05-04:00` | `0` | `0` | `0` | deferred |

Gate 2 repair generated freshness: all repair validators reported `generated_refresh: deferred`. Queue check `000000005179` at `2026-07-03T07:33:39-04:00` reported `queued jobs: 0`, `processing jobs: 0`, and generated refresh `23 queued / 1 processing` (`queued generated refresh jobs: 23`, `processing generated refresh jobs: 1`).

Gate 2 source-emitter repair on 2026-07-03: formal C++ was added to code-ready children `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI`; blank emitters plus no-code proof were added to `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG`; `0004FA` was kept non-emitting generated switch data with explicit proof. Parent/file support notes were synchronized. Scoped validators were rerun from `source-3/project-documentation`; each exited `0`, scanned one markdown file, and reported no warnings/errors in output.

| Source-emitter repair file / UID | command_id | command_timestamp | Exit | OK | Warnings | Errors | Generated refresh |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- |
| [UID:0004F7] `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md` | `000000005209` | `2026-07-03T07:53:53-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004F8] `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md` | `000000005210` | `2026-07-03T07:53:55-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004F9] `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | `000000005211` | `2026-07-03T07:53:57-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FA] `by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md` | `000000005212` | `2026-07-03T07:53:59-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FB] `by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md` | `000000005213` | `2026-07-03T07:54:01-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FC] `by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md` | `000000005214` | `2026-07-03T07:54:11-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FD] `by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md` | `000000005215` | `2026-07-03T07:54:13-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FE] `by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md` | `000000005216` | `2026-07-03T07:54:15-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FF] `by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md` | `000000005217` | `2026-07-03T07:54:17-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FG] `by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md` | `000000005218` | `2026-07-03T07:54:19-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FH] `by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md` | `000000005219` | `2026-07-03T07:54:21-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0004FI] `by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md` | `000000005220` | `2026-07-03T07:54:23-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0001FX] `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md` | `000000005221` | `2026-07-03T07:54:25-04:00` | `0` | `1` | `0` | `0` | deferred |
| [UID:0000N7] `by-file/RightButtonMenuPane.md` | `000000005222` | `2026-07-03T07:54:27-04:00` | `0` | `1` | `0` | `0` | deferred |

Latest source-emitter repair generated freshness: all validators reported `generated_refresh: deferred` with matching generated refresh command IDs `000000005209` through `000000005222`. No additional queue-status command was run during this repair; the validator output shows deferred generated refresh and normal validator-owned registry/stats side effects.

## Changed Files

- Created and validated child pages [UID:0004F7] through [UID:0004FI]:
  - `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md`
  - `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md`
  - `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`
  - `by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md`
  - `by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md`
  - `by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md`
  - `by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md`
  - `by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md`
  - `by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md`
  - `by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md`
  - `by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md`
  - `by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md`
- Updated parent target `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`.
- Updated support docs `by-class/RightButtonMenuPane.md`, `by-file/RightButtonMenuPane.md`, `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`, `by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md`, and `by-memory/0x00622f64-0x00622ff4.RightButtonMenuPaneVtableData.md`.
- Updated this report's Claim And Incorporation Ledger, Validator Results, Changed Files, and Implementation Tracking Checklist after callback implementation.
- Gate 2 focused repair: added concise `Item Summary` metadata values to all twelve child pages [UID:0004F7] through [UID:0004FI] and updated this report with the repair validator results.
- Gate 2 source-emitter repair: added first-draft formal C++ to child pages `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI`; blanked `EMITTER_UIDS` and added child-specific no-code proof to `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG`; strengthened `0004FA` generated-data no-code proof; synchronized parent `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md` and support file `by-file/RightButtonMenuPane.md`.
- No generated files, manual coverage reports, validator state, supervisor ledgers, lifecycle/archive state, or report execution state were edited during the Gate 2 `Item Summary` repair.
- No generated files, manual coverage reports, validator state, supervisor ledgers, lifecycle/archive state, or report execution state were edited manually during the Gate 2 source-emitter repair. Validator commands performed normal validator-owned registry/reference/projected-stats updates and deferred generated refresh.

Leases were taken for the parent/support docs and child validation batch, then released with `python leaser.py B005 unlease`; every listed lease release returned `Success`. For the Gate 2 `Item Summary` repair specifically, the twelve child files [UID:0004F7] through [UID:0004FI] were leased, edited, validated, and released; final lease-report check showed no active `B005` or `RightButtonMenuPane` leases. For the Gate 2 source-emitter repair, B005 leased the twelve child files plus `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md` and `by-file/RightButtonMenuPane.md`; the post-validator unlease command reported `Rejected[No active lease]` for each path, and `tools/leaser/Agents/current_leases.md` showed no active leases.

## Implementation Tracking Checklist

- [x] Create exact child by-memory pages for the UID0001FX split ranges listed in `Range / Split / Padding / Reclassification Analysis`; use validator/TMP UID workflow and do not invent UIDs. Applied: validator assigned [UID:0004F7] through [UID:0004FI].
- [x] Convert `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md` to the reviewed non-emitting container only after child pages exist: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000C0`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Applied in parent target.
- [x] Preserve child/source inventory, MCP session `1fc4a5a7`, exact function sizes, row label evidence, field offsets, helper names, row/action mapping, and negative packet-helper xref evidence in the target/container and children. Applied across parent and child pages.
- [x] Add or update the event jump-table data handling for `0x00554f59-0x00554f83`; do not misclassify the whole `0x00554f59-0x00554f90` gap as padding. Applied via [UID:0004FA] and parent padding map.
- [x] Update `by-class/RightButtonMenuPane.md` method map and evidence notes from monolithic UID0001FX blocker wording to split-ready/source-ready child rows, preserving packet-helper caveats and rejected owner alternatives. Applied.
- [x] Update `by-file/RightButtonMenuPane.md` proposed contents/source-output notes so UID0001FX is a non-emitting container and child methods emit through [UID:0000C0] to [UID:0000N7]. Applied.
- [x] Optionally sync `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md` with B005's current no-xref confirmation and row-action relationship, preserving no-direct-call caveat. Applied.
- [x] Optionally sync `by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md` to clarify it covers Look/Trade/Info only; Whisper/Group are at `0x0061537c`/`0x0061538c`. Applied.
- [x] Optionally sync vtable/read-only data docs with slot confirmations if stale; do not change metadata unless separately justified. Applied to `by-memory/0x00622f64-0x00622ff4.RightButtonMenuPaneVtableData.md` with no metadata change.
- [x] Keep formal C++ blank on UID0001FX; add formal C++ only to exact child pages after split and only for child ranges whose helper/source names are ready. Applied after Gate 2 source-emitter repair: UID0001FX is blank/non-emitting; `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` contain first-draft formal C++; `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` have blank emitters plus child-specific no-code proof; `0004FA` remains non-emitting generated switch data.
- [x] Run scoped validators from `source-3/project-documentation` for every edited by-* file: `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`. Applied; final commands `000000005118` through `000000005136` are listed in `Validator Results`.
- [x] Report validator command id, timestamp, exit code, ok count, warnings/errors, changed files, leases used/released, generated freshness observations, and checklist state during the implementation callback. Applied in this report and final callback response.
- [x] Gate 2 repair: add concise `Item Summary` metadata to child pages [UID:0004F7] through [UID:0004FI], validate the repaired child pages, release child-file leases, and report repair validator command IDs. Applied with clean validator commands `000000005163`, `000000005165`, `000000005167`, `000000005168`, `000000005169`, and `000000005171` through `000000005177`; each exited `0` with warnings `0`, errors `0`, generated refresh deferred. Queue check `000000005179` showed generated refresh `23 queued / 1 processing`. No generated/manual coverage/lifecycle state was edited, and final lease check showed no active `B005` or `RightButtonMenuPane` leases.
- [x] Gate 2 source-emitter repair: reopen child pages [UID:0004F7] through [UID:0004FI], ensure every eligible child has formal C++ or a target-specific no-code proof with metadata adjusted, keep jump-table child non-emitting, sync parent/file support notes, and validate every changed by-* file. Applied with clean validator commands `000000005209` through `000000005222`; each exited `0`, `ok:1`, warnings `0`, errors `0`, generated refresh deferred. No `execute_report`, lifecycle/archive command, generated edit, manual coverage edit, or supervisor-ledger edit was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000005224","destination_path":"executed-b-agent-research/B005/0001FX-RightButtonMenuPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001FX-RightButtonMenuPaneCore-source-quality.md","timestamp":"2026-07-03T08:04:50-04:00","uid":"0001FX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
