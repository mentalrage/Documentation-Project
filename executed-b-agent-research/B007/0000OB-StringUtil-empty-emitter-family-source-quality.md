** TARGET-REPORT-UID:0000OB **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000OB StringUtil Empty-Emitter Family Source-Quality Report

** ASSIGNMENT:** B007-report-0000OB-StringUtil-empty-emitter-family-20260701
** MODE:** Report-only research; no target/support by-* implementation edits applied.

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0000OB] `by-file/StringUtil.md` as the `NexusTK/util/StringUtil.cpp` source root, add a generated-output audit, and repair all eleven current generated empty markers with implementation-ready dispositions.

Final disposition:

- Add class-level first-draft declarations for [UID:0000D9] `SimpleUString` and [UID:0000DA] `SimpleUStringVector`.
- Add formal no-duplicate/no-code comments for layout/storage duplicates [UID:0001W5], [UID:0001W6], [UID:00027J], and for the accepted internal-helper no-code target [UID:0002U5].
- Add first-draft formal C++ for [UID:000112], [UID:00012G], [UID:0001J4], [UID:0000PW], and [UID:0001ZY].
- Keep the direct owner/emitter route through existing parents: `SimpleUString` and `SimpleUStringVector` class pages feed the `StringUtil.cpp` file root; exact storage [UID:00027J] feeds the global [UID:0000PW].

Confidence: high for current generated marker inventory, exact function/data evidence, and source-root placement; medium-high for exact original helper/type spellings because current IDB has no original symbols for the local string-handle and map-node helper names.

## Target

- Target UID: [UID:0000OB]
- Target path: `by-file/StringUtil.md`
- Generated output: `auto-generated/NexusTK/util/StringUtil.cpp`
- Source queue row: `auto-generated/-ag-research-tracker.md` -> Files With Empty Emitters, 15 total emitters, 4 filled, 11 empty, 26.7%.
- Current target scores: `COMPLETION:87`, `CONFIDENCE:88`.
- Current root metadata: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

Current generated `StringUtil.cpp` header:

- `validator-command-id: 000000003639`
- `validator-refreshed-at: 2026-07-01T06:36:43-04:00`
- Source by-file UID: `0000OB`

Current populated generated outputs:

- [UID:0002DV] `SimpleUString::Clear()`
- [UID:0002E3] `SimpleUString::Assign(const wchar_t *source, unsigned int length)`
- [UID:0000E7] `StringIter` class declaration
- [UID:0001J5] `StringIter` methods and scalar-deleting-destructor no-code note

Current generated empty markers:

| UID | Path | Current score | Current route | Disposition in this report |
|---:|---|---|---|---|
| 0000D9 | `by-class/SimpleUString.md` | 85/87 | owner/emitter `0000OB` | Add class declaration with SSO-7 fields and `[[CHILDREN]]`. |
| 0002U5 | `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md` | 87/90 | owner/emitter `0000D9` | Preserve accepted no-code decision, but put it in the formal block as a comment so generated output is not an empty marker. |
| 0001W5 | `by-type/by-struct/SimpleUStringSso7Layout.md` | 85/88 | owner/emitter `0000D9` | Formal no-duplicate layout comment; class declaration emits layout. |
| 0000DA | `by-class/SimpleUStringVector.md` | 85/88 | owner/emitter `0000OB` | Add class declaration with 4-byte string-handle vector triplet and `[[CHILDREN]]`. |
| 000112 | `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md` | 85/89 | owner/emitter `0000DA` | Add first-draft destructor C++. |
| 00012G | `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md` | 86/90 | owner/emitter `0000DA` | Add first-draft grow/insert C++. |
| 0001J4 | `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` | 86/90 | owner/emitter `0000DA` | Add first-draft push-back C++. |
| 0001W6 | `by-type/by-struct/SimpleUStringVectorLayout.md` | 86/90 | owner/emitter `0000DA` | Formal no-duplicate layout comment; class declaration emits layout. |
| 0000PW | `by-global/g_emptySimpleUString.md` | 88/86 | owner/emitter `0000OB` | Add source declaration for the shared empty fallback object. |
| 00027J | `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md` | 86/88 | owner/emitter `0000PW` | Formal exact-storage/no-duplicate comment. |
| 0001ZY | `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md` | 86/88 | owner/emitter `0000OB` | Add first-draft helper-island C++. |

## Evidence Checked

Current documentation read:

- `by-file/StringUtil.md`
- `by-class/SimpleUString.md`
- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`
- `by-type/by-struct/SimpleUStringSso7Layout.md`
- `by-class/SimpleUStringVector.md`
- `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md`
- `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`
- `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`
- `by-type/by-struct/SimpleUStringVectorLayout.md`
- `by-global/g_emptySimpleUString.md`
- `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`
- `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/NexusTK/util/StringUtil.cpp`
- `auto-generated/-ag-research-tracker.md`

Old-report search:

- Searched active and executed B-agent reports with `rg` terms: `0000OB`, `StringUtil`, `SimpleUString`, `0002U5`, `00423060`, `0001ZY`, `00453820`, `0000D9`, and `0000DA`.
- No exact active or executed `TARGET-REPORT-UID:0000OB` by-file family report was found.
- Relevant executed/support leads appeared for the early SSO island, vector/generic string family, fixed-format wrapper corrections, static string vector storage, and wide-string hash/no-owner checks. The accepted facts needed for this callback are already incorporated into current by-* docs and were revalidated with live MCP where they affect this report.

Live IDA MCP evidence:

- MCP `initialize` request 1: server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- MCP `tools/list` requests 2/3 confirmed current tool schema.
- MCP `idb_list` request 4: active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker, not analyzing.
- MCP `server_health` request 5: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready with 2067 strings.
- MCP `lookup_funcs` request 6:
  - `0x00423060` -> `sub_423060`, size `0x1a4`; `0x00423204` is not a function.
  - `0x00493f10` -> `sub_493F10`, size `0x6a`.
  - `0x0049cc40` -> `sub_49CC40`, size `0x209`.
  - `0x00584910` -> `sub_584910`, size `0x7c`.
  - `0x00453820` -> `sub_453820`, size `0x19`.
  - `0x00453840` -> `sub_453840`, size `0x1d`.
  - `0x00453860` -> `sub_453860`, size `0x88`.
  - `0x004538f0` -> `sub_4538F0`, size `0x14`; `0x00453904` is not a function.
  - `0x0066daec` is not a function.
- MCP `xrefs_to` request 7 for `0x0066daec`, `0x0066dafc`, and `0x0066db00` confirms initializer use at `0x00419f27`, metadata helper refs, ItemHelpPane/CollectionPane/UI string consumer refs, and capacity/length field refs.
- MCP `xrefs_to` request 8:
  - `0x00423060`: two code refs from `sub_421A40` and `sub_581CF0`.
  - `0x00493f10`: 19 code refs including Config/RegistryConfig/string/vector cleanup users.
  - `0x0049cc40`: seven code refs including DAT/profile/patch, `sub_5839C0`, sibling `sub_584910`, and block-list/config UI paths.
  - `0x00584910`: two code refs from `sub_5839C0`.
  - `0x00453820`: two callers, minimap and metadata constructor paths.
  - `0x00453840`: two callers, minimap and metadata insertion/allocation paths.
  - `0x00453860`: seven refs including self-recursion plus minimap and metadata cleanup paths.
  - `0x004538f0`: two exception-cleanup callers from minimap and metadata paths.
- MCP `analyze_function` requests 130-137:
  - `0x00423060`: prototype `char *__thiscall(_DWORD *Src, char *, char *, int)`, callers `sub_421A40`, `sub_581CF0`, callees `_memmove`, `sub_423D00`, `__CxxThrowException@8`, `sub_5C7526`, `sub_41B6D0`, `__invalid_parameter_noinfo_noreturn`, `sub_421310`, 25 basic blocks.
  - `0x00493f10`: prototype `void __thiscall(void ***this)`, callees `sub_5C7526`, `__invalid_parameter_noinfo_noreturn`, `sub_582B70`.
  - `0x0049cc40`: prototype `int __thiscall(int this, const void **, const void **)`, callees include `operator new`, `sub_582A90`, `sub_49D530`, `sub_582B70`, `sub_49D4C0`, `sub_423E00`, `sub_421500`, `sub_5C7526`, EH/invalid-parameter support, 37 basic blocks.
  - `0x00584910`: prototype `void *__thiscall(_DWORD *this, const void **)`, callees `sub_49CC40`, `_memmove`, `sub_584BA0`, `InterlockedIncrement`.
  - `0x00453820`, `0x00453840`, `0x00453860`, and `0x004538f0` match the four wide-string map-node helper bodies and caller sets above.
- MCP `decompile` request 153:
  - `0x00453820` allocates `0x2c`, self-links first three pointer slots, and writes word `257` at flag offset `+0x0c`.
  - `0x00453840` allocates `0x2c` and copies the three link fields from the header/owner node.
  - `0x00453860` recurses through child link `+0x08`, checks sentinel byte `+0x0d`, frees heap-backed string payload if capacity `+0x24 >= 8`, resets string fields, and frees each node.
  - `0x004538f0` is a one-call free wrapper.
  - `0x00584910` appends one pointer-backed wide string handle or delegates to `0x0049cc40` when capacity is full.
  - `0x00493f10` destroys each 4-byte slot, frees backing storage, and clears the vector triplet.
- MCP `decompile` requests 160-161:
  - `0x00423060` appends/sign-extends narrow bytes into SSO-7 UTF-16 storage, grows with `(length + 1) | 7`, uses allocator `0x00423d00`, calls cleanup/free helpers, and returns the final input cursor while cleaning three stack arguments.
  - `0x0049cc40` computes vector size/insert index/capacity with right shifts by two, grows by 1.5x, aligned-allocates large storage, copy-constructs the inserted slot and ranges, destroys old slots, and updates the triplet.
- MCP `get_bytes` request 167:
  - `0x0066daec` 24 bytes: twenty zero bytes followed by `07 00 00 00`.
  - `0x0045381b-0x00453820`: five `0xcc` padding bytes.
  - `0x00453904-0x00453910`: twelve `0xcc` padding bytes.
  - `0x0042305c-0x00423060`: four `0xcc` padding bytes.
  - `0x00423204-0x00423210`: twelve `0xcc` padding bytes.

No MCP availability blocker occurred.

## Positive Evidence Summary

- `StringUtil.cpp` is already the generated root with a valid projected path and broad utility-string documentation.
- Existing generated output already contains two `SimpleUString` exact methods and the complete `StringIter` class/method family, so adding class declarations and remaining exact helper bodies improves the same root rather than creating a new source file.
- The current empty markers are not ownerless: each has a valid owner/emitter chain that reaches [UID:0000OB] except exact storage [UID:00027J], which reaches [UID:0000PW] and then [UID:0000OB].
- Live MCP revalidated every source-bearing function/data range that this report recommends changing.
- Existing layout pages are accurate evidence pages, but their formal blocks are currently blank. They should not emit duplicate structs once class declarations carry the layout; formal no-code comments are the correct generated-output disposition.

## Negative Evidence Summary

- Do not route SSO-7 targets through [UID:0000OA] `StringBase`: current docs and MCP evidence separate the SSO-7 object from the pointer-backed `mystr::StringBase` family.
- Do not assign `0x00423060` to FittingRoom or startup code. It has two different subsystem callers and shared SSO-7 state, and the unused third stack argument makes a standalone formal method less source-faithful than caller-level conversion expressions.
- Do not treat `SimpleUStringVector` elements as inline 24-byte `SimpleUString` objects. Destruction/growth/push-back all use 4-byte pointer-backed string-handle slots.
- Do not attach [UID:0001ZY] to `MiniMapDialog`, `MetaMan`, or `LinkedList`. Its four helpers are shared by minimap and metadata code, use 44-byte nodes with UTF-16 small-string payloads, and differ from the 16-byte intrusive-list helper family.
- Do not hand-author [UID:00027J] as a second global declaration. It is exact storage for [UID:0000PW].
- Fixed-wide-format wrapper siblings remain historical/superseded context only and should not be used as positive direct `StringUtil` source precedent.

## Heuristic / Inference Reanalysis And Validation

The prior docs were conservative because several names were not original-symbol proven. Under the current B-agent rules, provisional helper/type names alone are not enough to keep a source-authored method above the code gate as an empty marker. This report therefore separates three cases:

1. **Source declarations needed by existing emitted children.** [UID:0000D9] and [UID:0000DA] should receive first-draft class declarations. The member names are inferred, but offsets and behavior are confirmed, and generated output currently emits methods without the corresponding class declarations.
2. **Exact source-authored methods with sufficient behavioral proof.** [UID:000112], [UID:00012G], [UID:0001J4], and [UID:0001ZY] should receive first-draft formal C++ using inferred source-facing names. The code preserves the same allocation/free, refcount, vector triplet, map-node, and recursion behavior documented by MCP.
3. **Duplicate/generated-storage/internal-helper dispositions.** [UID:0001W5], [UID:0001W6], and [UID:00027J] should not duplicate declarations; [UID:0002U5] should preserve the accepted no-standalone-source disposition because the exact binary helper ABI has an unused third stack argument and is best represented by caller-level conversion source.

This report validates every recommendation against current docs and live MCP rather than copying older "pending final names" blockers forward.

## Ranked Ownership Analysis

### 1. [UID:0000OB] `StringUtil`

Evidence for:

- Current file root has valid path `NexusTK/util/` and generated output.
- Current source-tree plan lists `util/StringUtil.cpp` beside `util/StringBase.cpp` and treats it as the shared Unicode utility module.
- SimpleUString, SimpleUStringVector, StringIter, empty fallback storage, and wide-string map-node support all have cross-subsystem caller spreads, not feature-local ownership.

Evidence against:

- Ref-counted `StringBase` remains a separate preferred owner for pointer-backed helpers around `0x00582500+`.
- Exact original source could have split `SimpleUString.cpp` from `StringUtil.cpp`.

Decision: keep [UID:0000OB] as broad file/source root for this family. Raise file-level completion/confidence modestly after adding the generated-output audit; do not create a new source root in this pass.

### 2. Direct class/global owners

Evidence for:

- `SimpleUString` owns SSO-7 object layout and exact methods.
- `SimpleUStringVector` owns the vector triplet, destructor, grow/insert, push-back, and layout.
- `g_emptySimpleUString` owns the exact global declaration and [UID:00027J] owns only storage evidence.

Decision: preserve existing direct owner/emitter chain, but repair blank formal blocks so each item either emits source or emits an intentional no-code comment.

### 3. Rejected feature-local owners

Rejected owners: FittingRoom, startup/update check, DATFile, Config, RegistryConfig, patch/profile/UI consumers, MiniMapDialog, MetaMan, and LinkedList.

Decision: all are consumers or adjacent support contexts. None is the source owner for shared string utility infrastructure.

## Function / Child Inventory

| Range / Item | UID | Role | Reconstructable | Direct parent | Score now | Recommendation |
|---|---:|---|---|---:|---|---|
| `SimpleUString` | 0000D9 | SSO-7 class/facade | TRUE | 0000OB | 85/87 | Add class declaration, recommend 88/88. |
| `0x00423060-0x00423204` | 0002U5 | Internal narrow-to-wide append helper | TRUE | 0000D9 | 87/90 | Add formal no-code comment, keep score. |
| `SimpleUStringSso7Layout` | 0001W5 | Layout evidence | TRUE | 0000D9 | 85/88 | Add no-duplicate comment, recommend 86/89. |
| `SimpleUStringVector` | 0000DA | Vector class | TRUE | 0000OB | 85/88 | Add class declaration, recommend 88/89. |
| `0x00493f10-0x00493f79` | 000112 | Vector destructor | TRUE | 0000DA | 85/89 | Add C++, recommend 88/90. |
| `0x0049cc40-0x0049ce48` | 00012G | Vector grow/insert | TRUE | 0000DA | 86/90 | Add C++, recommend 89/90. |
| `0x00584910-0x0058498b` | 0001J4 | Vector push-back | TRUE | 0000DA | 86/90 | Add C++, recommend 89/90. |
| `SimpleUStringVectorLayout` | 0001W6 | Layout evidence | TRUE | 0000DA | 86/90 | Add no-duplicate comment, recommend 87/90. |
| `g_emptySimpleUString` | 0000PW | Shared empty fallback global | TRUE | 0000OB | 88/86 | Add declaration, recommend 89/88. |
| `0x0066daec-0x0066db04` | 00027J | Exact global storage | TRUE | 0000PW | 86/88 | Add storage/no-duplicate comment, recommend 87/89. |
| `0x00453820-0x00453904` | 0001ZY | Wide-string map-node helper island | TRUE | 0000OB | 86/88 | Add C++, recommend 89/89. |

## First-Draft C++ Recommendation

All C++ below is exact formal `RECONSTRUCTION_CPP CODE` insertion text for a later implementation callback.

### [UID:0000D9] `SimpleUString`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:88`; keep `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OB`.

