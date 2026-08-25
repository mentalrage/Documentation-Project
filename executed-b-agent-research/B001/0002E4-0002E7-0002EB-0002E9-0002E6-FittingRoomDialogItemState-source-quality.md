** TARGET-REPORT-UID:0002E4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002E4/0002E7/0002EB/0002E9/0002E6 FittingRoomDialogItemState Source-Quality Report

Assignment: `B001-goal2-fittingroom-dialog-item-state-source-quality-0002E4-0002E7-0002EB-0002E9-0002E6-20260618`

Targets:

- [UID:0002E4] `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md`
- [UID:0002E7] `by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md`
- [UID:0002EB] `by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md`
- [UID:0002E9] `by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md`
- [UID:0002E6] `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`

## Finalized Report / Current Recommendation

Keep all five targets as reconstructable, emitting [UID:000051] `FittingRoomDialogItemState` children under [UID:0000JE] `FittingRoom` / `NexusTK/cashshop/FittingRoom.cpp`. Do not split the assigned five into a new source file and do not move them to JsonCpp, `ItemCatalog`, or the mixed [UID:0002EE] helper-island aggregate.

Recommended scores and routing:

| UID | Current | Recommended | Owner/emitter | Formal C++ |
| --- | ---: | ---: | --- | --- |
| `0002E4` | `84/88` | `87/90` | keep `CANONICAL_OWNER:000051`, `EMITTER_UIDS:000051` | populate first draft |
| `0002E7` | `84/88` | `87/90` | keep `CANONICAL_OWNER:000051`, `EMITTER_UIDS:000051` | populate first draft |
| `0002EB` | `84/88` | `87/90` | keep `CANONICAL_OWNER:000051`, `EMITTER_UIDS:000051` | populate first draft |
| `0002E9` | `84/88` | `87/90` | keep `CANONICAL_OWNER:000051`, `EMITTER_UIDS:000051` | populate first draft |
| `0002E6` | `84/88` | `87/89` | keep `CANONICAL_OWNER:000051`, `EMITTER_UIDS:000051` | populate first draft, with failure-cleanup caveat |

Support recommendations:

- Raise [UID:000051] `FittingRoomDialogItemState` from `86/88` to `88/90` after adding the resolved entry, part-record, category-map, cache-path, and source-signature text below.
- Keep [UID:0000JE] `FittingRoom` at `85/87` or raise to `86/88` if the supervisor incorporates the source-placement paragraph below. This cluster strengthens the file source route but does not resolve all fitting-room class-boundary questions.
- Raise [UID:0000WU] `FittingRoomItemShopCatalogState` from `86/88` to `87/89`. The `0xc0` entry layout and category parser are now source-quality; raw no-caller cache helpers `0x00422920`/`0x004229f0` and optional `ItemCatalog` facade placement still cap the aggregate.
- Raise [UID:0002E5] `FittingRoomCatalogEntryPartLookup` from `84/90` to `86/91` because the 6-byte part-record layout is now resolved enough to name byte `+0x01` as reserved/padding, not an unknown semantic field.

The code-entry gate is cleared for the five assigned targets after the recommended score updates: each target remains `RECONSTRUCTABLE:TRUE`, has a direct emitter route to [UID:000051] and file root [UID:0000JE], and has a nonblank source-facing C++ draft below. The only caveat is [UID:0002E6]'s malformed-input ownership behavior; it is documented as a binary/source-quality caveat, not a no-code proof.

## Evidence Checked

Instruction and workflow evidence:

- Re-read `tools/leaser/Agents/Supervisor.md`, `Agent-B001/goal.md`, and `Agent-B001/notes.md`.
- Confirmed this assignment is report-only and that direct edits to by-* docs, generated reports/source, IDA DB, and `by-memory/-coverage-report.md` are banned.
- Attempted the local MCP endpoint at `http://127.0.0.1:13337/mcp`; it was not listening. No live IDA mutation or direct IDA edit was performed for this report.

Primary target docs:

- [UID:0002E4] documents `0x00421a40-0x00421fd8`, single caller `0x00422d0e`, `0xc0` entry allocation/setup by [UID:0002E6], JsonCpp string keys `name`, `tile`, `color`, `items`, `part`, `gender`, destination offsets `+0x04/+0x06/+0x08/+0x0a/+0xb4`, and a still-open byte in the packed 6-byte record.
- [UID:0002E7] documents `0x00422020-0x0042232a`, one constructor caller `0x0041be6c`, category lookup at `+0x220`, cache path at `+0x18`, cache-loaded byte at `+0x24c`, encode/decode keys at `+0x250/+0x268`, constructor cache-file read/transform/parse, and EH cleanup caveats.
- [UID:0002EB] documents `0x00422330-0x0042246f`, reset-helper call, string/key teardown, equipment-vector destructor, category-storage destructor, inline path-buffer non-ownership, and scalar-deleting destructor caller.
- [UID:0002E9] documents `0x00422740-0x00422919`, four callers, JsonCpp document/root parse, `version` lookup, move into item-state offset `+0x000`, category loop `0..10`, and consumed source-buffer cleanup.
- [UID:0002E6] documents `0x00422ba0-0x00422e91`, one parser caller, all 11 category string refs, category array lookup, `0xc0` entry allocation/setup, handoff to [UID:0002E4], pending pointer-vector insertion into category storage `+0x220`, and the adjacent generated switch table.

Support docs checked:

- [UID:000051] `FittingRoomDialogItemState`, [UID:0000JE] `FittingRoom`, [UID:0000WU] `FittingRoomItemShopCatalogState`.
- [UID:0002E5] part lookup, [UID:0002EC] reset, [UID:0002EF] save, [UID:0002EA] raw cache-path helper, [UID:0002EG] no-caller encoded cache-file helper, [UID:0002ED] no-caller `test.json` loader, [UID:0002E8] transform, [UID:0002EH] switch table.
- [UID:0002EE] mixed category/string helper island and B001 older report `executed/older/0002EE-FittingRoomCategoryStorageAndStringHelpers.md`.
- Exact category-map and vector helpers: [UID:0002U4] insert node, [UID:0002U6] 6-byte part vector grow insert, [UID:0002U8] category lookup finalize/rehash, [UID:0002U9] cleanup, [UID:0002UF] part-vector destroy, [UID:0002UH] sentinel allocator, [UID:0002UI] node cleanup/free.
- JsonCpp boundary docs [UID:0000KI], [UID:0000WY], [UID:0000X0], small-string docs [UID:0002CZ]/[UID:0000WN]/[UID:0002UG], and equipment/facade docs [UID:0001UH]/[UID:0000WV]/[UID:00006T].

