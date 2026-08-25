** TARGET-REPORT-UID:00016X **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-hierlist-source-quality-00016X-20260617

Agent: Agent-B001

Primary target: [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`

Report date: 2026-06-17

Result: supervisor execution recommended; no shared by-* files were edited in this pass.

## Scope And Leaser Compliance

I followed the B001 goal and notes for the HierList source-quality assignment. This pass was read-only for shared documentation and wrote only this durable report under the Agent-B001 research folder. The B001 split exception was not used because the required repair is a supervisor-owned metadata/routing change and coverage-report replacement, not an emergency direct by-structure split edit.

Do not directly edit `by-memory/-coverage-report.md` from this agent report. Exact replacement rows are provided below for supervisor application.

## Executive Recommendation

[UID:00016X] should not remain a reconstructable/emitting source unit. It should become a reviewed non-emitting method-cluster/split index for the contiguous HierList code island. The exact child pages [UID:0002I8]-[UID:0002IM] already carry the source-bearing method bodies and should remain the reconstructable/emitting units under [UID:000065] `HierList`, which then emits through [UID:0000JV] `NexusTK/util/HierList.cpp`.

Recommended target metadata:

| UID | Completion | Confidence | Canonical owner | Reconstructable | Emitters | C++ |
|---|---:|---:|---|---|---|---|
| 00016X | 88 | 91 | 000065 | FALSE | blank | blank |

Reason: [UID:00016X] is a physical aggregate of exact method children and padding. Keeping it `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0000JV` duplicates the class/source route already owned by the exact children and creates a blank aggregate source emission candidate. Current by-structure rules say this kind of container/index should be non-emitting when exact children own the source.

No child split repair is required. The child ranges are exact, the raw wrappers are real executable ranges even though IDA did not model them as functions, and the `0x004cee52-0x004cee60` successor padding before HourPane is confirmed.

## Evidence Reviewed

Documentation reviewed:

- `by-memory/0x004ce730-0x004cee52.HierList.md`
- child pages [UID:0002I8]-[UID:0002IM]
- `by-class/HierList.md`
- `by-file/HierList.md`
- `by-type/by-struct/HierListNode.md`
- `by-class/List.md`
- `by-file/List.md`
- `by-class/Layer.md`
- `by-file/Layer.md`
- `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`
- `by-memory/0x004cee60-0x004cf1ef.HourPane.md`
- `by-memory/0x0061b36c-0x0061b444.HourPaneVtableResourceData.md`
- `by-memory/-coverage-report.md` lines 1591-1620, read-only
- `auto-generated/-ag-memory-coverage.md`, read-only duplicate-route check

Live IDA MCP checks:

- `lookup_funcs` across `0x004ce730-0x004cee60`
- `get_bytes` around `0x004ce7d0`, `0x004cee40`, and `0x0061b340`
- `disasm` for the raw wrappers and `FindNodeByData`
- `xrefs_to` for method starts, vtable, and Layer callers
- `analyze_function` for constructor, destructors, insert/remove/search/update methods
- `analyze_component` for the HierList island call graph
- `entity_query` for `HierList`, `HourPane`, and attempted node-name recovery

Wave2/Wave3 generated source was not used as source authority. Existing project documentation that notes generated HierList omissions was used only as a support-doc consistency check.

## Exact Range And Boundary Findings

The child partition is correct:

| UID | Range | Role | Finding |
|---|---|---|---|
| 0002I8 | `0x004ce730-0x004ce760` | constructor | IDA function `sub_4CE730`, exact 0x30 bytes |
| 0002I9 | `0x004ce760-0x004ce7d1` | non-deleting destructor | IDA function `sub_4CE760`, exact 0x71 bytes |
| 0002IA | `0x004ce7e0-0x004ce839` | tail insert wrapper | real raw code, not an IDA function |
| 0002IB | `0x004ce840-0x004ce854` | default insert wrapper | real raw code, not an IDA function |
| 0002IC | `0x004ce860-0x004ce9ad` | insert-before core | IDA function `sub_4CE860`, exact 0x14d bytes |
| 0002ID | `0x004ce9b0-0x004ceafc` | insert-after core | IDA function `sub_4CE9B0`, exact 0x14c bytes |
| 0002IE | `0x004ceb00-0x004ceb45` | remove node | IDA function `sub_4CEB00`, exact 0x45 bytes |
| 0002IF | `0x004ceb50-0x004ceb62` | get element/payload | IDA function `sub_4CEB50`, exact 0x12 bytes |
| 0002IG | `0x004ceb70-0x004ceba9` | virtual insert-at | IDA function `sub_4CEB70`, exact 0x39 bytes |
| 0002IH | `0x004cebb0-0x004cebb9` | virtual append | IDA function `sub_4CEBB0`, exact 0x09 bytes |
| 0002II | `0x004cebc0-0x004cebec` | virtual remove-at | IDA function `sub_4CEBC0`, exact 0x2c bytes |
| 0002IJ | `0x004cebf0-0x004cec22` | virtual swap | IDA function `sub_4CEBF0`, exact 0x32 bytes |
| 0002IK | `0x004cec30-0x004ced0f` | recursive find | IDA function `sub_4CEC30`, exact 0xdf bytes |
| 0002IL | `0x004ced10-0x004ceda4` | hierarchy link repair | IDA function `sub_4CED10`, exact 0x94 bytes |
| 0002IM | `0x004cedb0-0x004cee52` | scalar deleting destructor | IDA function `sub_4CEDB0`, exact 0xa2 bytes |

Internal padding is all `0xcc` alignment:

- `0x004ce7d1-0x004ce7e0`
- `0x004ce839-0x004ce840`
- `0x004ce854-0x004ce860`
- `0x004ce9ad-0x004ce9b0`
- `0x004ceafc-0x004ceb00`
- `0x004ceb45-0x004ceb50`
- `0x004ceb62-0x004ceb70`
- `0x004ceba9-0x004cebb0`
- `0x004cebb9-0x004cebc0`
- `0x004cebec-0x004cebf0`
- `0x004cec22-0x004cec30`
- `0x004ced0f-0x004ced10`
- `0x004ceda4-0x004cedb0`

The next boundary is exact: `0x004cee52-0x004cee60` is `0xcc` padding and `0x004cee60` starts `HourPaneConstructor`. The related rdata boundary is also exact: the HierList vtable data ends before the HourPane locator/vtable at `0x0061b36c`.

## Heuristic / Inference Reanalysis And Validation

Best defensible source placement:

- `HierList` remains a utility class in `NexusTK/util/HierList.cpp`.
- Exact method pages [UID:0002I8]-[UID:0002IM] remain direct children of [UID:000065] `HierList`.
- [UID:00016X] becomes a non-emitting physical index owned by [UID:000065] or, if the supervisor prefers ownerless physical indexes, ownerless with blank emitter. My preferred route is owner [UID:000065], emitter blank, because every byte in the aggregate is class method code or padding for the class island.
- [UID:0000JV] remains the file-level source emitter for the class, not the direct owner of this aggregate island.

Best defensible type and field interpretation:

- `List` base layout is the first 0x14 bytes: vtable, row stride, page size, count, data pointer.
- `HierList + 0x14` is the owner/parent node for the current list instance. Constructor stores the incoming node there and writes the new `HierList*` into `ownerNode + 0x04`.
- `HierListNode + 0x00` is the parent node pointer for this row.
- `HierListNode + 0x04` is the child `HierList*`.
- `HierListNode + 0x08` is the caller-visible payload returned by `GetElementAt`.
- The row stride is `payloadSize + 0x0b`; compare/copy length is `this->List.elementSize - 0x0b`. This proves 8 bytes of visible hierarchy header plus 3 additional bytes in the list stride. No load/store evidence gives those 3 bytes independent semantics. They should be documented as trailing reserved/padding bytes in the binary stride, not named as flags.

Best defensible method names and source-facing roles:

- `HierList::HierList(int payloadSize, HierListNode* ownerNode)` for `0x004ce730`.
- `HierList::~HierList()` for the non-deleting destructor body at `0x004ce760`.
- Scalar deleting destructor at `0x004cedb0` is compiler ABI glue and should not be hand-authored as a normal source method.
- `TailInsertWrapper` is better source-facing as `AppendChild`, `InsertLast`, or `InsertAtTailOfParent`. It computes a root/child tail sibling then forwards to the insert core.
- `DefaultInsertWrapper` is better source-facing as `InsertFirst` or `InsertAtHead`. It forwards a null sibling to the insert core.
- Keep the documented public names `InsertBefore` and `InsertAfter` because Layer caller names support them. Internally, `InsertBefore` resolves a reference payload and inserts at `index + 1`; this means the reference parameter behaves like a predecessor/slot marker in the binary implementation even if the higher Layer API is named "before".
- `RemoveNode` is more precise as `RemoveByPayload`, but `RemoveNode` remains acceptable if the docs clearly state the input is a payload pointer, not a node pointer.
- `FindNodeByData` is more precise as `FindNodeByPayload`. It recursively compares `elementSize - 11` bytes at `row + 8`, returns the matched full row, and writes owner list plus zero-based index out parameters.
- `UpdateHierarchy` is better described as `RepairParentLinks` or `UpdateChildOwnerLinks`. It updates child-list owner pointers and child row parent pointers after insert/remove/swap.

Layer caller validation:

- `Layer::Layer` calls the constructor at `0x004f0562`.
- `Layer::AddChildAfter` calls `HierListInsertAfter` at `0x004f081a`.
- `Layer::AddChildBefore` calls `HierListInsertBefore` at `0x004f0a3b`.
- `Layer::RemoveChild` calls `HierListRemoveNode` at `0x004f0b25`.
- These xrefs prove Layer is the consumer and naming source for some public operations, but not owner. `HierList` has its own vtable, RTTI/vftable name, `List` base behavior, and util-file route.

Rejected alternatives:

- Keep [UID:00016X] as reconstructable/emitting through [UID:0000JV]: rejected. This duplicates exact child method emission and violates the by-structure split/index policy for physical aggregates.
- Move the aggregate or methods to `Layer`: rejected. Layer has caller evidence only; the code is a separate `HierList` utility with its own vtable and base class.
- Move the methods to `List`: rejected. `List` supplies generic storage and virtual slots, but HierList adds node headers, child lists, recursive lookup, and hierarchy repair.
- Extend the range into HourPane: rejected. `0x004cee52-0x004cee60` is padding and `0x004cee60` begins HourPane code. Vtable data likewise changes to HourPane at `0x0061b36c`.
- Treat the 3 extra stride bytes as known flags: rejected. They are part of the observed row stride, but no observed method reads or writes them semantically.
- Hand-author the scalar deleting destructor as ordinary source: rejected. It is vtable ABI glue with delete flags and should be represented as compiler-generated behavior, while the non-deleting destructor body is the source destructor.

Score, source-placement, and final-C++ impact:

- The aggregate can safely rise from `82/88` to `88/91` after reclassifying to a non-emitting split/index because range, padding, children, boundary, and ownership are now resolved.
- Child pages should remain reconstructable and class-owned. Several current child coverage rows are stale and should be raised to match current page/evidence scores.
- Formal C++ should remain blank on the aggregate permanently.
- Formal C++ on exact children should remain blank for this repair cycle, despite many pages meeting the numeric gate, until a coordinated class declaration/source pass sets the method signatures, node struct spelling, and ABI destructor policy consistently.

## First-Draft C++ Recommendation

Formal C++ for [UID:00016X] should remain blank because the aggregate should be `RECONSTRUCTABLE:FALSE` and non-emitting.

Formal C++ for the exact child methods should also remain blank in this specific supervisor repair cycle. The child pages are source-bearing and route correctly, but placing isolated snippets now would lock in unresolved source spellings across the class declaration, `HierListNode` flexible payload representation, the two raw wrapper overload names, and scalar deleting destructor policy. The safer source-quality action is to fix aggregate routing now, then do one class-wide source pass for [UID:000065].

Review-only source shape for that future pass:

```cpp
struct HierListNode {
    HierListNode* parent;
    HierList* children;
    unsigned char payload[1];
};

class HierList : public List {
public:
    HierList(int payloadSize, HierListNode* ownerNode);
    virtual ~HierList();

    void InsertAtTailOfParent(const void* parentPayload, const void* payload);
    void InsertAtHead(const void* parentPayload, const void* payload);
    void InsertBefore(const void* parentPayload, const void* siblingPayload, const void* payload);
    void InsertAfter(const void* parentPayload, const void* siblingPayload, const void* payload);
    void RemoveByPayload(const void* payload);

    void* GetElementAt(int index) override;
    int InsertAt(int index, const void* rows, int count) override;
    int Append(const void* rows, int count) override;
    int RemoveAt(int index, int count) override;
    int SwapElements(int first, int second) override;

private:
    HierListNode* FindNodeByPayload(const void* payload, HierList** ownerList, int* index);
    int UpdateHierarchy(int first, int last, bool clearParent);

    HierListNode* ownerNode;
};
```

Notes for that future pass:

- The binary row stride is `payloadSize + 11`, not `sizeof(HierListNode)` in ordinary C++ terms.
- `payload[1]` above is only a source-facing flexible payload marker. Exact reconstruction must account for the 3 trailing stride bytes with a helper/allocator policy, not by inventing semantic flag fields.
- The scalar deleting destructor page should document ABI behavior, but source should only author `~HierList()`.

## Child Page Route And Score Recommendations

| UID | Page | Owner | Emitter | Reconstructable | Recommended score | Formal C++ now |
|---|---|---|---|---|---|---|
| 0002I8 | HierListConstructor | 000065 | 000065 | TRUE | 86/91 | blank |
| 0002I9 | HierListNonDeletingDestructor | 000065 | 000065 | TRUE | 86/90 | blank |
| 0002IA | HierListTailInsertWrapper | 000065 | 000065 | TRUE | 85/89 | blank |
| 0002IB | HierListDefaultInsertWrapper | 000065 | 000065 | TRUE | 85/89 | blank |
| 0002IC | HierListInsertBefore | 000065 | 000065 | TRUE | 86/90 | blank |
| 0002ID | HierListInsertAfter | 000065 | 000065 | TRUE | 86/90 | blank |
| 0002IE | HierListRemoveNode | 000065 | 000065 | TRUE | 86/90 | blank |
| 0002IF | HierListGetElementAt | 000065 | 000065 | TRUE | 88/92 | blank |
| 0002IG | HierListInsertAt | 000065 | 000065 | TRUE | 86/91 | blank |
| 0002IH | HierListAppend | 000065 | 000065 | TRUE | 86/92 | blank |
| 0002II | HierListRemoveAt | 000065 | 000065 | TRUE | 86/91 | blank |
| 0002IJ | HierListSwapElements | 000065 | 000065 | TRUE | 86/91 | blank |
| 0002IK | HierListFindNodeByData | 000065 | 000065 | TRUE | 87/89 | blank |
| 0002IL | HierListUpdateHierarchy | 000065 | 000065 | TRUE | 88/92 | blank |
| 0002IM | HierListScalarDeletingDestructor | 000065 | 000065 | TRUE | 86/90 | blank |

The blank-C++ recommendation for these children is not a downgrade of their source ownership. It is a sequencing recommendation: they should be populated in a coordinated HierList class pass, not as isolated snippets under an aggregate-routing repair.

## Support Documentation Recommendations

Apply these support changes with normal leaser/validator workflow:

- `by-memory/0x004ce730-0x004cee52.HierList.md`: change to non-emitting split/index, set owner to [UID:000065] or ownerless physical index per supervisor policy, blank `EMITTER_UIDS`, blank formal C++, update status text to say exact children emit source.
- Child pages [UID:0002I8]-[UID:0002IM]: keep owner/emitter [UID:000065]. Replace stale "below 95/95 source gate" wording with current quality-bar wording. Keep formal C++ blank until a coordinated class pass.
- `by-class/HierList.md`: align the class summary with the route: class owns exact methods and emits via [UID:0000JV]. Clarify `+0x14` as owner/parent node for this list and `HierListNode +0x04` as child list.
- `by-type/by-struct/HierListNode.md`: keep `+0x00 parent`, `+0x04 child HierList*`, `+0x08 payload`. Clarify the extra 3 bytes as unresolved trailing stride/reserved bytes, not flags. A modest score increase to `86/91` is defensible after that clarification.
- `by-file/HierList.md`: mention that the physical aggregate no longer emits and that exact children/class pages are the source reconstruction route.
- `auto-generated/-ag-memory-coverage.md`: after validation, confirm the duplicate aggregate route to `NexusTK/util/HierList.cpp` is gone and only exact child/class routes remain.

No direct edits are recommended to `Layer` ownership docs except optional wording that its HierList xrefs are consumer evidence.

## Supervisor-Owned Coverage Rows

Replace the current HierList block in `by-memory/-coverage-report.md` with the following rows after applying the metadata/support updates. This is intentionally supplied as exact pending coverage text for supervisor execution.

```markdown
    - [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) 0x004ce730-0x004cee52 | class-method-cluster-index | HierList : not_reconstructable : 88% : strong : Non-emitting HierList method-cluster/split index; exact child pages cover constructor, destructors, insert/remove/search/update methods, two IDA-unmodeled wrapper bodies, and internal padding under [UID:000065].
        - [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md) 0x004ce730-0x004ce760 | constructor | HierListConstructor : reconstructable : 86% : strong : Exact HierList constructor; constructs the List base with `payloadSize + 0x0b` and page size `0x20`, stores owner node at `+0x14`, links `ownerNode + 0x04` to this list, installs the HierList vtable, and is called by Layer construction.
        - [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) 0x004ce760-0x004ce7d1 | destructor-body | HierListNonDeletingDestructor : reconstructable : 86% : strong : Source destructor body releases nested child HierList objects from row `+0x04`, clears child pointers, restores destructor vtable state, and destroys base List storage; scalar delete flags remain isolated to the ABI wrapper.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce7d1-0x004ce7e0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment before the first raw insert wrapper.
        - [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) 0x004ce7e0-0x004ce839 | raw-wrapper-method | HierListTailInsertWrapper : reconstructable : 85% : strong : IDA-unmodeled but executable wrapper that chooses the root or child-list tail payload, then forwards to the insert-before core; exact raw body, calls, returns, and padding are confirmed.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce839-0x004ce840 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment before the second raw insert wrapper.
        - [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) 0x004ce840-0x004ce854 | raw-wrapper-method | HierListDefaultInsertWrapper : reconstructable : 85% : strong : IDA-unmodeled but executable wrapper that forwards a null sibling/reference payload to the insert-before core and returns with `retn 8`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce854-0x004ce860 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment before `HierListInsertBefore`.
        - [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) 0x004ce860-0x004ce9ad | method | HierListInsertBefore : reconstructable : 86% : strong : Core insert path copies `elementSize - 0x0b` payload bytes into a hierarchy row, resolves parent and reference payloads, lazily allocates child lists, and inserts through the virtual List slot.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce9ad-0x004ce9b0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) 0x004ce9b0-0x004ceafc | method | HierListInsertAfter : reconstructable : 86% : strong : Core insert-after path zero-allocates a hierarchy row, copies payload bytes, resolves parent/sibling storage, appends when no sibling is supplied, and inserts through the virtual List slot.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ceafc-0x004ceb00 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) 0x004ceb00-0x004ceb45 | method | HierListRemoveNode : reconstructable : 86% : strong : Removes by payload lookup; recursively resolves owner list and index, deletes any child list at node `+0x04`, clears it, and dispatches owner-list `RemoveAt(index, 1)`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ceb45-0x004ceb50 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md) 0x004ceb50-0x004ceb62 | virtual-method | HierListGetElementAt : reconstructable : 88% : strong : Virtual payload accessor calls the base List element accessor and returns row address plus `0x08`, hiding the hierarchy node header from callers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ceb62-0x004ceb70 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IG][0x004ceb70-0x004ceba9.HierListInsertAt](by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md) 0x004ceb70-0x004ceba9 | virtual-method | HierListInsertAt : reconstructable : 86% : strong : Virtual insert-at override delegates to base List insertion, then repairs hierarchy links for shifted rows with `UpdateHierarchy(index + count, oldCount, false)`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ceba9-0x004cebb0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md) 0x004cebb0-0x004cebb9 | virtual-method | HierListAppend : reconstructable : 86% : strong : Tiny HierList vtable override that tail-dispatches to the base List append helper while preserving the derived virtual slot.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004cebb9-0x004cebc0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002II][0x004cebc0-0x004cebec.HierListRemoveAt](by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md) 0x004cebc0-0x004cebec | virtual-method | HierListRemoveAt : reconstructable : 86% : strong : Virtual remove-at override delegates to base List removal and repairs parent/child links for the shifted tail range.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004cebec-0x004cebf0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md) 0x004cebf0-0x004cec22 | virtual-method | HierListSwapElements : reconstructable : 86% : strong : Virtual swap override delegates to base List swap and repairs hierarchy links for both swapped indices.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004cec22-0x004cec30 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) 0x004cec30-0x004ced0f | helper-method | HierListFindNodeByData : reconstructable : 87% : strong : Recursive payload lookup compares `elementSize - 0x0b` bytes at `row + 0x08`, descends through child lists at `row + 0x04`, and returns matched row plus owner list and zero-based index outputs.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ced0f-0x004ced10 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed single `0xcc` alignment byte.
        - [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) 0x004ced10-0x004ceda4 | helper-method | HierListUpdateHierarchy : reconstructable : 88% : strong : Repairs or clears child-list owner pointers and child-node parent pointers across an inclusive row range after insert/remove/swap operations.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ceda4-0x004cedb0 | padding | HierList internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment.
        - [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) 0x004cedb0-0x004cee52 | scalar-deleting-destructor | HierListScalarDeletingDestructor : reconstructable : 86% : strong : Vtable-only scalar deleting destructor wrapper duplicates child-list cleanup, destroys base storage, and conditionally frees `this` according to delete flags; not a normal source-authored method.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004cee52-0x004cee60 | padding | HierList to HourPane alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding after `HierList` scalar deleting destructor and before `HourPaneConstructor` at `0x004cee60`.
```

## Validation Commands For Supervisor Execution

From `E:\NTK\GhidraBridge\source-3\project-documentation` after acquiring the required leases:

> Executable block R001 was removed from this report and preserved verbatim in [00016X-hierlist-source-quality-removed.md](00016X-hierlist-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If child metadata/status text is updated in the same batch, also validate each changed child page [UID:0002I8]-[UID:0002IM] with `--mode file`.

Post-validation checks:

> Executable block R002 was removed from this report and preserved verbatim in [00016X-hierlist-source-quality-removed.md](00016X-hierlist-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: [UID:00016X] no longer appears as an emitting source route, exact child pages still route through [UID:000065], and the HourPane successor row remains unchanged after the `0x004cee52-0x004cee60` padding row.

## Files Changed By This Pass

- Added this report: `tools/leaser/Agents/Agent-B001/research/00016X-hierlist-source-quality.md`

No by-memory, by-class, by-file, by-type, generated, tool state, or coverage report files were edited by Agent-B001 in this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00016X-hierlist-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"00016X"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016X-hierlist-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00016X-hierlist-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
