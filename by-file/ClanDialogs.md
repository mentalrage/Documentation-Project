*** UID:0000IA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ClanDialogs

## Current Status And File Role

- Current disposition (2026-08-14): non-standalone, non-emitting modal-family index. `ClanDialogs` is a useful documentation grouping, not a proven original translation unit and not an output target.
- Reconstruction path and owner are intentionally `NONE`. This page owns no formal CPP/H channel, emits no source, and must not generate `NexusTK/ui/dialogs/ClanDialogs.cpp` or `ClanDialogs.h`.
- All source-bearing classes, methods, constructors, vtable declarations, resources, and helper relationships remain under [UID:0000I8][Clan](by-file/Clan.md), with exact class and by-memory children emitting through `NexusTK/social/Clan.cpp` and `Clan.h`.
- [UID:0000I9][ClanBank](by-file/ClanBank.md) begins at the `ClanItemDialog` successor family after the modal range and remains excluded from this index.
- Confidence is `92/92`: the family inventory, ownership graph, retained code/data boundaries, layouts, event ABI, callback ABI, and source placement are resolved. The remaining uncertainty concerns the historical filename and exact original lexical spellings, not whether this page should emit.
- Reversal criterion: restore a standalone source route only if a direct historical artifact or a complete independent owner/emitter boundary proves that the modal family was compiled from a distinct translation unit. Similarity of class purpose alone is insufficient.

## Current Whole-Family Evidence

Fresh 2026-08-14 read-only IDA MCP evidence bounds the modal code/data family without relying on stale Wave2/Wave3 classifications:

- Eighteen modeled source functions occupy the retained modal implementation island: four `ClanNameInputDialog` methods at `0x00488b40`, `0x00488eb0`, `0x00488f30`, and `0x00488f70`; six name/money submitters at `0x00488fe0`, `0x004890b0`, `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510`; four `ClanAttrInputDialog` methods at `0x00489600`, `0x00489df0`, `0x00489ec0`, and `0x00489f50`; two derived `OnSubmit` methods at `0x00489fc0` and `0x0048a030`; and leave callbacks at `0x0048a0a0` and `0x0048a0b0`.
- Nine retained constructor bodies at `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, and `0x0048a060` are not current IDA function objects and have no inbound start xrefs or VA/RVA/raw-pointer routes. Those negative entry facts are confidence evidence, not no-code proof. Exact bounded disassembly shows complete out-of-line source constructors: one forwarded packet argument for the first eight, four forwarded AlertPane arguments for the ninth, a base-constructor call, three derived-vtable stores, return-this behavior, and `retn 4` or `retn 0x10` as appropriate. Each exact by-memory child therefore owns a formal constructor definition.
- The eleven modal primary vtable heads are contiguous from `0x006158f8` through `0x00615f38`, with secondary/tertiary groups through `0x00615fd8`. `ClanItemDialog` at `0x00615fdc` is the first excluded [UID:0000I9][ClanBank](by-file/ClanBank.md) successor.
- `DLGCLAN1.EPF` is the one-field shell with controls `1`, `2`, and `4` and no proven derived persistent fields. `DLGCLAN2.EPF` produces a `0x870` derived layout with three 256-wide-character arrays at `+0x26c`, `+0x46c`, and `+0x66c`, followed by the 16-bit submitted attribute value at `+0x86c`.
- The source event contract is mutable `Event *`, not `const InputEvent &`: no `InputEvent` UDT exists, current `Event` is `0x110` bytes, and both dialog handlers inspect `event->m_type == 3`, forward the same pointer through the `ClanStatusPane` secondary EventHandler route, and then call the base handler. The current source-facing method is `HandlePointerOrMouseEvent(Event *event)`.
- `ClanLeaveConfirmDialog::OnConfirm()` and `OnCancel()` are `void`. Each wrapper loads `g_pClanStatusPane`, passes response byte `1` or `0` to the decompiled void `SendClanLeaveResponse` helper, ignores no meaningful return value, and returns.
- Resource storage remains the exact UTF-16 `DLGCLAN1.EPF` and `DLGCLAN2.EPF` strings at `0x00616430-0x00616468`. Their modal consumers remain in Clan source ownership even though this index documents them together.
- Padding and compiler support remain explicit: alignment gaps separate the modeled functions and raw constructors, while destructor adjustors/scalar wrappers in the later destructor band are compiler-generated support and do not become handwritten modal methods.

## Current Source And Formal-Channel Disposition

- [UID:0000I8][Clan](by-file/Clan.md) remains the source-bearing file owner. Class declarations belong in their class-page `RECONSTRUCTION_H CODE`; method and constructor definitions belong in their exact by-memory `RECONSTRUCTION_CPP CODE` children.
- `ClanNameInputDialog`, `ClanAttrInputDialog`, and the secondary `ClanStatusPane` EventHandler route use `HandlePointerOrMouseEvent(Event *event)` consistently. This supersedes the historical `OnInputEvent(const InputEvent &)` / `ForwardInputEvent(const InputEvent &)` spellings.
- The six `ClanNameInputDialog`-derived retained constructor children emit packet-forwarding definitions; the two `ClanAttrInputDialog`-derived children emit packet-forwarding definitions; and the leave-confirm child emits its exact four-argument AlertPane-forwarding definition.
- The class pages for `ClanStatusPane`, `ClanAttrInputDialog`, `ClanEnlistInputDialog`, `ClanChangeInputDialog`, and `ClanLeaveConfirmDialog` place declarations in H and retain only `[[CHILDREN]]` in CPP. This index itself remains code-blank.
- Clan status parser/dispatcher/openers remain `ClanStatusPane`/Clan source. Clan bank/item dialogs remain ClanBank source. Their use or construction of modal dialogs does not transfer ownership to this index.

## Historical Status (Superseded 2026-08-14)

- Historical confidence snapshot: very strong for the modal-dialog function island, vtable anchors, layouts, packet submitters, and raw-constructor caveats; medium-high for the then-unresolved source split from [UID:0000I8][Clan](by-file/Clan.md). The 2026-08-14 resolution supersedes that uncertainty.
- Historical proposal (superseded): create `NexusTK/ui/dialogs/ClanDialogs.cpp` by splitting the modal family from [UID:0000I8][Clan](by-file/Clan.md). The accepted route is `NexusTK/social/Clan.cpp`; this page is not a validator path or fallback output target.
- Historical header proposal (superseded): create `NexusTK/ui/dialogs/ClanDialogs.h` or fold declarations into `NexusTK/social/Clan.h`. The accepted result is the latter: declarations emit through the owning class H channels into `Clan.h`.
- Evidence basis: live IDA MCP checks on 2026-06-04, 2026-06-14, and 2026-06-16, plus the existing layout/vtable memory docs, PE byte-scan reachability checks, and `by-project-structure/proposed-source-tree.md`.
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)

## Historical Split-Candidate File Role (Superseded 2026-08-14)

The following material is retained as the earlier split hypothesis and evidence trail. It is not the current owner/path recommendation.

Historical 2026-06 statement (superseded): `ClanDialogs.cpp` was proposed as a split-candidate home for clan modal dialogs and submitters: name/money/member input dialogs, attribute-change dialogs, enlist/change/leave confirmation flows, and their small opcode `0x4b` packet submitters.

Historical 2026-06 conclusion (superseded in wording, confirmed in ownership): [UID:0000I8][Clan](by-file/Clan.md) was already the stronger owner because the cluster shares clan status pane state, child list panes, resources, packet helpers, and destructor bands. The accepted 2026-08-14 result fixes that route and rejects this page as a migration target.

Historical 2026-06-20 B002 snapshot (superseded split proposal): [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) remained owned/emitted through [UID:0000I8][Clan](by-file/Clan.md), while this page was still being considered as a coordinated future `ClanDialogs.cpp` split. The accepted route keeps the class under Clan and discards the split proposal.

Historical 2026-06-20 B002/B009 snapshot (superseded split proposal): [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) remained routed through [UID:0000I8][Clan](by-file/Clan.md) and `social/Clan.cpp`, while a coordinated modal-family split was still under consideration. The accepted route keeps the full family in Clan; no migration remains pending.

2026-06-28 B006 [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md) implementation keeps the raw opcode `0x4b` subtype `6-10` helper strip out of this split candidate. The raw starts have no live route and only mirror row-action/list-pane/submitter behavior; the vtable-backed submitter children stay modal-dialog context, but the raw strip remains a [UID:0000I8][Clan](by-file/Clan.md) retained marker with no helper C++ and no one-off migration to `ClanDialogs.cpp`.

Do not route [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) or [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md) to this split candidate. B012's 2026-06-19 source-quality reanalysis confirms those two rows are `ClanStatusPane` packet handling in `social/Clan.cpp`: the parser writes status-pane fields/child state, and the dispatcher is the status-pane secondary-vtable opcode `0x43` handler. Dialog constructors and modal dialog classes are callees, not owners, for those two rows.

Do not route [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) to this split candidate either. B002's 2026-06-20 source-quality reanalysis confirms cases `1`, `2`, and `6` are live `ClanStatusPane` packet/view helpers, while the no-xref dialog opener siblings are retained `social/Clan.cpp` file-local helpers that construct modal dialogs. Modal dialog classes are callees for this opcode `0x43` island, not owners.

Do not fold the clan bank/item dialogs into this page by default. Those dialogs are larger and currently have a stronger split case in [UID:0000I9][ClanBank](by-file/ClanBank.md).

## Retained Modal Family Inventory

The table remains an exhaustive family inventory. All entities are fixed to UID0000I8 and their exact class/by-memory children; the former `ClanDialogs.cpp` split is retained only in the explicitly historical sections above.

| Entity | Range / anchors | Role |
| --- | --- | --- |
| `ClanNameInputDialog` | `0x00488b40-0x00488fa0`; vtables `0x006158f8`, `0x0061595c`, `0x0061598c` | Shared `DLGCLAN1.EPF` modal input shell for clan name/money/text flows. |
| `ClanDepMoneyInputDialog` | raw constructor [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md); submitter [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md); vtables `0x00615998`, `0x006159fc`, `0x00615a2c` | Deposit-money dialog variant. The active owner/emitter route is [UID:0000I8][Clan](by-file/Clan.md). The exact raw child emits the packet-forwarding constructor definition; lack of a VA/RVA/rel32 entry route remains confidence evidence only. Active inline construction stores occur at `0x00485120/26/30` and `0x00487de4/ea/f4`, and submit slot `0x006159f4 -> 0x00488fe0` is `OnSubmitText(const wchar_t *)`. |
| `ClanWidMoneyInputDialog` | raw constructor [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md); submitter [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md); vtables `0x00615a38`, `0x00615a9c`, `0x00615acc` | Withdraw-money dialog variant. |
| `ClanExpelNameInputDialog` | raw constructor [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md); submitter [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md); vtables `0x00615ad8`, `0x00615b3c`, `0x00615b6c` | Expel-member-by-name dialog variant under [UID:0000I8][Clan](by-file/Clan.md). The exact raw child emits `ClanExpelNameInputDialog(const unsigned char *packet)`, forwarding to `ClanNameInputDialog`; submit slot `0x00615b34 -> 0x00489180` emits `OnSubmitText(const wchar_t *)`. No modal-family migration remains pending. |
| `ClanSummonNameInputDialog` | raw constructor [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md); submitter [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md); vtables `0x00615b78`, `0x00615bdc`, `0x00615c0c` | Summon-member-by-name dialog variant under [UID:0000I8][Clan](by-file/Clan.md). The exact raw child emits the constructor definition; no-route evidence and inline stores at `0x0048522c/0x00485232/0x0048523c` and `0x00488294/0x0048829a/0x004882a4` remain confidence corroboration, not a no-code disposition. |
| `ClanAppearNameInputDialog` | raw constructor [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md); submitter [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md); vtables `0x00615c18`, `0x00615c7c`, `0x00615cac` | Appearance/name action dialog variant. |
| `ClanChangeNameInputDialog` | raw constructor [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md); submitter [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md); vtables `0x00615cb8`, `0x00615d1c`, `0x00615d4c` | Clan rename dialog variant under [UID:0000I8][Clan](by-file/Clan.md). The exact raw child emits the constructor definition; no-route evidence and inline stores at `0x00485337/0x0048533d/0x00485347` and `0x0048842e/0x00488434/0x0048843e` remain confidence corroboration, not ignored/dead/no-code evidence. |
| `ClanAttrInputDialog` | `0x00489600-0x00489f80`; vtables `0x00615d58`, `0x00615dbc`, `0x00615dec` | Shared `DLGCLAN2.EPF` multi-field attribute input shell. |
| `ClanEnlistInputDialog` | raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), submit override [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) / `OnSubmit()`; vtables `0x00615df8`, `0x00615e5c`, `0x00615e8c` | Enlistment attribute dialog under `social/Clan.cpp`. UID00021W emits the exact constructor definition and UID0002O3 emits the class-owned submit override. [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) subtype `6` action `1` constructs the dialog but remains `ClanStatusPane`/Clan packet-handler source. |
| `ClanChangeInputDialog` | raw constructor [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md); submitter [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md); vtables `0x00615e98`, `0x00615efc`, `0x00615f2c` | Clan attribute-change submit path through helper `0x00486330`. |
| `ClanLeaveConfirmDialog` | raw constructor [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md); callbacks [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) and [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md); vtables `0x00615f38`, `0x00615fa0`, `0x00615fd0` | Alert-derived leave confirmation dialog. |

## Boundary Notes

- Current correction: the nine raw starts below are explicit out-of-line constructor definitions and emit through their exact by-memory children. Their no-function/no-xref/no-pointer state remains an entry-route caveat and IDA protection, not a no-code classification.

- IDA reports no function at the projected constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, or `0x0048a060`; the bytes are still constructor-shaped raw ranges and should not be discarded.
- 2026-06-16 A001 live IDA/PE recheck reconfirmed the same nine projected constructor starts are not IDA functions and have zero IDA xrefs. A section-mapped PE scan also found zero loaded VA pointers, zero RVA literals, and zero direct `E8`/`E9`/`0F 8x` branch encodings to any of those starts.
- 2026-06-14 C001 IDA MCP xrefs recheck reports zero exact xrefs to those projected constructor starts, while vtable-head refs still land in the named raw/open sites and modeled core constructors.
- The vtable records above are stronger class identity anchors than the projected constructor starts.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits for those projected constructor starts. The bytes are still constructor-shaped and contain base-constructor calls plus derived vtable stores, so they should be modeled as unresolved constructor-boundary bytes rather than thrown away or treated as confirmed callable starts.
- The true `0x0048c27b-0x0048c341` destructor adjustor-thunk band is layout support for these dialogs and `ClanStatusPane`, but compiler-emitted adjustor thunks should not be rewritten as source methods. The preceding `0x0048c260-0x0048c26b` and `0x0048c270-0x0048c27b` bodies are singleton-clear cleanup helpers for ClanBankPane and ClanStatusPane, not modal-dialog thunks.
- `ClanNameInputDialog` uses inherited control host offset `+0x1fc` to fetch controls `1`, `2`, and `4`. `ClanAttrInputDialog` adds submitted-field storage at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; see [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md).

## Live IDA Evidence

- Current authority is the fresh 2026-08-14 read-only MCP recheck summarized above. Stale Wave2/Wave3 names and ownership projections are historical only and are not used to select current source, owner, emitter, signature, score, or code.

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, checked through IDA MCP on 2026-06-04.
- 2026-06-14 C001 recheck used live IDA MCP session `b001_0003gy` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; the modal island boundaries and vtable sequence remain consistent with the 2026-06-04 audit.
- Function boundaries in the modal-dialog island: `0x00488b40-0x00488eab`, `0x00488eb0-0x00488f24`, `0x00488f30-0x00488f67`, `0x00488f70-0x00488fa0`, submitters `0x00488fe0-0x00489062`, `0x004890b0-0x00489132`, `0x00489180-0x0048926e`, `0x004892b0-0x0048939e`, `0x004893e0-0x004894ce`, `0x00489510-0x004895fe`, `ClanAttrInputDialog` core methods `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, `0x00489f50-0x00489f80`, submitters `0x00489fc0-0x00489fe9` and `0x0048a030-0x0048a059`, and leave-confirm callbacks `0x0048a0a0-0x0048a0ae` and `0x0048a0b0-0x0048a0be`.
- Raw constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, and `0x0048a060` are not IDA function starts, have no current xrefs to the exact start addresses, and begin with standard constructor-shaped prologues (`55 8b ec 51 56 ff 75 ...`).
- Modal-dialog vtable data is contiguous from `0x006158f8` through `0x00615fd0`: `ClanNameInputDialog`, the six `ClanNameInputDialog` derivatives, `ClanAttrInputDialog`, `ClanEnlistInputDialog`, `ClanChangeInputDialog`, and `ClanLeaveConfirmDialog` each have primary/secondary/tertiary vtable groups.
- The 2026-06-14 `entity_query` pass reconfirmed the contiguous vtable-name run from `ClanNameInputDialog` at `0x006158f8` through `ClanLeaveConfirmDialog` at `0x00615fd0`, followed immediately by the `ClanItemDialog` successor at `0x00615fdc`.
- 2026-06-16 A001 IDA MCP `lookup_funcs` reconfirmed the modeled modal-dialog functions and current names/sizes: `0x00488b40` size `0x36b`, `0x00488eb0` size `0x74`, `0x00488f30` size `0x37`, `0x00488f70` size `0x30`, submitters `0x00488fe0`/`0x004890b0` size `0x82`, name submitters `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510` size `0xee`, `ClanAttrInputDialog` body starts `0x00489600`, `0x00489df0`, `0x00489ec0`, `0x00489f50`, and leave callbacks `0x0048a0a0`/`0x0048a0b0` size `0xe`.
- The same 2026-06-16 pass reconfirmed representative vtable-head refs: `0x00615998` has refs at `0x00485120`, `0x00487de4`, and raw `0x00488fb2`; `0x00615d58` has a constructor ref at `0x00489660`; `0x00615f38` has refs at `0x004850a7`, `0x00487d22`, and raw `0x0048a07b`. `ClanItemDialog` successor head `0x00615fdc` starts the next family with refs at `0x0048a0d8`, `0x0048a100`, `0x0048a690`, `0x0048acf0`, and `0x0048c476`.
- Representative 2026-06-14 vtable-head refs remain source-shape anchors: `ClanNameInputDialog` head `0x006158f8` is stored from `0x00488b9e`, `ClanDepMoneyInputDialog` head `0x00615998` from `0x00485120`, `0x00487de4`, and raw `0x00488fb2`, `ClanAttrInputDialog` head `0x00615d58` from `0x00489660`, and `ClanLeaveConfirmDialog` head `0x00615f38` from `0x004850a7`, `0x00487d22`, and raw `0x0048a07b`.
- IDA vtable store xrefs match the raw/inline construction evidence: `ClanNameInputDialog` stores at `0x00488b9e/0x00488ba4/0x00488bae`; derived name-dialog variants have stores at their inline open sites and raw constructor bodies, including `ClanDepMoneyInputDialog` `0x00485120/0x00487de4/0x00488fb2`, `ClanWidMoneyInputDialog` `0x00485398/0x004884d4/0x00489082`, `ClanExpelNameInputDialog` `0x004851cb/0x004881e4/0x00489152`, `ClanSummonNameInputDialog` `0x0048522c/0x00488294/0x00489282`, `ClanAppearNameInputDialog` `0x00485284/0x0048833c/0x004893b2`, and `ClanChangeNameInputDialog` `0x00485337/0x0048842e/0x004894e2`.
- `ClanAttrInputDialog` vtable stores are `0x00489660/0x00489666/0x00489670`; derived/enclosing stores include `ClanEnlistInputDialog` `0x00487f34/0x00489f92`, `ClanChangeInputDialog` `0x004852ee/0x004883ed/0x0048a002`, and `ClanLeaveConfirmDialog` `0x004850a7/0x00487d22/0x0048a07b`.
- Historical placement lead (superseded 2026-08-14): `by-project-structure/proposed-source-tree.md` once listed `ClanDialogs.cpp` under `ui/dialogs/`. Current canonical metadata intentionally has no reconstruction path/owner/emitter for this index, and all accepted modal source remains under [UID:0000I8][Clan](by-file/Clan.md) in `NexusTK/social/Clan.cpp` and `Clan.h`.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md)
- [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md)
- [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md)
- [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md)
- [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md)
- [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md)
- [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md)
- [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md)
- [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md)
- [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md)

