*** UID:0000L9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MerchantDialogPane

## B002 UID0000OP Accepted Shared-Base Completion

`MerchantDialogPane` is the exact 0x274 shared base for all seven menu-dialog caller families. It stores `m_menuDialogType` at `+0x26c`, explicit reserve bytes at `+0x26d..+0x26f`, and inherited `m_menuObjectId` at `+0x270`, declares protected `SendMenuRequestPacket()`, and routes exact child UID0004H8 `[0x00517ec0,0x00517f26)` through MerchantDialogPane.cpp. The method SHA256 is `14A50CC09956CDF5005C574BC476CB18A6D12C67D89E2D4247F3011C922B445D`; callers are `0x00519362`, `0x0051a2b1`, `0x0051aced`, `0x0051c34d`, `0x0051d55d`, `0x0051e51d`, and `0x0051f1ad`. Its formal body writes exactly six bytes through scalar PacketBuffer helpers, sends `sizeof(packet)`, and closes; no trailing-byte source claim remains. TextMenuDialogs owns none of this method source. The class and file scores are `94/94`; ordinary destructor source remains compiler-covered through inherited cleanup.

The previous standalone-versus-folded uncertainty and TextMenu-only request-method attribution are superseded. Item/spell/argumented families remain separate source owners while inheriting this common base storage and method.

## Historical Status

