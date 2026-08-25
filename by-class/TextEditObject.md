*** UID:0000EN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class TextEditPane;
struct TextEditLineRecord;
struct TextRunFormatData;

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

class TextEditObject : public LObject
{
public:
    TextEditObject(void *ownerHandle);
    virtual ~TextEditObject();

    int GetObjectType() const;
    void GetPayloadPair(int *outPair) const;
    void *GetOwnerHandle() const;
    void SetPayloadPair(int first, int second);

    virtual void OnUpdate();
    virtual void OnMouseEvent(Event *event,
                              bool repeatedClick,
                              unsigned int messageTime);

protected:
    friend class TextEditPane;
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);

    int m_objectType;
    void *m_ownerHandle;
    int m_payload0;
    int m_payload1;
};

typedef char TextEditObjectSizeMustBe14[
    (sizeof(TextEditObject) == 0x14) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextEditObject

## Status

- Current UID0000OJ incorporation: the complete declaration and exact `0x14` size assertion are formal H, not pre-include CPP. UID0000EO inserts this authoritative class page at explicit pre-TextEditPane H position 10 under the merged UID0000ON TextEditPane source family; method bodies remain on their exact source-bearing children.
- Confidence: very strong for class behavior, vtable identity, support-object placement, core method child ownership, `LObject` inheritance, scalar deleting destructor, and the target-proven second virtual hook signature; medium-high for the first no-op hook product name and exact original header/source split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) and scalar deleting destructor `0x00595670-0x005956ae`
- Current recovered file: `source-3/simroot_v2/class_TextEditObject.cpp`
- Formal C++: declaration-container only. Method bodies remain owned by [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) and sibling exact rows.

## UID0000OJ Whole-File Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-462 | Exact `TextEditObject` `0x14` layout/declaration moved from CPP to H. |
| C0000OJ-505 | Complete methods, fields, callback friendship, and size assertion preserved once through UID0000EO's pre-class H child route at position 10. |

## Class Purpose

`TextEditObject` is the base object for text-edit payloads or inline objects. It derives from `LObject`, stores an object-type/state dword, an owner/handle pointer, and a two-dword opaque payload pair, installs a `TextEditObject` vtable, and provides source-empty virtual hooks that derived classes can override or inherit.

Both the file-local cdecl measurement callback and compiler-retained private TextEditPane measurement members consume protected `m_payload1` as embedded-object advance width. The class therefore preserves the exact callback friend and adds `friend class TextEditPane`; payload storage remains protected and no synthetic accessor or public-field weakening is introduced.

## Observed State

IDA-backed field usage and the [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) child currently support this base layout:

```text
+0x000  vtable
+0x004  `m_objectType`, descriptive object-type/state field returned by 0x00594eb0
+0x008  `m_ownerHandle`, descriptive owner/handle pointer copied from the constructor argument and returned by 0x00594ee0
+0x00c  `m_payload0`, first opaque payload/position word
+0x010  `m_payload1`, second opaque payload/position word
```

These names are source-facing reconstruction names, not original-proof spellings. Older documentation used `m_state`, `m_ownerOrType`, `m_payloadA`, and `m_payloadB`; those remain useful historical assumptions, but B011's child-level reanalysis narrows the active names because the constructor stores one owner/handle-like argument at `+0x08`, the `+0x04` accessor exposes an object-type/state field, and the `+0x0c/+0x10` helpers treat the remaining fields as an opaque pair. Keep the class emitted through [UID:0000ON][TextEditPane](by-file/TextEditPane.md); the support object is part of the text-edit implementation module until file-level evidence proves a standalone source file.

The payload pair remains protected. `TextRunMeasureCallback` receives exact function friendship because the shipped cdecl callback directly loads `m_payload1` at `+0x10` when an inline object supplies run width. `TextEditPane` receives class friendship because private raw members including [UID:0003FC][0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw](by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md) perform the same protected load through `format->object`. These source-legal routes preserve observed access without making fields public, inventing `GetPayload1()`, or weakening source into raw offsets. `DrawTextRunCallback` needs only public virtual `OnUpdate()` and is not a friend here.

