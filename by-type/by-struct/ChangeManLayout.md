*** UID:0001TW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChangeMan : public LObject {
public:
    ChangeMan();
    virtual ~ChangeMan();

    void Register(LObject *owner,
                  LObject *listener,
                  MessageType messageType,
                  bool allMessages);
    void Unregister(LObject *owner,
                    LObject *listener,
                    MessageType messageType,
                    bool allMessages);
    void DispatchMessage(LObject *owner, Message *message);
    void UnregisterObject(LObject *object);
    bool HasRegistrationForObject(LObject *object);

private:
    SortedList *m_changeList;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangeMan Layout

## Status

- Confidence: strong for field offsets, allocation size, complete observed method surface, concrete shared types, and callback ownership; retained predicate spelling/visibility remain inferred.
- Owner class: [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- Parent attachment: attached to [UID:00001K][ChangeMan](by-class/ChangeMan.md), which now clears the strict route gate at `85/89` and emits through [UID:0000I2][ChangeMan](by-file/ChangeMan.md).
- Evidence: IDA constructor/destructor decompilation, `Application::Initialize` allocation site, and `g_pChangeMan` xrefs.
- Reconstructable: yes, as source-level class layout information. The formal declaration uses the established `LObject`, `Message`, `MessageType`, `bool`, and `SortedList` contracts; no separate listener interface or scope enum is required.

## Layout

```text
0x00  LObject/vtable
0x04  SortedList* changeList
0x08  end of object / sizeof(ChangeMan)
```

`Application::Initialize` allocates `0x08` bytes and calls `ChangeMan::ChangeMan` at `0x004644c1`. The constructor calls `LObject` setup, publishes `this` through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), installs the [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md), allocates a 24-byte [UID:0000DF][SortedList](by-class/SortedList.md), and stores the returned list pointer at `+0x04`.

## Registration Storage

The list is constructed as `SortedList(0x10, CompareChangeEntries, 100)`. Each row is a 16-byte [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md):

```text
0x00  owner
0x04  listener
0x08  bool allMessages; natural padding through +0x0b
0x0c  MessageType messageType
```

The comparator at `0x0047ef20` sorts only by the `owner` field. Register/unregister/dispatch methods use the list through virtual container calls rather than embedding list storage in the `ChangeMan` object itself. [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md) reads the same list pointer, reverse-scans its rows, and tests both `owner` and `listener` without mutation.

## Teardown

The scalar deleting destructor at `0x0047ef50` writes the `ChangeMan` vtable, destroys `changeList` through its virtual destructor with delete flag `1`, clears the `+0x04` field, clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), chains to `LObject` cleanup, and optionally frees the object.

The constructor cleanup fragment at `0x0047ed20-0x0047ed50` performs the same partial-list cleanup and singleton clear during exception unwind. It is compiler-generated cleanup, not handwritten source behavior.

The ordinary source destructor is now emitted on [UID:00001K][ChangeMan](by-class/ChangeMan.md); this layout page keeps the declaration surface and the exact `SortedList *m_changeList` member at `+0x04`.

## 2026-07-13 B003 UID0000ZW Family Synchronization

- ChangeMan remains exactly eight bytes: its `LObject` base/vptr occupies `+0x00` and `SortedList *m_changeList` occupies `+0x04`. Allocation size, constructor stores, ordinary destructor, compiler cleanup, scalar deleting wrapper, and singleton lifecycle all agree.
- The backing list remains external and is constructed with 16-byte elements, the owner-only `CompareChangeEntries` callback, and page size 100. The list element is now source-modeled as two `LObject *` pointers, `bool allMessages`, natural three-byte x86 padding, and `MessageType`.
- Register and filtered unregister use `(LObject *owner, LObject *listener, MessageType messageType, bool allMessages)`. Dispatch uses `(LObject *owner, Message *message)`. Broad unregister and the retained membership predicate use `LObject *object`.
- `allMessages == true` is the wildcard path and `allMessages == false` is the message-type path. Invalid byte values remain documented binary negative evidence, not a reason to expose a source enum. `MessageType` is the existing 32-bit tag type compared with `Message::m_type`.
- Listener dispatch through primary vtable slot `+0x08` is the common `LObject::OnChangeMessage(LObject *, Message *)` contract. AboveFrame, FramePartPane, MapPane, and VideoPlayerPane replace that exact slot; no secondary interface adjustment occurs.
- The source file remains `NexusTK/app/ChangeMan.cpp`. The three adjacent public forwarding methods are inherited LObject methods emitted from `NexusTK/util/LObject.cpp`, not ChangeMan-local or Application-owned helpers.
- Compiler artifacts remain excluded from this source declaration: no scalar deleting destructor, constructor-EH fragment, vtable bytes, singleton-clear helper, explicit record padding, or aggregate-index body is emitted here.

## IDA MCP Evidence