```cpp
class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;

    [[CHILDREN]]
};
```

Rationale: this supplies the missing class declaration for already emitted [UID:0002DV] and [UID:0002E3]. Constructor/destructor names remain first-draft declarations; exact bodies are not claimed here.

### [UID:0002U5] `SharedNarrowRangeToWideSsoAppendHelper`

Recommended metadata: keep `87/90`, owner/emitter `0000D9`.

```cpp
// Internal SimpleUString SSO-7 narrow-range to UTF-16 append helper. The
// binary helper cleans three stack arguments but reads only the half-open
// source range; caller evidence shows the third value is an unused tag/context
// artifact, so no standalone source method is emitted for this exact range.
```

Rationale: preserves the accepted no-code proof while removing the stale generated empty marker.

### [UID:0001W5] `SimpleUStringSso7Layout`

Recommended metadata: `COMPLETION:86`, `CONFIDENCE:89`; keep owner/emitter `0000D9`.

```cpp
// SimpleUString SSO-7 layout evidence is emitted by the SimpleUString class
// declaration; this page records offset and storage-policy proof only and
// should not emit a duplicate struct.
```

### [UID:0000DA] `SimpleUStringVector`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OB`.

```cpp
typedef wchar_t *SimpleUStringHandle;

class SimpleUStringVector
{
public:
    SimpleUStringVector();
    ~SimpleUStringVector();

    void PushBack(const SimpleUStringHandle *value);

private:
    SimpleUStringHandle *m_begin;
    SimpleUStringHandle *m_end;
    SimpleUStringHandle *m_capacity;

    SimpleUStringHandle *GrowAndInsert(SimpleUStringHandle *position,
                                       const SimpleUStringHandle *value);

    [[CHILDREN]]
};
```