Exported/local evidence checked:

- `resources/exported_data/functions/0x00421a40.json`: IDA name `sub_421A40`, size `1432`, signature `char __thiscall(wchar_t *this, _BYTE *)`, one IDA xref from `0x00422d0e`.
- `resources/exported_data/functions/0x00422020.json`: IDA name `sub_422020`, size `778`, signature `char *__thiscall(char *this)`, one IDA xref from `0x0041be6c`.
- `resources/exported_data/functions/0x00422330.json`: IDA name `sub_422330`, size `319`, three IDA xrefs: `0x0041c2e4`, `0x0041d527`, and EH/unwind `0x005f683f`. The target doc should not keep saying only the scalar-deleting destructor reaches this body.
- `resources/exported_data/functions/0x00422740.json`: IDA name `sub_422740`, size `473`, four xrefs: `0x0041cc30`, `0x004222c2`, `0x00422ac5`, `0x00422f90`.
- `resources/exported_data/functions/0x00422ba0.json`: IDA name `sub_422BA0`, size `753`, one xref from `0x0042287c`.
- `resources/exported_data/functions/0x00422920.json`: Ghidra models `FUN_00422920` with size `208`, IDA name blank, caller count zero.
- `resources/exported_data/functions/0x004229f0.json` and `0x00422ec0.json`: modeled bodies but zero callers, agreeing with their no-route helper docs.
- PE section map from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: image base `0x00400000`; `.text` starts at VA `0x00401000` and raw `0x00000400`.
- PE byte checks with shared read handle confirmed:
  - `0x00421fd8-0x00421fe0`: eight `cc` bytes.
  - `0x0042201c-0x00422020`: four `cc` bytes.
  - `0x0042232a-0x00422330`: six `cc` bytes.
  - `0x0042246f`: one `cc` byte.
  - `0x0042273f`: one `cc` byte.
  - `0x00422919-0x00422920`: seven `cc` bytes.
  - `0x00422b93-0x00422ba0`: thirteen `cc` bytes.
  - `0x00422e91-0x00422e94`: `0f 1f 00` alignment.
  - `0x00422e94-0x00422ec0`: 11 dword switch targets `0x00422bde, 0x00422be5, 0x00422bec, 0x00422bf3, 0x00422bfa, 0x00422c01, 0x00422c08, 0x00422c0f, 0x00422c16, 0x00422c1d, 0x00422c24`.
  - `0x00422ff1-0x00423000`: fifteen `cc` bytes.
- PE literal VA scan found zero absolute pointer-table hits for starts `0x00422920`, `0x004229f0`, `0x00422ec0`, `0x00421a40`, `0x00422020`, `0x00422330`, `0x00422740`, and `0x00422ba0`. Direct call xrefs remain the only supported route evidence for the five assigned modeled functions; no hidden pointer route was found for the no-caller helpers.
- Generated `source-3/simroot_v2/class_FittingRoomDialogItemState.cpp` was checked as a lead. It uses useful names like `LoadOneCategoryFromDocument`, `ResetCategoryEntryLists`, and local `ItemStateView`, but it relies on synthetic overlays, generated helper names, modern constructs, and incomplete field declarations. It is not proof of original source names. Its useful facts are accepted only where binary/docs independently support them.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Owner Route

Best source placement is still [UID:0000JE] `FittingRoom` at `NexusTK/cashshop/FittingRoom.cpp`, with [UID:000051] as the direct class support. The five assigned targets operate on the embedded item-state object constructed at fitting-room dialog offset `+0x504`, parse item-shop cache/catalog JSON, and maintain item-state-owned category storage.

Rejected alternatives:

- JsonCpp ownership is rejected. The assigned functions consume `Json::Value`/reader helpers but own NexusTK schema fields, cache paths, entry allocation, and category storage.
- [UID:0000KD] `ItemCatalog` ownership is rejected for the five assigned targets. `ItemCatalog` is a two-method facade over `this + 0x220` category storage. It may remain separate for `GetItemCount`/`GetItemByIndex`, but it does not own JSON parsing, cache loading, constructor/destructor state, or category-entry allocation.
- [UID:0002EE] aggregate ownership is rejected. The older B001 report and current child docs show `0002EE` is a mixed helper-island container crossing fitting-room category helpers, shared SimpleUString/StringUtil, DAT/vector support, and compiler cleanup. Exact children can route to [UID:000051]; the aggregate must stay non-emitting.

Impact: owner/emitter metadata for all five assigned targets should stay `000051`; source path stays under [UID:0000JE]. Formal C++ should be placed through the class/file route, not as a standalone file or aggregate island.

### Entry Layout And Field Names

The `0xc0` entry layout is now strong enough for source-facing documentation:

| Offset | Recommended name/type | Evidence |
| --- | --- | --- |
| `+0x00` | `FittingRoomCatalogCategory category` / `uint32_t categoryId` | [UID:0002E6] writes the category index before [UID:0002E4] parses the entry. |
| `+0x04` | `bool enabled` or `bool valid` | [UID:0002E4] writes `1` at function start; no other semantic name is proven. Prefer `enabled`/`valid` over `active` only if local UI consumers later confirm selection semantics. |
| `+0x05` | reserved/pad byte | Not assigned by the parser; required for subsequent `int16_t tile` alignment. |
| `+0x06` | `int16_t tile` or `tileId` | [UID:0002E4] reads JSON `tile`, stores it, then subtracts `0x4000`. Existing wording that treats this as adding `0xc000` should be replaced by the exact source operation `tile = rawTile - 0x4000`; the 16-bit result may print equivalently in unsigned views. |
| `+0x08` | `uint8_t color` | [UID:0002E4] reads JSON `color` with default `-1` and stores one byte. |
| `+0x09` | reserved/pad byte | Not assigned by the parser. |
| `+0x0a` | `wchar_t name[0x50]` | `wcscpy_s(entry + 0x0a, 0x50, convertedName)` after `name` lookup/default `None`; 80 UTF-16 code units. |
| `+0xaa..+0xb3` | reserved/padding | Gap between 80-WCHAR name buffer and vector triplet. |
| `+0xb4/+0xb8/+0xbc` | `FittingRoomCatalogPartRecord *partsBegin/partsEnd/partsCapacity` | [UID:0002E6] zeroes these three dwords before [UID:0002E4]; [UID:0002E4], [UID:0002E5], [UID:0002U6], and [UID:0002UF] all use a 6-byte element stride. |