- 2026-05-31 decompilation of `0x0047ec70` confirms constructor setup: `LObject` initialization, [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) / `dword_67AB2C` publication, `ChangeMan` vtable install, 24-byte `SortedList` allocation, and `SortedList(16, sub_47EF20, 100)` stored at `this + 4`.
- 2026-05-31 decompilation of `0x0047ef50` confirms the scalar deleting destructor reads `Block[1]`, installs the `ChangeMan` vtable, calls the list virtual destructor with delete flag `1`, clears `Block[1]`, clears `dword_67AB2C`, calls `LObject` cleanup, and optionally frees the object.
- 2026-05-31 decompilation of `0x0047ed50` and `0x0047ee20` confirms all registration/dispatch methods use `this[1]` as the external sorted-list pointer rather than embedded list storage.
- 2026-06-16 live IDA refresh reconfirmed constructor `0x0047ec70-0x0047ed20`, register `0x0047ed50-0x0047ed80`, filtered unregister `0x0047ed80-0x0047ee18`, dispatch `0x0047ee20-0x0047ee95`, broad unregister `0x0047eea0-0x0047eedf`, comparator `0x0047ef20-0x0047ef3f`, singleton clear `0x0047ef40-0x0047ef4b`, and scalar deleting destructor `0x0047ef50-0x0047efae`. `xrefs_to 0x0067ab2c` still reports the same 11 singleton refs from Application cleanup, BackPane teardown, constructor/cleanup/destructor writes, and Application wrappers.
- The same pass saved source-quality IDA labels for the ChangeMan lifecycle/method helpers, Application wrapper call surface, and `g_pChangeMan`. Member/type edits were skipped because the final `SortedList` declaration, listener interface name, and public API signatures still need a source-header pass.
- 2026-07-12 bounded raw disassembly confirms the complete retained method at `0x0047eee0-0x0047ef1f`: it loads `m_changeList` at `+0x04`, starts at count minus one, retrieves each 16-byte row, and returns true for either owner or listener equality. IDA has no modeled function, xref, pointer route, named ChangeMan type, or source symbol for it.

## Score Rationale

Completion is `92` because the complete object size, vtable base, singleton lifecycle, `+0x04` list pointer, constructor allocation, destructor cleanup, comparator-driven record storage, concrete full method surface, LObject callback ownership, source route, and first-draft class declaration are documented and cross-linked. Confidence is `94`; only exact original private spellings and predicate visibility/const qualification remain inferred, not field offsets, object size, types, or behavior.

## Historical 2026-07-01 B009 Empty-Emitter Implementation

B009's accepted empty-emitter report populated the formal first-draft `ChangeMan` class declaration and raised the score to `88/91`. The declaration deliberately keeps only the source-level layout and public method surface: `LObject` base, constructor, ordinary virtual destructor, register/filtered-unregister/dispatch/broad-unregister methods, and private `SortedList *m_changeList`. It does not include scalar deleting destructor wrapper details, vtable bytes, constructor EH lowering, or exact header/source split decisions.

## Historical 2026-07-12 B001 Predicate Declaration Sync

- Added `bool HasRegistrationForObject(void *object);` to the accepted class declaration and raised score `88/91 -> 89/92`.
- The method name is descriptive. Its read-only behavior does not prove original `const` qualification, and no documented const-correct `SortedList` interface supports adding one to the first draft.
- No field or object-size change is implied; the method uses existing `m_changeList` and `ChangeManEntry` owner/listener fields.

## Open Questions

- Final source should decide whether the global singleton pointer is exposed directly or hidden behind a manager accessor/template wrapper.
- Exact original private member and retained-predicate spellings remain unavailable; current names are descriptive and do not affect the established layout or callback contract.

## Cross-References

- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md)

## Changes

- What existed before: the layout table described `0x08` as `end / allocated size`, and the page was scored unevaluated.
- What changed: `0x08` is now explicitly described as the end of the 8-byte object, the page is marked reconstructable, and the evidence section records live IDA MCP constructor/destructor checks.
- Summary/evidence: IDA MCP rechecked constructor `0x0047ec70`, registration/dispatch helpers `0x0047ed50` and `0x0047ee20`, comparator `0x0047ef20`, and scalar deleting destructor `0x0047ef50`.

- 2026-06-06: Completion/confidence changed from `78/89` to `82/90`, and `AUTOGEN_PARENT_UID` was set to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
  - Before: the page had enough constructor/destructor/list evidence for attachment, but the metadata stayed below the parent-child gate and the manual by-struct coverage row still described an old `50%` state.
  - After: the page records the attachment gate, score rationale, and coverage report sync.
  - Evidence: existing documented IDA MCP checks cover the 8-byte allocation, `this + 4` `SortedList*`, singleton publication/clear, destructor list release, and registration/dispatch calls through the external list pointer.
- 2026-06-16 C001: Completion changed from `82` to `85`.
  - Evidence: live IDA reconfirmed the constructor/destructor/method/comparator/helper boundaries, the 11-ref singleton lifecycle/consumer set, external `SortedList*` ownership at `+0x04`, and the 16-byte registration record flow. Safe IDA names were saved for the documented function/global symbols; type/member mutations remain blocked by provisional listener and `SortedList` declaration names.
- 2026-07-01 B009 empty-emitter implementation:
  - Changed score from `85/90` to `88/91`.
  - Evidence: populated formal first-draft `ChangeMan` class declaration with `SortedList *m_changeList` at `+0x04`, source method surface, and ordinary virtual destructor while preserving source-name/header caveats.
- 2026-07-12 B001 accepted UID0000ZU callback:
  - Changed score `88/91 -> 89/92`, added the retained UID0004I6 predicate declaration/evidence, and preserved the exact 8-byte object layout and source-name caps.
- 2026-07-13 B003 UID0000ZW implementation:
  - Changed score `89/92 -> 92/94` and synchronized the complete class surface to `LObject`, `Message`, `MessageType`, `bool allMessages`, and natural record padding.
  - Evidence: complete register/unregister/dispatch/object-cleanup/predicate family, primary LObject callback slot, confirmed derived overrides, constructor element-size/comparator arguments, and inherited LObject wrapper routes.
