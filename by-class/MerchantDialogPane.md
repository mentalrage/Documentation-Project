*** UID:000083 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MerchantDialogPane.h"

#include "Event.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "DialogPane.h"

class Event;

class MerchantDialogPane : public DialogPane
{
public:
    explicit MerchantDialogPane(unsigned char menuDialogType);
    virtual bool HandlePacketEvent(Event *event);

protected:
    void SendMenuRequestPacket();

    unsigned char m_menuDialogType;
    unsigned char m_reserved[3];
    unsigned int m_menuObjectId;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MerchantDialogPane

## 2026-08-22 UID0000KF Accepted Shared-Base Correction

The formal H channel preserves the existing header preamble and installs the accepted shared base declaration. `m_menuDialogType` is byte `+0x26c`, `m_reserved[3]` occupies `+0x26d..+0x26f`, and `m_menuObjectId` is the shared dword at `+0x270`; the complete base remains `0x274`. The protected `SendMenuRequestPacket()` declaration is shared by all seven derived caller families. UID0004H8 owns the exact six-byte definition through `MerchantDialogPane.cpp`; ItemMenuDialogs inherits this member and does not duplicate it.

The older `m_dialogId` lexical choice and trailing-byte narrative below are historicalized by this accepted correction. Exact method range `[0x00517ec0,0x00517f26)`, SHA256 `14A50CC09956CDF5005C574BC476CB18A6D12C67D89E2D4247F3011C922B445D`, callers `0x00519362`, `0x0051a2b1`, `0x0051aced`, `0x0051c34d`, `0x0051d55d`, `0x0051e51d`, and `0x0051f1ad`, and MerchantDialogPane ownership remain unchanged.

## Historical B002 UID0000OP Shared-Base Completion

`MerchantDialogPane` is the exact 0x274 shared base for all seven menu-dialog caller families. It stores `m_menuDialogType` at `+0x26c` and `m_menuObjectId` at `+0x270`, declares protected `SendMenuRequestPacket()`, and routes exact child UID0004H8 `[0x00517ec0,0x00517f26)` through MerchantDialogPane.cpp. The method SHA256 is `14A50CC09956CDF5005C574BC476CB18A6D12C67D89E2D4247F3011C922B445D`; callers are `0x00519362`, `0x0051a2b1`, `0x0051aced`, `0x0051c34d`, `0x0051d55d`, `0x0051e51d`, and `0x0051f1ad`. TextMenuDialogs owns none of this method source. The class and file scores are `94/94`; ordinary destructor source remains compiler-covered through inherited cleanup.

The previous standalone-versus-folded uncertainty and TextMenu-only request-method attribution are superseded. Item/spell/argumented families remain separate source owners while inheriting this common base storage and method.

## Historical Status

- Confidence: very strong for the class role, EventHandler contract, exact constructor and packet method children, vtable materialization, inherited consumer family, and file-parent routing; only the exact historical physical file fold remains inferred.
- Likely source file: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- Split/container range: [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- Exact constructor: [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md)
- Exact shared virtual: [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- Current generated files: `auto-generated/NexusTK/ui/dialogs/MerchantDialogPane.cpp` and `MerchantDialogPane.h`; the old simroot file is historical context.

## Class Purpose

`MerchantDialogPane` is the shared base for merchant/NPC menu dialogs. It derives from [UID:00003T][DialogPane](by-class/DialogPane.md), initializes the dialog with an empty title and modal flags, stores a one-byte merchant/menu type at `+0x26c`, and overrides `EventHandler::HandlePacketEvent(Event*)` for text, item, spell, and argumented menu dialogs.

The class has primary, EventHandler, and timer-handler views at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`. Source declares an ordinary virtual member; compiler lowering supplies the secondary-view entry and vtables. Raw IDA typing for the entry must therefore distinguish the incoming EventHandler facet from a complete-object pointer, but no pointer adjustment belongs in human source.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) | Builds the `DialogPane(L"", 1, 1)` base, stores inferred `m_menuDialogType` at `+0x26c`, returns `this`, and installs the `MerchantDialogPane` vtables through compiler lowering. |
| `HandlePacketEvent(Event*)` | [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) | EventHandler secondary slot `+0x10`; accepts slash-prefixed packets, parses `0...` object-response payloads through ObjectStatusBlob, and emits the exact ten-byte opcode `0x3a` response. |

## Evidence Notes

- IDA `lookup_funcs` reports `0x00517d30` as not currently modeled as a function, but disassembly confirms a complete constructor body.
- IDA models `0x00517d80` as `sub_517D80`, size `0x13f`; xrefs are vtable data entries, not normal call sites.
- The `0x00517d80` vtable references sit in `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog` vtables.
- `0x00517ec0` begins base-owned `MerchantDialogPane::SendMenuRequestPacket`; it emits through this class/file. The following `TextMenuDialog` constructor begins at `0x00517f30`.
- 2026-06-01 IDA MCP recheck reconfirms that `0x00517d30` is still unmodeled but constructor-shaped, stores the three `MerchantDialogPane` vtable bases, and has no direct xrefs. `0x00517d80` remains a modeled vtable-only virtual with data refs from the merchant/text/item/spell/argumented menu dialog vtables.
- Current generated `NexusTK/ui/dialogs/MerchantDialogPane.cpp` contains the UID00041Q constructor, UID0001BM `HandlePacketEvent(Event *)`, and shared UID0004H8 `SendMenuRequestPacket()` definitions, while `MerchantDialogPane.h` declares the request method. The earlier `class_MerchantDialogPane.cpp` constructor-only output is historical and superseded by the accepted standalone source graph and subsequent validator generation.
- The 2026-06-14 recheck correctly established the raw constructor and `0x00517d80`/`0x00517ec0` sizes, but its `TextMenuDialog` label for the `0x66` successor is superseded by current `MerchantDialogPane::SendMenuRequestPacket` ownership.
- 2026-06-14 `xrefs_to` reconfirmed eight data refs to the shared virtual from vtable slots `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`; it also reconfirmed raw constructor vtable store refs to `0x0061ec10`, `0x0061ec70`, and `0x0061eca0` at `0x00517d53`, `0x00517d59`, and `0x00517d63`, with no direct xrefs to the raw constructor start.
- 2026-06-14 decompilation of `0x00517d80` still matches the documented merchant action-string virtual: slash-prefixed action strings return accepted, `0...` encoded payloads are parsed through packet helper calls, a 10-byte payload is queued through `dword_67A7EC` / `0x00574bb0`, and nonmatching prefixes are rejected.
- 2026-06-16 A001 live IDA/PE refresh reconfirmed `0x00517d30` as raw non-function code with no IDA xrefs and no section-mapped PE VA/RVA/direct-branch hits, `0x00517d80` as a `0x13f` vtable-only function with the same eight vtable data refs and no direct branches, and the constructor stores to all three owner-specific vtable views.
- 2026-06-25 B006 accepted-report implementation split the old broad memory page into exact constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) plus existing action virtual [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md). The constructor child carries the approved formal constructor C++ block and records the `0x00517d72-0x00517d73` `retn 4` endpoint correction.
- 2026-07-26 B002's accepted UID0001BM evidence resolves the former unknown virtual/action-object model: secondary cell `0x0061ec80` is canonical EventHandler slot `+0x10`, the explicit argument is `Event *`, and Event packet data is at `+0x0c`. Seven derived-family cells inherit the same base method.
- The exact method preserves packet byte `+7`, signed-16-bit trailer arithmetic, a 256-byte response local, ObjectStatusBlob parsing at `+8`, and a ten-byte opcode `0x3a` send. No null/type/size/parser guard is added.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) because the file parent now has enough IDA-backed confidence and the class role is shared across the merchant menu-dialog family.
- The H channel owns the complete C++03 class declaration, including required `DialogPane.h`, pointer-only `Event` forward declaration, constructor, packet virtual, and exact one-byte member. The CPP channel includes its own header and Event/ObjectStatusBlob/PacketBuffer/Socket dependencies, then expands `[[CHILDREN]]`; declarations and examples do not remain in CPP.
- Child pages own method definitions: [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) emits the constructor and [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) emits `HandlePacketEvent`.
- Rejected routing alternatives remain TextMenuDialogs, ItemMenuDialogs, SpellMenuDialogs, ArgumentedMenuDialogs, PacketBuffer, Socket, ObjectStatusBlob, DialogPane, and the broad mixed MerchantMenuDialog vtable family. Those pages are derived consumers, callees, base dependencies, or mixed-family context, not the direct owner for this class body.

## Historical Assumptions Superseded

- Earlier scoring retained blank class C++ and treated the method signature/action wrapper as unresolved. That conclusion was reasonable before canonical Event/EventHandler slot evidence was incorporated, but it is now superseded.
- The old vtable-only reachability, raw constructor status, exact store sites, eight inherited method refs, and standalone-versus-folded source uncertainty remain valid evidence and are preserved.
- Candidate action wrappers such as `MenuActionString`, `DialogAction`, and `DialogObjectAction` are rejected in favor of the established Event packet record; the raw secondary-view receiver remains an IDA concern rather than source syntax.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The class page documents the exact constructor, packet virtual, shared request-method child, complete H/CPP channel routing, EventHandler slot and object views, packet behavior, vtable refs, derived inheritance, exact member offsets, compiler-generated exclusions, source ownership, and current generated topology. |
| Confidence | 94 | Binary evidence and canonical Event/EventHandler documentation agree on the class contract, source declaration, raw secondary-view ABI, inherited `m_menuObjectId`, request-method ownership, standalone generated placement, and three-definition generated state. Only stripped local lexical names remain inferred. |

## Cross-References

- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)

## Changes

- 2026-08-21 B002 Gate 2A repair: corrected active boundary/generated prose so UID0004H8 is a base-owned MerchantDialogPane method at `0x00517ec0`, not the start of TextMenuDialog; the TextMenu constructor begins at `0x00517f30`.
- 2026-07-26 B002 accepted UID0001BM implementation callback (historical / superseded score snapshot):
  - Raised `87/88 -> 92/94`; retained UID0000L9 owner/emitter route and reconstructable state. The later UID0000KF callback and current metadata replace that intermediate score with `94/94` and include UID0004H8 in the generated source graph.
  - Installed the complete class declaration in H and the separate own/dependency include plus `[[CHILDREN]]` shell in CPP.
  - Replaced the unknown action-wrapper/no-code wording with canonical `HandlePacketEvent(Event*)`, exact EventHandler offsets/slot, method behavior, child ownership, and source/generated boundary while preserving prior evidence as history.
- 2026-06-25 B006 accepted-report implementation:
  - Linked new exact constructor child [UID:00041Q][0x00517d30-0x00517d74.MerchantDialogPaneConstructor](by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md) and retained [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) as the shared action virtual.
  - Corrected stale constructor range wording from `0x00517d30-0x00517d71` to half-open `0x00517d30-0x00517d74`.
  - Recorded inferred `m_menuDialogType` at `+0x26c`, the empty-title `DialogPane(L"", 1, 1)` base initializer, child-level constructor C++ routing, and action-virtual no-code condition.
- 2026-06-16 A001 file-completion support refresh:
  - Changed `86/87 -> 87/88`.
  - Evidence: live IDA MCP reconfirmed raw constructor/no-xref status, shared virtual size/decompilation, eight vtable-only refs, and three constructor vtable-store refs; section-mapped PE scanning found no hidden reachability for the raw constructor and no direct branches to the shared virtual.
  - Scope: owner/emitter remain [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md); final C++ remains blank pending source-grade constructor/signature/helper/source-split evidence.
- 2026-06-14 A001 Goal 2 low-confidence refresh (historical / superseded readiness state):
  - Changed completion/confidence from `82/82` to `86/87`.
  - Evidence: live IDA MCP session `b001_0003gy` reconfirmed the raw constructor/no-xref caveat, modeled `0x00517d80` virtual size, `0x00517ec0` successor boundary, eight inherited vtable data refs to the shared virtual, three raw constructor vtable-store refs, and action-string decompilation. The direct file parent [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) and exact vtable child [UID:00031W][MerchantDialogPaneVtables](by-type/by-vtable/MerchantDialogPaneVtables.md) already clear the current gate.
  - At that time final C++ remained blank under the then-active source-entry gate because the constructor was raw/unmodeled and the standalone-versus-folded source split was not final. Accepted UID000083/UID0000L9 formal channels and the current generated constructor/packet/request definitions supersede that blocker.
- Completion/confidence score update: existed before as `0/0`; changed to `76/78`. Summary: the shared merchant/NPC menu-dialog base has responsibility, source-owner candidates, constructor behavior, shared virtual behavior, vtable references, and derived-dialog relationships documented, but exact file split and constructor function modeling remain medium confidence. Evidence: linked base/action-string memory pages, IDA-modeled `0x00517d80` shared virtual, vtable references across merchant dialog variants, and `0x00517ec0` island boundary note.
- 2026-06-01 IDA MCP rescore: `76/78` -> `82/82`; marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). Evidence: constructor bytes/vtable stores, shared virtual vtable xrefs, and text-menu boundary rechecked in IDA.