The exact source-facing type can be either a nested `FittingRoomDialogItemState::CatalogEntry` or a file-local `FittingRoomCatalogEntry`. Because the object is not the `FittingRoomDialogItemState` itself, [UID:0002E4]'s source-facing signature should not be a method on the item-state object. Best signature:

```cpp
bool FittingRoomCatalogEntry::LoadFromJson(const Json::Value& value);
```

or, if the project avoids a nested method:

```cpp
static bool LoadFittingRoomCatalogEntryFromJson(FittingRoomCatalogEntry& entry, const Json::Value& value);
```

### Packed 6-Byte Part Record

Recommended part-record layout:

```cpp
#pragma pack(push, 1)
struct FittingRoomCatalogPartRecord {
    uint8_t part;       // +0x00, JSON "part", reject sentinel 0xf5 (-11)
    uint8_t reserved;   // +0x01, padding/reserved; no known consumer
    uint16_t tile;      // +0x02, JSON "tile", default -11 stored as 0xfff5 if accepted
    uint8_t color;      // +0x04, JSON "color", default 0xff accepted
    uint8_t gender;     // +0x05, JSON "gender", reject sentinel 0xff
};
#pragma pack(pop)
```

Evidence:

- [UID:0002E4] appends one dword plus one word, fast path `*dword = recordLow4; word[+4] = color/gender`, slow path [UID:0002U6].
- [UID:0002E5] callers read byte `+0x00`, word `+0x02`, and byte `+0x04`.
- [UID:0002E4] writes `part` into low byte, `tile` into high word of the first dword, `color` into low byte of the trailing word, and `gender` into high byte of the trailing word.
- Byte `+0x01` is not read by the known list-input consumers and is not assigned a semantic JSON value by the parser. Decompiler stack-variable reuse makes it appear to inherit stale bits from a temporary pointer. The safest source-quality conclusion is reserved/padding; do not invent a field name.

Rejected alternatives:

- `+0x01` as a second part field is rejected: no string key, assignment, or consumer exists.
- `gender` as padding is rejected: [UID:0002E4] explicitly reads JSON `gender`, stores it in the high byte of the trailing word, and rejects `0xff`.
- A 5-byte record is rejected: vector arithmetic, lookup helper, grow helper, and destroy helper all use a fixed 6-byte stride.

Impact: [UID:0002E4] and [UID:0002E5] no longer need an open question for the packed record; note only that `reserved` has no known source semantic. This supports raising [UID:0002E4] and [UID:0002E5].

### Category Enum And JSON Keys

Recommended enum/table:

```cpp
enum FittingRoomCatalogCategory {
    kFittingRoomCategoryMain = 0,
    kFittingRoomCategoryUsableItems = 1,
    kFittingRoomCategoryWeapons = 2,
    kFittingRoomCategoryMounts = 3,
    kFittingRoomCategoryFace = 4,
    kFittingRoomCategoryHead = 5,
    kFittingRoomCategoryMantle = 6,
    kFittingRoomCategoryNecklaces = 7,
    kFittingRoomCategoryCoats = 8,
    kFittingRoomCategoryShoes = 9,
    kFittingRoomCategorySpecialtySets = 10,
    kFittingRoomCategoryCount = 11
};

static const char* const kFittingRoomCategoryJsonKeys[kFittingRoomCategoryCount] = {
    "main",
    "usable_items",
    "weapons",
    "mounts",
    "face",
    "head",
    "mantle",
    "necklaces",
    "coats",
    "shoes",
    "specialty_sets"
};
```

Evidence:

- [UID:0002E6] switch cases map exactly `0..10` to those strings; out-of-range returns false.
- [UID:0002EH] confirms the adjacent data is compiler alignment plus an 11-entry switch target table and should remain non-reconstructable.

Rejected alternatives:

- Hand-authoring the jump table is rejected. Source should use the enum/table or switch; the compiler regenerates the target table.
- Naming the enum as a generic `ItemCatalogCategory` is weaker because current consumers are fitting-room item-shop catalog state and category/list UI, not a global item database.

### Category Lookup And Vector Helper Roles

The item-state category storage at `this + 0x220` is a category-keyed lookup/map, not a row table and not a direct array indexed by category.

Recommended descriptive layout:

```cpp
struct FittingRoomCategoryLookup {
    float maxLoadFactor;              // +0x00, initialized to 1.0
    FittingRoomCategoryNode* sentinel; // +0x04
    unsigned int nodeCount;            // +0x08
    void* bucketsBegin;                // +0x0c
    void* bucketsEnd;                  // +0x10
    void* bucketsCapacity;             // +0x14
    unsigned int bucketMask;            // +0x18
    unsigned int bucketCount;           // +0x1c
};

struct FittingRoomCategoryNode {
    FittingRoomCategoryNode* next;      // +0x00
    FittingRoomCategoryNode* prev;      // +0x04
    uint8_t category;                   // +0x08
    // padding +0x09..+0x0b
    FittingRoomCatalogEntry** begin;    // +0x0c
    FittingRoomCatalogEntry** end;      // +0x10
    FittingRoomCatalogEntry** capacity; // +0x14
};
```

Evidence:

- [UID:0002E7] initializes `+0x220` threshold and sentinel, then bucket count 8.
- [UID:0002U4] moves a temporary transfer record `{category byte, entry pointer vector}` into node offsets `+0x08/+0x0c/+0x10/+0x14` and clears source ownership.
- [UID:0002U8] hashes one key byte with FNV-1a, compares node byte `+0x08`, handles duplicate/insertion, updates bucket first/last ranges, and rehashes by load factor.
- [UID:0002U9]/[UID:0002UI] clean up nodes and payload pointer-vector storage.