## Changes

All dated entries below are retained historical provenance. Any entry describing this page as a split candidate, validator path, migration target, fallback source owner, or no-final-C++ policy is superseded by the 2026-08-14 non-standalone resolution and exact constructor emission documented above.

- 2026-06-28 B006 `00021L` route sync:
  - Added the explicit negative route for [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md). Its raw helper strip has no live route and only mirrors live Clan row/list/submitter behavior, so it remains a [UID:0000I8][Clan](by-file/Clan.md) retained marker rather than a one-off `ClanDialogs.cpp` migration.
- 2026-06-20 B003 `0002O3` source-quality sync:
  - Updated the `ClanEnlistInputDialog` candidate row to call [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) the class-owned `OnSubmitEnlistment()` submit override while preserving this page's split-candidate status. Active emission still routes through [UID:0000I8][Clan](by-file/Clan.md), not this page, until a coordinated modal-family migration is accepted.
- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed exact modeled modal-dialog function starts/sizes, zero IDA functions or xrefs at the nine projected raw constructor starts, representative vtable-store refs into modeled and raw/open sites, and the `ClanItemDialog` successor boundary. A section-mapped PE scan found no VA/RVA/direct-branch references to the raw constructor starts. The remaining blocker is real: [UID:0000I8][Clan](by-file/Clan.md) is still the stronger current social feature owner for final source placement, while this page remains the `ui/dialogs/ClanDialogs.cpp` split candidate.
- 2026-06-19 B012 parser/dispatcher source-quality report accepted by supervisor:
  - Added an explicit negative route for [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) and [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md). These are not `ClanDialogs.cpp` ownership targets despite opening/calling modal dialogs; they remain `ClanStatusPane`/`social/Clan.cpp` packet handling.
