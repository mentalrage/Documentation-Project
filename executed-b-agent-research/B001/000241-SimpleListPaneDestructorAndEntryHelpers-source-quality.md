** TARGET-REPORT-UID:000241 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000241 SimpleListPane Destructor And Entry Helpers Source-Quality Research

## Finalized Report / Current Recommendation

Assignment `B001-rework-report-000241-SimpleListPaneDestructorAndEntryHelpers-source-quality-20260627` amends the original report in place. Live IDA MCP evidence was obtained from session `b001_000241_20260627`; MCP was available during the original evidence pass and was rechecked successfully for this amendment. No IDA DB edits were made.

Recommended implementation result for [UID:000241] `by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md`:

- Keep [UID:000241] as a documentation/container aggregate for the exact SimpleListPane destructor/helper children and inter-function padding.
- Keep `CANONICAL_OWNER:0000D8`, `EMITTER_UIDS:0000D8`, and `RECONSTRUCTABLE:TRUE`.
- Raise the aggregate from current `COMPLETION:85` / `CONFIDENCE:89` to `COMPLETION:88` / `CONFIDENCE:90` after adding the live MCP evidence and no-code proof below.
- Do not add monolithic formal C++ to [UID:000241]. Instead insert the exact aggregate marker block listed in this report: a comment explaining that emitted code is supplied by child ranges, followed by `[[CHILDREN]]`.
- Keep [UID:0002LE] reconstructable/emitting and insert the exact `SimpleListPane::~SimpleListPane()` formal C++ body listed below. This resolves the destructor relationship by treating [UID:0002LE] as the source destructor body and [UID:0001HQ] as compiler-generated adjustor/scalar-deleting wrapper output.
- Keep [UID:0002LF]-[UID:0002LI] reconstructable/emitting and insert the exact inferred source C++ helper bodies listed below, using the accepted current source vocabulary `GetMemoryMan()->AllocateBufferMemory(...)`, `GetMemoryMan()->FreeBufferMemory(...)`, `ListPane::GetItemCount`, `ListPane::GetItem`, `ListPane::InsertItem`, and `ListPane::RemoveItems`.
- Do not split or reparent the range. The current child boundaries are correct and the direct owner remains `SimpleListPane` through [UID:0000D8].
- Update support wording on the target, child pages, and SimpleListPane class/file pages to replace stale generated-output and old-gate wording with the current evidence.

No fallback-only report was finalized. The report used IDA MCP for function boundaries, disassembly, decompilation, xrefs, byte checks, byte-pattern pointer searches, range signatures, strings/names/type searches, and server health.

## Evidence Checked

- Current Agent-B001 `goal.md`, including the required report path, report-only restrictions, and 2026-06-27 no-empty-emitter/formal-disposition amendment.
- Project-level `ntk-b-agent-workflow` skill and required B-agent research / Rule 26 references.
- `source-3/project-documentation/by-structure.md`.
- `source-3/project-documentation/by-memory/-guidance.md`.
- Target [UID:000241] `by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md`.
- Child pages:
  - [UID:0002LE] `by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md`
  - [UID:0002LF] `by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md`
  - [UID:0002LG] `by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md`
  - [UID:0002LH] `by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md`
  - [UID:0002LI] `by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md`
