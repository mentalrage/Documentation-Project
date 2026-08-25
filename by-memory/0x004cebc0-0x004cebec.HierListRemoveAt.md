*** UID:0002II | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000065 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000065 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void HierList::RemoveAt(int index, int count)
{
    List::RemoveAt(index, count);
    if (index <= m_count - 1) {
        UpdateHierarchy(index, m_count - 1, false);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Delegates to base remove-at and repairs hierarchy links after removal. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x004cebc0-0x004cebec HierListRemoveAt

## Status

- Entity kind: class virtual method
- Owner: [UID:000065][HierList](by-class/HierList.md)
- Likely source file: [UID:0000JV][HierList](by-file/HierList.md)
- Parent aggregate: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- Address range: `0x004cebc0-0x004cebec`, half-open.
- IDA function: `sub_4CEBC0`, size `0x2c`.
- Rebuild handling: source-authored virtual method, reconstructable.
- Parent attachment: attached to [UID:000065][HierList](by-class/HierList.md) at position `110`; this page and the class parent both satisfy the 80/80 attachment gate.
- Formal C++ is now present. B010's 2026-07-01 implementation accepts the `void` remove override and shifted-range hierarchy repair.

## Signature

IDA decompiles the method as:

```c
int __thiscall sub_4CEBC0(_DWORD *this, int a2, int a3)
{
  int result;

  sub_4F33E0(this, a2, a3);
  result = this[3] - 1;
  if ( a2 <= result )
    return sub_4CED10(this, a2, result, 0);
  return result;
}
```

Current interpretation:

| Parameter | Meaning | Evidence |
| --- | --- | --- |
| `this` / `ecx` | `HierList` object | The method is stored in the `HierList` vtable slot at `0x0061b360`. |
| `a2` | first index to remove | Forwarded unchanged to base [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md) remove-range method and reused as the first index needing hierarchy repair. |
| `a3` | remove count | Forwarded unchanged to the base remove-range method. |
| return value | base/remove repair result | If repair runs, the return value is [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md)'s end-of-loop result; otherwise it returns `newCount - 1`. |

## Behavior

Overrides base removal to preserve hierarchy links after the base fixed-width array has shifted elements down. It delegates to the base [UID:000079][List](by-class/List.md) remove-range routine, computes `newCount - 1`, and repairs all remaining rows from the removal index through the new tail when that range is non-empty.

Step order:

1. Save the removal index in `edi` and the `HierList` object in `esi`.
2. Call base `List::RemoveRange(index, count)` at `0x004f33e0`.
3. Read the post-remove count from `this + 0x0c` and compute `lastIndex = count - 1`.
4. If `index <= lastIndex`, call `UpdateHierarchy(index, lastIndex, 0)` so shifted child lists and child nodes point at their new owning rows.
5. If the removed range was at or beyond the new tail, skip repair and return `lastIndex`.

The `clear` argument to `UpdateHierarchy` is `0`, so this path rewrites parent links to current row pointers rather than clearing them.

## Raw IDA Evidence

IDA MCP live recheck on 2026-06-06 confirms `sub_4CEBC0` at `0x004cebc0-0x004cebec`, size `0x2c`, in the active `NexusTK.exe` IDA database.

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x004cebb9` | not a function; start of preceding alignment padding |
| `0x004cebc0` | `sub_4CEBC0`, size `0x2c` |
| `0x004cebeb` | inside `sub_4CEBC0` |
| `0x004cebec` | not a function; start of trailing alignment padding |
| `0x004cebf0` | next function `sub_4CEBF0`, size `0x32` |

Boundary and byte evidence:

```text
0x004cebb0: 55 8b ec 5d e9 07 48 02 00 cc cc cc cc cc cc cc
0x004cebc0: 55 8b ec 56 57 ff 75 0c 8b 7d 08 8b f1 57 e8 0d
0x004cebd0: 48 02 00 8b 46 0c 48 3b f8 7f 0b 6a 00 50 57 8b
0x004cebe0: ce e8 2a 01 00 00 5f 5e 5d c2 08 00 cc cc cc cc
0x004cebf0: 55 8b ec 53 56 8b 75 08 8b d9 57 8b 7d 0c 57 56
```

The preceding [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md) ends at `0x004cebb9`; `0x004cebb9-0x004cebc0` is `0xcc` padding. This method ends at `0x004cebec`; `0x004cebec-0x004cebf0` is padding before [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md).

Disassembly:

```asm
4cebc0  push    ebp
4cebc1  mov     ebp, esp
4cebc3  push    esi
4cebc4  push    edi
4cebc5  push    [ebp+arg_4]
4cebc8  mov     edi, [ebp+arg_0]
4cebcb  mov     esi, ecx
4cebcd  push    edi
4cebce  call    sub_4F33E0
4cebd3  mov     eax, [esi+0Ch]
4cebd6  dec     eax
4cebd7  cmp     edi, eax
4cebd9  jg      short loc_4CEBE6
4cebdb  push    0
4cebdd  push    eax
4cebde  push    edi
4cebdf  mov     ecx, esi
4cebe1  call    sub_4CED10
4cebe6  pop     edi
4cebe7  pop     esi
4cebe8  pop     ebp
4cebe9  retn    8
```

Important instructions:

| Address | Evidence |
| --- | --- |
| `0x004cebce` | Calls base `List::RemoveRange` at `0x004f33e0` with `index` and `count`. |
| `0x004cebd3-0x004cebd9` | Reads the post-remove count from `this + 0x0c`, computes `newCount - 1`, and skips repair when the removed index is beyond the new tail. |
| `0x004cebdb-0x004cebe1` | Calls `UpdateHierarchy(index, newCount - 1, 0)` for the shifted remaining range. |
| `0x004cebe9` | Returns with `retn 8`, matching two stack arguments. |

## Callers, Callees, And State

Direct callers:

| Caller | Evidence |
| --- | --- |
| none modeled | IDA `callers` reports no direct code callers for `0x004cebc0`; IDA `xrefs_to` shows the vtable data reference at `0x0061b360`, so normal dispatch is virtual. |

Callees:

| Address | Role |
| --- | --- |
| `0x004f33e0` | Base [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md) remove-range method; shifts fixed-size rows left, shrinks allocation if a page becomes unused, and updates the count. |
| `0x004ced10` | [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md); rewrites child-list owner pointers and child-node parent pointers for the shifted range. |

Touched state:

| State | Use |
| --- | --- |
| `this + 0x0c` | Base `List` count field read after removal to determine the new last valid index. |
| base `List` backing storage | Shifted and possibly reallocated by the base remove-range call. |
| `HierListNode + 0x04` child-list pointer | Repaired indirectly by `UpdateHierarchy` when shifted nodes own child lists. |
| child-list `+0x14` owner pointer | Rewritten by `UpdateHierarchy` for child lists under shifted rows. |
| child node `+0x00` parent pointer | Rewritten by `UpdateHierarchy` for each child node in a shifted child list. |
| `0x0061b360` | `HierList` vtable slot for this remove override. |

## Evidence

- IDA MCP `py_eval` confirmed an IDA function object at `0x004cebc0-0x004cebec`, size `0x2c`.
- IDA xrefs show this method in the `HierList` vtable at `0x0061b360`.
- IDA xrefs to `0x004ced10` include the update call from `0x004cebe1`.
- IDA `callees` reports calls to `sub_4F33E0` and `sub_4CED10`; `xrefs_to 0x004f33e0` includes this method's call at `0x004cebce`.

## Confidence And Caveats

The behavior, range, vtable slot, base remove call, repair condition, and surrounding padding are strong. Final source representation should wait for the surrounding class and base virtual interface audit, especially around exact source names for range removal and the return-value convention.

## Cross-References

- [UID:000065][HierList](by-class/HierList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:000079][List](by-class/List.md)
- [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md)
- [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md)
- [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md)

## Changes

- 2026-07-01 B010 accepted empty-emitter family implementation:
  - Raised this override page to `COMPLETION:90`, `CONFIDENCE:92` and inserted formal `void HierList::RemoveAt(int index, int count)` C++.
  - Current MCP decompile of `0x004cebc0` shows base `List::RemoveAt(index, count)` followed by repair of the remaining shifted range when `index <= m_count - 1`: `UpdateHierarchy(index, m_count - 1, false)`.
  - The decompiler return is rejected as a register artifact because accepted List and HierList mutation APIs are source-facing `void`. The visible behavior is base removal plus hierarchy parent/owner repair.

- 2026-06-06 A005 live IDA recheck:
  - Before: page was a `75/88` summary with blank autogen parent and only high-level base-remove/update evidence.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, `AUTOGEN_PARENT_UID:000065`, `AUTOGEN_PARENT_POSITION_OPTIONAL:110`, expanded signature/parameter interpretation, exact boundary bytes, disassembly, caller/callee/state tables, vtable-slot notes, and final-source caveats.
  - Summary/evidence: IDA MCP `lookup_funcs`, `decompile`, `disasm`, `callers`, `callees`, `xrefs_to`, and byte inspection confirm the exact `0x004cebc0-0x004cebec` range, surrounding padding, vtable slot `0x0061b360`, base remove call at `0x004cebce`, post-remove `newCount - 1` comparison, hierarchy repair call at `0x004cebe1`, and attachment to the high-confidence `HierList` class owner.