- 2026-06-20 B002 ClanAppearNameInputDialog owner check:
  - Reconfirmed that [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) should not migrate alone to this split candidate; its class shell and submitter remain emitted through [UID:0000I8][Clan](by-file/Clan.md).
- 2026-06-20 B002/B009 ClanNameInputDialogCore owner check:
  - Reconfirmed that [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) should not migrate alone to this split candidate. Its first-draft constructor/handler C++ remains under [UID:0000I8][Clan](by-file/Clan.md) until a coordinated modal-family migration moves the base core, vtables, raw constructors, and derived submitters together.
- 2026-06-20 B002 `00021S` negative-route sync:
  - Added the explicit negative route for [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md). The opcode `0x43` helper island constructs clan modal dialogs, but its live packet/view handlers and retained no-xref opener siblings remain `social/Clan.cpp`/`ClanStatusPane` or file-local Clan helper ownership rather than `ClanDialogs.cpp`.
- 2026-06-20 B004 ClanDepMoneyInputDialog route sync:
  - Reconfirmed [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md) should not migrate alone to this split candidate. Its class summary, raw constructor, and submitter remain emitted/routed through [UID:0000I8][Clan](by-file/Clan.md) until a coordinated modal-family migration moves the base dialog, vtables, raw constructors, and derived submitters together.