Rejected alternatives:

- Direct-tier array taxonomy is rejected: there is a sentinel/list, hash buckets, load factor, key compare, duplicate handling, and rehash.
- Row-table taxonomy is rejected: payload is a vector of entry pointers per category node, not rows in a fixed table.

### Small-String, Cache-Path, And Key-Buffer Types

Recommended item-state fields:

```cpp
std::string m_catalogVersion;        // +0x000, SSO-15 24-byte string; initialized from Locale, overwritten by JSON "version"
wchar_t m_cacheFilePath[MAX_PATH];   // +0x018, fixed 260 WCHAR buffer
FittingRoomCategoryLookup m_categoryLookup; // +0x220
std::vector<FittingRoomEquipmentEntry> m_equipmentEntries; // +0x240/+0x244/+0x248, 0xb4 stride entries
bool m_cacheLoaded;                  // +0x24c
std::string m_encodeKey;             // +0x250, "CASHEncodeDecodeByChris"
std::string m_decodeKey;             // +0x268, "sirhCyBedoceDedocnEHSAC"
```

Evidence:

- `+0x018 + 260 * 2 == +0x220`, exactly matching the category lookup start; therefore `+0x18` is a fixed `WCHAR[MAX_PATH]`, not a heap string.
- [UID:0002E9] extracts JSON `version` and moves it into `+0x000`; [UID:0002E7] seeds the same field from `Locale`.
- [UID:0002E8]/[UID:0002EF] use encode/decode keys at `+0x250/+0x268`.
- [UID:0001UH] confirms the separate equipment-entry vector at `+0x240/+0x244/+0x248`, distinct from category storage.

Rejected alternatives:

- Naming `+0x000` only `localeName` is incomplete after [UID:0002E9]; source-facing name should be `m_catalogVersion` or `m_itemShopVersion`. It is initialized from `Locale` but semantically becomes the parsed catalog `version`.
- Treating `+0x18` as `std::wstring` is rejected by the fixed-size arithmetic and lack of destructor/free in [UID:0002EB].

### JsonCpp Wrapper Names

Use source-facing JsonCpp calls in C++ drafts; do not retain address-derived wrapper names.

Recommended mapping:

| Address | Source-facing role |
| --- | --- |
| `0x00424c90` | `Json::Value` construction |
| `0x00424d80` | integer/null/default `Json::Value` construction |
| `0x00424ec0` | string/default `Json::Value` construction |
| `0x00425010` | `Json::Value` copy construction/assignment |
| `0x00425200` | `Json::Value` destructor |
| `0x00425ac0` | `Json::Value::asString()` / string extraction |
| `0x00425c90` | `Json::Value::asInt()` |
| `0x004269d0` | `Json::Value::isNull()` |
| `0x00426ea0` | `Json::Value::size()` |
| `0x00427500` | `Json::Value::operator[](ArrayIndex)` |
| `0x004278e0` | object member `get()` / lookup with default value |
| `0x004298f0`, `0x00429b30` | reader/document construction and parse front-end |

Rejected alternatives:

- Promoting `sub_4278E0`/`sub_425AC0` names into formal C++ is rejected; they are library/wrapper artifacts.
- Moving these helpers into fitting-room ownership is rejected; [UID:0000KI]/[UID:0000WY]/[UID:0000X0] own JsonCpp implementation.

### Constructor, Destructor, Source-Buffer Cleanup, And EH Mapping

[UID:0002E7] should be documented as a normal source constructor, not as explicit SEH/EH cleanup chunks. It initializes members, derives cache path, opens `ItemShop.jbn`, transforms bytes, parses the buffer through [UID:0002E9], and sets `m_cacheLoaded` on success. Compiler cleanup tails should not be hand-written in formal C++.

[UID:0002EB] should be documented as `FittingRoomDialogItemState::~FittingRoomDialogItemState()`. Exported metadata shows three xrefs, not one:

- `0x0041d527` from the dialog scalar-deleting destructor: ordinary destruction.
- `0x0041c2e4` in the dialog constructor cleanup path: constructor-failure/unwind cleanup for the embedded item-state.
- `0x005f683f` EH/unwind thunk path: compiler cleanup.

This validates current destructor behavior but corrects the caller evidence. The source destructor body should call `ResetCategoryEntryLists()` and let declared member destructors/free helpers regenerate key/category/equipment cleanup.

[UID:0002E9] consumes a 24-byte SSO-15 source buffer. The binary destroys the source object before return; source-facing signature should be by value:

```cpp
bool FittingRoomDialogItemState::LoadEncodedStateBuffer(std::string source);
```

If the project's reconstructed small-string wrapper is not `std::string`, use that wrapper by value. Do not use raw `char*` in formal C++; generated `simroot_v2` uses `char*` only because it casts the stack object overlay.

### Failure-Path Ownership In [UID:0002E6]

Evidence checked:

- [UID:0002E6] allocates a `0xc0` entry, initializes category and part-vector triplet, then calls [UID:0002E4].
- On [UID:0002E4] false return, current IDA decompilation destroys the current JsonCpp item value, sets the return flag false, and jumps to cleanup of the pending pointer-vector buffer and category Json value.
- The normal false path does not visibly call the entry-tail destroy helper, delete the just-allocated entry, or release already accepted entry objects still held in the pending vector. Existing cleanup frees the vector backing storage, not the objects.
- This is not proven to be compiler EH cleanup because the branch is a normal false-return path, not an exception unwind. The local EH state only covers exceptional exits.

Best inference:

- The shipped binary probably leaks malformed category entries on invalid JSON (`name == None`, missing `part`, or missing `gender`) after allocation. This is a malformed-data/error-path behavior and likely was not exercised by valid item-shop catalogs.
- A source-quality first draft should include explicit cleanup because that is the defensible human-written source shape. If the supervisor wants strict invalid-data binary matching, remove the `delete entry` and `ReleaseCatalogEntryVector(pendingEntries)` calls marked in the draft. This caveat caps [UID:0002E6] confidence at `89`, but it does not justify leaving formal C++ blank.

### Validation Or Contradiction Of Current Docs

