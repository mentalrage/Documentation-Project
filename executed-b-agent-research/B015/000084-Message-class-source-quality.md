** TARGET-REPORT-UID:000084 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000084] Message Class Source-Quality Reanalysis

Agent: B015  
Assignment target: `by-class/Message.md`  
Report path: `tools/leaser/Agents/Agent-B015/research/000084-Message-class-source-quality.md`  
Mode: report-only source-quality pass. No `by-*` documentation, generated file, or coverage report was edited.

## Executive Recommendation

Raise [UID:000084] `Message` from `COMPLETION:85 / CONFIDENCE:86` to `COMPLETION:88 / CONFIDENCE:90` after implementation. The score should not go above that yet because the raw typed-entry helper band has no static caller or pointer route in the PE scan, the original source names for the twelve typed entry kinds are not proven, and the final tiny-model-file-vs-MessageDialogs placement remains a documented source-placement ambiguity. The binary behavior, layout, constructor/destructor shape, raw helper inventory, `Message::m_type` role, `SortedList` ownership, and compare/sequence semantics are now strong enough for a declaration-level first draft on the class page and detailed support incorporation in [UID:0002Y5] `MessageCore`.

Keep `CANONICAL_OWNER:0000LA` and `EMITTER_UIDS:0000LA` for now. The best current repository route remains [UID:0000LA] `MessageDialogs`, but the report should explicitly preserve a lower-confidence future candidate for a tiny generic `Message`/`MessageModel` source file if a later pass finds real non-dialog API consumers of the raw entry helpers. Do not move the class to `MessageShowPane`, `ChangeMan`, `Application`, or `SortedList`.

Class-page C++ should be added as a declaration-only draft. Method bodies and raw helper overload bodies should remain deferred to [UID:0002Y5] until the helper band is split or the source-route policy is accepted. The scalar deleting destructor is compiler-generated and should not be emitted as source API.

## Evidence Checked

Primary target and support pages:

- `by-class/Message.md`
- `by-file/MessageDialogs.md`
- `by-memory/0x00520e30-0x00521d94.MessageCore.md`
- `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md`
- `by-class/MessageShowPane.md`
- `by-file/MessageShowPane.md`
- `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`
- `by-class/SortedList.md`
- `by-memory/0x004f3600-0x004f3681.SortedListConstructor.md`
- `by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md`
- `by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md`
- `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`
- `by-type/by-struct/ChangeManEntry.md`
- `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md`
- `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`
- `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`
- `by-memory/0x0061fa3c-0x0061fa4c.MessageVtableData.md`
- `by-class/LObject.md`

Generated and coverage evidence:

- `auto-generated/NexusTK/ui/dialogs/MessageDialogs.cpp`
- `auto-generated/simroot_v2/class_Message.cpp`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md` was read only for row text context and was not edited.

Prior B-agent reports checked:

- `tools/leaser/Agents/Agent-B002/research/executed/older/0000ZZ-000100-changeman-method-source-quality.md`
- B001/B015 report folders were searched for Message/MessageShowPane/ChangeMan references. No older Message-specific B015/B001 report was found that supersedes the current target. The B002 ChangeMan report supports keeping `Message::m_type` as a 32-bit message type/FourCC-like dispatch key, not as a fully named enum yet.

Binary evidence:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- `.text`: VA `0x00401000-0x0060c4ac`
- Capstone disassembly available and used locally for the target region.
- Local PE scan checked rel32 call/jump references, absolute VA dword references, and RVA dword references for every raw helper start in `0x00520f00-0x00521c80`.

## Current Documentation State

`by-class/Message.md` currently has `COMPLETION:85`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000LA`, `EMITTER_UIDS:0000LA`, and a blank C++ section. It correctly records the class as an `LObject`-derived base message object with `m_type` at `+0x04` and a `SortedList` pointer at `+0x08`, but it does not yet contain enough source-quality detail for the raw helper band, entry layout, source names, ownership decision, or first-draft declaration policy.

`by-memory/0x00520e30-0x00521d94.MessageCore.md` currently owns the exact methods and raw helper band, but it under-documents the 24 helper starts, the exact typed payload families, the no-route scan, and the strongest field/type names. Its existing no-code reasoning is partly stale: method bodies still should not be emitted wholesale, but the class declaration can now be drafted safely.

`by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md` is correctly audit-only and nonreconstructable. The split between Message and MessageShowPane is valid and should not be collapsed.

## Exact Range, Padding, And Modeling Status

The Message core child [UID:0002Y5] covers the half-open range `0x00520e30-0x00521d94`.

Confirmed subranges:

- `0x00520e30-0x00520ecb`: `Message::Message(uint32_t messageType)`. IDA-modeled/source-model function. Body ends at `0x00520ecb`; alignment padding `0x00520ecb-0x00520ed0`.
- `0x00520ed0-0x00520ef5`: `Message::~Message()`. IDA-modeled/source-model function. Body ends at `0x00520ef5`; alignment padding `0x00520ef5-0x00520f00`.
- `0x00520f00-0x00521c80`: raw typed entry insert/get helper band. This is code-shaped but not currently modeled as normal named functions in the source docs. It contains 24 function-shaped prologues, twelve insert helpers and twelve lookup helpers.
- `0x00521c80-0x00521cf6`: inserted-entry sequence normalizer. IDA-modeled/source-model function. Body ends at `0x00521cf6`; alignment padding `0x00521cf6-0x00521d00`.
- `0x00521d00-0x00521d35`: `CompareMessageEntries`. IDA-modeled/source-model callback. Body ends at `0x00521d35`; alignment padding `0x00521d35-0x00521d40`.
- `0x00521d40-0x00521d94`: scalar deleting destructor thunk/body for `Message`. Compiler-generated; should be documented but not hand-emitted as normal source API.

The adjacent aggregate [UID:0001C3] continues into MessageShowPane after padding `0x00521d94-0x00521da0`. That padding is a useful source boundary. `MessageShowPane` begins at `0x00521da0` and is a separate UI overlay source-family item, not part of the base Message model.

## Constructor, Destructor, And Vtable Behavior

`Message::Message(uint32_t messageType)` at `0x00520e30`:

- Calls `LObject` constructor at `0x004f4a80`.
- Installs the `Message` vtable pointer `0x0061fa3c` at `this+0x00`.
- Stores the constructor argument at `this+0x04`. This field is the dispatch message type consumed by `ChangeMan`.
- Allocates `0x18` bytes for a `SortedList`.
- If allocation succeeds, constructs the list with:
  - element size `0x98`
  - compare callback `0x00521d00`
  - page/initial allocation count `0x10`
- Stores the list pointer at `this+0x08`.
- If allocation fails, stores null at `this+0x08`.
- Returns `this` and uses `ret 4`.

Best source-facing layout for `Message`:

- `+0x00`: inherited `LObject` vptr, overridden by `Message` vtable.
- `+0x04`: `MessageType m_type` or current doc name `uint32_t m_type`.
- `+0x08`: `SortedList *m_entries` or `SortedList *m_pEntries`.
- Size: `0x0c`, confirmed by the scalar deleting destructor's guarded delete path.

`Message::~Message()` at `0x00520ed0`:

- Reinstalls the `Message` vtable.
- Loads `this+0x08`.
- If non-null, calls the pointed object's vtable slot 0 with scalar-delete flag `1`; this is the `SortedList` owned by `Message`.
- Clears `this+0x08` to null after deletion.
- Tails into `LObject` destructor at `0x004f4a90`.

`Message` scalar deleting destructor at `0x00521d40`:

- Repeats the owned-list teardown and base destructor.
- If `(flags & 1)` is clear, returns without deleting `this`.
- If `(flags & 1)` is set and `(flags & 4)` is clear, calls ordinary delete `0x004f4ac0`.
- If `(flags & 4)` is set, calls the guarded/sized delete helper `0x0041b6a0` with size `0x0c`.
- This is compiler-generated. Name it as scalar deleting destructor in docs/vtable support only; do not expose it as source-facing API.

Vtable data [UID:0003PB]:

- `??_7Message@@6B@` at `0x0061fa3c`.
- First slot points to `0x00521d40`.
- Later slots reuse base `LObject` slots at `0x004f4b10` and `0x0041b6c0`.
- Xrefs from constructor/destructor/scalar paths support the class identity.

## Caller And Reachability Evidence

Direct constructor calls found:

- `0x00464ab0` inside [UID:0002H1] `ApplicationCleanupResources`.
- `0x00467990` inside [UID:0002GX] `ApplicationSendShutdownMessage`.

Direct destructor calls found:

- `0x00464cac` inside [UID:0002H1] `ApplicationCleanupResources`.
- `0x004679aa` inside [UID:0002GX] `ApplicationSendShutdownMessage`.
- Exception/unwind style jumps/references also appear at `0x005fa82a` and `0x005faa0f`, but those are compiler support routes rather than normal source call sites.

Application/ChangeMan route:

- [UID:00019B] `ApplicationForwardMessage` pushes a `Message *` and owner pointer, reads `g_pChangeMan`, and calls ChangeMan dispatch.
- [UID:0002H1] builds a stack `Message` with message tag/value `0x7465726d`, documented as the cleanup/termination stack message, forwards it, then destroys it.
- [UID:0002GX] builds a stack `Message` with message tag/value `0x676f6f67`, forwards it, then destroys it.
- [UID:0000ZZ] `ChangeManDispatchMessage` compares listener records against `message->m_type` at `message+0x04` when the listener scope is type-specific.