- 2026-06-21 B011 ClanExpelNameInputDialog route sync:
  - Reconfirmed [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md) should not migrate alone to this split candidate. Its class declaration and submitter remain routed through [UID:0000I8][Clan](by-file/Clan.md) / `social/Clan.cpp`; [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) stays retained no-route constructor evidence despite live inline construction sites.
- 2026-06-22 B001 `0002NX/0002O1` route sync:
  - Reconfirmed [UID:00002M][ClanSummonNameInputDialog](by-class/ClanSummonNameInputDialog.md) and [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md) should not migrate alone to this split candidate. Their raw constructor children remain reconstructable retained no-route evidence, their submitter children remain the emitted method bodies, and the active file route remains [UID:0000I8][Clan](by-file/Clan.md) until a coordinated modal-family migration moves the base dialog, vtables, raw constructors, and derived submitters together.
  - Evidence: B001 found no absolute VA, RVA, or direct branch/call route to twelve clan raw constructor starts, including `0x00489270` and `0x004894d0`, while the raw bodies and inline opener sites still install the correct class vtables. This rejects ignored/dead/duplicate-only classification but preserves the no-final-C++ caveat for the standalone raw constructor starts.
- 2026-06-22 B014 ClanDestructorBand support sync:
  - Corrected the destructor-band note so this split candidate no longer treats `0x0048c260-0x0048c341` as a single thunk strip. `0x0048c260` and `0x0048c270` are cleanup helpers; `0x0048c27b-0x0048c341` is generated thunk support.
  - Evidence: direct PE byte review in [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md). Scores and route policy are unchanged.
