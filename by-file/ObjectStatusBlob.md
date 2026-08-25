*** UID:0000M6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectStatusBlob

## 2026-08-18 Complete CPP And H Source Route

- Current source pair is exactly NexusTK/map/ObjectStatusBlob.cpp and NexusTK/map/ObjectStatusBlob.h.
- H owns the complete [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) declaration, public [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) prefix relationship, status-kind aliases, three parser declarations, m_faceShape, trailing padding, and exact 0x44 size guard.
- CPP includes ObjectStatusBlob.h and emits the existing tagged, full, and partial parser children in source order. It neither redeclares the class nor emits the non-source aggregate/index.
- File-owned inventory remains exactly one declaration plus the three parser bodies. [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md) remains a non-emitting range/index; alignment and raw successor leads remain excluded.
- ObjectImage, MapPane, SelfLook, UserLook, HeadSelect, NewHuman and dialog families are consumers. Their broad use is complete-type and shared-source evidence, not ownership transfer.
- Scores are now 94/94 after formal H/CPP closure. Remaining confidence limits are inferred historical folder/name spellings and absent rebuilt-binary comparison.
- Historical note: the older 90/93 checkpoint and CPP-local declaration described the pre-closure generated state. They are retained below as dated evidence, not current source authority.

## UID0003ZT Complete Declaration Header Contract - 2026-07-23

- Canonical source pair: `NexusTK/map/ObjectStatusBlob.h` and `NexusTK/map/ObjectStatusBlob.cpp`. The header basename is the highest-probability same-name declaration route for this dedicated shared descriptor module.
- ObjectStatusBlob.h owns the complete naturally aligned 68-byte [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) declaration, status-kind aliases, fields, method declarations, and size contract. It does not duplicate parser definitions.
- ObjectStatusBlob.cpp owns the tagged/full/partial parser bodies and all normalization/helper behavior inventoried below.
- MapPane.cpp includes ObjectStatusBlob.h before methods instantiate local ObjectStatusBlob values, pass them by value, or access status members. A forward declaration is insufficient for those uses.
- At the dated 2026-07-23 checkpoint, this complete-type closure supported the then-accepted `90/93` file score and preserved the blank by-file formal, `NexusTK/map/` placement, complete parser/source inventory, consumer evidence, and rejection of MapPane or one-consumer ownership. The later complete CPP/H callback superseded that score with current `94/94`.

## Current file role

- `NexusTK/map/ObjectStatusBlob.cpp` is the source root for class UID00009S and exact member children UID0004LK, UID0004LL, and UID0004LM. UID000179 is their non-emitting split/index and contributes no fourth source body.
- Completion/confidence `94/94` reflects the coherent complete module, exact class/method inventory, broad consumers, public `HumanImageRenderParams` prefix declaration, separate CPP/H route, and generated source/header verification. The inferred historical folder/file spelling and absent rebuilt-binary comparison remain the score caps.
- This dedicated shared descriptor module is stronger than ownership by MapPane, ObjectImage, UserLook/Profile, SelfLook, NewHumanImageLib, MetaMan, PacketBuffer, or a UI dialog. Those modules consume or support the value but do not own its thiscall parsers.

## Source inventory

| Entity | UID/range | Role |
| --- | --- | --- |
| ObjectStatusBlob class | [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) | complete naturally aligned 68-byte declaration, enum aliases, three member declarations, size check |
| aggregate/index | [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md) | non-reconstructable/non-emitting split, internal padding and shared evidence |
| tagged member | [UID:0004LK][0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus](by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md) | tag 0 full delegation, tags 1/2 compact parse, exact 44/4/0 returns |
| full member | [UID:0004LL][0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus](by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md) | exact 43-byte parser, riding/resource/remap and normalization body |
| partial member | [UID:0004LM][0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus](by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md) | exact five-byte compact update body |

- Source order is class declaration followed by tagged/full/partial children at emitter positions 10/20/30. Parent alignment bytes are not emitted.
- File pages do not carry a managed formal block; all declaration/body text exists only on the class and three exact children.

## Complete data model

- Exact 68-byte layout: kind dword `+0x00`; appearance/face/head index word `+0x04`; variant/hair/head draw byte `+0x06`; padding `+0x07`; Body/weapon/shield words `+0x08/+0x0a/+0x0c`; Helmet byte `+0x0e`; padding `+0x0f`; FaceDec/HairDec/second FaceDec/Mantle/Neck/Shoes/Coat/All words `+0x10..+0x1e`; headgear byte `+0x20`; gender/direction and composition/posture bytes `+0x21/+0x22`; padding `+0x23`; action dword `+0x24`; display/default byte `+0x28`; padding `+0x29`; riding words `+0x2a/+0x2c/+0x2e/+0x30`; colors `+0x32..+0x3e`; invisibility and face shape `+0x3f/+0x40`; trailing padding `+0x41..+0x43`.
- Kind 0 aliases Human/FullLiving, kind 1 aliases Monster/CompactLiving, and kind 2 is Item. Context-dependent unions preserve Map/ObjectImage, full-human, compact update, and HeadSelect source surfaces without duplicate physical fields.
- Natural alignment is sufficient; no packing or generic 68-byte raw field array is accepted. ObjectImage and SelfLook fixed-size storage/copies independently confirm the size.

## Parser and normalization inventory

