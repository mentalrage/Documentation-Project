*** UID:00009O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ObjectImageControlPane.h"

#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../core/ScreenPane.h"
#include "../../render/EPFTileContext.h"
#include "../../render/GrafPort.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/MonsterImageLib.h"
#include "../../render/NewHumanImageLib.h"
#include "../../render/Surface.h"
#include <windows.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/ControlPane.h"
#include "../../map/ObjectStatusBlob.h"

struct Event;

class ObjectImageControlPane : public ControlPane
{
public:
    ObjectImageControlPane(const ObjectStatusBlob *objectStatus,
                           const RectBounds *bounds);
    virtual void OnPaint();

protected:
    ObjectStatusBlob m_objectStatus;
};

typedef char ObjectImageControlPaneSizeMustBe332[
    sizeof(ObjectImageControlPane) == 0x14c ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectImageControlPane

## 2026-08-18 Permanent Compiler Children

- Authored constructor and OnPaint remain on [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md).
- [UID:00055W][0x00520afd-0x00520b13.ObjectImageControlPaneDestructorThunks](by-memory/0x00520afd-0x00520b13.ObjectImageControlPaneDestructorThunks.md) and [UID:00055X][0x00520ca0-0x00520cdb.ObjectImageControlPaneScalarDeletingDestructor](by-memory/0x00520ca0-0x00520cdb.ObjectImageControlPaneScalarDeletingDestructor.md) are exact no-code compiler children regenerated from this class's virtual destruction and 0x14c layout.
- [UID:00055Z][0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand](by-memory/0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand.md) records the primary/EventHandler/TimerHandler tables and inherited routes. It does not emit a source vtable.
- Source order remains class declaration in H and authored children in CPP. Compiler children remain documentation-only.

## ObjectStatusBlob member synchronization

- The pane owns an exact 68-byte copied ObjectStatusBlob member at binary `+0x108..+0x14b`. Kind 0/1/2 selects Human/Monster/Item rendering; appearance/item `+0x04`, variant/palette `+0x06`, and display/default `+0x28` are formal UID00009S union/member fields.
- UID00009S now also resolves all equipment ids, context aliases, action, riding definition/palette/Y, complete colors including shared skin/tint, invisibility/face shape, and padding. RidableAnimals and HAIRCOL roles supersede prior title/profile/generic-remap shorthand.
- ObjectImageControlPane consumes/copies the value and does not own parsers UID0004LK/UID0004LL/UID0004LM. Existing class score, owner/emitter, inheritance, methods, and formal block remain unchanged.


## Status

- Confidence: strong for class role, principal method boundaries, source placement, descriptor type, constructor order, and paint dispatch; medium-high for exact original enum/member spellings and render-library preview flag names.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- Address range: [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- Parent attachment: enabled because this class page, its memory-range page, and the owning file page all meet the 80%+ completion/confidence gate.

## Class Purpose

`ObjectImageControlPane` is a `ControlPane`-derived image preview widget. It copies a 68-byte [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) snapshot, centers the resolved image inside its pane bounds, and paints human/avatar, monster, or item/EPF imagery depending on `ObjectStatusBlob::m_statusKind`.

## Layout Notes

| Offset | Field direction | Evidence |
| --- | --- | --- |
| `+0x108..+0x14b` | `ObjectStatusBlob m_objectStatus` / `m_imageStatus` | The constructor copies exactly `0x44` / 68 bytes from the caller descriptor, and paint dispatch reads blob offsets `+0`, `+4`, and `+6`. |
| `+0x130` | `m_objectStatus.m_displayStatusByte` / `defaultByte` | This is descriptor offset `+0x28`, not a separate pane render-state field. The constructor writes `0x50` before the full blob copy, so normal non-aliasing constructor inputs overwrite it with the caller-provided descriptor byte. |

Do not introduce a new source-owned `ObjectImageDescriptor` type for this class. A later header pass may choose a typedef/readability alias, but the strongest current owner for the copied layout is `ObjectStatusBlob`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)` | `0x00520540-0x005205b5` | Constructs a type `8` control pane, installs three vtable pointers, seeds descriptor byte `+0x28` to `0x50`, then copies the 68-byte `ObjectStatusBlob` snapshot. Caller push order confirms descriptor-first/bounds-second source order. |
| `void OnPaint()` | `0x005205c0-0x00520816` | Initializes `EPFTileContext`, sets draw color `0`, prepares the pane region through Surface callback slot `0x0069b3fc`, measures the descriptor-specific image, centers it, and dispatches to `NewHumanImageLib`, `MonsterImageLib`, or `ItemObjImageLib`; endpoint includes the final `retn`. |
| Adjustor thunks | `0x00520afd-0x00520b12` | Compiler-generated secondary-vtable thunks that forward to the scalar deleting destructor after this-pointer adjustment. |
| `ScalarDeletingDestructor` | `0x00520ca0-0x00520cdb`, size `0x3b` | Calls shared pane-base teardown `0x00544580`, checks scalar-delete flags, then conditionally frees through `0x004f4ac0` or the guarded sized/vector-delete helper `0x0041b6a0(this, 0x14c)`. |

## Evidence Notes

- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) documents the constructor field writes, the `OnPaint` descriptor branches, vtable refs, byte-boundary checks, and the associated non-contiguous thunks/destructor.
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) documents the broader source family and explains why the object-image button sibling belongs adjacent to this reusable preview control rather than in a generic button bucket.
- Constructor call sites from menu/dialog constructors and from `ObjectImageButtonPane::ObjectImageButtonPane` support a reusable control class instead of a single feature-dialog owner.
- The deleting destructor evidence resolves only the shared pane-base teardown helper plus conditional delete helper; generated `TextButtonExControlPane`/`Pane` labels remain owner-name pollution, not inheritance proof.
- B002 2026-06-19 sibling comparison confirms the plain `ObjectImageControlPane` scalar deleting destructor mirrors [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md), but this base wrapper passes complete-object size `0x14c` while the button subclass passes `0x150`. Both wrappers share inherited teardown `0x00544580`, ordinary delete helper `0x004f4ac0`, and guarded sized/vector-delete helper `0x0041b6a0`; the size difference supports the button subclass field extension rather than a separate source owner.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed constructor `0x00520540` size `0x75`, `OnPaint` `0x005205c0` size `0x256`, destructor thunks `0x00520afd`/`0x00520b08` size `0xb` each, and deleting destructor `0x00520ca0` size `0x3b`.
- `xrefs_to 0x00520540` reports 28 constructor call sites across menu/dialog/head-select/text/image-button families, including the [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) constructor path, which strengthens the reusable-control classification.
- `OnPaint` decompilation confirms the copied descriptor lives at `+0x108` and branches on descriptor type: type `0` uses the human image path, type `1` uses the monster image path, and type `2` uses the EPF/item image path before centering inside pane bounds.
- Vtable store/xref checks keep the three class vtable heads anchored at `0x0061f6c0`, `0x0061f728`, and `0x0061f758`; the paint slot is referenced at `0x0061f704`, and the deleting destructor is reached from the thunk pair and vtable data.
- B008 2026-06-19 source-quality reanalysis resolves the old descriptor blocker: [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) now uses `ObjectStatusBlob m_objectStatus` at `+0x108..+0x14b`, constructor signature `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`, corrected constructor endpoint `0x00520540-0x005205b5`, and first-draft constructor/paint C++. Vtable stores, adjustor thunks, scalar deleting destructor, and read-only vtable bytes remain compiler-generated support, not source method bodies.
- Object-image UI uses more specific render-dispatch aliases than the broad MapPane living-object wording: status kind `0` is human/avatar appearance through `g_pNewHumanImageLib`, kind `1` is monster appearance through `g_pMonsterImageLib`, and kind `2` is item/EPF appearance through `g_pItemObjImageLib`. Exact enum spellings remain descriptive.

## Attachment and Reconstruction State

- Attached to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) after the class page was refreshed from nearby by-file/by-memory evidence and raised above the child attachment gate.
- The accepted class CPP channel includes `ObjectImageControlPane.h` and all direct compile-visible dependencies before `[[CHILDREN]]`; exact constructor and `OnPaint` definitions remain on [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) and are assembled through that child route without duplication. The formal H channel is complete with the `ControlPane`-derived declaration, constructor, virtual `OnPaint`, protected `ObjectStatusBlob` member, and `0x14c` size guard. Remaining original lexical spellings cap confidence only and do not defer either formal channel.
- Keep `ObjectImageButtonPane` as a sibling class with its own page; this page should summarize the base preview behavior and point to the button subclass rather than absorbing its command handling.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-22 B010 Gate 2A contradiction repair: replaced active blank-CPP/header-pending wording with the accepted dependency-preamble plus `[[CHILDREN]]` CPP route and complete formal H declaration; preserved the older pre-closure statements below as dated history.
- 2026-06-06: Raised completion from `78` to `82`, attached the class to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), removed stale generated-source/Wave-derived framing from the evidence notes, and added an attachment/reconstruction-state section. Confidence stays `84` because the existing by-memory evidence proves behavior and ownership, while final field names and source-quality declarations remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor, paint, adjustor, and deleting-destructor functions at `0x00520540`, `0x005205c0`, `0x00520afd`, `0x00520b08`, and `0x00520ca0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate even though likely parent [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) passes the parent score gate.
- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, destructor support, constructor callers, and owner-pollution caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, `OnPaint`, non-contiguous thunks/destructor, descriptor rendering behavior, caller sources, and generated base-label pollution are documented; remaining gaps are detailed field names and full reconstructed C++.
- 2026-06-14: raised from `82/84` to `85/86` after live IDA MCP session `a001_goal2_class_batch` reconfirmed function sizes, broad constructor caller fan-in, descriptor-type paint branches, vtable heads/slots, and destructor thunk routing. Final C++ stays blank because source-quality descriptor field names and class declaration details remain unresolved.
- 2026-06-20 B002 Rule 26 cross-reference: score unchanged. Added sibling scalar-deleting-destructor comparison against [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md): same wrapper shape and helper roles, but `ObjectImageControlPane` size `0x14c` versus `ObjectImageButtonPane` size `0x150`.
- 2026-06-21 B008 Rule 26 source-quality incorporation: raised from `85/86` to `88/90`. The class page now records `ObjectStatusBlob m_objectStatus`, the corrected constructor range and signature, descriptor byte `+0x28` handling at object offset `+0x130`, precise image-library dispatch roles, and first-draft method-body readiness in the exact memory child while keeping class-level C++ blank to avoid duplicate emission.

## 2026-08-18 Accepted Class Closure

- The emitted declaration is complete and source-facing: direct `ControlPane` inheritance, constructor, virtual `OnPaint`, and one protected `ObjectStatusBlob m_objectStatus` member at `+0x108`; the size guard fixes `sizeof(ObjectImageControlPane) == 0x14c`.
- Primary/EventHandler/TimerHandler vtable heads are `0x0061f6c0`, `0x0061f728`, and `0x0061f758`. The primary paint slot `0x0061f704` reaches UID0001BU. Secondary/tertiary deleting entries route through the exact base adjustor page to the exact base scalar wrapper page.
- Source-authored children are constructor then `OnPaint` on UID0001BU. There is no handwritten destructor body: the four inherited-base vptr views, adjustor thunks, scalar deleting wrapper, RTTI, and vtable data are compiler consequences of the declaration and implicit virtual destructor.
- The CPP channel supplies `ObjectImageControlPane.h` plus direct compile-visible includes for DialogPane, Event, ScreenPane, EPFTileContext, GrafPort, ImageLib, ItemObjImageLib, MonsterImageLib, NewHumanImageLib, Surface, and Windows before `[[CHILDREN]]`. The H channel supplies only this first class fragment. UID00009N follows at source position 20, so the generated header closes the derived declaration without duplicate includes or declarations.
- Completion/confidence `94/94` reflects exact layout, three vtables, two authored methods, compiler split, complete H/CPP route, and generated size/declaration verification; only original lexical spellings and rebuilt-binary comparison remain capped.