Validated:

- Single direct caller for [UID:0002E4] and [UID:0002E6].
- One constructor caller for [UID:0002E7].
- Four parser callers for [UID:0002E9].
- Category keys and generated switch-table policy.
- [UID:0002EE] mixed-container strategy.
- Cache raw helper/no-caller conclusions for `0x00422920` and `0x004229f0`.

Contradicted or refined:

- [UID:0002EB] caller list is incomplete; exported metadata shows constructor cleanup and EH/unwind xrefs in addition to scalar deleting destructor.
- [UID:0002E4] top-level tile operation should be stated as subtracting `0x4000`, not simply adding/casting to `0xc000`.
- [UID:0002E4]/[UID:0002E5] should no longer leave the packed record as "unknown byte"; byte `+0x01` is reserved/padding with no known semantic consumer.
- [UID:0002E9] `+0x000` should be `catalogVersion`/`itemShopVersion`, not only locale/name.
- [UID:0002E6] failure ownership is not safely "normal cleanup"; the binary-visible false path lacks object release.

## Open Questions Resolved Or Remaining

Resolved or high-probability inferred:

- `0xc0` category-entry layout and nested 6-byte part record are resolved to source-facing field names with one reserved byte.
- Category enum/key names are resolved from string xrefs and switch cases.
- Category storage is a byte-keyed hash/list lookup, not a direct category array or row table.
- `+0x18` is a fixed `WCHAR[MAX_PATH]` cache path; `+0x24c` is a cache-loaded/cache-valid flag; `+0x250/+0x268` are SSO-15 encode/decode key strings.
- [UID:0002E9] source parameter should be by-value small string/string, because the callee consumes/destroys it.
- [UID:0002EB] source destructor should not explicitly model compiler cleanup funclets; document constructor-failure/EH xrefs separately.
- Formal C++ is ready as a first draft for all five assigned targets.

Remaining blockers:

- Exact original typedef/class spelling for `FittingRoomCatalogEntry`, `FittingRoomCatalogPartRecord`, and `FittingRoomCategoryLookup` is not preserved in IDA/Ghidra UDTs. The recommended names are high-confidence descriptive names.
- [UID:0002E6] malformed-input normal failure cleanup is not source-quality certain. The draft uses source-hygienic cleanup; strict binary matching should review/remove it.
- `0x00422920` and `0x004229f0` remain no-caller cache helper variants. This affects the aggregate [UID:0000WU] score and support docs, but not formal C++ readiness for the assigned five.
- Optional `ItemCatalog.cpp` split remains open only for [UID:0000WV]/[UID:00006T] lookup facade, not for these five targets.

## First-Draft C++ Recommendation

Supervisor should populate formal C++ for the five assigned targets. The following draft is source-facing and intentionally omits address-derived helper names, EH state variables, security-cookie scaffolding, generated switch-table bytes, and allocator guard thunks.

Shared support declarations assumed by the per-target drafts:

```cpp
enum FittingRoomCatalogCategory {
    kFittingRoomCategoryMain = 0,
    kFittingRoomCategoryUsableItems,
    kFittingRoomCategoryWeapons,
    kFittingRoomCategoryMounts,
    kFittingRoomCategoryFace,
    kFittingRoomCategoryHead,
    kFittingRoomCategoryMantle,
    kFittingRoomCategoryNecklaces,
    kFittingRoomCategoryCoats,
    kFittingRoomCategoryShoes,
    kFittingRoomCategorySpecialtySets,
    kFittingRoomCategoryCount
};

static const char* const kFittingRoomCategoryJsonKeys[kFittingRoomCategoryCount] = {
    "main",
    "usable_items",
    "weapons",
    "mounts",
    "face",
    "head",
    "mantle",
    "necklaces",
    "coats",
    "shoes",
    "specialty_sets"
};

#pragma pack(push, 1)
struct FittingRoomCatalogPartRecord {
    unsigned char part;
    unsigned char reserved;
    unsigned short tile;
    unsigned char color;
    unsigned char gender;
};
#pragma pack(pop)

struct FittingRoomCatalogEntry {
    unsigned int category;
    bool enabled;
    unsigned char reserved05;
    short tile;
    unsigned char color;
    unsigned char reserved09;
    wchar_t name[0x50];
    unsigned char reservedTail[0x0a];
    std::vector<FittingRoomCatalogPartRecord> parts;

    bool LoadFromJson(const Json::Value& value);
};
```

[UID:0002E4] recommended formal C++:

```cpp
bool FittingRoomCatalogEntry::LoadFromJson(const Json::Value& value)
{
    enabled = true;

    const std::string itemName = value.get("name", "None").asString();
    if (itemName == "None") {
        return false;
    }

    SimpleUString wideName;
    wideName.AssignAnsi(itemName.data(), itemName.data() + itemName.size());
    wcscpy_s(name, 0x50, wideName.c_str());

    tile = static_cast<short>(value.get("tile", -1).asInt());
    tile = static_cast<short>(tile - 0x4000);
    color = static_cast<unsigned char>(value.get("color", -1).asInt());

    const Json::Value items = value.get("items", Json::Value());
    const int itemCount = static_cast<int>(items.size());
    for (int index = 0; index < itemCount; ++index) {
        const Json::Value& partValue = items[index];

        FittingRoomCatalogPartRecord part = {};
        part.part = static_cast<unsigned char>(partValue.get("part", -11).asInt());
        if (part.part == 0xf5) {
            return false;
        }

        part.tile = static_cast<unsigned short>(partValue.get("tile", -11).asInt());
        part.color = static_cast<unsigned char>(partValue.get("color", -1).asInt());
        part.gender = static_cast<unsigned char>(partValue.get("gender", -1).asInt());
        if (part.gender == 0xff) {
            return false;
        }

        parts.push_back(part);
    }

    return true;
}
```

[UID:0002E7] recommended formal C++:

```cpp
FittingRoomDialogItemState::FittingRoomDialogItemState()
    : m_catalogVersion(Locale),
      m_cacheLoaded(false),
      m_encodeKey("CASHEncodeDecodeByChris"),
      m_decodeKey("sirhCyBedoceDedocnEHSAC")
{
    m_categoryLookup.Initialize(8);
    m_equipmentEntries.clear();
    m_cacheFilePath[0] = L'\0';

    wchar_t documentsPath[MAX_PATH];
    wchar_t directoryPath[MAX_PATH];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) == S_OK) {
        swprintf_s(directoryPath, MAX_PATH, L"%s\\NexusTK", documentsPath);
        if (CreateDirectoryW(directoryPath, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
            swprintf_s(directoryPath, MAX_PATH, L"%s\\NexusTK\\ItemShop", documentsPath);
            if (CreateDirectoryW(directoryPath, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
                swprintf_s(m_cacheFilePath, MAX_PATH, L"%s\\ItemShop.jbn", directoryPath);
            }
        }
    }

    FILE* cacheFile = _wfopen(m_cacheFilePath, L"rb");
    if (cacheFile == NULL) {
        return;
    }

    fseek(cacheFile, 0, SEEK_END);
    const long fileLength = ftell(cacheFile);
    fseek(cacheFile, 0, SEEK_SET);

    std::string decoded;
    if (fileLength >= 0) {
        char* fileBytes = static_cast<char*>(malloc(static_cast<size_t>(fileLength) + 1));
        if (fileBytes != NULL) {
            fileBytes[fileLength] = '\0';
            if (fread(fileBytes, 1, static_cast<size_t>(fileLength), cacheFile) ==
                static_cast<size_t>(fileLength)) {
                TransformPersistedBuffer(fileBytes, static_cast<size_t>(fileLength));
                decoded.assign(fileBytes, static_cast<size_t>(fileLength));
            }
            free(fileBytes);
        }
    }

    fclose(cacheFile);

    if (LoadEncodedStateBuffer(decoded)) {
        m_cacheLoaded = true;
    }
}
```

[UID:0002EB] recommended formal C++:

```cpp
FittingRoomDialogItemState::~FittingRoomDialogItemState()
{
    ResetCategoryEntryLists();
}
```

Notes for [UID:0002EB]: the by-memory range also contains compiler-emitted member teardown for `m_decodeKey`, `m_encodeKey`, `m_equipmentEntries`, `m_categoryLookup`, and `m_catalogVersion`. Do not hand-author those as destructor body statements if the class declaration gives those fields real destructors. If the reconstruction framework cannot express class members yet, the supervisor may add a comment after the formal C++ saying the remainder is generated member cleanup.

[UID:0002E9] recommended formal C++:

```cpp
bool FittingRoomDialogItemState::LoadEncodedStateBuffer(std::string source)
{
    Json::Value root;
    Json::Reader reader;
    reader.parse(source, root, true);

    const Json::Value versionValue = root.get("version", Json::Value());
    if (versionValue.isNull()) {
        return false;
    }

    m_catalogVersion = versionValue.asString();

    for (int category = 0; category < kFittingRoomCategoryCount; ++category) {
        if (!LoadCategoryFromJson(
                root,
                static_cast<FittingRoomCatalogCategory>(category))) {
            return false;
        }
    }

    return true;
}
```

[UID:0002E6] recommended formal C++:

```cpp
bool FittingRoomDialogItemState::LoadCategoryFromJson(
    const Json::Value& root,
    FittingRoomCatalogCategory category)
{
    if (category < 0 || category >= kFittingRoomCategoryCount) {
        return false;
    }

    const Json::Value categoryValue =
        root.get(kFittingRoomCategoryJsonKeys[category], Json::Value());
    if (categoryValue.isNull()) {
        return false;
    }

    std::vector<FittingRoomCatalogEntry*> pendingEntries;
    const int itemCount = static_cast<int>(categoryValue.size());

    for (int index = 0; index < itemCount; ++index) {
        const Json::Value& itemValue = categoryValue[index];

        FittingRoomCatalogEntry* entry = new FittingRoomCatalogEntry;
        memset(entry, 0, sizeof(*entry));
        entry->category = static_cast<unsigned int>(category);

        if (!entry->LoadFromJson(itemValue)) {
            delete entry;
            ReleaseCatalogEntryVector(pendingEntries);
            return false;
        }

        pendingEntries.push_back(entry);
    }

    m_categoryLookup.Insert(static_cast<unsigned char>(category), pendingEntries);
    return true;
}
```

Strict-binary caveat for [UID:0002E6]: current IDA decompilation does not show the `delete entry` or `ReleaseCatalogEntryVector(pendingEntries)` cleanup on normal false return after `LoadFromJson` failure. Those lines are the source-hygienic draft. If the supervisor wants invalid-data leak behavior to match the binary literally, remove those cleanup calls and document that malformed JSON may leak the just-allocated/current category entries.

## Exact Supervisor Changes Required

Metadata changes:

```text
[UID:0002E4] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000051, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000051
[UID:0002E7] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000051, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000051
[UID:0002EB] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000051, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000051
[UID:0002E9] COMPLETION:87, CONFIDENCE:90, CANONICAL_OWNER:000051, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000051
[UID:0002E6] COMPLETION:87, CONFIDENCE:89, CANONICAL_OWNER:000051, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:000051
```

Target text changes:

- [UID:0002E4], placement after current "Behavior": add the `0xc0` entry layout table and 6-byte part-record table from this report. Replace "one padding/unused byte still needs a type-layout pass" with: `Record byte +0x01 is best documented as reserved/padding. No string key, parser assignment, or known caller gives it semantic meaning; callers validate +0x00 part, +0x02 tile, +0x04 color, and the parser also stores +0x05 gender.`
- [UID:0002E4], placement in "Score Rationale": replace the current cap sentence with: `Completion is raised because the entry layout, tile subtraction, and 6-byte part-record fields are now source-quality. Confidence remains below final type recovery only because original typedef/class spellings are not preserved.`
- [UID:0002E7], placement after current "Reconstruction Notes": add: `Source-facing constructor should be emitted as FittingRoomDialogItemState::FittingRoomDialogItemState(). It should inline the cache-path creation seen in this body; [UID:0002EA] remains a separate no-caller/raw helper duplicate and should not block this constructor's formal C++. EH cleanup funclets are compiler-generated and should not be hand-authored.`
- [UID:0002EB], placement in "Address And Boundary Notes": add: `Exported metadata reports three xrefs: ordinary dialog constructor cleanup at 0x0041c2e4, ordinary dialog scalar-deleting destructor at 0x0041d527, and EH/unwind path 0x005f683f. Only 0x0041d527 is the normal destructor call; the others are constructor-failure/compiler cleanup routes.`
- [UID:0002EB], placement in "Reconstruction Notes": add: `Formal source should be the destructor body ResetCategoryEntryLists(); member string/vector/category storage destruction is generated from the class fields and should not be duplicated manually if the class declaration models those fields.`
- [UID:0002E9], placement after "Behavior": add: `The source parameter is a consumed 24-byte SSO-15 string object. Source-facing signature should be bool LoadEncodedStateBuffer(std::string source) or the project small-string equivalent by value, not raw char*.`
- [UID:0002E9], placement in "JsonCpp Boundary": add the JsonCpp wrapper mapping table from this report or a shorter equivalent that uses `Json::Reader`, `Json::Value::get`, `isNull`, `asString`, and `size`.
- [UID:0002E6], placement after current category key list: add the enum/table recommendation from this report and state that [UID:0002EH] remains generated switch-table data.
- [UID:0002E6], placement after "Behavior": add: `Normal false return after entry parser failure does not visibly destroy the just-allocated 0xc0 entry or previously accepted pending entries; current evidence supports a malformed-input leak caveat. Source-hygienic first draft includes cleanup, but strict binary matching should review that path.`

Support doc changes:

- [UID:000051] `FittingRoomDialogItemState`, placement in "Notable Data", replace `Category storage is shared with [UID:00006T][ItemCatalog]` with:

```text
- Category storage at item-state offset `+0x220` is an item-state-owned byte-keyed category lookup, not an `ItemCatalog`-owned table. [UID:00006T] `ItemCatalog` is a small facade over this storage for count/index lookup. The lookup has load factor at `+0x00`, sentinel at `+0x04`, node count at `+0x08`, bucket vector/mask/count fields through `+0x1c`, and nodes carrying category byte `+0x08` plus entry-pointer vector `+0x0c/+0x10/+0x14`.
```

- [UID:000051] `FittingRoomDialogItemState`, placement after the current category-entry parser bullet, insert:

```text
- The category-entry object allocated by [UID:0002E6] is `0xc0` bytes: category dword `+0x00`, enabled/valid byte `+0x04`, tile word `+0x06` computed as JSON tile minus `0x4000`, color byte `+0x08`, 80-WCHAR name buffer at `+0x0a`, reserved gap `+0xaa..+0xb3`, and packed part-vector triplet at `+0xb4/+0xb8/+0xbc`. Packed part records are 6 bytes: part byte `+0x00`, reserved byte `+0x01`, tile word `+0x02`, color byte `+0x04`, and gender byte `+0x05`.
```

- [UID:0000JE] `FittingRoom`, placement in "Proposed Placement", append:

```text
The `FittingRoomDialogItemState` JSON/cache parser cluster (`0x00421a40`, `0x00422020`, `0x00422330`, `0x00422740`, `0x00422ba0`) should remain in `NexusTK/cashshop/FittingRoom.cpp` through [UID:000051]. The optional `ItemCatalog.cpp` split applies only to the count/index facade at `0x00422690/0x004226d0`; it should not take ownership of cache construction, JsonCpp parsing, category-entry allocation, or category lookup storage mutation.
```

- [UID:0000WU] `FittingRoomItemShopCatalogState`, placement in "Open Questions", replace the field-layout bullet with:

```text
- Resolved by B001 2026-06-18: the `0xc0` category-entry layout and nested 6-byte part-record layout are now source-quality descriptive layouts. Remaining aggregate blockers are no-direct-caller cache helper liveness at `0x00422920`/`0x004229f0`, optional `ItemCatalog` facade source split, and exact original typedef spelling.
```

- [UID:0002E5] `FittingRoomCatalogEntryPartLookup`, placement in "Open Questions", replace the unresolved byte statement with:

```text
- Record byte `+0x01` is best documented as reserved/padding. Known callers read `+0x00` part, `+0x02` tile, and `+0x04` color; [UID:0002E4] also stores `+0x05` gender. No known source or consumer gives `+0x01` semantic meaning.
```

Formal C++ placement:

- Populate [UID:0002E4] with the `FittingRoomCatalogEntry::LoadFromJson` body.
- Populate [UID:0002E7] with the constructor body.
- Populate [UID:0002EB] with the destructor body and compiler-member-cleanup note.
- Populate [UID:0002E9] with the by-value `LoadEncodedStateBuffer` body.
- Populate [UID:0002E6] with the `LoadCategoryFromJson` body and the strict-binary failure-cleanup caveat.

## Coverage Report Replacement Text

Do not let B001 edit `by-memory/-coverage-report.md` directly. Placement context: replace the following rows inside the [UID:0000WU] `0x00421a40-0x00422e91.FittingRoomItemShopCatalogState` block. Keep unchanged padding rows and unchanged child rows as-is unless listed here.