2026-06-30 B004 revision note: the stale `RectBounds` / `Draw(GrafPort*)` / `GetBounds` / `SetBounds` declaration shape is rejected. It conflicts with this accepted `m_objectType` / `m_ownerHandle` / payload-pair layout, with [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) field evidence, with [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) inline-object dispatch, and with [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) using `m_payload1` as an embedded-object advance value while preserving the payload-pair interpretation.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00594e60-0x00594e99` | `TextEditObject::TextEditObject(void* ownerHandle)` | Raw constructor-shaped body; calls [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md), stores the caller argument at `+0x08`, installs vtable `0x0062e048`, and clears `+0x04/+0x0c/+0x10`. |
| `0x00594ea0-0x00594eab` | `TextEditObject::~TextEditObject()` non-deleting body | Reinstalls `TextEditObject` vtable and tail-jumps/chains to [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md); no delete-flag test and no operator-delete call. |
| `0x00594eb0-0x00594eb4` | `TextEditObject::GetObjectType() const` | Returns the dword at `+0x04`; `GetKind()` remains a possible shorter alias, but `object type` better fits current support-object evidence. |
| `0x00594ec0-0x00594ed5` | `TextEditObject::GetPayloadPair(int* outPair) const` | Copies `+0x0c/+0x10` into the caller-provided output pair. |
| `0x00594ee0-0x00594ee4` | `TextEditObject::GetOwnerHandle() const` | Returns the dword/pointer at `+0x08`. |
| `0x00594ef0-0x00594f03` | `TextEditObject::SetPayloadPair(int first, int second)` | Writes caller-provided values to `+0x0c/+0x10`. |
| `0x00594f10-0x00594f11` | `TextEditObject::OnUpdate()` provisional | Source-empty no-op virtual hook at vtable slot `0x0062e054`; [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) now proves it is dispatched for inline text objects and suppresses plain text drawing, but exact product name remains provisional. |
| `0x00594f20-0x00594f23` | `TextEditObject::OnMouseEvent(Event *,bool,unsigned int)` | Source-empty no-op virtual hook at vtable slot `0x0062e058`, also reused by [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md). UID00030E is the sole semantic caller: it passes the current Event pointer, strict repeated-click predicate, and stored message time for an inline object selected by the active one-character range. |
| `0x00595670-0x005956ae` | scalar deleting destructor | Vtable entry at `0x0062e048`; reinstalls base vtable, runs `LObject` cleanup, and conditionally deletes or sized-deletes according to scalar-delete flags. |

Friendship is declaration-only and introduces no executable method, field, size, padding, vtable, or child range. It makes existing UID0003FC and sibling TextEditPane member definitions legal while preserving this exact method family.

## Evidence Notes

- `EPFTextEditObject` inherits the same base shape and initializes `TextEditObject` fields before loading symbol frames.
- The class is tightly located next to `TextEditScrap` and `EPFTextEditObject`, supporting placement under the text-edit implementation module.
- 2026-06-06 live IDA MCP `lookup_funcs` confirms `0x00594e60` is still not promoted as an IDA function, while `0x00594f10` is `nullsub_58` size `0x1`, `0x00595670` is a `0x3e` scalar deleting destructor, neighboring `EPFTextEditObject` constructor `0x005954c0` is size `0xd0`, and `TextEditScrap` constructor `0x00594f30` is size `0x38`.
- 2026-06-06 raw IDA disassembly of `0x00594e60` shows a complete constructor-shaped body: call `0x004f4a80`, store the constructor argument at `+0x08`, write `??_7TextEditObject@@6B@` at `+0x00`, clear `+0x04`, `+0x10`, and `+0x0c`, then `retn 4`.
- 2026-06-06 IDA `xrefs_to 0x0062e048` reports the constructor vtable store at `0x00594e77`, cleanup helper store at `0x00594ea0`, `EPFTextEditObject` base-vtable restore at `0x00595590` and `0x00595636`, and `TextEditObject` destructor restore at `0x00595676`.
- 2026-06-06 vtable dword read shows `0x0062e048 -> 0x00595670`, `0x0062e04c -> 0x004f4b10`, `0x0062e050 -> 0x0041b6c0`, `0x0062e054 -> 0x00594f10`, and `0x0062e058 -> 0x00594f20`; `0x0062e05c` begins the adjacent `TextEditScrap` RTTI locator.
- IDA reports no direct code callers for the raw constructor, no-op hooks, or scalar deleting destructor. The destructor and no-op hook are vtable-reached; construction is evidenced by raw code and derived support-object initialization rather than direct caller xrefs.
- 2026-06-12 A004 live IDA MCP `entity_query` and `trace_data_flow` reconfirm `??_7TextEditObject@@6B@` at `0x0062e048`, first slot `0x00595670`, and xrefs at `0x00594e77`, `0x00594ea0`, `0x00595590`, `0x00595636`, and `0x00595676`; exact child [UID:0003GA][0x0062e044-0x0062e05c.TextEditObjectVtableData](by-memory/0x0062e044-0x0062e05c.TextEditObjectVtableData.md) is now split and routed here.
- 2026-06-21 B011 Rule 26 incorporation split [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md) and created [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) as the direct class-method child for the constructor, non-deleting destructor body, accessors, payload helpers, and no-op virtual hooks.
- B011 local PE range checks confirm the child ends at `0x00594f23`, followed by thirteen `0xcc` bytes at `0x00594f23-0x00594f30` before [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md).
- The first no-op hook name `OnUpdate()` remains descriptive. The second hook is no longer provisional: UID00030E proves `OnMouseEvent(Event *,bool,unsigned int)` through the only semantic callsite and current Event ABI. Historical `OnAction(int,int,int)` wording is superseded because it erased the pointer and bool types consumed at that callsite.
- 2026-06-26 B006 [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) implementation adds a live draw-callback callsite for vtable slot `+0x0c` / `0x0062e054`. When `TextRunFormatData::object` at `+0x08` is non-null, `DrawTextRunCallback` dispatches this slot and returns without drawing the ordinary UTF-16 segment. This strengthens the hook as an inline-object draw/update callback, but the accepted source-facing name remains provisional `OnUpdate()` until a dedicated support-object pass renames the virtual.
- 2026-08-22 B003 UID0003FC source-quality evidence confirms the raw private member's object branch at `0x00593d15-0x00593d25`: `TextRunFormatData::object +0x08` is tested and protected `TextEditObject::m_payload1 +0x10` supplies run width. The sibling raw member family establishes that this is class-level TextEditPane access, not another file-local callback signature, so `friend class TextEditPane` is the narrow source-legal declaration.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md)
- [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md)
- [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:0003FC][0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw](by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:00026O][0x0062df94-0x0062e268.TextEditReadOnlyData](by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md)
- [UID:0003GA][0x0062e044-0x0062e05c.TextEditObjectVtableData](by-memory/0x0062e044-0x0062e05c.TextEditObjectVtableData.md)

## Changes

- 2026-08-22 B003 UID0003FC support implementation: preserved `94/94`, the exact `0x14` layout, protected payload pair, callback friendship, class/file ownership, and single H emitter; added only `friend class TextEditPane` plus the raw-member access evidence needed to make UID0003FC and sibling member payload reads source-legal.
- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: set explicit H child position 10 under UID0000EO so this page is the sole TextEditObject definition and precedes TextEditScrap and TextEditPane in generated H.

- 2026-07-20 B002 UID00030E accepted implementation callback:
  - Raised the class from `89/92` to `90/93` while retaining UID0000ON ownership/emission, reconstructable true, blank position, inheritance, full layout, callback friendship, and all unrelated methods.
  - Added the source-safe `Event` forward declaration and replaced only provisional `OnAction(int,int,int)` with target-proven `OnMouseEvent(Event *,bool,unsigned int)` at the same vtable position.
  - Preserved `OnAction` as a rejected historical alias: UID00030E's sole semantic inline-object call carries an Event pointer, strict repeated-click bool, and message-time dword, so the generic triple-int spelling loses source types.

- 2026-07-19 B001 UID0002ZY accepted implementation callback:
  - Score changed from `88/90` to `89/92`; owner/emitter UID0000ON, reconstructable true, blank position, and existing method/layout union remain unchanged.
  - Installed the accepted declaration block with exact forward declarations, generic measure-callback prototype, and protected friend declaration.
  - Preserved `m_payload0/m_payload1` as protected and retained every existing method, vtable, source placement, derived-object, history, and provisional virtual-name fact.
  - Rejected public payload fields, synthetic accessor substitution, and raw-offset access because exact callback friendship preserves the direct live `+0x10` load in compilable source.

- 2026-06-30 B004 corrected TextEditPane support declaration:
  - Before: `87/90`, formal C++ blank; implementation pause rejected a stale report proposal that would have used `RectBounds`, `Draw`, `GetBounds`, and `SetBounds`.
  - After: `88/90`, formal declaration-container C++ inserted for the current accepted layout and method family: `m_objectType`, `m_ownerHandle`, `m_payload0`, `m_payload1`, `GetObjectType`, `GetPayloadPair`, `GetOwnerHandle`, `SetPayloadPair`, provisional `OnUpdate`, and provisional `OnAction`.
  - Evidence: current class page, executed B011 [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) split evidence, executed B006 inline-object draw callback route, and executed B007 measure callback payload use all support the payload/object-type declaration and reject the stale rectangle/bounds declaration. Method bodies remain on exact child rows.

- 2026-06-21 B011 Rule 26 split incorporation:
  - Before: `85/88`, field names still broad/provisional and the pre-TextBoxPane methods were only described through the mixed [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md) page.
  - After: `87/90`; added direct method child [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md), refined active field names to `m_objectType`, `m_ownerHandle`, `m_payload0`, and `m_payload1`, and documented the no-op virtual hook names as provisional.
  - Evidence: B011 local PE/range reanalysis, existing vtable docs, `LObject` constructor/destructor pages, and prior live IDA function/raw-pocket evidence support first-draft child C++ while keeping this class page's top-level C++ blank.

- 2026-06-26 B006 DrawTextRunCallback inline-object hook sync:
  - Score, owner/emitter, and class formal C++ unchanged at `87/90`, [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Added [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) as callsite evidence for vtable slot `+0x0c` / provisional `TextEditObject::OnUpdate()`.
  - Evidence: B006 MCP session `80de0a67` confirmed `TextRunFormatData::object` at `+0x08`; a non-null object dispatches the slot and skips plain text drawing. The provisional method name is preserved pending a dedicated support-object rename pass.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the no-op virtual stub at `0x00594f10` and scalar deleting destructor at `0x00595670`; `0x00594e60` remains a raw non-function constructor start within the documented support-object cluster. The likely parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md) passes 80/80, but this class page is only `76/78`, so the child-side parent gate does not pass. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page documents the base-object role, likely owner, constructor/no-op/destructor ranges, inheritance context, and support-object memory cluster; completion remains limited because exact file split and derived-object field semantics are not fully detailed.

- 2026-06-06 live IDA vtable/support-object pass:
  - Before: the class page stayed below the parent-attach gate and omitted the base helper/accessor island, exact vtable slots, and constructor raw-disassembly evidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Evidence: live IDA MCP confirmed the raw constructor body, helper/accessor island, `nullsub_58`/`nullsub_59` slots, scalar deleting destructor, vtable dwords, `TextEditScrap` boundary at `0x0062e05c`, and matching base-vtable restores from `EPFTextEditObject`. C++ remains blank because exact field names and source-quality declarations are below the 95/95 reconstruction-code gate.
- 2026-06-12 A004 Batch 277:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`; parent remains [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Evidence: live IDA MCP reconfirmed the exact vtable child, first-slot destructor target, five vtable xrefs, and owner-code boundaries. The exact vtable child [UID:0003GA][0x0062e044-0x0062e05c.TextEditObjectVtableData](by-memory/0x0062e044-0x0062e05c.TextEditObjectVtableData.md) is now assigned here because both child and direct class parent clear the strict `85/85` gate.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Score unchanged at `85/88`; final C++ remains blank.
  - Added descriptive source-facing field names `m_state`, `m_ownerOrType`, `m_payloadA`, and `m_payloadB` while preserving [UID:0000ON][TextEditPane](by-file/TextEditPane.md) source placement.
  - Evidence: B005 report confirmed these are useful reconstruction names for the support object but not original-proof enough to raise this class to method-body C++ readiness.