Rationale: uses the confirmed three-pointer vector triplet and 4-byte pointer-backed string-handle element model. `SimpleUStringHandle` is an inferred source-facing type alias for the one-dword wide string slot.

### [UID:000112] `SimpleUStringVectorDestructor`

Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter `0000DA`.

```cpp
SimpleUStringVector::~SimpleUStringVector()
{
    SimpleUStringHandle *slot = m_begin;
    if (slot == NULL)
        return;

    while (slot != m_end) {
        ReleaseWideStringHandle(slot);
        ++slot;
    }

    FreeStringHandleVectorStorage(m_begin,
                                  static_cast<unsigned int>(m_capacity - m_begin));
    m_begin = NULL;
    m_end = NULL;
    m_capacity = NULL;
}
```

`ReleaseWideStringHandle` and `FreeStringHandleVectorStorage` are inferred helper names for `0x00582b70` and the size-aware/aligned free path through `0x005c7526`.

### [UID:00012G] `SimpleUStringVectorGrowAndInsert`

Recommended metadata: `COMPLETION:89`, `CONFIDENCE:90`; keep owner/emitter `0000DA`.

```cpp
SimpleUStringHandle *SimpleUStringVector::GrowAndInsert(
    SimpleUStringHandle *position,
    const SimpleUStringHandle *value)
{
    unsigned int size = static_cast<unsigned int>(m_end - m_begin);
    unsigned int insertIndex = static_cast<unsigned int>(position - m_begin);

    if (size == 0x3fffffff)
        ThrowVectorTooLong();

    unsigned int oldCapacity = static_cast<unsigned int>(m_capacity - m_begin);
    unsigned int newCapacity = size + 1;
    if (oldCapacity <= 0x3fffffff - (oldCapacity >> 1)) {
        unsigned int grownCapacity = oldCapacity + (oldCapacity >> 1);
        if (newCapacity < grownCapacity)
            newCapacity = grownCapacity;
    }

    SimpleUStringHandle *newBegin = AllocateStringHandleVectorStorage(newCapacity);
    SimpleUStringHandle *newPosition = newBegin + insertIndex;

    ConstructWideStringHandle(newPosition, value);
    CopyConstructWideStringHandleRange(m_begin, position, newBegin);
    CopyConstructWideStringHandleRange(position, m_end, newPosition + 1);

    for (SimpleUStringHandle *slot = m_begin; slot != m_end; ++slot)
        ReleaseWideStringHandle(slot);

    FreeStringHandleVectorStorage(m_begin, oldCapacity);

    m_begin = newBegin;
    m_end = newBegin + size + 1;
    m_capacity = newBegin + newCapacity;
    return m_begin + insertIndex;
}
```

