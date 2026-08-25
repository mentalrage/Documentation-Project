*** UID:000084 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

class Message : public LObject
{
public:
    explicit Message(MessageType messageType);
    virtual ~Message();

protected:
    MessageType m_type;
    SortedList *m_entries;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Message

## Status

- Confidence: strong for class identity, layout, constructor/destructor behavior, sorted-entry ownership, vtable route, ChangeMan dispatch use, and the typed-entry helper inventory. The remaining caps are original raw-helper overload names, the human names for tags `0/1/2/3/4/5/8/9`, and whether a final hand-authored source tree splits a tiny generic `Message`/`MessageModel` file from [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), with a nearby tiny message-model file still possible only if later source evidence finds real non-dialog consumers or source-tree names for the raw entry API.
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), because the class and direct file parent clear the current gate. The class page emits declaration-level C++ with `[[CHILDREN]]`; exact method/helper bodies remain with [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) and future exact helper children.
- Main address range: [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md), split from [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md).
- Vtable data: [UID:0003PB][0x0061fa3c-0x0061fa48.MessageVtableData](by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md), symbol-style name `??_7Message@@6B@`.
- Current recovered file lead: `source-3/simroot_v2/class_Message.cpp`. Treat this as generated lead material, not as final source placement proof.

## Class Purpose

`Message` is the compact base message object used by the Application/ChangeMan message route. It derives from [UID:00007D][LObject](by-class/LObject.md), stores a 32-bit message type at `+0x04`, and owns a [UID:0000DF][SortedList](by-class/SortedList.md) of fixed `0x98`-byte `MessageEntry` records at `+0x08`.

The `m_type` field identifies the outer message for [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md). The `MessageEntry::type` field inside each sorted payload record is a separate typed-payload discriminator and must not be conflated with `Message::m_type`.

## Source Reconstruction Policy

The formal C++ block is intentionally declaration-only. B015 resolved the class layout, vtable route, entry record shape, and helper-family semantics strongly enough for a source-facing declaration, typedef, enum, and entry struct. Method bodies are still deferred because [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) contains a large raw helper band that has not been split into exact child pages and the raw helper overload names are descriptive rather than recovered.

Do not emit the scalar deleting destructor as handwritten source. It is compiler-generated ABI support from the declared virtual destructor. The source declaration should regenerate [UID:0003PB][0x0061fa3c-0x0061fa48.MessageVtableData](by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md) and the deleting-destructor route.

`MessageType` is currently modeled as `unsigned int` / `uint32_t`. Known values are FourCC-like 32-bit tags, but only the cleanup/termination route and shutdown route are confirmed here, so a final named enum is not yet justified.

## Layout

| Offset | Field | Evidence |
| ---: | --- | --- |
| `+0x00` | inherited `LObject` vptr, overwritten by `Message` vtable `0x0061fa3c` | Constructor/destructor/scalar paths write `0x0061fa3c`; vtable child [UID:0003PB][0x0061fa3c-0x0061fa48.MessageVtableData](by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md) has constructor/destructor xrefs. |
| `+0x04` | `MessageType m_type` | Constructor stores the single argument here; ChangeMan dispatch compares `ChangeManEntry::messageType` to `message+0x04`; Application stack messages pass 32-bit literal tags. |
| `+0x08` | `SortedList *m_entries` | Constructor allocates a `SortedList` and stores it here; destructor and deleting destructor delete it through its vtable and clear the field. |

The class size is `0x0c`, confirmed by the scalar deleting destructor guarded-delete path that uses size `0x0c`.

## Message Entry Record

The constructor creates a `SortedList` with element size `0x98`, compare callback `0x00521d00`, and page/initial allocation count `0x10`. That fixed element size and the raw helper access pattern make `MessageEntry` the strongest current record name. It is a Message payload record, not a `SortedList` internal node.