- Confidence: very strong for the complete class/constructor/EventHandler-method source graph, owner-specific vtables, dependencies, and derived-family use; the remaining uncertainty is only whether the historical source was standalone or folded into a broader menu-dialog unit.
- Candidate file: `NexusTK/ui/dialogs/MerchantDialogPane.cpp`
- Alternative compact placement: private base code inside `ui/dialogs/TextMenuDialogs.cpp` or a broader menu-dialog source.
- Current generated source: `source-3/simroot_v2/class_MerchantDialogPane.cpp` is used only as historical generated-output context; current confidence comes from IDA evidence and local docs.
- Primary class doc: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- Split/container address doc: [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- Exact constructor doc: [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md)
- Exact shared virtual doc: [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## File Role

`MerchantDialogPane` is the shared `DialogPane`-derived base used by merchant/NPC packet menu dialogs. It stores the merchant/menu type byte at offset `+0x26c`, installs primary/EventHandler/timer-handler views at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`, and provides `virtual bool HandlePacketEvent(Event *event)` in canonical EventHandler slot `+0x10`.

The method at `0x00517d80` is referenced from vtables for `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`. That makes this base a cross-family dialog component, not a text-menu-only helper. The explicit argument is the canonical Event packet record; no separate action-string wrapper belongs in the source graph.

The adjacent [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) range is a caller-side menu-dialog factory island, not part of the base class body. B010's accepted implementation keeps that dispatcher emitted through [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) with formal first-draft `CreateMerchantMenuDialog` / wrapper C++; do not merge it into `MerchantDialogPane` unless a later source-tree pass deliberately groups factory and base helpers together.

IDA confirms `MerchantDialogPane` vtable bases at `0x0061ec10`, `0x0061ec70`, and `0x0061eca0`. Current generated metadata omits these vtables, so use the family page above for reconstruction layout decisions.

Shared default destructor note: the primary `MerchantDialogPane` vtable slot `0x0061ec10` uses [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), with secondary/tertiary slots `0x0061ec70` and `0x0061eca0` routed through [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md). This is compiler-generated deleting-destructor glue; source reconstruction should declare/default the dialog destructor and rely on [UID:0000IT][DialogPane](by-file/DialogPane.md) for ordinary cleanup, not hand-port the wrapper.

The broad memory page [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md) is now a reviewed non-emitting split container, not this file's source-body emitter. Source-bearing class content is carried by exact children: constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) and action virtual [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md).

## 2026-06-10 B001-008 IDA Refresh

Live IDA MCP `py_eval` against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirms the three `MerchantDialogPane` vtable views: `0x0061ec10`, `0x0061ec70`, and `0x0061eca0`. Their complete-object-locator pointers are at `0x0061ec0c`, `0x0061ec6c`, and `0x0061ec9c`, and constructor-shaped stores occur at `0x00517d53`, `0x00517d59`, and `0x00517d63`. The secondary view still contains `0x00517d80` at `0x0061ec80`, matching the shared action-string virtual documented in [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md).

## 2026-06-16 A001 IDA/PE Refresh

The dated session reconfirmed `0x00517d30` as raw constructor-shaped code and `0x00517d80` as a `0x13f` action-string virtual. Current classification corrects its then-used successor label: `0x00517ec0` is `MerchantDialogPane::SendMenuRequestPacket`, a second base-owned method with seven derived-family callers; the `TextMenuDialog` constructor begins at `0x00517f30`. The no-xref constructor and eight vtable refs to `0x00517d80` remain valid evidence.

## Proposed Contents

| Entity | Address evidence | Current file | Role |
| --- | --- | --- | --- |
| `MerchantDialogPane` constructor | [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) | constructor child emits through [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) | Initializes the empty-title `DialogPane(L"", 1, 1)` base, stores inferred `m_menuDialogType` at `+0x26c`, and relies on compiler lowering for primary/secondary/tertiary vtable installs. |
| `MerchantDialogPane::HandlePacketEvent(Event*)` | [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) | exact child emits through [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) | EventHandler packet override that accepts slash packets, parses `0...` object-response data through ObjectStatusBlob, and sends an exact ten-byte opcode `0x3a` response. |
| `MerchantDialogPane` declaration/source shell | [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) | H declaration; CPP own/dependency includes plus `[[CHILDREN]]` | H includes `DialogPane.h`, forward-declares Event, and declares the constructor, packet virtual, and `m_menuDialogType`; CPP includes MerchantDialogPane/Event/ObjectStatusBlob/PacketBuffer/Socket before child expansion. |

## Complete Source Graph And Dependencies

- Header contract: `MerchantDialogPane : public DialogPane`, constructor taking the menu type byte, `virtual bool HandlePacketEvent(Event *event)`, and protected `m_menuDialogType`.
- Constructor child `[0x00517d30,0x00517d74)` initializes `DialogPane(L"", 1, 1)` and the byte member; compiler lowering emits the three vtable stores.
- Method child `[0x00517d80,0x00517ebf)` reads Event packet data at `+0x0c`, preserves byte `+7`, uses a signed-short trailer cursor, parses ObjectStatusBlob at `+8`, writes a 256-byte local response buffer, and sends ten bytes.
- Source dependencies are `MerchantDialogPane.h`, `Event.h`, `ObjectStatusBlob.h`, `PacketBuffer.h`, and `Socket.h`. PacketBuffer, Socket, g_packetSender, and ObjectStatusBlob remain dependencies rather than source owners.
- The broad UID0001BL memory page remains a non-emitting split container. Owner-specific vtable data, RTTI, deleting destructors, secondary-this adjustment, and stack-cookie handling remain compiler-generated.

## Boundary Notes

- IDA does not currently model `0x00517d30` as a function, but raw disassembly shows a complete constructor-shaped body now covered by exact child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md). The corrected half-open range includes the full `retn 4` endpoint at `0x00517d72-0x00517d73`.
- IDA does model `0x00517d80-0x00517ebf` as a function, with only data xrefs from merchant/text/item/spell/argumented-menu vtables.
- `0x00517d23-0x00517d30` is alignment padding after the preceding factory helper cluster.
- `0x00517d74-0x00517d80` is alignment padding after the constructor and before the action virtual.
- `0x00517ec0` starts base-owned `MerchantDialogPane::SendMenuRequestPacket`; `0x00517f30` starts the following TextMenuDialog constructor. Keep both exact children separate while routing the request method through this file.
- The 2026-06-01 recheck correctly established constructor bytes, `0x00517d80` size, and vtable stores but used the now-superseded TextMenu label for `0x00517ec0`.
- Historical generated output omitted the shared virtual body and emitted empty markers. The accepted source graph replaced it: current generated `MerchantDialogPane.cpp` contains UID00041Q construction, UID0001BM `HandlePacketEvent(Event *)`, and UID0004H8 `SendMenuRequestPacket()`, and the generated H declares the shared request method. Generated files remain validator-owned; physical receipts are snapshots produced by scoped refreshes, not timeless authority.

## Placement Notes

The cleanest migration target is:

```text
NexusTK/ui/dialogs/MerchantDialogPane.cpp
```

Accepted reconstruction uses standalone `NexusTK/ui/dialogs/MerchantDialogPane.cpp`, adjacent to the text, item, spell, and argumented menu files. Earlier fold alternatives are historical and no longer current placement authority.

Rejected direct-source placements from the accepted split report remain: TextMenuDialogs, ItemMenuDialogs, SpellMenuDialogs, ArgumentedMenuDialogs, PacketBuffer, Socket, ObjectStatusBlob, DialogPane, and the broad `MerchantMenuDialogVtableFamily` page are consumers, callees, base dependencies, or mixed context rather than the source root for this class.

The former unknown action-wrapper/no-code conclusion and fold uncertainty are retained only as historical context. Canonical Event/EventHandler evidence and UID0004H8 resolve both base-owned methods and standalone `MerchantDialogPane.cpp` placement without changing exact vtable reachability or inherited-consumer facts.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The file page records the complete class/header/source graph, exact constructor, EventHandler, and shared request-method children, source dependencies, vtable/compiler boundary, inherited consumers, ranges/padding, rejected owners, projected path, and generated three-definition state. |
| Confidence | 94 | Binary evidence, canonical Event/EventHandler support, inherited item-menu consumers, and generated CPP/H agree on method/type/behavior ownership. Only original private lexical spellings remain inferred. |

## Cross-References

- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)

## Changes

- 2026-08-21 B002 Gate 2A repair: corrected active boundary and source-placement prose so `0x00517ec0` is the base-owned request method, the TextMenuDialog constructor begins at `0x00517f30`, and standalone MerchantDialogPane.cpp is accepted. Earlier TextMenu/fold wording remains dated history.
- 2026-07-26 B002 accepted UID0001BM implementation callback (historical / superseded score snapshot):
  - Raised `86/88 -> 90/90`; retained `NexusTK/ui/dialogs/` path and file ownership. The later UID0000KF callback and current metadata replace that intermediate score with `94/94` and include UID0004H8 in the generated source graph.
  - Added the complete MerchantDialogPane H/CPP/constructor/method source graph, EventHandler slot/offset contract, exact packet-method behavior, dependencies, child/source routing, and compiler-generated exclusions.
  - Historicalized the former unknown action-wrapper/no-code and generated-empty-marker states while preserving exact reachability, boundary, vtable, rejected-owner, and physical-file uncertainty evidence.
- 2026-06-25 B006 accepted-report implementation:
  - Added exact constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) and clarified that [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md) is now a non-emitting split container rather than a source-body emitter.
  - Corrected stale constructor endpoint wording and recorded the `m_menuDialogType` field at `+0x26c`.
  - Preserved standalone-versus-folded source-file uncertainty while keeping `NexusTK/ui/dialogs/MerchantDialogPane.cpp` as the current source root.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync: score unchanged. Reconfirmed the factory/base split: the factory emits through `TextMenuDialogs.cpp` and remains adjacent support, not `MerchantDialogPane` method/body code.
- 2026-06-16 A001 file-completion refresh: raised `85/86 -> 86/88`.
  - Evidence: live IDA MCP reconfirmed raw constructor non-function status, shared virtual size, successor boundary, constructor vtable-store refs, eight inherited vtable refs, and action-string decompilation; section-mapped PE scanning found no hidden pointer/branch refs to the raw constructor and only the eight vtable pointers for the shared virtual.
  - Scope: file root remains `NexusTK/ui/dialogs/MerchantDialogPane.cpp`; direct class-owned support is now routed through [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md) where appropriate. Final C++ stays blank pending raw constructor/source-split and helper/signature names.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: shared merchant/menu dialog base role, constructor and action-string virtual, vtable family, boundary notes, placement choices, and cross-family refs are documented; confidence is capped by raw constructor modeling and uncertainty over standalone versus broader menu-dialog source placement.
- 2026-06-01 IDA MCP path/confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:78`, and blank projected reconstruction path.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:82`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: current IDA MCP recheck reconfirms constructor-shaped bytes, vtable stores, shared virtual xrefs across merchant/text/item/spell/argumented menu dialogs, and the `0x00517ec0` text-menu boundary. Confidence now clears the parent-attachment threshold, while final C++ remains gated by raw constructor modeling and exact file split.
- 2026-06-10 B001-008 ownership-gate refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP reconfirmed decorated vtable views, complete-object-locator pointers, raw constructor vtable stores, inherited `0x00517d80`, and the split child [MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md). The exact standalone-vs-folded source file name remains provisional, but this file root now clears the strict `85/85` gate as the direct owner bucket for the merchant dialog base.