The helper names map to current MCP callees `0x00582a90`, `0x0049d530`, `0x00582b70`, `0x00423e00`/`0x005c7526`, and `0x00421500`.

### [UID:0001J4] `SimpleUStringVectorPushBack`

Recommended metadata: `COMPLETION:89`, `CONFIDENCE:90`; keep owner/emitter `0000DA`.

```cpp
void SimpleUStringVector::PushBack(const SimpleUStringHandle *value)
{
    if (m_end == m_capacity) {
        GrowAndInsert(m_end, value);
        return;
    }

    CopyConstructWideStringHandle(m_end, value);
    ++m_end;
}
```

Rationale: the formal source can call the same copy-construction helper that the binary inlines in the fast path; the report must preserve that MCP saw the binary branch into share/refcount and private-copy paths through `InterlockedIncrement`, `0x00584ba0`, and `memmove`.

### [UID:0001W6] `SimpleUStringVectorLayout`

Recommended metadata: `COMPLETION:87`, `CONFIDENCE:90`; keep owner/emitter `0000DA`.

```cpp
// SimpleUStringVector layout is emitted by the SimpleUStringVector class
// declaration; this page records the begin/end/capacity offsets and 4-byte
// string-handle slot proof only and should not emit a duplicate struct.
```

### [UID:0000PW] `g_emptySimpleUString`

Recommended metadata: `COMPLETION:89`, `CONFIDENCE:88`; keep owner/emitter `0000OB`.

```cpp
SimpleUString g_emptySimpleUString;
```

Rationale: exact storage initializes to the default empty SSO-7 state; startup/cleanup wrappers and cross-subsystem consumers support one source-level declaration in the string utility module. If later implementation policy requires file-local linkage, use `static SimpleUString g_emptySimpleUString;` only after confirming external visibility expectations from generated source consumers.

### [UID:00027J] `g_emptySimpleUString` storage

Recommended metadata: `COMPLETION:87`, `CONFIDENCE:89`; keep owner/emitter `0000PW`.

```cpp
// Exact storage for g_emptySimpleUString is emitted by the global source
// declaration; this page records the 24-byte .data initializer and field xrefs
// only and should not emit a duplicate definition.
```

### [UID:0001ZY] `WideStringMapNodeSupport`

Recommended metadata: `COMPLETION:89`, `CONFIDENCE:89`; keep owner/emitter `0000OB`.

```cpp
struct WideStringMapNode
{
    WideStringMapNode *left;
    WideStringMapNode *parent;
    WideStringMapNode *right;
    unsigned char color;
    unsigned char isSentinel;
    unsigned char reserved[2];
    SimpleUString key;
    int value;
};

static WideStringMapNode *CreateWideStringMapSentinel()
{
    WideStringMapNode *node = static_cast<WideStringMapNode *>(
        operator new(sizeof(WideStringMapNode)));
    node->left = node;
    node->parent = node;
    node->right = node;
    node->color = 1;
    node->isSentinel = 1;
    return node;
}

static WideStringMapNode *CreateWideStringMapNodeFromHeader(WideStringMapNode *header)
{
    WideStringMapNode *node = static_cast<WideStringMapNode *>(
        operator new(sizeof(WideStringMapNode)));
    node->left = header->left;
    node->parent = header->left;
    node->right = header->left;
    return node;
}

static void DestroyWideStringMapNodes(WideStringMapNode *node)
{
    while (!node->isSentinel) {
        DestroyWideStringMapNodes(node->right);
        WideStringMapNode *next = node->left;
        node->key.Clear();
        FreeMemory(node);
        node = next;
    }
}

static void FreeWideStringMapNode(WideStringMapNode *node)
{
    FreeMemory(node);
}
```

Rationale: this is first-draft source-shape code for the four-helper island. `WideStringMapNode`, `left`, `parent`, `right`, `color`, `isSentinel`, `key`, and `value` are inferred source-facing names; exact offset roles, allocation size `0x2c`, sentinel flag byte, recursive cleanup, and SimpleUString payload cleanup are direct MCP facts. Implementation should preserve the caveat that final field names and RB-tree/list semantics remain inferred.

## Recommended Target Doc Changes

`by-file/StringUtil.md`:

- Recommend `COMPLETION:89`, `CONFIDENCE:89`.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`.
- Add a 2026-07-01 B007 generated-output audit section with:
  - generated header proof `validator-command-id: 000000003639`, `validator-refreshed-at: 2026-07-01T06:36:43-04:00`;
  - tracker context 15 total emitters, 4 filled, 11 empty, 26.7%;
  - list of the four populated outputs and eleven empty-marker dispositions;
  - route rationale preserving `StringUtil.cpp` versus `StringBase.cpp`;
  - fixed-wide-format wrapper exclusions and `StringBase` pointer-backed family exclusions as historical context, not direct contents.

## Recommended Support Doc Changes

Apply only after supervisor implementation callback:

- [UID:0000D9] `by-class/SimpleUString.md`: update metadata to `88/88`; insert formal class declaration; preserve SSO-7 versus pointer-backed `StringBase` caveat.
- [UID:0002U5] `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`: keep `87/90`; insert formal no-code comment; preserve accepted unused-third-argument proof.
- [UID:0001W5] `by-type/by-struct/SimpleUStringSso7Layout.md`: update metadata to `86/89`; insert formal no-duplicate comment.
- [UID:0000DA] `by-class/SimpleUStringVector.md`: update metadata to `88/89`; insert class declaration; preserve 4-byte pointer-backed slot semantics and reject inline 24-byte SSO elements.
- [UID:000112] `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md`: update metadata to `88/90`; insert destructor C++; preserve half-open range and helper-name caveats.
- [UID:00012G] `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`: update metadata to `89/90`; insert grow/insert C++; preserve 521-byte function proof, 1.5x growth, aligned allocation, and helper policy caveats.
- [UID:0001J4] `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`: update metadata to `89/90`; insert push-back C++; preserve refcount/private-copy fast-path proof.
- [UID:0001W6] `by-type/by-struct/SimpleUStringVectorLayout.md`: update metadata to `87/90`; insert no-duplicate layout comment.
- [UID:0000PW] `by-global/g_emptySimpleUString.md`: update metadata to `89/88`; insert global declaration; preserve source-linkage caveat.
- [UID:00027J] `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`: update metadata to `87/89`; insert exact-storage/no-duplicate comment.
- [UID:0001ZY] `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md`: update metadata to `89/89`; insert helper-island C++; preserve inferred field/name caveats and rejected MiniMap/MetaMan/LinkedList ownership alternatives.

## Score And Metadata Recommendation

The file root can move from `87/88` to `89/89` because the report resolves the current generated empty-marker family into implementation-ready code/no-code dispositions, updates the generated-output audit, and preserves the `StringUtil.cpp`/`StringBase.cpp` boundary. It should not move to `90+` yet because exact original names for `SimpleUStringHandle`, vector helper wrappers, `WideStringMapNode`, map-node fields, and the fine-grained `SimpleUString.cpp` versus `StringUtil.cpp` split remain inferred.

Every current empty marker above the code gate now has one of:

- exact first-draft formal C++;
- exact formal no-code/no-duplicate comment;
- already accepted internal-helper no-code proof converted to formal block text.

No rare no-current-improvement exception is needed.

## Open Questions With Attempted Resolution

- `SimpleUString` versus pointer-backed `StringBase`: current evidence supports keeping SSO-7 under `SimpleUString`/`StringUtil` and pointer-backed ref-counted helpers under `StringBase`. This is resolved enough for the current empty markers.
- Exact helper names for string handles and vector allocation/free: original names are unavailable, but behavior and call graph are strong enough for inferred names. Preserve as source-quality caveats, not blockers.
- `g_emptySimpleUString` linkage: one global declaration is supported; exact `static`/external linkage is not proven. This caps confidence but does not block a first-draft declaration.
- `WideStringMapNode` exact field names and value tail: offset roles are known; names are inferred. The C++ is first-draft and should carry caveats.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or supervisor-owned tracker edits are requested. The generated research tracker should update through normal supervisor `execute_report` lifecycle after the report is accepted and implemented.

## Proposed Validator Scope For Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000OB-StringUtil-empty-emitter-family-source-quality-removed.md](0000OB-StringUtil-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, inspect `auto-generated/NexusTK/util/StringUtil.cpp` and confirm:

- Header `validator-refreshed-at` is at or after the final scoped validator timestamp.
- [UID:0000D9], [UID:0000DA], [UID:000112], [UID:00012G], [UID:0001J4], [UID:0000PW], and [UID:0001ZY] appear as populated source.
- [UID:0002U5], [UID:0001W5], [UID:0001W6], and [UID:00027J] no longer appear as actionable empty markers because they emit formal no-code comments.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|
| C-0000OB-AUDIT | Add generated-output audit and move file root to `89/89`. | High | Applied: `by-file/StringUtil.md` metadata is `89/89`; B007 audit records header `000000003639`, tracker row 15/4/11/26.7%, populated outputs, empty-marker dispositions, and boundaries. | `by-file/StringUtil.md` | applied | validator `000000003745` exit 0 / ok 1 |
| C-0000D9-CLASS | Add `SimpleUString` class declaration with SSO-7 fields and `[[CHILDREN]]`. | Medium-high | Applied: formal class declaration inserted; current status/score rationale updated to `88/88`; SSO-7 vs pointer-backed `StringBase` caveat retained. | `by-class/SimpleUString.md` | applied | validator `000000003746` exit 0 / ok 1 |
| C-0002U5-NOCODE | Preserve no-standalone-source disposition as formal no-code comment. | High | Applied: formal no-standalone-source comment inserted; current prose preserves two callers, unused third stack argument, and no-pointer-route evidence. | `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md` | applied | validator `000000003747` exit 0 / ok 1 |
| C-0001W5-LAYOUT | Convert SSO-7 layout marker to no-duplicate formal comment. | High | Applied: metadata is `86/89`; formal no-duplicate layout comment inserted; page points emission to [UID:0000D9]. | `by-type/by-struct/SimpleUStringSso7Layout.md` | applied | validator `000000003748` exit 0 / ok 1 |
| C-0000DA-CLASS | Add `SimpleUStringVector` class declaration with pointer-backed string-handle slots. | High | Applied: metadata is `88/89`; `SimpleUStringHandle` typedef and class declaration inserted; inline 24-byte SSO element model rejected in prose. | `by-class/SimpleUStringVector.md` | applied | validator `000000003749` exit 0 / ok 1 |
| C-000112-DTOR | Add destructor first-draft C++. | High | Applied: metadata is `88/90`; destructor C++ inserted; helper-name and half-open range caveats preserved. | `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md` | applied | validator `000000003750` exit 0 / ok 1 |
| C-00012G-GROW | Add grow/insert first-draft C++. | High | Applied: completion is `89`; grow/insert C++ inserted; 521-byte body, 1.5x growth, aligned allocation, and helper dependency evidence retained. | `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md` | applied | validator `000000003751` exit 0 / ok 1 |
| C-0001J4-PUSH | Add push-back first-draft C++. | High | Applied: completion is `89`; push-back C++ inserted; refcount/private-copy fast-path evidence retained. | `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` | applied | validator `000000003752` exit 0 / ok 1 |
| C-0001W6-LAYOUT | Convert vector layout marker to no-duplicate formal comment. | High | Applied: completion is `87`; formal no-duplicate vector layout comment inserted; page points emission to [UID:0000DA]. | `by-type/by-struct/SimpleUStringVectorLayout.md` | applied | validator `000000003753` exit 0 / ok 1 |
| C-0000PW-GLOBAL | Add `SimpleUString g_emptySimpleUString;` declaration. | Medium-high | Applied: metadata is `89/88`; formal global declaration inserted; linkage/source-placement caveat retained. | `by-global/g_emptySimpleUString.md` | applied | validator `000000003754` exit 0 / ok 1 |
| C-00027J-STORAGE | Convert exact storage page to no-duplicate formal comment. | High | Applied: metadata is `87/89`; formal exact-storage/no-duplicate comment inserted; 24-byte initializer and field-xref role retained. | `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md` | applied | validator `000000003755` exit 0 / ok 1 |
| C-0001ZY-MAPNODE | Add four-helper wide-string map-node first-draft C++. | Medium-high | Applied: metadata is `89/89`; four-helper C++ cluster inserted; inferred field-name caveats and rejected MiniMap/MetaMan/LinkedList ownership retained. | `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md` | applied | validator `000000003756` exit 0 / ok 1 |
| C-STRINGBASE-BOUNDARY | Preserve `StringBase.cpp` as owner for pointer-backed ref-counted helpers; do not absorb those into this callback. | High | Already present and preserved in `by-file/StringUtil.md` source-structure/audit text. | `by-file/StringUtil.md` audit/rejected alternatives | already-present | verified in `by-file/StringUtil.md`; validator `000000003745` exit 0 |
| C-FIXED-FORMAT-REJECT | Preserve fixed-wide-format wrapper exclusions as historical/superseded context only. | High | Already present and preserved in `by-file/StringUtil.md` scope exclusions and B007 audit. | `by-file/StringUtil.md` audit/rejected alternatives | already-present | verified in `by-file/StringUtil.md`; validator `000000003745` exit 0 |

## Implementation Tracking Checklist

- [x] Supervisor validation accepted the report and issued implementation callback.
- [x] `by-file/StringUtil.md`: updated metadata to `89/89`; added B007 generated-output audit with header proof, tracker context, four populated outputs, eleven empty-marker dispositions, and source-root rationale.
- [x] [UID:0000D9] `by-class/SimpleUString.md`: updated metadata to `88/88`; inserted the formal `SimpleUString` class declaration; preserved SSO-7 versus pointer-backed `StringBase` caveat and inferred field-name caveats.
- [x] [UID:0002U5] `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`: kept `87/90`; inserted the formal no-code comment; preserved unused third-argument, two-caller, no-pointer-route evidence.
- [x] [UID:0001W5] `by-type/by-struct/SimpleUStringSso7Layout.md`: updated metadata to `86/89`; inserted formal no-duplicate layout comment.
- [x] [UID:0000DA] `by-class/SimpleUStringVector.md`: updated metadata to `88/89`; inserted the formal class declaration and `SimpleUStringHandle` typedef; preserved 4-byte slot model.
- [x] [UID:000112] `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md`: updated metadata to `88/90`; inserted destructor first-draft C++; preserved helper-name and half-open range caveats.
- [x] [UID:00012G] `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`: updated metadata to `89/90`; inserted grow/insert first-draft C++; preserved 521-byte body, aligned allocation, 1.5x growth, and helper dependency evidence.
- [x] [UID:0001J4] `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`: updated metadata to `89/90`; inserted push-back first-draft C++; preserved refcount/private-copy evidence.
- [x] [UID:0001W6] `by-type/by-struct/SimpleUStringVectorLayout.md`: updated metadata to `87/90`; inserted no-duplicate layout comment.
- [x] [UID:0000PW] `by-global/g_emptySimpleUString.md`: updated metadata to `89/88`; inserted `SimpleUString g_emptySimpleUString;`; preserved linkage caveat.
- [x] [UID:00027J] `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`: updated metadata to `87/89`; inserted exact-storage/no-duplicate comment; preserved 24-byte initializer and field xrefs.
- [x] [UID:0001ZY] `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md`: updated metadata to `89/89`; inserted four-helper first-draft C++; preserved inferred `WideStringMapNode` field-name caveats and rejected MiniMap/MetaMan/LinkedList ownership.
- [x] Preserved already-present `StringBase.cpp` boundary and fixed-wide-format wrapper exclusions in `by-file/StringUtil.md`; no extra callback targets added.
- [x] Run scoped validators listed in this report with `--wait-generated`: final proof commands `000000003745` through `000000003756`, all exit 0 / ok 1.
- [x] Inspect generated `auto-generated/NexusTK/util/StringUtil.cpp` for freshness and removal/population state of all eleven audited empty markers: refreshed by `000000003756` at `2026-07-01T07:16:39-04:00`; populated/formal-comment UIDs present; no empty-marker text remains.
- [x] Update this report with validator command IDs/timestamps and final generated-output proof.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`. Final proof run:

| File | command_id | command_timestamp | Exit | ok | generated_refresh |
|---|---:|---|---:|---:|---|
| `by-file/StringUtil.md` | `000000003745` | `2026-07-01T07:14:43-04:00` | 0 | 1 | completed, `000000003745` |
| `by-class/SimpleUString.md` | `000000003746` | `2026-07-01T07:14:53-04:00` | 0 | 1 | completed, `000000003746` |
| `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md` | `000000003747` | `2026-07-01T07:15:04-04:00` | 0 | 1 | completed, `000000003747` |
| `by-type/by-struct/SimpleUStringSso7Layout.md` | `000000003748` | `2026-07-01T07:15:15-04:00` | 0 | 1 | completed, `000000003748` |
| `by-class/SimpleUStringVector.md` | `000000003749` | `2026-07-01T07:15:26-04:00` | 0 | 1 | completed, `000000003749` |
| `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md` | `000000003750` | `2026-07-01T07:15:36-04:00` | 0 | 1 | completed, `000000003750` |
| `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md` | `000000003751` | `2026-07-01T07:15:46-04:00` | 0 | 1 | completed, `000000003751` |
| `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` | `000000003752` | `2026-07-01T07:15:57-04:00` | 0 | 1 | completed, `000000003752` |
| `by-type/by-struct/SimpleUStringVectorLayout.md` | `000000003753` | `2026-07-01T07:16:07-04:00` | 0 | 1 | completed, `000000003753` |
| `by-global/g_emptySimpleUString.md` | `000000003754` | `2026-07-01T07:16:17-04:00` | 0 | 1 | completed, `000000003754` |
| `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md` | `000000003755` | `2026-07-01T07:16:28-04:00` | 0 | 1 | completed, `000000003755` |
| `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md` | `000000003756` | `2026-07-01T07:16:39-04:00` | 0 | 1 | completed, `000000003756` |