```text
        - [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) 0x00421a40-0x00422e91 | aggregate | FittingRoomItemShopCatalogState : reconstructable : 87% : very-strong : B001 2026-06-18 source-quality pass keeps the aggregate attached to FittingRoom/FittingRoomDialogItemState; exact children cover cache construction, destructor, save/load, JsonCpp version/category parsing, raw no-caller cache helpers, transform, ItemCatalog facade, and generated switch-table data. The `0xc0` category-entry layout, packed 6-byte part record, category enum/key table, source placement, and first-draft C++ for the assigned item-state parser cluster are resolved; remaining aggregate blockers are no-caller cache helper liveness, optional ItemCatalog facade split, and original typedef spelling.
            - [UID:0002E4][0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson](by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md) 0x00421a40-0x00421fd8 | parser helper | FittingRoomCatalogEntryFromJson : reconstructable : 87% : very-strong : B001 2026-06-18 resolves the source-facing `FittingRoomCatalogEntry::LoadFromJson` shape, `0xc0` entry layout, `tile = rawTile - 0x4000`, 80-WCHAR name buffer, nested 6-byte part record `{part,reserved,tile,color,gender}`, reject sentinels `0xf5`/`0xff`, single category-loader caller, JsonCpp consumer boundary, and first-draft formal C++.
            - [UID:0002E5][0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup](by-memory/0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup.md) 0x00421fe0-0x0042201c | helper method | FittingRoomCatalogEntryPartLookup : reconstructable : 86% : very-strong : B001 2026-06-18 resolves the packed 6-byte part-record declaration enough to name byte `+0x01` reserved/padding; live evidence still confirms exact `0x3c` boundary, no callees, two list-input call sites, begin/end offsets `+0xb4/+0xb8`, 6-byte count/stride, and caller reads of part/tile/color fields.
            - [UID:0002E7][0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor](by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md) 0x00422020-0x0042232a | constructor | FittingRoomDialogItemStateConstructor : reconstructable : 87% : very-strong : B001 2026-06-18 resolves source constructor placement under `FittingRoomDialogItemState`, field names for catalog version/cache path/category lookup/equipment vector/cache flag/encode-decode keys, inline `Documents\\NexusTK\\ItemShop\\ItemShop.jbn` construction, cache read/transform/parse flow, raw helper duplicate caveat, EH cleanup mapping, and first-draft formal C++.
            - [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) 0x00422330-0x0042246f | destructor | FittingRoomDialogItemStateDestructor : reconstructable : 87% : very-strong : B001 2026-06-18 keeps source shape as `FittingRoomDialogItemState::~FittingRoomDialogItemState()` with `ResetCategoryEntryLists()` body, records exported xrefs from constructor cleanup `0x0041c2e4`, scalar deleting destructor `0x0041d527`, and EH/unwind `0x005f683f`, preserves member-cleanup/compiler-teardown caveat, and provides first-draft formal C++.
            - [UID:0002EC][0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries](by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md) 0x00422470-0x0042259a | method | FittingRoomDialogItemStateResetCategoryEntries : reconstructable : 86% : very-strong : C001 2026-06-16 direct IDA refresh plus B001 2026-06-18 layout pass confirm exact `0x12a` body, destructor/action/test-loader callers, category-node vector copy/free loop, `0xc0` entry releases, packed part-vector destroy at entry `+0xb4`, lookup clear, eight-bucket reinit, and source split from destructor.
            - [UID:0002EF][0x004225a0-0x0042268f.FittingRoomDialogItemStateSaveEncodedStateBuffer](by-memory/0x004225a0-0x0042268f.FittingRoomDialogItemStateSaveEncodedStateBuffer.md) 0x004225a0-0x0042268f | method | FittingRoomDialogItemStateSaveEncodedStateBuffer : reconstructable : 86% : very-strong : C001 2026-06-16 direct IDA refresh confirms exact `0xef` body, sole fitting-action caller, consumed SSO-15 source buffer, wide `wb` cache open through `_wfopen` dispatch, transform/write/close/free sequence, unconditional cache flag store at `+0x24c`, source-buffer cleanup, and remaining wrapper/type naming caveats.
            - [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) 0x00422690-0x0042273f | method pair | ItemCatalogLookup : reconstructable : 86% : very-strong : A001 2026-06-16 refresh confirms exact `GetItemCount`/`GetItemByIndex` function ranges, corrected internal padding, fitting-room-only caller sets, `g_pFittingRoomDialog + 0x504` embedded-object evidence, category lookup/vector behavior, and remaining standalone-vs-embedded ItemCatalog source split caveat.
            - [UID:0002E9][0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer](by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md) 0x00422740-0x00422919 | method | FittingRoomDialogItemStateLoadEncodedStateBuffer : reconstructable : 87% : very-strong : B001 2026-06-18 resolves source-facing by-value consumed string signature, JsonCpp reader/value boundary, `version` key handling into `m_catalogVersion`, all-11 category loop, four direct callers, source-buffer cleanup, support for shared `version` literal emitter route, and first-draft formal C++.
            - [UID:0002EA][0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw](by-memory/0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md) 0x00422920-0x004229ef | raw helper | FittingRoomDialogItemStateBuildCacheFilePathRaw : reconstructable : 85% : very-strong : A001 2026-06-15/16 evidence and B001 2026-06-18 PE scan confirm raw `0xd0` body through return byte, no IDA function record, zero direct callers/xrefs/literal VA pointer hits, seven `0xcc` bytes before the body, immediate cache-load helper adjacency, duplicated constructor path-building logic, wide path format strings, directory-create already-exists handling, and cache-path field `+0x18`; final C++ remains blank pending source route/name.
            - [UID:0002E6][0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson](by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md) 0x00422ba0-0x00422e91 | method | FittingRoomDialogItemStateLoadCategoryFromJson : reconstructable : 87% : very-strong : B001 2026-06-18 resolves source-facing `LoadCategoryFromJson` signature, enum/key table for 11 categories, generated switch-table policy, byte-keyed category lookup insertion, `0xc0` entry allocation/setup, pending entry-pointer vector transfer, JsonCpp boundary, malformed-input cleanup caveat, and first-draft formal C++.
        - [UID:0002ED][0x00422ec0-0x00422ff1.FittingRoomItemShopTestJsonLoader](by-memory/0x00422ec0-0x00422ff1.FittingRoomItemShopTestJsonLoader.md) 0x00422ec0-0x00422ff1 | debug/test helper | FittingRoomItemShopTestJsonLoader : reconstructable : 86% : very-strong : C001 2026-06-16 direct IDA refresh plus B001 2026-06-18 PE scan confirm exact `0x131` source-authored plaintext `test.json` loader, zero xrefs/literal VA pointer hits, unique `test.json` string ref, shared `rb` mode literal, full-file read/null terminator, parser dispatch without cache transform, reset fallback on parse failure, cleanup/support callees, and no proven runtime route or final helper name.
```

Rows intentionally not changed by this report:

- [UID:0002EG] already has a current `85%` row from the accepted A001 cache-helper pass.
- [UID:0002EH] already correctly marks the switch table as ignored/generated data.
- [UID:0002E8] transform helper was not re-scored by this assignment.
- [UID:0002EE] helper-island aggregate remains a reviewed non-reconstructable mixed container; no new change is needed from this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002E4-0002E7-0002EB-0002E9-0002E6-FittingRoomDialogItemState-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002E4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