- Support pages:
  - [UID:0000D8] `by-class/SimpleListPane.md`
  - `by-file/SimpleListPane.md`
  - [UID:0001HP] `by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md`
  - [UID:0001HQ] `by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md`
  - [UID:0003OV] `by-memory/0x00624c64-0x00624d24.SimpleListPaneVtableData.md`
  - [UID:0003OU] `by-type/by-struct/SimpleListPaneLayout.md`
  - [UID:0000KT] `by-class/ListPane.md`
  - `by-file/ListPane.md`
  - [UID:0000KT aggregate] `by-memory/0x004f3a50-0x004f4a77.ListPane.md`
  - [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
  - [UID:0001BD] `by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md`
  - [UID:0001BF] `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
  - `auto-generated/NexusTK/util/MemoryMan.cpp`
- Read-only generated state:
  - `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
- Existing reports:
  - `executed-b-agent-research/B002/B002-MEMTOOL-00573C38-SimpleListPaneDestructorThunks.md`
  - `executed-b-agent-research/B003/0001HP-SimpleListPaneConstructor-source-quality.md`
- Supervisor assignment and local Agent-B001 notes.
- No stale Wave2/Wave3 source material was used as source-quality evidence. The current workspace has no `source-3/simroot_v2` or `source-3/core/data` tree.

## Current Documentation State

The target page currently records:

- `UID:000241`
- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000D8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000D8`
- Blank formal C++.

The child inventory is already structurally correct:

| Child | Range | Current page role | Current state |
| --- | --- | --- | --- |
| [UID:0002LE] | `0x00573a00-0x00573a98` | cleanup/destructor-adjacent entry-buffer cleanup | Current doc still has a blank formal block; this amendment requires the destructor C++ body below. |
| padding | `0x00573a98-0x00573aa0` | alignment | `0xCC` padding |
| [UID:0002LF] | `0x00573aa0-0x00573b08` | append copied text | Current doc still has a blank formal block; this amendment requires the `AppendText` body below. |
| padding | `0x00573b08-0x00573b10` | alignment | `0xCC` padding |
| [UID:0002LG] | `0x00573b10-0x00573b6d` | insert copied text | Current doc still has a blank formal block; this amendment requires the `InsertText` body below. |
| padding | `0x00573b6d-0x00573b70` | alignment | `0xCC` padding |
| [UID:0002LH] | `0x00573b70-0x00573bac` | remove copied text | Current doc still has a blank formal block; this amendment requires the `RemoveText` body below. |
| padding | `0x00573bac-0x00573bb0` | alignment | `0xCC` padding |
| [UID:0002LI] | `0x00573bb0-0x00573c38` | replace copied text | Current doc still has a blank formal block; this amendment requires the `ReplaceText` body below. |

Current generated output `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` is not zero-byte; it contains the accepted [UID:0001HP] constructor body and empty emitter markers for [UID:0000D8], [UID:000241], [UID:0002LE], [UID:0002LF], [UID:0002LG], [UID:0002LH], [UID:0002LI], [UID:0001HQ], and [UID:0001W3]. Its marker scores are stale relative to current by-* docs, so implementation should refresh through validators rather than hand-edit generated output.

## IDA MCP Availability And Session Evidence

MCP availability was verified live:

- JSON-RPC `initialize` and `tools/list` succeeded.
- Initial `idb_list` returned no sessions, so the existing IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` was opened read-only for this research with `idb_open`.
- Opened session: `b001_000241_20260627`.
- Module: `NexusTK.exe`.
- Imagebase: `0x400000`.
- Health after open: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- One broad `search_text` query for `SimpleListPane.cpp` timed out after 60 seconds. Follow-up health checks remained `status:"ok"`, and narrower `entity_query` calls succeeded. This was a single expensive-query timeout, not MCP unavailability.
- No write/edit MCP operation was used.

2026-06-27 amendment recheck:

- TCP listener check for `127.0.0.1:13337` succeeded.
- Process check showed `idalib-mcp` PID `10020` and active Python worker processes, including session worker PID `23132`.
- JSON-RPC `initialize` succeeded and returned server `ida-pro-mcp` version `1.0.0`.
- JSON-RPC `tools/list` succeeded.
- `idb_list` returned active session `b001_000241_20260627`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID / worker PID `23132`, `is_analyzing:false`.
- `server_health(database=b001_000241_20260627)` returned `status:"ok"`, uptime about `881` seconds, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and string-cache size `2067`.
- Amendment `lookup_funcs` confirmed current modeled allocator/destructor functions: `0x00516030` size `0x6`, `0x00516050` size `0x7e`, `0x00516170` size `0x14`, `0x00573a00` size `0x98`, `0x00573c38` size `0xb`, `0x00573c43` size `0xb`, and `0x00573c50` size `0xc5`.
- Amendment `decompile` reconfirmed `0x00516050` as the `malloc(size)` / pointer-throw allocation wrapper represented in docs as `MemoryMan::AllocateBufferMemory(size_t size)`.
- Amendment `decompile` reconfirmed `0x00516170` as `free(buffer); return 0;`, represented in docs as `MemoryMan::FreeBufferMemory(void *buffer)`.
- Amendment `decompile` reconfirmed `0x00573a00` and `0x00573c50` share the same copied-entry cleanup loop; `0x00573c50` additionally contains the scalar-deleting flag branch through `0x004f4ac0`.
- Amendment `xrefs_to` reconfirmed no xrefs to `0x00573a00`, vtable data refs to `0x00573c38` / `0x00573c43`, and thunk plus vtable refs to `0x00573c50`. This supports treating [UID:0002LE] as the source destructor body and [UID:0001HQ] as compiler-generated destructor wrapper/thunk output rather than emitting two source destructors.

## IDA MCP Function And Boundary Evidence

`lookup_funcs` results:

| Address | MCP result |
| --- | --- |
| `0x005739a0` | not a function |
| `0x005739f6` | not a function |
| `0x00573a00` | function `sub_573A00`, size `0x98` |
| `0x00573a98` | not a function |
| `0x00573aa0` | not a function |
| `0x00573b08` | not a function |
| `0x00573b10` | not a function |
| `0x00573b6d` | not a function |
| `0x00573b70` | not a function |
| `0x00573bac` | not a function |
| `0x00573bb0` | not a function |
| `0x00573c38` | function `sub_573C38`, size `0xb` |
| `0x00573c43` | function `sub_573C43`, size `0xb` |
| `0x00573c50` | function `sub_573C50`, size `0xc5` |

This confirms [UID:000241] ends exactly before the destructor-thunk page at `0x00573c38`. The target should not absorb [UID:0001HQ].

Padding byte checks:

| Range start | Bytes |
| --- | --- |
| `0x005739f6` | ten `0xCC` bytes |
| `0x00573a98` | eight `0xCC` bytes |
| `0x00573b08` | eight `0xCC` bytes |
| `0x00573b6d` | three `0xCC` bytes |
| `0x00573bac` | four `0xCC` bytes |
| `0x00573c35` | `c2 08 00`, the `retn 8` ending [UID:0002LI] |

`make_signature_for_range` returned unique signatures for all four raw helper ranges:

- `0x00573aa0-0x00573b08`
- `0x00573b10-0x00573b6d`
- `0x00573b70-0x00573bac`
- `0x00573bb0-0x00573c38`

These signatures support the current raw helper boundaries even though IDA does not model those raw starts as functions.

## IDA MCP Behavioral Evidence

### `0x00573a00` cleanup routine

MCP decompilation of `sub_573A00` shows a `__thiscall` routine that:

- Restores SimpleListPane vtable pointers.
- Reads the inherited list state pointer at `this + 0x130`.
- Uses the list count at `list + 0x0c`.
- Loops over entries by index.
- Calls the ListPane indexed accessor at `0x004f3dc0`.
- If the returned slot points to a buffer, frees it through `0x00516030` / `0x00516170`, then clears the slot.
- Calls `0x004f3b60` at the end.

MCP disassembly confirms the same shape: `edi` holds `this`, vtable stores target `0x00624c64`, `0x00624cec`, and `0x00624d1c`, the loop begins near `0x00573a50`, the indexed accessor call is at the loop head, and the routine returns at `0x00573a97`.

This is SimpleListPane-owned cleanup behavior, but it is not enough by itself to write one source-level destructor body in [UID:000241]. The destructor thunk/scalar deleting destructor range begins at [UID:0001HQ] `0x00573c38`, and source output must avoid duplicating destructor text across [UID:0002LE] and [UID:0001HQ].

### `0x00573aa0-0x00573b08` append helper

MCP `insn_query` shows a raw helper with normal prologue and `retn 4`:

- Preserves `ecx` as `this`.
- Calls `0x004f3bd0` to get the current item count.
- Reads the text argument from `[ebp+8]`.
- Computes a UTF-16 string length.
- Allocates/initializes a copied wide-string buffer through `0x00516030` / `0x00516050`.
- Copies text with `_wcscpy_s`.
- Pushes the address of the local copied pointer and the old count.
- Calls `0x004f3c00`.

Behavioral role: append a copied text pointer at the end of the inherited ListPane list.

### `0x00573b10-0x00573b6d` insert helper

MCP `insn_query` shows a raw helper with `retn 8`:

- Reads index from `[ebp+8]` and text from `[ebp+0c]`.
- Computes a UTF-16 string length.
- Allocates/initializes/copies a wide-string buffer through the same allocation path.
- Pushes the copied pointer and caller-supplied index.
- Calls `0x004f3c00`.

Behavioral role: insert a copied text pointer into the inherited ListPane list at an explicit index.

### `0x00573b70-0x00573bac` remove helper

MCP `insn_query` shows a raw helper with `retn 4`:

- Reads index from `[ebp+8]`.
- Calls `0x004f3dc0` to retrieve the indexed entry.
- If a copied pointer exists, frees it through `0x00516030` / `0x00516170` and clears the slot.
- Pushes count `1` and the index.
- Calls `0x004f3d60`.

Behavioral role: remove one copied text entry from the inherited ListPane list.

### `0x00573bb0-0x00573c38` replace helper

MCP `insn_query` shows a raw helper with `retn 8`:

- Reads index from `[ebp+8]` and replacement text from `[ebp+0c]`.
- Retrieves the current slot through `0x004f3dc0`.
- Frees and clears the old copied pointer if present.
- Removes one item through `0x004f3d60`.
- Allocates/initializes/copies the replacement wide-string buffer.
- Inserts the replacement through `0x004f3c00`.

Behavioral role: replace one copied text entry at an inherited ListPane index.

## ListPane Callee Evidence

MCP decompilation of ListPane helper callees supports the current role names:

| Callee | Evidence-backed role |
| --- | --- |
| `0x004f3bd0` | returns `this[76] ? *(this[76] + 0x0c) : 0`; current best role is `GetItemCount` |
| `0x004f3c00` | inserts into primary list at `this + 0x130`, mirrors selection state into `this + 0x138`, calls layout/refresh; current best role is `InsertItem` |
| `0x004f3d60` | removes from primary and parallel lists, invalidates, resets selected index, calls selection update; current best role is `RemoveItems` |
| `0x004f3dc0` | dispatches primary-list vtable slot `+0x10` with the caller's index; current best role is `GetItem` or `GetEntryAt`, not selected-entry-only |

The current [UID:000241] page should refer to the indexed accessor as row/item lookup, not as selected-item lookup.

## Xrefs, Pointer Searches, And Negative Evidence

MCP `xrefs_to` results for starts:

| Target | Xref result |
| --- | --- |
| `0x00573a00` | zero xrefs |
| `0x00573aa0` | zero xrefs |
| `0x00573b10` | zero xrefs |
| `0x00573b70` | zero xrefs |
| `0x00573bb0` | zero xrefs |
| `0x00573c38` | data xref from `0x00624cec` |
| `0x00573c43` | data xref from `0x00624d1c` |
| `0x00573c50` | code refs from thunks `0x00573c3e` and `0x00573c49`, data xref from `0x00624c64` |

MCP `xrefs_to` for SimpleListPane vtable bases:

| Vtable base | Xrefs |
| --- | --- |
| `0x00624c64` | constructor `0x005739d3`, cleanup `0x00573a2f`, scalar destructor `0x00573c7f` |
| `0x00624cec` | constructor `0x005739db`, cleanup `0x00573a35`, scalar destructor `0x00573c85` |
| `0x00624d1c` | constructor `0x005739e5`, cleanup `0x00573a3f`, scalar destructor `0x00573c8f` |

MCP byte-pattern pointer searches found no absolute or RVA pointer references for the four raw helper starts:

- `a0 3a 57 00` and `a0 3a 17 00`
- `10 3b 57 00` and `10 3b 17 00`
- `70 3b 57 00` and `70 3b 17 00`
- `b0 3b 57 00` and `b0 3b 17 00`

MCP `entity_query` / type searches:

- `*SimpleListPane*` strings: one RTTI string at `0x0067918c`, `.?AVSimpleListPane@@`.
- `*SimpleListPane.cpp*`: no string hits.
- `*ListPane.cpp*`: no string hits.
- `*ClientItemMenuItemList*`: one RTTI string at `0x00677a64`, not ownership evidence for this target.
- Names matching `*SimpleListPane*`: vtables and RTTI metadata only.
- `type_query` for `*SimpleListPane*` and `*ListPane*`: zero type hits.
- `search_structs *SimpleListPane*`: zero structure hits.

Conclusion: there is no recovered source filename, IDA UDT, exported method symbol, direct caller, or function-pointer table that proves original helper method spellings. The raw helper behavior is strong; original source-facing names are not proven.

## Source Ownership And Placement

`SimpleListPane` remains the direct source owner:

- The cleanup routine writes SimpleListPane vtables and frees the list entries owned by SimpleListPane's text-helper family.
- The four raw helpers operate on inherited ListPane storage but implement SimpleListPane-specific copied wide-string ownership.
- `SimpleListPaneLayout` shows no local fields beyond inherited ListPane state; the relevant storage is inherited at `+0x130` / related ListPane offsets.
- `ListPane` supplies generic list operations; it does not own the copied wide-string policy.
- The current generated file root `NexusTK/ui/controls/SimpleListPane.cpp` is the best placement. No live evidence supports moving this family into `ListPane.cpp`.

Recommended implementation wording: keep `SimpleListPane.cpp` as the owning generated source root, with a note that the class is a thin ListPane subclass whose source-authored methods mostly wrap inherited list storage with copied text lifetime management.

## Helper Name Reanalysis

The current page names `AppendCopiedText`, `InsertCopiedText`, `RemoveCopiedText`, and `ReplaceCopiedText` are accurate descriptive documentation names. They should not be treated as recovered original symbols, but lack of recovered original symbols is no longer an acceptable reason to leave formal C++ blank.

For formal child C++ on [UID:0002LF]-[UID:0002LI], avoid baking the word `Copied` into the source-facing method name. Copying is the implementation policy, not necessarily the public API spelling. The best current source-facing inferred method family is:

- `SimpleListPane::AppendText(const wchar_t *text)`
- `SimpleListPane::InsertText(int index, const wchar_t *text)`
- `SimpleListPane::RemoveText(int index)`
- `SimpleListPane::ReplaceText(int index, const wchar_t *text)`

Alternative `String` spellings remain plausible, especially `AppendString` / `InsertString` / `RemoveString` / `ReplaceString`, but MCP did not recover evidence to choose them over `Text`. The implementation callback should explicitly document these as inferred source-facing names, not recovered symbols, and still insert the exact formal C++ below.

## Formal Dispositions

This amendment closes the no-empty-emitter blocker. No item in [UID:000241] / [UID:0002LE]-[UID:0002LI] should remain `RECONSTRUCTABLE:TRUE` with nonblank `EMITTER_UIDS` and a plain blank formal block.

### [UID:000241] aggregate

Keep:

- `CANONICAL_OWNER:0000D8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000D8`
- `COMPLETION:88`
- `CONFIDENCE:90`

Insert this exact content between the managed `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines:

```cpp
// Emitted code for this aggregate is supplied by exact child ranges [UID:0002LE]-[UID:0002LI].
[[CHILDREN]]
```

This is valid because the parent range is a container over exact child bodies and padding. `[[CHILDREN]]` is the validator-supported insertion point for child snippets; it avoids monolithic aggregate C++ while ensuring the parent is no longer a plain empty emitter.

### [UID:0002LE] destructor source body

Keep:

- `CANONICAL_OWNER:000241`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000241`
- Recommended score: `COMPLETION:89`, `CONFIDENCE:91`

Insert this exact formal C++:

```cpp
SimpleListPane::~SimpleListPane()
{
    for (int index = 0; index < GetItemCount(); ++index) {
        wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
        if (*textSlot != NULL) {
            GetMemoryMan()->FreeBufferMemory(*textSlot);
            *textSlot = NULL;
        }
    }
}
```

Rationale: MCP shows `0x00573a00` is a real `0x98`-byte non-deleting destructor body with no direct xrefs, while `0x00573c50` duplicates the same cleanup and adds scalar-deleting flag handling. That is the usual MSVC split between the source destructor body and compiler-generated deleting-destructor wrapper. The source body belongs on [UID:0002LE]; [UID:0001HQ] should no longer be treated as the source destructor emitter. The `GetItemCount()` spelling is the source-facing ListPane count role; the binary's direct inherited count read is compatible with inlined/base storage access in the destructor. `GetItem(index)` matches the live `0x004f3dc0` indexed accessor evidence, and `GetMemoryMan()->FreeBufferMemory(...)` is the accepted current MemoryMan source vocabulary for `0x00516030` + `0x00516170`.

### [UID:0002LF] append helper

Keep:

- `CANONICAL_OWNER:000241`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000241`
- Recommended score: `COMPLETION:89`, `CONFIDENCE:90`

Insert this exact formal C++:

```cpp
void SimpleListPane::AppendText(const wchar_t *text)
{
    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(GetItemCount(), &copiedText);
}
```

Rationale: MCP shows `retn 4`, the current-count call to `0x004f3bd0`, UTF-16 length scan, allocation through `0x00516030` / `0x00516050`, `_wcscpy_s`, and insertion through `0x004f3c00` using the old count as the append index. `AppendText` is inferred, not recovered, but is the best source-facing method name for this behavior.

### [UID:0002LG] insert helper

Keep:

- `CANONICAL_OWNER:000241`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000241`
- Recommended score: `COMPLETION:89`, `CONFIDENCE:90`

Insert this exact formal C++:

```cpp
void SimpleListPane::InsertText(int index, const wchar_t *text)
{
    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(index, &copiedText);
}
```

Rationale: MCP shows `retn 8`, first argument as index, second argument as text, UTF-16 length scan, allocation/copy through the accepted MemoryMan path, and `0x004f3c00` insertion at the supplied index.

### [UID:0002LH] remove helper

Keep:

- `CANONICAL_OWNER:000241`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000241`
- Recommended score: `COMPLETION:89`, `CONFIDENCE:90`

Insert this exact formal C++:

```cpp
void SimpleListPane::RemoveText(int index)
{
    wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
    if (*textSlot != NULL) {
        GetMemoryMan()->FreeBufferMemory(*textSlot);
        *textSlot = NULL;
    }
    RemoveItems(index, 1);
}
```

Rationale: MCP shows `retn 4`, indexed slot lookup through `0x004f3dc0`, free/clear through `0x00516030` / `0x00516170`, then `0x004f3d60(index, 1)`.

### [UID:0002LI] replace helper

Keep:

- `CANONICAL_OWNER:000241`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000241`
- Recommended score: `COMPLETION:89`, `CONFIDENCE:90`

Insert this exact formal C++:

```cpp
void SimpleListPane::ReplaceText(int index, const wchar_t *text)
{
    wchar_t **textSlot = static_cast<wchar_t **>(GetItem(index));
    if (*textSlot != NULL) {
        GetMemoryMan()->FreeBufferMemory(*textSlot);
        *textSlot = NULL;
    }
    RemoveItems(index, 1);

    const size_t textLength = wcslen(text);
    wchar_t *copiedText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory((textLength + 1) * sizeof(wchar_t)));
    wcscpy_s(copiedText, textLength + 1, text);
    InsertItem(index, &copiedText);
}
```

Rationale: MCP shows `retn 8`, indexed old-slot lookup/free/clear, one-item removal, replacement text length scan, allocation/copy, and reinsertion at the same index.

### [UID:0001HQ] destructor wrapper relationship

The implementation callback should update [UID:0001HQ] as support if the supervisor accepts this report:

- Change `RECONSTRUCTABLE:FALSE`.
- Change `EMITTER_UIDS:` to blank.
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank.
- Recommended score after support update: `COMPLETION:88`, `CONFIDENCE:91`.

Rationale: [UID:0001HQ] contains two adjustor thunks and the scalar deleting destructor wrapper. Current MCP shows vtable references to the thunks/wrapper and duplicate cleanup logic in `0x00573c50`, plus compiler scalar-delete flag handling through `0x004f4ac0`. Once [UID:0002LE] emits the source destructor body, [UID:0001HQ] has no separate handwritten source construct to emit. Its role should be documented as compiler-generated destructor wrapper/thunk output for the source destructor represented by [UID:0002LE].

## Score Recommendation

Recommended scores after implementation:

| UID | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| [UID:000241] | `85/89` | `88/90` | Aggregate ownership, range shape, child boundaries, padding, live MCP evidence, generated-state wording, and exact `[[CHILDREN]]` formal disposition are resolved. |
| [UID:0002LE] | `86/91` | `89/91` | Source destructor body is now assigned to the non-deleting destructor body with exact formal C++; [UID:0001HQ] duplicate wrapper relationship is resolved. |
| [UID:0002LF] | `86/88` | `89/90` | Append helper now has exact inferred source C++ and accepted MemoryMan/ListPane vocabulary. |
| [UID:0002LG] | `86/88` | `89/90` | Insert helper now has exact inferred source C++ and accepted MemoryMan/ListPane vocabulary. |
| [UID:0002LH] | `86/88` | `89/90` | Remove helper now has exact inferred source C++ and accepted MemoryMan/ListPane vocabulary. |
| [UID:0002LI] | `86/88` | `89/90` | Replace helper now has exact inferred source C++ and accepted MemoryMan/ListPane vocabulary. |
| [UID:0001HQ] support | `86/91` | `88/91` with `RECONSTRUCTABLE:FALSE` | The page becomes a compiler-generated destructor thunk/scalar-deleting wrapper page once [UID:0002LE] emits the source destructor body. |

Do not raise these pages into final-audit tier merely because the behavior is understood. Original helper spellings remain inferred, not recovered, and final class/header declarations are broader source-file work.

## Required Implementation Changes

A later implementation callback should make these scoped edits after taking normal leases:

1. Update [UID:000241] `by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md`.
   - Change metadata to `COMPLETION:88` and `CONFIDENCE:90`.
   - Keep owner/emitter/reconstructable unchanged.
   - Add the live MCP evidence summary from this report.
   - Add the no-code proof for the parent aggregate.
   - State that generated `SimpleListPane.cpp` currently contains the constructor and empty/stale markers for the destructor/helper family, not a zero-byte file.
   - Insert this exact formal block:

```cpp
// Emitted code for this aggregate is supplied by exact child ranges [UID:0002LE]-[UID:0002LI].
[[CHILDREN]]
```

2. Update [UID:0002LE] `by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md`.
   - Change metadata to `COMPLETION:89` and keep `CONFIDENCE:91`.
   - Keep `CANONICAL_OWNER:000241`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000241`.
   - Replace stale "below old gate" wording with the source-destructor-body decision.
   - Add the live MCP evidence for vtable stores, list-count loop, indexed accessor, buffer free/clear, and `0x004f3b60` cleanup.
   - Insert the exact `SimpleListPane::~SimpleListPane()` formal C++ block from this report.

3. Update [UID:0002LF]-[UID:0002LI].
   - Change each child to `COMPLETION:89` and `CONFIDENCE:90`.
   - Keep each child as `CANONICAL_OWNER:000241`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000241`.
   - Add the raw-start MCP evidence and no direct caller/pointer-table evidence.
   - Record the behavior summaries and signatures from this report.
   - Record `AppendText` / `InsertText` / `RemoveText` / `ReplaceText` as inferred source-facing names.
   - Insert the exact formal C++ blocks from this report.

4. Update [UID:0000D8] `by-class/SimpleListPane.md` and `by-file/SimpleListPane.md`.
   - Note that the constructor now emits in generated output.
   - Note that [UID:000241] now emits a child insertion marker, [UID:0002LE] owns the source destructor body, and [UID:0002LF]-[UID:0002LI] emit inferred `AppendText` / `InsertText` / `RemoveText` / `ReplaceText` helper bodies.
   - Replace old zero-byte / empty-marker / old-gate wording with the current generated-output and formal-disposition state.
   - Keep `SimpleListPane.cpp` as the preferred generated root.

5. Update [UID:0001HQ] `by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md`.
   - Change `RECONSTRUCTABLE:FALSE`.
   - Change `EMITTER_UIDS:` to blank.
   - Keep formal C++ blank because the page is reclassified as compiler-generated adjustor/scalar-deleting destructor wrapper output.
   - Recommended score: `COMPLETION:88`, `CONFIDENCE:91`.
   - Add the relationship note that [UID:0002LE] emits the source `SimpleListPane::~SimpleListPane()` body; [UID:0001HQ] records the compiler-generated thunk/wrapper variants and must not duplicate source destructor text.

## Implementation Tracking Checklist

- [x] Take implementation leases only after report-only research is complete. Required paths: target [UID:000241], children [UID:0002LE]-[UID:0002LI], support [UID:0001HQ], `by-class/SimpleListPane.md`, and `by-file/SimpleListPane.md`.
  - Proof: `leaser.py B001 lease ...` returned `Success` for all nine approved by-* paths before edits.
- [x] Update [UID:000241] score to `88/90`, preserve `CANONICAL_OWNER:0000D8`, `EMITTER_UIDS:0000D8`, and `RECONSTRUCTABLE:TRUE`.
  - Proof: validator command `000000004612`, timestamp `2026-06-27T21:56:18-04:00`, exit `0`, `ok: 1`.
- [x] Add the live MCP evidence and explicit parent aggregate no-code proof to [UID:000241].
  - Proof: [UID:000241] now records MCP session `b001_000241_20260627`, modeled starts, padding, no raw-start xrefs/pointer hits, and `[[CHILDREN]]` aggregate disposition.
- [x] Insert the exact [UID:000241] formal block containing the child-coverage comment plus `[[CHILDREN]]`.
  - Proof: [UID:000241] formal block now contains the child-coverage comment and `[[CHILDREN]]`; validator normalized UID references in the comment but preserved the marker and generated child output.
- [x] Update [UID:0002LE] to `89/91`, keep owner/emitter/reconstructable metadata, replace stale old-gate wording, and insert the exact `SimpleListPane::~SimpleListPane()` formal C++ from this report.
  - Proof: validator command `000000004614`, timestamp `2026-06-27T21:56:37-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0002LF] to `89/90`, keep owner/emitter/reconstructable metadata, and insert the exact `SimpleListPane::AppendText(const wchar_t *text)` formal C++ from this report.
  - Proof: validator command `000000004616`, timestamp `2026-06-27T21:56:53-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0002LG] to `89/90`, keep owner/emitter/reconstructable metadata, and insert the exact `SimpleListPane::InsertText(int index, const wchar_t *text)` formal C++ from this report.
  - Proof: validator command `000000004617`, timestamp `2026-06-27T21:57:12-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0002LH] to `89/90`, keep owner/emitter/reconstructable metadata, and insert the exact `SimpleListPane::RemoveText(int index)` formal C++ from this report.
  - Proof: validator command `000000004618`, timestamp `2026-06-27T21:57:26-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0002LI] to `89/90`, keep owner/emitter/reconstructable metadata, and insert the exact `SimpleListPane::ReplaceText(int index, const wchar_t *text)` formal C++ from this report.
  - Proof: validator command `000000004620`, timestamp `2026-06-27T21:57:41-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0001HQ] to `88/91`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep formal C++ blank, and document it as compiler-generated destructor thunk/scalar-deleting wrapper output covered by [UID:0002LE]'s source destructor body.
  - Proof: validator command `000000004622`, timestamp `2026-06-27T21:57:56-04:00`, exit `0`, `ok: 1`; registry update changed [UID:0001HQ] `true -> false`.
- [x] Update SimpleListPane class/file support pages with current generated-output state, source-placement conclusion, destructor-body ownership on [UID:0002LE], [UID:0001HQ] wrapper reclassification, and helper method inferred-name decision.
  - Proof: class validator command `000000004623`, timestamp `2026-06-27T21:58:12-04:00`, exit `0`, `ok: 1`; file validator command `000000004624`, timestamp `2026-06-27T21:58:50-04:00`, exit `0`, `ok: 1`.
- [x] Run scoped validators from `source-3/project-documentation` after implementation edits, with `--wait-generated` for generated-output freshness.
  - Proof: all nine required scoped validator commands exited `0` with `ok: 1` and `generated_refresh: completed`.
- [x] Confirm `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` refreshes through the validator, contains the constructor, destructor, `AppendText`, `InsertText`, `RemoveText`, and `ReplaceText` output, and no plain empty emitter remains for [UID:000241] or [UID:0002LE]-[UID:0002LI].
  - Proof: generated file header reports validator command `000000004624`, refreshed `2026-06-27T21:58:50-04:00`, length `3750`; `rg` found `SimpleListPane::SimpleListPane`, `SimpleListPane::~SimpleListPane`, `AppendText`, `InsertText`, `RemoveText`, and `ReplaceText`, and no empty marker for [UID:000241] or [UID:0002LE]-[UID:0002LI].
- [x] Release implementation leases after validation.
  - Proof: `leaser.py B001 unlease` reported `B001: No active leases`; `tools/leaser/Agents/Agent-B001/current_leases.md` reports `No active leases`, and global `tools/leaser/Agents/current_leases.md` has no B001/SimpleListPane lease entries.
- [x] Keep this report in the assigned Agent-B001 research path until supervisor-directed executed-report archival.
  - Proof: no executed-report move was requested in this implementation callback; report checklist is updated in place.

Validator commands executed during this implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [000241-SimpleListPaneDestructorAndEntryHelpers-source-quality-removed.md](000241-SimpleListPaneDestructorAndEntryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No manual generated C++ or generated report edits are required; generated output should update only through validator/autogen.

## Final Status

`FINISHED_REPORT`

The current assignment is implementation-ready. All current-scope blockers named in `goal.md` were investigated with live MCP evidence: helper names, raw starts, destructor thunk roles, direct parent choice, source placement, split/container shape, blank formal C++, caller/reachability, and first-draft C++ readiness. Remaining limitations are documented negative evidence or implementation-policy choices, not unattempted research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md","timestamp":"2026-06-27T22:06:39","uid":"000241"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000241-SimpleListPaneDestructorAndEntryHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000241"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