- Tagged: leading 0 parses full payload and returns 44; leading 1/2 parses compact kind, BE16 appearance, and variant, returning 4; default returns 0 without writes.
- Partial: writes kind 1, action 11, display default `0x50`, direction/posture aliases, BE16 appearance, variant, and returns 5.
- Full: consumes 43 bytes and initializes kind 0/action 11/full-body sentinel. It parses gender/composition, riding id, display byte, face/hair/colors, Body/Coat, all equipment/color tail fields, invisibility, and face shape.
- Face normalization preserves the exact observed predicate and forces face 200 while moving its low byte to Hair. Body/Coat split uses threshold 9999 and `0xffff` counterpart sentinels. Shoes and headgear preserve exact allowlist/hide behavior.
- Exact `Part.tbl` inventory is Body, Coat, Face, Emotion, FaceDec, Hair, Helmet, HairDec, Sword, Spear, Bow, Fan, Shield, Arrow, Mantle, Shoes, Neck, All, and Back. These rows resolve every equipment id/color and shared skin/tint at `+0x34`.

## Riding, globals, callees, and consumers

- Full parsing formats nonzero riding id with UTF-16 `%d`, uses MetaMan `FindEntry` table `RidableAnimals`, and converts columns 1-3 to riding definition index, packed palette/render flags, and signed Y offset. This supersedes the historical title metadata model.
- UID0000SW `g_useEpfAssets` controls the legacy nonzero riding-id force. UID0000RT `g_pNewHumanImageLib` owns the `HAIRCOL.TBL` vector at NewHuman layout `+0x54/+0x58`; `0x0067a760` is not a generic appearance-remap table.
- Canonical helper/dependency route is PacketBuffer BE16 reader `0x00575480`, MetaMan `FindEntry` `0x00523120`, secure formatter `0x0041b9b0`, SimpleUString assign/clear lowering `0x00421590/0x00421310`, and `_wtol` `0x005cea43`. Direct packet bytes do not require a second source reader; `0x00575470` is compiler/runtime lowering.
- Consumers include MapPane full/partial handlers, ObjectImage 68-byte preview copies and kind dispatch, HeadSelect compact aliases, SelfLook/SelfLookPane2 full/partial updates, UserLook/Profile, and broad merchant/text/item/spell/message/Nexonclub tagged-dialog families. Returned lengths advance variable packet cursors where appropriate.
- NewHuman composition consumes composition mode, all equipment selectors/colors, shared tint, and riding definition/palette/Y fields; this is field-role evidence, not NewHuman ownership of parser source.

## Boundaries and rejected history

- UID0002J1 ends at `0x004d1f22`; fourteen `0xcc` bytes precede the tagged method. Internal alignment is seven `0xcc` bytes at `0x004d1f99-0x004d1fa0` and nine at `0x004d2637-0x004d2640`.
- UID000179 ends exclusively at `0x004d2697`. Raw leads `0x004d26a0`/`0x004d26e0` have no modeled functions/xrefs and remain excluded. HumanImageLib begins at `0x004d2720`.
- Historical title/profile/general-tail wording, generic remap naming for `0x0067a760`, universal direction/posture claims, static/free wrappers, aggregate emission, packed/raw layout, and one-consumer ownership are rejected or superseded. No unresolved semantic byte is deferred as a raw placeholder.

## Changes

- 2026-08-22 B010 Gate 2A repair: reconciled active file-role score prose with current `94/94`; prior `90/91` and `90/93` values remain only as explicitly dated pre-closure checkpoints.
- 2026-07-13 B005 UID000179 callback: raised `86/88 -> 90/91`; preserved FILE ownership and `NexusTK/map/`; linked class UID00009S and children UID0004LK/UID0004LL/UID0004LM; recorded UID000179 as a non-emitting index; replaced title/profile/remap shorthand with complete layout, parser, resource, normalization, global, caller, source, boundary, and negative evidence.
- Earlier parser-boundary, caller-family, Map/ObjectImage alias, and source-placement findings remain retained. Only their formerly unresolved or stale semantic interpretations were superseded.

## Cross-references

- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0004LK][0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus](by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md)
- [UID:0004LL][0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus](by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md)
- [UID:0004LM][0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus](by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000M6)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- NexusTK/map/ObjectStatusBlob.h is now the explicit compile-visible companion of the complete UID00009S 68-byte declaration consumed by UID000050. m_compositionMode remains the selected union spelling.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-079 | 000050 | The complete dialog formal uses `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h`; UID0000IT/UID0000M6 are explicit callback destinations for the first two companion-header paths, while UID0000I0 already documents the third. Current autogen is not misrepresented as having materialized them. | Strong | Current by-file/class source roots, exact complete class declaration owners, and UID0000I0 Proposed Placement. | UID000050 formal/dependency prose; UID0000IT/UID0000M6/UID0000I0 source-package support. | incorporate | implemented |
| C2E6-084 | 0000M6 | `NexusTK/map/ObjectStatusBlob.h` is the exact companion-header destination for complete declaration UID00009S; UID0000M6 currently records only the `.cpp` module and must add the header route for FittingRoom's two embedded values. | Strong | UID0000M6 source root, complete UID00009S formal, and exact FittingRoom ObjectStatusBlob members. | UID0000M6 proposed-header/source-placement prose and manual by-file row. | incorporate | implemented |