Raw helper reachability:

- The PE scan checked all 24 raw helper starts for rel32 call/jump targets, absolute VA dword references, and RVA dword references across the PE image.
- No static caller, jump-table pointer, vtable pointer, callback pointer, or data-pointer route was found for any raw helper start in `0x00520f00-0x00521bc0`.
- This negative evidence means the helper band is almost certainly real source code that became unreferenced in this binary configuration, or an exported/API-like overload family that was compiled in but not used by the reachable client build. It is not enough evidence to delete the helpers or model them as generated compiler artifacts.
- The normalizer at `0x00521c80` has internal calls from insert helpers, so the raw helpers are cohesive and were compiled as functioning Message entry API code.

## SortedList Ownership And Entry Record Layout

The constructor creates a `SortedList` with element size `0x98`, compare callback `CompareMessageEntries`, and page size/count `0x10`. `Message` owns this `SortedList`; it is not a borrowed global list and not a `ChangeMan` list.

`SortedList` support pages confirm the layout and operations:

- [UID:0000DF] `SortedList` layout:
  - `+0x00` vtable
  - `+0x04` element size
  - `+0x08` page size
  - `+0x0c` count
  - `+0x10` data pointer
  - `+0x14` compare callback
- [UID:00037I] constructor is called from `Message` constructor at `0x00520e94`.
- [UID:00037J] sorted insert is called from the raw insert helpers.
- [UID:00037K] find-first-equal is called from the raw lookup helpers.

Best `MessageEntry` record layout from raw helpers and comparator:

| Offset | Size | Best name | Evidence |
|---:|---:|---|---|
| `+0x00` | 4 | `type` / `entryType` | Every raw helper writes a constant tag `0..0x0b`; comparator sorts by this dword first. |
| `+0x04` | `0x80` | `key[0x40]` as UTF-16/wchar key | Every helper copies the key argument into this field with the safe wide-copy helper at `0x005cd657`; comparator calls wide case-insensitive compare on this field. |
| `+0x84` | 4 | `sequence` / `duplicateOrdinal` | Insert helpers initialize to `0x7fffffff`, then normalizer rewrites to 0 or previous duplicate + 1; lookup helpers search an exact requested sequence. |
| `+0x88` | variable | payload union | Scalar helpers store dword/word/byte/pointer/length here; struct helpers copy 8 or 16 bytes here; string/blob helpers store length here. |
| `+0x8c` | variable | second payload word/pointer | Tag 6 stores a second dword; string/blob tags store allocated pointer here. |
| `+0x90-0x97` | variable | payload tail/reserved | Tag 7 writes a 16-byte payload starting at `+0x88`, covering through `+0x97`. |

The field at `+0x84` should not be named capacity/count. Its behavior is a per-key duplicate sequence/index used to keep same-type/same-key records sorted and individually retrievable.

The fixed `0x98` record size is a strong source type boundary. The helper band repeatedly allocates a stack local record of this shape, copies fields into it, inserts or searches the `SortedList`, and then reads/writes the payload.

## Raw Helper Band Inventory

The raw helper band is `0x00520f00-0x00521c80`. It is best modeled as a contiguous Message typed-entry accessor overload family. The functions are hand-code-shaped, not compiler thunks: they build typed records, call `SortedList`, allocate/copy string buffers for string/blob payloads, and normalize duplicate sequence numbers after insertion.

Insertion helpers:

| Span | Tag | Return bytes | Best descriptive role | Payload evidence |
|---|---:|---:|---|---|
| `0x00520f00-0x00520f70` | `0` | `ret 8` | add/insert tag-0 dword | Stores dword argument at entry `+0x88`. |
| `0x00520f70-0x00520fe0` | `1` | `ret 8` | add/insert tag-1 dword | Stores dword argument at entry `+0x88`. |
| `0x00520fe0-0x00521050` | `2` | `ret 8` | add/insert tag-2 word | Stores word argument at entry `+0x88`. |
| `0x00521050-0x005210c0` | `3` | `ret 8` | add/insert tag-3 word | Stores word argument at entry `+0x88`. |
| `0x005210c0-0x00521130` | `4` | `ret 8` | add/insert tag-4 byte | Stores byte argument at entry `+0x88`. |
| `0x00521130-0x005211a0` | `5` | `ret 8` | add/insert tag-5 byte | Stores byte argument at entry `+0x88`. |
| `0x005211a0-0x00521210` | `6` | `ret 0x0c` | add/insert two-dword or point-pair payload | Stores two dword arguments at `+0x88` and `+0x8c`; lookup miss defaults through point-pair initializer. |
| `0x00521210-0x00521280` | `7` | `ret 8` | add/insert 16-byte rect/bounds payload | Copies 16 bytes from caller pointer to `+0x88` with SIMD move; lookup miss defaults through rect initializer. |
| `0x00521280-0x005212f0` | `8` | `ret 8` | add/insert tag-8 dword or pointer | Stores dword/pointer argument at `+0x88`. |
| `0x005212f0-0x00521360` | `9` | `ret 8` | add/insert tag-9 dword or pointer | Stores dword/pointer argument at `+0x88`. |
| `0x00521360-0x00521420` | `10` | `ret 8` | add/insert owned wide string | Calculates UTF-16 length, allocates `(len * 2) + 2`, copies value, null terminates; stores length at `+0x88` and buffer pointer at `+0x8c`. |
| `0x00521420-0x005214d0` | `11` | `ret 0x0c` | add/insert owned counted blob/buffer | Allocates exact byte length, copies caller buffer, stores length at `+0x88` and pointer at `+0x8c`. |

Lookup helpers:

| Span | Tag | Return bytes | Best descriptive role | Miss/default behavior |
|---|---:|---:|---|---|
| `0x005214d0-0x00521570` | `0` | `ret 0x0c` | try-get tag-0 dword | Writes `0` to output on miss. |
| `0x00521570-0x00521610` | `1` | `ret 0x0c` | try-get tag-1 dword | Writes `0` to output on miss. |
| `0x00521610-0x005216b0` | `2` | `ret 0x0c` | try-get tag-2 word | Writes `0` to output on miss. |
| `0x005216b0-0x00521750` | `3` | `ret 0x0c` | try-get tag-3 word | Writes `0` to output on miss. |
| `0x00521750-0x005217e0` | `4` | `ret 0x0c` | try-get tag-4 byte | Writes `0` to output on miss. |
| `0x005217e0-0x00521870` | `5` | `ret 0x0c` | try-get tag-5 byte | Writes `0` to output on miss. |
| `0x00521870-0x00521920` | `6` | `ret 0x0c` | try-get two-dword/point-pair payload | Miss path initializes destination through the project point-pair initializer with zeros. |
| `0x00521920-0x005219c0` | `7` | `ret 0x0c` | try-get 16-byte rect/bounds payload | Miss path initializes destination through the project rect/bounds initializer with zeros. |
| `0x005219c0-0x00521a60` | `8` | `ret 0x0c` | try-get tag-8 dword or pointer | Writes `0` to output on miss. |
| `0x00521a60-0x00521b00` | `9` | `ret 0x0c` | try-get tag-9 dword or pointer | Writes `0` to output on miss. |
| `0x00521b00-0x00521bc0` | `10` | `ret 0x10` | try-get owned wide string into caller buffer with in/out length | On hit copies `min(storedLen, *inoutLen)` UTF-16 chars, writes actual count back, null terminates; on miss writes empty string and zero count. |
| `0x00521bc0-0x00521c80` | `11` | `ret 0x10` | try-get owned counted blob/buffer into caller buffer with in/out length | On hit copies `min(storedLen, *inoutLen)` bytes and writes actual count back; on miss writes zero count. |

Important caveat: the table above uses start-to-next-start spans for raw helper splitting. Several lookup helpers contain success and miss returns before final alignment padding, so the implementation callback should preserve body-end and padding bytes when creating exact child pages.

Raw helper callees/names checked:

- `0x005cd657`: safe wide-character key copy, already documented as `_wcscpy_s`-like.
- `0x005de165`: case-insensitive wide compare, `_wcsicmp`-like.
- `0x004f3690`: `SortedList::InsertSorted` / `SortedListInsertSorted`.
- `0x004f3780`: `SortedList::FindFirstEqual` / `SortedListFindFirstEqual`.
- `0x00521c80`: inserted-entry sequence normalizer.
- `0x00516030`: `GetMemoryMan`.
- `0x00516050`: `AllocateBufferMemory`.
- `0x00516220`: memory-copy wrapper used by string/blob payload copies.
- `0x004b7c30`: project point-pair initializer used as tag-6 miss default.
- `0x004b7c50`: project rect/bounds initializer used as tag-7 miss default.
- `0x005c772f`: compiler security-cookie check on helpers using protected stack locals.

## Sequence Normalizer And Compare Callback

`0x00521c80-0x00521cf6` is best named `NormalizeInsertedEntrySequence` or `Message::NormalizeInsertedEntrySequence`.

Behavior:

- Called after a raw insert helper inserts a stack-built record into `m_entries`.
- Takes/uses the inserted index returned from `SortedList::InsertSorted`.
- Fetches the inserted entry through the list's indexed accessor vtable slot.
- If the inserted index is greater than zero, fetches the previous entry.
- If previous and current entries have identical `type` and case-insensitive identical `key`, sets current `sequence` to `previous.sequence + 1`.
- Otherwise sets current `sequence` to `0`.
- For the first entry, sets current `sequence` to `0`.

This is duplicate-ordinal assignment, not a count of all entries and not a capacity field.

`0x00521d00-0x00521d35` is best named `CompareMessageEntries`.

Comparator order:

1. `entry.type`
2. case-insensitive `entry.key`
3. `entry.sequence`

This proves the lookup helpers search by exact type/key/sequence, and the insert normalizer makes repeated same-type/same-key inserts addressable by sequence.

## `Message::m_type` Type And Dispatch Role

Best source-facing type: `MessageType`, implemented as `unsigned int` / `uint32_t`.

Evidence:

- Constructor stores the sole argument at `this+0x04`.
- [UID:0000ZZ] `ChangeManDispatchMessage` compares this dword against `ChangeManEntry.messageType` when listener scope is type-specific.
- [UID:0002H1] and [UID:0002GX] create stack messages from 32-bit literal tags and pass them through `ApplicationForwardMessage` into `ChangeMan`.
- [UID:00019B] forwards `Message *` without inspecting entry payloads.
- [UID:0002Y5] raw entry helpers are independent of `m_type`; they populate the message object's payload/list entries, while `m_type` identifies the message for dispatch.

Rejected type alternatives:

- Do not promote to a named enum yet. Only two direct stack-message literals are confirmed here, and ChangeMan supports arbitrary registered dword types.
- Do not model as pointer or class RTTI field. It is passed as an immediate/source dword and compared numerically.
- Do not conflate with raw entry tag at `MessageEntry+0x00`; that is a separate typed-payload discriminator inside `m_entries`.
- Do not name it `id` generically. Existing docs and ChangeMan support make `m_type` / `messageType` more precise.

FourCC policy:

- The field is FourCC-like because known values are 32-bit literal tags and are treated as opaque message identities.
- The source docs should show both numeric values and existing mnemonic when known, for example `0x7465726d` documented as the cleanup/termination stack message.
- Avoid inventing enum names for `0x676f6f67` or other values until more route evidence is present.

## Heuristic / Inference Reanalysis And Validation

Best-supported class/source names:

- Class name `Message`: proven by class page, vtable symbol-style name `??_7Message@@6B@`, generated class output, and constructor/destructor patterns.
- Constructor `Message::Message(MessageType messageType)`: source-like and supported by direct call sites creating stack messages.
- Destructor `Message::~Message()`: source-like and supported by direct call sites plus vtable/scalar deleting destructor.
- `Message::m_type`: keep current field name. Alternative `m_messageType` is descriptive, but current project docs and generated source consistently use `m_type`. ChangeMan already documents the same field. Use a typedef `MessageType` for source-quality rather than an enum.
- `Message::m_entries`: best field name for `this+0x08`. Existing generated code uses `m_pEntries`; both are plausible. Prefer `m_entries` in documentation because source style can encode the pointer in the type (`SortedList *`) and the field is the owned entry list. If maintaining generated-name continuity is more important, `m_pEntries` is acceptable but should be explicitly tied to the same field.
- `MessageEntry`: best struct name for the fixed `0x98` record. It is sorted by the Message comparator and is not a `SortedList` internal node.
- `MessageEntry::type` / `entryType`: best name for `+0x00`. It should not be named `messageType` because that would collide with `Message::m_type`.
- `MessageEntry::key`: best name for `+0x04`. Rejected `name` because the field participates in lookup semantics, not presentation.
- `MessageEntry::sequence` or `duplicateOrdinal`: best name for `+0x84`. Rejected `count`, `index`, and `capacity` because the normalizer assigns it based only on previous equal key/type.
- `MessageEntry::payload`: best name for `+0x88`. It is a union of scalar, struct, pointer, wide-string, and blob payloads.

Best-supported helper names:

- `CompareMessageEntries`: proven comparator role. Keep as file-local/static callback or private helper in the Message source file. It is not a virtual method.
- `NormalizeInsertedEntrySequence`: best descriptive name for `0x00521c80`. It can be private `Message` method or file-local helper taking the list/index depending on implementation style. The code uses Message-owned list state and helper-band context, so documenting it as `Message::NormalizeInsertedEntrySequence` is reasonable. Rejected `UpdateEntryCount` and `FixEntryIndex` because they hide the duplicate-key logic.
- Raw insert/get helpers: original names cannot be safely recovered because no static callers or source strings route to them. The best implementation names should be descriptive and tag-preserving:
  - `AddDword0` / `TryGetDword0`
  - `AddDword1` / `TryGetDword1`
  - `AddWord2` / `TryGetWord2`
  - `AddWord3` / `TryGetWord3`
  - `AddByte4` / `TryGetByte4`
  - `AddByte5` / `TryGetByte5`
  - `AddPointPair6` or `AddDwordPair6` / `TryGetPointPair6` or `TryGetDwordPair6`
  - `AddRect7` or `AddRectBounds7` / `TryGetRect7` or `TryGetRectBounds7`
  - `AddPointer8` / `TryGetPointer8`
  - `AddPointer9` / `TryGetPointer9`
  - `AddWideString` / `TryGetWideString`
  - `AddBlob` / `TryGetBlob`
- Use `Add`/`Insert`, not `Set`/`Update`, unless a later caller proves overwrite semantics. The code always inserts and then assigns a duplicate ordinal; it does not search for an existing entry and replace it.
- Use `TryGet` for lookup helpers because they return a boolean in `al` and write default values on miss.

Typed-entry tag semantics:

- Tags 0/1, 2/3, 4/5, 8/9 are distinct binary families but their human domain names are not recoverable without callers. The highest-confidence naming keeps type width and tag number in the name.
- Tag 6 is likely a point pair or two-coordinate structure because lookup miss initializes via the project helper at `0x004b7c30`; however, the insert path accepts two dwords directly. Best docs should say `DwordPair/PointPair` until `0x004b7c30` and consumers are fully tied to a named type.
- Tag 7 is strongly a 16-byte rectangle/bounds structure because insert copies 16 bytes and lookup miss calls the project rect/bounds initializer at `0x004b7c50`. Best name: `RectBounds` or `Rect`.
- Tag 10 is an owned wide string payload. It stores character count and an allocated UTF-16 buffer. The lookup API copies into a caller buffer with an in/out character count and null terminates.
- Tag 11 is an owned counted binary buffer/blob. It stores byte count and an allocated byte buffer. Lookup copies into a caller buffer with an in/out byte count and does not append a terminator.

Compiler/generated/raw classification:

- Constructor/destructor and compare/normalizer are normal source functions.
- Scalar deleting destructor is compiler-generated and should stay documented as vtable/runtime support, not emitted as hand source.
- Raw helper band is not compiler-generated filler. It has real source behavior, stack locals, payload management, and internal calls. It is "raw" only because the current documentation/modeling layer lacks individual function records and no external caller route was found.
- The raw helper no-route finding should be documented as negative evidence, not as proof of dead padding.

Owner/source-placement inference:

- Keep [UID:0000LA] `MessageDialogs` as current canonical owner/emitter because it already owns `Message`, current generated output routes `Message` there, and the class sits in the existing Message/MessageDialogs source family.
- Preserve a documented future candidate for a tiny generic `Message.cpp` or `MessageModel.cpp` source only if a later pass finds real non-dialog raw helper users or stronger source tree evidence. The live constructor callers from `Application` show that `Message` is general-purpose, but consumer location alone is not enough to create a new source file now.
- Reject `MessageShowPane` ownership. `MessageShowPane` is an overlay/UI class beginning at `0x00521da0`; its own pages explicitly state it should not absorb earlier Message model code.
- Reject `ChangeMan` ownership. ChangeMan consumes `Message::m_type` but does not own the payload container class.
- Reject `SortedList` ownership. `SortedList` is the container implementation used by Message entries, not the owner of the entry schema.
- Reject `Application` ownership. Application creates two stack messages and forwards them; it does not define the Message model.

Open-question closure:

- Raw helper original names: not safely recoverable from current binary because there are no callers, pointers, vtable slots, string references, or source-tree route naming them. Highest-probability names are descriptive `Add*/TryGet*` typed accessors as listed above.
- Entry tag semantic names: partially recoverable by width/initializer/path. Tags 6/7/10/11 have stronger semantic names; tags 0/1/2/3/4/5/8/9 should remain width+tag names.
- Tiny model source file: plausible but not actionable. Current owner should stay `MessageDialogs`; docs should record the possible future split without changing emitter.
- First-draft bodies: not ready for raw helper overloads because source names and exact child split are not accepted. Class declaration is ready.

## First-Draft C++ Recommendation

Add declaration-level C++ to `by-class/Message.md` on implementation callback. This is appropriate because the class is reconstructable, emits through [UID:0000LA], and the layout/constructor/destructor/vtable are strong. Keep method bodies out of the class page and do not emit scalar deleting destructor source.

Recommended class-page draft:

```cpp
typedef unsigned int MessageType;

enum MessageEntryType {
    MessageEntryType_Dword0 = 0,
    MessageEntryType_Dword1 = 1,
    MessageEntryType_Word2 = 2,
    MessageEntryType_Word3 = 3,
    MessageEntryType_Byte4 = 4,
    MessageEntryType_Byte5 = 5,
    MessageEntryType_DwordPair6 = 6,
    MessageEntryType_RectBounds7 = 7,
    MessageEntryType_Dword8 = 8,
    MessageEntryType_Dword9 = 9,
    MessageEntryType_WideString = 10,
    MessageEntryType_Blob = 11
};

struct MessageEntry {
    unsigned int type;
    wchar_t key[0x40];
    unsigned int sequence;
    union {
        unsigned int dwordValue;
        unsigned short wordValue;
        unsigned char byteValue;
        struct {
            unsigned int first;
            unsigned int second;
        } dwordPair;
        unsigned char rectBounds[0x10];
        void *pointerValue;
        struct {
            unsigned int length;
            wchar_t *text;
        } wideString;
        struct {
            unsigned int length;
            void *bytes;
        } blob;
    } payload;
};

class Message : public LObject {
public:
    explicit Message(MessageType messageType);
    virtual ~Message();

protected:
    MessageType m_type;
    SortedList *m_entries;
};
```

Emitter metadata for this draft:

- Target page: `by-class/Message.md`
- Owner/emitter: keep `CANONICAL_OWNER:0000LA`, `EMITTER_UIDS:0000LA`
- Output source route: `auto-generated/NexusTK/ui/dialogs/MessageDialogs.cpp` under the current model
- C++ policy: declaration-level only on class page; raw helper bodies deferred to [UID:0002Y5] and future exact helper children; scalar deleting destructor remains non-source compiler support.

Why not method bodies now:

- [UID:0002Y5] contains a large raw helper band that is not yet split into individual child pages.
- No static callers prove original overload names, argument names, or domain names for tags 0/1/2/3/4/5/8/9.
- The correct later implementation can still add constructor/destructor bodies to the method child, but adding raw overload bodies now would create unstable names that later consumers may contradict.

## Score, Metadata, And Ownership Recommendations

Target [UID:000084] `Message`:

- `COMPLETION`: `88`
- `CONFIDENCE`: `90`
- `RECONSTRUCTABLE`: keep `TRUE`
- `CANONICAL_OWNER`: keep `0000LA`
- `EMITTER_UIDS`: keep `0000LA`
- Add/update C++ with the declaration-only draft above.

Support [UID:0002Y5] `MessageCore`:

- Recommended `COMPLETION:88`, `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:000084`
- Keep `EMITTER_UIDS:000084`
- Keep C++ bodies blank or limited to constructor/destructor only if the implementation callback explicitly allows partial method bodies. Preferred current action: document raw helper table and no-route evidence, defer helper bodies until child split/source-route policy.

Support [UID:0001C3] `MessageAndMessageShowPane`:

- Keep `RECONSTRUCTABLE:FALSE`
- Keep score unless supervisor wants row text refresh. It is an audit-only mixed-owner island and should not emit.
- Add note that B015 confirmed Message raw helper inventory and no-route scan, while preserving the split at `0x00521da0`.

Support [UID:0003PB] `MessageVtableData`:

- Keep current score and owner.
- Add cross-reference to declaration-only `Message` class update if desired.

Source owner [UID:0000LA] `MessageDialogs`:

- Keep as source route.
- Optional confidence nudge is possible, but I recommend no score change until the tiny-model-file question is closed by stronger source-tree evidence.

SortedList/ChangeMan/Application support pages:

- No score changes required.
- Optional cross-reference synchronization only, especially if the implementation callback updates `MessageType` typedef wording.

## Target And Support Implementation Checklist

For later same-agent implementation callback:

1. Update `by-class/Message.md`.
   - Raise score to `88/90`.
   - Add the `## Heuristic / Inference Reanalysis And Validation` content or equivalent source-quality section.
   - Add exact class layout: `+0x04 m_type`, `+0x08 m_entries`, class size `0x0c`.
   - Add `MessageType` policy: `uint32_t`/`unsigned int`, FourCC-like but not a proven enum.
   - Add `MessageEntry` layout table: `type`, `key[0x40]`, `sequence`, payload union.
   - Add reachability: constructor/destructor direct callers from Application cleanup/shutdown; `ApplicationForwardMessage` and `ChangeManDispatchMessage` path.
   - Add raw helper no-route evidence summary.
   - Add declaration-only C++ draft.
   - Keep owner/emitter `0000LA`.