| Offset | Size | Best source name | Evidence |
| ---: | ---: | --- | --- |
| `+0x00` | 4 | `type` / `entryType` | Every raw helper writes a constant tag `0..0x0b`; comparator sorts by this dword first. |
| `+0x04` | `0x80` | `key[0x40]` | Every helper copies the wide key with the safe wide-copy helper at `0x005cd657`; comparator uses case-insensitive wide compare at `0x005de165`. |
| `+0x84` | 4 | `sequence` / `duplicateOrdinal` | Insert helpers initialize it to `0x7fffffff`, then the normalizer rewrites it to `0` or `previous.sequence + 1` for same-type/same-key duplicates. |
| `+0x88` | variable | `payload` union head | Scalar, pointer, string, blob, point-pair, and rect/bounds payload families start here. |
| `+0x8c` | variable | second payload word/pointer | Tag 6 stores the second dword here; tag 10/11 store allocated text/blob pointers here. |
| `+0x90-0x97` | variable | payload tail/reserved | Tag 7 copies a 16-byte rect/bounds payload across `+0x88..+0x97`. |

The `+0x84` field should not be named capacity, count, or a global index. The normalizer makes it a duplicate sequence number inside a sorted `(type,key)` group.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00520e30-0x00520ecb` | `Message::Message(MessageType messageType)` | Constructs `LObject`, installs the `Message` vtable, stores `m_type`, allocates a `SortedList` with item size `0x98`, compare callback `CompareMessageEntries`, and page count `0x10`, then stores `m_entries`. |
| `0x00520ed0-0x00520ef5` | `Message::~Message()` | Reinstalls the `Message` vtable, deletes the owned `SortedList` with scalar-delete flag `1` if present, clears `m_entries`, and tails into `LObject` destruction. |
| `0x00520f00-0x00521c80` | raw typed entry helper band | Twelve insert helpers and twelve lookup helpers for `MessageEntry` typed payloads. No static caller/pointer route is currently found, but the code is source-shaped and cohesive. |
| `0x00521c80-0x00521cf6` | `Message::NormalizeInsertedEntrySequence` | Updates an inserted entry's duplicate sequence after sorted insertion by comparing the previous same-type/same-key entry. |
| `0x00521d00-0x00521d35` | `CompareMessageEntries` | `SortedList` comparator: orders by entry type, case-insensitive wide key, then sequence. |
| `0x00521d40-0x00521d94` | `Message` scalar deleting destructor | Compiler-generated deleting destructor with ordinary delete and guarded/sized delete branches. Document as ABI support only. |

## Raw Helper Family

The raw `0x00520f00-0x00521c80` helper band is real source-shaped Message API code even though IDA does not promote the starts to functions. B015 scanned all 24 raw helper starts for rel32 call/jump targets, absolute VA dword refs, and RVA dword refs across the PE image and found no static caller, jump-table pointer, vtable pointer, callback pointer, or data-pointer route.

Treat that as negative route evidence, not as proof of padding or compiler filler. The helpers build stack `MessageEntry` records, call [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md), call the sequence normalizer after insertion, or search through [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md) and copy/default payload values.

Highest-probability source names are descriptive and tag-preserving, not recovered original names:

| Tag | Insert role | Lookup role | Current semantic confidence |
| ---: | --- | --- | --- |
| `0` | `AddDword0` / `InsertDword0` | `TryGetDword0` | Width known; domain name unknown. |
| `1` | `AddDword1` / `InsertDword1` | `TryGetDword1` | Width known; domain name unknown. |
| `2` | `AddWord2` | `TryGetWord2` | Width known; domain name unknown. |
| `3` | `AddWord3` | `TryGetWord3` | Width known; domain name unknown. |
| `4` | `AddByte4` | `TryGetByte4` | Width known; domain name unknown. |
| `5` | `AddByte5` | `TryGetByte5` | Width known; domain name unknown. |
| `6` | `AddDwordPair6` / `AddPointPair6` | `TryGetDwordPair6` / `TryGetPointPair6` | Two dwords; lookup miss uses the project point-pair initializer at `0x004b7c30`. |
| `7` | `AddRectBounds7` / `AddRect7` | `TryGetRectBounds7` / `TryGetRect7` | 16-byte copy; lookup miss uses the project rect/bounds initializer at `0x004b7c50`. |
| `8` | `AddDword8` / `AddPointer8` | `TryGetDword8` / `TryGetPointer8` | Dword/pointer width known; domain name unknown. |
| `9` | `AddDword9` / `AddPointer9` | `TryGetDword9` / `TryGetPointer9` | Dword/pointer width known; domain name unknown. |
| `10` | `AddWideString` | `TryGetWideString` | Owned UTF-16 string; stores character count and allocated wide buffer. |
| `11` | `AddBlob` | `TryGetBlob` | Owned counted byte buffer; stores byte count and allocated byte buffer. |

Use `Add` or `Insert`, not `Set` or `Update`, until a caller proves replacement semantics. The code inserts and assigns duplicate ordinals; it does not search and overwrite an existing record. Use `TryGet` for lookups because the helpers return a boolean and write default values on miss.

## Message Type And Dispatch Role

`Message::m_type` is the ChangeMan dispatch key. [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) compares this dword against [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) `messageType` when `scope == 0`; `scope == 1` receives all messages. [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md) forwards a `Message *` and Application owner pointer without inspecting payload entries.

Confirmed stack-message producers:

- [UID:0002H1][0x00464a60-0x00464cc1.ApplicationShutdown](by-memory/0x00464a60-0x00464cc1.ApplicationShutdown.md) constructs a stack `Message` with tag `0x7465726d`, documented as the cleanup/termination message, forwards it through `Application::ForwardMessage`, then destroys it.
- [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) constructs a stack `Message` with tag `0x676f6f67`, clears the observed payload/status dword, forwards it, then destroys it.

Do not promote `MessageType` to a final named enum yet. The observed values are FourCC-like literal dwords, but ChangeMan supports arbitrary registered dword types and only a small number of producers are currently proven.

## Ownership And Source Placement

Keep [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) as canonical owner/emitter. The current repository route already owns the base `Message` model, [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md), and the current generated output path. A tiny `Message.cpp` / `MessageModel.cpp` remains plausible in a final hand-authored tree because Application and ChangeMan use the base model generally, but consumer location alone is not enough evidence to create a new file root now.

Rejected ownership alternatives:

- [UID:000087][MessageShowPane](by-class/MessageShowPane.md) / [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md): the overlay begins at `0x00521da0`; it should not absorb the earlier base Message model or raw entry helper band.
- [UID:00001K][ChangeMan](by-class/ChangeMan.md): ChangeMan consumes `m_type`, but it does not own the payload container class or entry schema.
- [UID:0000DF][SortedList](by-class/SortedList.md): SortedList supplies the fixed-width container; `Message` owns the `MessageEntry` record schema and comparator.
- [UID:00000D][Application](by-class/Application.md): Application creates two stack messages and forwards them; it is a caller/producer, not the Message model owner.

## Heuristic / Inference Reanalysis

- Class name `Message` is supported by current class pages, vtable symbol-style name `??_7Message@@6B@`, and constructor/destructor/vtable behavior.
- `m_type` is retained rather than renamed to a final enum field because the binary proves a 32-bit dispatch key but not a closed enum. `MessageType` is the best source-facing typedef.
- `m_entries` is the preferred documentation name for `+0x08`; the older `m_pEntries` spelling is acceptable as generated continuity but should point to the same owned `SortedList *` field.
- `MessageEntry::key` is preferred over `name` because the field participates in exact lookup and sort semantics, not only presentation.
- `MessageEntry::sequence` / `duplicateOrdinal` is preferred over `count`, `index`, or `capacity` because it is assigned only for duplicate same-type/same-key inserts.
- `CompareMessageEntries` is a file-local/static callback or private helper, not a virtual method.
- `NormalizeInsertedEntrySequence` can be documented as a private Message helper because it uses the Message-owned list context; exact declaration style remains open.
- Raw helper original names remain unrecovered after route scans. The docs should carry descriptive `Add*/TryGet*` names with explicit tag numbers until a caller, source string, export, or header-like evidence proves stronger domain names.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0003PB][0x0061fa3c-0x0061fa48.MessageVtableData](by-memory/0x0061fa3c-0x0061fa48.MessageVtableData.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md)
- [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md)

## Changes

- 2026-06-22 B015 Rule 26 source-quality incorporation:
  - Before: `85/86`, blank C++, shallow raw-helper description, and unresolved-but-uninvestigated helper/source-placement caveats.
  - After: `88/90`, owner/emitter remain [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and the class page emits declaration-only first-draft C++ with `MessageType`, `MessageEntryType`, `MessageEntry`, `class Message`, and `[[CHILDREN]]`.
  - Evidence: B015 raw PE/Capstone scan confirms constructor/destructor/scalar ranges, `Message` vtable data, Application cleanup/shutdown stack-message callers, ChangeMan `m_type` consumption, `SortedList(0x98, CompareMessageEntries, 0x10)` ownership, 24 raw helper starts with no static route, entry layout `{type, key[0x40], sequence, payload}`, sequence normalizer, compare callback, and rejected MessageShowPane/ChangeMan/Application/SortedList ownership alternatives.
  - Remaining caps: original raw overload names and several tag-domain names remain descriptive; final `MessageDialogs.cpp` versus tiny `MessageModel.cpp` source placement remains open; method bodies wait for exact helper child split/source-route policy.
- 2026-06-07 A005 Batch 047 parent-gate refresh:
  - Before: `76/84`, with only constructor/destructor/scalar-destructor rows and no raw helper/compare inventory.
  - After: `85/86`; added [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md), the raw `0x00520f00-0x00521c80` helper band, `0x00521c80` normalizer, and `0x00521d00` compare callback evidence.
  - Assignment effect: direct parent now satisfies `85/85` for [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md). This class remains unassigned to a file parent because [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is still below the confidence gate at `88/80`.
- 2026-06-07 A008 Batch 053 parent-chain repair:
  - Before: `AUTOGEN_PARENT_UID` was blank, so [UID:0002Y5][0x00520e30-0x00521d94.MessageCore](by-memory/0x00520e30-0x00521d94.MessageCore.md) still produced a generated memory-coverage parent-chain error despite the direct class parent being `85/86`.
  - Changed to: `AUTOGEN_PARENT_UID:0000LA`.
  - Why: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) was refreshed to `89/85` with exact `MessageCore` evidence, and it remains the best direct source-family parent for the base message model while the overlay half is split to [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md).
- 2026-06-16 B002 ChangeMan source-quality recheck:
  - Scores unchanged.
  - Evidence: documented the `Message::m_type` linkage used by ChangeMan dispatch and retained provisional source typing for the 32-bit/FourCC-like message type.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms this compact base message object has real constructor/destructor/scalar-destructor functions and owns message-entry storage setup. Kept `AUTOGEN_PARENT_UID` blank because the class was `76/84`, below the 80/80 parent-attachment gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) was the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00520e30`, `0x00520ed0`, and `0x00521d40`; `callers` confirms constructor uses from `0x00464ab0` and `0x00467990`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the compact base message object has clear class role, constructor/destructor/scalar destructor boundaries, sorted-list ownership, and entry size/compare evidence, but the page remains concise and does not yet include full entry-structure reconstruction. Evidence: linked `MessageAndMessageShowPane` range, IDA-confirmed starts, Wave3 grade, and `SortedList` allocation with item size `0x98`.