- 2026-06-14 C001 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed the modeled modal-dialog function sizes, no IDA functions or exact xrefs at the raw constructor starts, the contiguous clan dialog vtable run through `0x00615fd0`, representative vtable-store refs into both modeled constructors and raw/open sites, and the `ClanItemDialog` successor boundary. Confidence stops at `85` because [UID:0000I8][Clan](by-file/Clan.md) remains a plausible final owner if the original source did not split the modal dialogs into `ClanDialogs.cpp`.
- 2026-05-27: Corrected the `ClanNameInputDialog` core range from `0x00488b40-0x00488f9f` to `0x00488b40-0x00488fa0` and added [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) for the `ClanDepMoneyInputDialog` raw constructor-shaped bytes. Evidence: IDA MCP disassembly shows the final byte at `0x00488f9f` belongs to `sub_488F70`'s `retn 4`, and raw-head audit shows `0x00488fa0-0x00488fd5` installs `ClanDepMoneyInputDialog` vtables without an IDA function object.
- 2026-05-27: Corrected `ClanAttrInputDialog` core end from `0x00489f7f` to `0x00489f80` and added [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, then constructor-shaped bytes that install `ClanEnlistInputDialog` vtables before alignment padding at `0x00489fb5-0x00489fc0`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: candidate dialog family contents, vtable/layout anchors, raw constructor caveats, and Clan/ClanBank ownership relationships are documented; confidence remains medium-high because this page is explicitly a split candidate rather than a committed final source module.
- 2026-06-04 live IDA path and confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, and a blank `PROPOSED_RECONSTRUCTION_PATH`, with older external-source hints and only partial exact child links.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: live IDA MCP now records exact modal-dialog function boundaries, the raw constructor starts with no IDA function/xref at the start, contiguous vtable groups from `0x006158f8-0x00615fd0`, concrete vtable store xrefs for each dialog family, and the `ui/dialogs/ClanDialogs.cpp` placement in `by-project-structure/proposed-source-tree.md`. Confidence remains capped because [UID:0000I8][Clan](by-file/Clan.md) is still a strong fallback owner for final source layout.