2. Update `by-memory/0x00520e30-0x00521d94.MessageCore.md`.
   - Raise score to `88/90`.
   - Replace shallow raw-band wording with the 24-helper table from this report.
   - Document exact half-open subranges and padding around modeled functions.
   - Document constructor, destructor, scalar deleting destructor, normalizer, and comparator behavior at field level.
   - Add PE no-route scan result for all raw helper starts.
   - Name helpers with best descriptive names and explicitly mark original names as not safely recoverable.
   - Keep raw helper method bodies deferred unless separate exact child pages are created.

3. Update `by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md`.
   - Keep nonreconstructable aggregate status.
   - Add a short support note that [UID:0002Y5] now has B015 raw helper inventory and source-placement decision.
   - Keep Message and MessageShowPane split unchanged.

4. Update `by-file/MessageDialogs.md`.
   - Keep Message under current source route.
   - Add caveat: current owner retained, future tiny generic Message/MessageModel file possible only if more source evidence appears.
   - Note declaration-only class draft now lives on [UID:000084]; raw method bodies remain in [UID:0002Y5] policy.

5. Optionally sync cross-references only if implementation scope allows:
   - `by-memory/0x0061fa3c-0x0061fa4c.MessageVtableData.md`: mention declaration-level class update; no score change required.
   - `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`: keep `Message::m_type`/`MessageType` wording aligned; no score change required.
   - `by-type/by-struct/ChangeManEntry.md`: keep `messageType` wording aligned; no score change required.
   - `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md`, `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`, and `by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md`: optional wording sync for stack `Message` construction and tags.
   - `by-class/MessageShowPane.md`, `by-file/MessageShowPane.md`, and `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`: only add negative-ownership cross-reference if needed; do not move Message model code there.

6. Do not hand-edit generated files. Let validator/autogen rebuild generated outputs if an implementation callback permits by-* edits.

7. Do not edit `by-memory/-coverage-report.md` directly. Use the supervisor-owned row text below.

## Exact Supervisor-Owned Coverage Text

`by-class/-coverage-report.md` replacement row for [UID:000084]:

```text
- [UID:000084][Message](by-class/Message.md) : reconstructable : 88% : strong : B015 source-quality pass keeps the source route through [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), confirms the constructor/destructor/scalar destructor and [UID:0003PB] vtable, resolves `m_type` at +0x04 as a 32-bit MessageType/FourCC-like ChangeMan dispatch key and `m_entries` at +0x08 as an owned SortedList of 0x98-byte MessageEntry records, documents the full raw no-static-route entry helper band [UID:0002Y5] with 24 typed insert/get overload starts, entry layout `{type, key[0x40], sequence, payload}`, sequence normalizer, compare callback, and Application cleanup/shutdown stack-message callers, and is ready for declaration-only first-draft C++ while method bodies wait for exact helper child split/source-route policy.
```

`by-memory/-coverage-report.md` replacement row for [UID:0002Y5]:

```text
    - [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) 0x00520e30-0x00521d94 | class-method-cluster | Message core methods : reconstructable : 88% : strong : B015 source-quality pass confirms the exact Message constructor/destructor/scalar destructor, raw `0x00520f00-0x00521c80` typed entry helper band, sequence normalizer, compare callback, and vtable route through [UID:000084][Message]; raw helper reanalysis identifies 24 insert/get overload starts, a 0x98-byte MessageEntry layout `{type, key[0x40], sequence, payload}`, SortedList insert/find ownership, string/blob allocation and copy behavior, no static caller/pointer route for raw helpers, and declaration-level readiness while helper bodies remain deferred pending exact child split/source-name policy.
```

`by-memory/-coverage-report.md` replacement row for [UID:0001C3] is optional; no score change is required. If the supervisor wants a refresh without changing status:

```text
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md) 0x00520e30-0x005227c6 | aggregate | Message and MessageShowPane split audit : ignored : 86% : strong : Audit-only mixed source-owner island retained as nonreconstructable; B015 source-quality pass confirms the child split at Message core [UID:0002Y5] `0x00520e30-0x00521d94` and MessageShowPane methods [UID:0002Y8] `0x00521da0-0x005227c6`, including padding at `0x00521d94-0x00521da0`, and rejects moving base Message model/raw entry helpers into MessageShowPane ownership.
```

No direct edit to `by-memory/-coverage-report.md` was made in this pass.

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000084-Message-class-source-quality-removed.md](000084-Message-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- Validator reported `ok: 1`
- Target line: `ok 000084 by-class/Message.md UID header exists`
- Dry run only; no generated or project files were written.

## Final Non-Edit Statement

This pass created only this B015 research report. It did not edit `by-class/Message.md`, any other `by-*` documentation file, any generated file, or any coverage report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/000084-Message-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"000084"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000084-Message-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/000084-Message-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000084"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