Generated `auto-generated/NexusTK/util/StringUtil.cpp` header after final validation:

```text
validator-command-id: 000000003756
validator-refreshed-at: 2026-07-01T07:16:39-04:00
validator-refresh-source: foreground-generated-refresh
```

Freshness: generated header is exactly at the final scoped validator command metadata and therefore at/after all prior scoped validators.

Generated marker inspection:

- Present as populated source/formal comments: [UID:0000D9], [UID:0002U5], [UID:0001W5], [UID:0000DA], [UID:000112], [UID:00012G], [UID:0001J4], [UID:0001W6], [UID:0000PW], and [UID:0001ZY].
- [UID:00027J] exact-storage child does not appear in `StringUtil.cpp`; its formal no-duplicate block remains in the by-memory page and no actionable empty marker remains in generated output.
- Search for `EMPTY`, `empty marker`, `NO GENERATED`, `No generated`, `TODO`, and `UID:00027J` in `StringUtil.cpp` returned no matches.

## Changed Files

Modified during implementation callback:

- `by-file/StringUtil.md`
- `by-class/SimpleUString.md`
- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`
- `by-type/by-struct/SimpleUStringSso7Layout.md`
- `by-class/SimpleUStringVector.md`
- `by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md`
- `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`
- `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`
- `by-type/by-struct/SimpleUStringVectorLayout.md`
- `by-global/g_emptySimpleUString.md`
- `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`
- `by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md`
- `tools/leaser/Agents/Agent-B007/research/0000OB-StringUtil-empty-emitter-family-source-quality.md`

Validator-owned generated output refreshed, not edited by hand:

- `auto-generated/NexusTK/util/StringUtil.cpp`

Leases:

- Leased the 12 scoped target/support docs as B007 before editing/validation. Initial lease was present but expired before validation; renewed the same 12-doc lease before the validator batch. After validation, explicit `unlease` returned `Rejected[No active lease]` for each scoped file, and `current_leases.md` showed no B007/StringUtil-family active leases.

## Blockers

None. MCP was available and responsive during the report pass; implementation validation passed. Remaining items are source-quality caveats, not blockers: exact original helper names for string-handle construction/free helpers, exact linkage of `g_emptySimpleUString`, exact `WideStringMapNode` field names, and the possible future split between `StringUtil.cpp` and a narrower `SimpleUString.cpp` remain inferred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000OB-StringUtil-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000OB-StringUtil-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T07:21:09","uid":"0000OB"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000OB-StringUtil-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000OB-StringUtil-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000OB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
