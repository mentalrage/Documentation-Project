** TARGET-REPORT-UID:00016P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016P CachedHashTable Raw Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00016P] as a `CachedHashTable.cpp` helper-island documentation item, but correct its physical end from the stale `0x004c64de/0x004c64df` wording to half-open `0x004c62d0-0x004c64e1`.
- Final disposition: reconstructable source-authored/retained class-local helper code; owner and emitter should remain [UID:0000HZ] `CachedHashTable`.
- Required action: rename the target file to `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md`, refresh the coverage row, update support docs with the PE-aware no-route evidence and exact endpoint, and keep formal `RECONSTRUCTION_CPP` blank on this aggregate.
- Score recommendation: [UID:00016P] `82/88` -> `86/90`.
- Confidence: strong. Behavior, field offsets, helper boundaries, no direct route, and source placement are now checked against live IDA and PE-section evidence. Active runtime construction remains unproven.

## Target

- Target UID: [UID:00016P]
- Current target path: `by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md`
- Recommended target path: `by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md`
- Source queue/report row: B002 supervisor assignment `B002-goal2-cached-hash-table-raw-helpers-source-quality-00016P-20260617`.
- Current scores and parent state: `82/88`, `CANONICAL_OWNER:0000HZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HZ`, blank formal C++.

## Executive Recommendation

The helper island is real NexusTK project code over the documented `CachedHashTable` object, not padding, CRT/STL, or compiler-only glue. Keep it under [UID:0000HZ] `CachedHashTable` / `NexusTK/util/CachedHashTable.cpp`. The best liveness classification is source-authored retained utility/legacy helper code with no surviving direct route currently proven: IDA reports no direct xrefs to constructor, destructor, raw helper starts, or count accessors, and a PE-aware scan found no external rel32/Jcc edges, no VA/RVA pointers into the helper range, and no function-table entries for the helper starts.

The current docs are mostly right about ownership and behavior, but the exact target end is stale. The final helper at `0x004c64d0` ends with `retn 4` starting at `0x004c64de`; that instruction consumes bytes through `0x004c64e0`, so the helper island half-open end is `0x004c64e1`. Padding before the scalar deleting destructor is `0x004c64e1-0x004c64f0`.

Do not populate [UID:00016P]'s formal C++ block. This page is a multi-helper island and already overlaps the exact count-accessor child [UID:00016Q]. Final C++ should be entered only after either exact child pages are created for each helper or the `CachedHashTable` class-level assembly policy is updated to avoid duplicate emission.

## Evidence Standards Used

- Live IDA MCP session: `b002_00014p_exchange_ready_20260617`, opened/adopted for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA tools used: `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `decompile`, and `int_convert`.
- Independent binary evidence: local PE-section scan over `NexusTK.exe` for direct rel32/Jcc/short-branch targets, exact VA pointers, exact RVA pointers, and pointers into `0x004c62d0-0x004c64f0`.
- Documentation evidence checked: target page, [UID:00016O], [UID:00016Q], [UID:00001F], [UID:0000HZ], [UID:0001TU], [UID:0001X6], [UID:0002M7], `by-meta/client_containers.md`, `proposed-source-tree.md`, generated memory rows, `simroot_v2/class_CachedHashTable.cpp`, and old executed B reports mentioning this island as contrast context.

## IDA MCP Facts

- `lookup_funcs`:
  - `0x004c6160` is `CachedHashTable_Constructor`, size `0xf9`.
  - `0x004c6260` is `CachedHashTable_Destructor`, size `0x6e`.
  - `0x004c62d0`, `0x004c63d0`, `0x004c63f0`, `0x004c6420`, `0x004c6450`, and `0x004c64d0` are still not IDA function objects.
  - `0x004c64b0` is `CachedHashTable_GetSlotCount`, size `0x4`.
  - `0x004c64c0` is `CachedHashTable_GetEntryCount`, size `0x4`.
  - `0x004c64f0` is `CachedHashTable_ScalarDeletingDestructor`, size `0xac`.
- `xrefs_to`:
  - No xrefs to `0x004c6160`, `0x004c6260`, raw helper starts, or `0x004c64b0/0x004c64c0`.
  - `0x004c64f0` has one data xref from vtable slot `0x0061aac4`.
  - `0x0061aac4` has only vtable-base references at `0x004c61a1`, `0x004c6288`, and `0x004c651f` from constructor/destructor/scalar-deleting-destructor code.
- `get_bytes`:
  - Count accessors: `0x004c64b0`: `8b 41 10 c3`; `0x004c64c0`: `8b 41 14 c3`.
  - Tail helper: `0x004c64d0`: `55 8b ec 8b 41 0c 0f af 45 08 03 41 04 5d c2 04 00`, then `0xcc` padding from `0x004c64e1`.
  - Vtable neighborhood: `0x0061aac0 -> 0x00647de8`, `0x0061aac4 -> 0x004c64f0`, `0x0061aac8 -> 0x004f4b10`, `0x0061aacc -> 0x0041b6c0`, `0x0061aad0 -> 0x00647eb8`.
- `int_convert` verified `0x1c` = 28, `0x10` = 16, and `0x14` = 20.

## PE-Aware Liveness Evidence

The PE scan parsed image base `0x00400000` and executable `.text` `0x00401000-0x0060c600`.

- External rel32/Jcc hits to the lifecycle/helper starts or into `0x004c62d0-0x004c64f0`: none.
- External short-branch hits into the helper range: none.
- Exact VA pointer hits:
  - `0x004c61a3`, `0x004c628a`, and `0x004c6521` contain immediate `0x0061aac4` vtable-base references.
  - `0x0061aac4` in `.rdata` contains pointer `0x004c64f0`.
- Exact RVA pointer hits to target starts/vtable addresses: none.
- Pointers into `0x004c62d0-0x004c64f0`: none.

This validates and strengthens the existing no-direct-xref caveat. It does not prove the class was never constructed at runtime by an indirect or manually computed address, but it rejects a normal surviving direct call, jump, vtable, callback table, or static pointer-table route to the raw helpers.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c62d0-0x004c63c1` | contained in [UID:00016P] | `CachedHashTable::ComputeHashIndex(const void* keyBytes, int keyLength) const` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; no direct route |
| `0x004c63c1-0x004c63d0` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c63d0-0x004c63ee` | contained in [UID:00016P] | `CachedHashTable::Clear()` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; no direct route |
| `0x004c63ee-0x004c63f0` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c63f0-0x004c641e` | contained in [UID:00016P] | `CachedHashTable::RemoveAt(unsigned int slotIndex)` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; no direct route |
| `0x004c641e-0x004c6420` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c6420-0x004c6447` | contained in [UID:00016P] | `CachedHashTable::GetAt(unsigned int slotIndex) const` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; no direct route |
| `0x004c6447-0x004c6450` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c6450-0x004c64a7` | contained in [UID:00016P] | `CachedHashTable::SetAt(const void* entry, unsigned int slotIndex)` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; calls `sub_516220` memmove wrapper |
| `0x004c64a7-0x004c64b0` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c64b0-0x004c64c4` | [UID:00016Q] | `GetSlotCount()` and `GetEntryCount()` | TRUE | [UID:0000HZ] | optional `86/91` | exact modeled accessor pair |
| `0x004c64c4-0x004c64d0` | internal padding | `0xcc` alignment | FALSE if split | none | n/a | keep inside aggregate or ignored if exact split happens |
| `0x004c64d0-0x004c64e1` | contained in [UID:00016P] | `CachedHashTable::GetEntryAddressUnchecked(unsigned int slotIndex) const` | TRUE | [UID:0000HZ] | covered by 00016P | raw helper body; endpoint correction required |
| `0x004c64e1-0x004c64f0` | successor padding | `0xcc` alignment before scalar deleting destructor | FALSE if split | none | n/a | should be documented as padding if exact child split happens |

## Source-Facing Names And Type Directions

- `ComputeHashIndex`: best descriptive name for `0x004c62d0`. The body sums key bytes with an SSE/unrolled loop and returns `sum % m_slotCount`. It does not use the four seed bytes, so `HashIndex` is descriptive rather than proof of original name.
- `Clear`: best name for `0x004c63d0`. It resets `m_entryCount` and clears every slot-state byte.
- `RemoveAt`: best name for `0x004c63f0`. It checks bounds and occupancy, clears `m_slotState[slotIndex]`, decrements `m_entryCount`, and returns the entry address or null.
- `GetAt`: best name for `0x004c6420`. It checks bounds and occupancy and returns the entry address or null without changing state.
- `SetAt`: best name for `0x004c6450`. Binary stack order is first source entry pointer, second slot index. It copies `m_entrySize` bytes via `sub_516220`, marks a new slot occupied, increments `m_entryCount` only for a formerly empty slot, and returns `1` for new insert, `0` for replacement, `-1` for out of range.
- `GetSlotCount` and `GetEntryCount`: existing [UID:00016Q] names are now strong. They directly return offsets `+0x10` and `+0x14`.
- `GetEntryAddressUnchecked`: best name for `0x004c64d0`. It returns `m_entries + m_entrySize * slotIndex` with no bounds or occupancy check.

Field/type directions:

- `+0x04`: `unsigned char* m_entries` or `void* m_entriesBuffer`; contiguous fixed-size entry storage.
- `+0x08`: `unsigned char* m_slotState` or `m_occupiedSlots`; byte state array parallel to the entries.
- `+0x0c`: `int m_entrySize`.
- `+0x10`: `int m_slotCount`.
- `+0x14`: `int m_entryCount`.
- `+0x18..+0x1b`: four `unsigned char` seed bytes. Source-level declaration can be `unsigned char m_hashSeed[4]`, but the visible helper bodies in [UID:00016P] do not consume them.
- Slot-state semantics: `0` means empty; nonzero means occupied. `SetAt` writes exactly `1` for newly occupied slots; `Clear` and `RemoveAt` write `0`.

## Heuristic / Inference Reanalysis And Validation

- Existing docs validated: ownership under [UID:0000HZ] `CachedHashTable`, the 28-byte layout, constructor parameter order `entrySize, slotCount`, count accessor behavior, vtable ownership, utility placement, and no normal IDA xrefs are all supported by current evidence.
- Existing docs rejected or corrected: the target endpoint is wrong or at least dangerously ambiguous. `0x004c64de` is the start of a three-byte `retn 4`, not the final covered byte. The correct half-open helper island is `0x004c62d0-0x004c64e1`; padding to the next modeled function is `0x004c64e1-0x004c64f0`.
- Generated-source evidence rechecked: `simroot_v2/class_CachedHashTable.cpp` contains constructor/destructor/scalar deleting destructor only, not the raw helper island. `auto-generated/NexusTK/util/CachedHashTable.cpp` is currently zero bytes even though the generated memory coverage route for [UID:00016P] points there. Generated output is therefore a route check only, not behavior authority.
- Old report evidence rechecked: old executed B reports mention this island only as contrast for a different hash helper; they do not settle 00016P. The old statement that this is class-local is consistent with current IDA/PE evidence.
- Best liveness inference: retained source-authored utility/legacy code with no proven direct runtime route. This is stronger than "IDA no xrefs" because the PE scan also found no external rel32/Jcc edges and no VA/RVA pointer-table entries into the helper range.
- Rejected alternative, active indirect-use proven: rejected for now. No constructor callers, no helper callers, no helper pointers, and no vtable references except scalar deleting destructor are present in current static evidence. Indirect construction remains possible but unproven.
- Rejected alternative, compiler artifact: rejected. The bodies are ordinary thiscall class methods over stable fields, include source-like API helpers, call the project memmove wrapper, and sit between the class destructor and scalar deleting destructor.
- Rejected alternative, feature-local owner: rejected. There are no feature callers; `client_containers.md` and `proposed-source-tree.md` place generic containers under `util/`; Wave2 source metadata names `CachedHashTable.cpp`.
- Rejected alternative, static table/callback dispatch: rejected. No PE pointer/table entries to the raw helper starts were found, and the only exact function pointer in the neighborhood is vtable slot `0x0061aac4 -> 0x004c64f0`.
- Score/source-placement impact: evidence now supports raising [UID:00016P] to `86/90`, keeping owner/emitter [UID:0000HZ], and documenting a source-complete utility/legacy caveat rather than a vague raw/no-xref blocker.
- Final-C++ impact: the helper bodies are source-reconstructable, but [UID:00016P] should not receive formal aggregate C++ because it is a multi-helper island, physically overlaps [UID:00016Q], and should first be range-corrected or split into exact children.

## Ranked Ownership Analysis

### 1. [UID:0000HZ] CachedHashTable / `util/CachedHashTable.cpp`

- Evidence for: class layout, constructor/destructor/scalar deleting destructor, exact vtable data, count accessor names, raw helper field touches, `client_containers` guidance, and proposed source tree all point to the same utility source file.
- Evidence against: no live construction or feature caller found.
- Decision: accepted. No-caller status lowers runtime priority but does not move ownership away from the class/source file.

### 2. [UID:00001F] CachedHashTable class

- Evidence for: the helper bodies are class-local methods and use `ecx` as `this`.
- Evidence against: current docs route method bodies through the file owner [UID:0000HZ], while the class page is a semantic/type owner. The target currently uses [UID:0000HZ] and generated route is valid.
- Decision: keep [UID:0000HZ] as the current direct owner/emitter for this by-memory helper-island page unless the broader project decides all class methods should canonical-own to by-class pages.

### 3. Feature-local owner

- Evidence for: none found.
- Evidence against: no callers, no data refs, no strings/resources, no feature state, and source-tree/container docs classify it as reusable infrastructure.
- Decision: rejected.

### 4. Compiler/runtime/generated helper

- Evidence for: no live callers could mean leftover code.
- Evidence against: source-shaped methods, stable object layout, class vtable/lifecycle, and Wave2 `CachedHashTable.cpp` provenance.
- Decision: rejected as a rebuild classification. Treat as source-authored retained utility/legacy code.

## Aggregate / Split / Emission Policy

Preferred immediate supervisor action: keep [UID:00016P] as the reviewed helper-island page, correct the endpoint/filename to `0x004c64e1`, raise to `86/90`, keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter [UID:0000HZ], and keep formal C++ blank.

Future exact split direction if final C++ is to be emitted:

- Create exact child pages for the six raw non-IDA helpers listed in the inventory table.
- Keep [UID:00016Q] as the exact count-accessor child.
- Move formal method C++ to the exact child pages or to a class-level `CachedHashTable` assembly strategy that inserts exact children once, not both aggregate and child code.
- If exact child pages are created, record internal `0xcc` spans in `by-memory/-ignored.md` and coverage rows as padding. Until then, the aggregate can cover the physical helper island and its internal alignment bytes.

Do not classify the raw helper bodies as non-reconstructable just because no direct route is found. They are source-authored class methods retained in the binary. The only non-source bytes are the internal alignment pads.

## First-Draft C++ Recommendation

Do not populate [UID:00016P]'s formal `RECONSTRUCTION_CPP CODE` block from this report.

Reason: after the recommended score raise, [UID:00016P] would satisfy the minimum reconstructable/emitting combined-score gate, but the current page is a multi-function aggregate, has a stale filename/range that must be corrected, and overlaps [UID:00016Q]. Emitting aggregate C++ here would either duplicate the count-accessor child or create a partial aggregate block that no longer represents the full range.

Review-only source shape for later exact child pages:

```cpp
unsigned int CachedHashTable::ComputeHashIndex(const void* keyBytes, int keyLength) const
{
    const unsigned char* bytes = static_cast<const unsigned char*>(keyBytes);
    unsigned int sum = 0;
    for (int i = 0; i < keyLength; ++i) {
        sum += bytes[i];
    }
    return sum % static_cast<unsigned int>(m_slotCount);
}

void CachedHashTable::Clear()
{
    m_entryCount = 0;
    for (int i = 0; i < m_slotCount; ++i) {
        m_slotState[i] = 0;
    }
}

void* CachedHashTable::RemoveAt(unsigned int slotIndex)
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount) || m_slotState[slotIndex] == 0) {
        return 0;
    }

    m_slotState[slotIndex] = 0;
    --m_entryCount;
    return m_entries + (m_entrySize * slotIndex);
}

void* CachedHashTable::GetAt(unsigned int slotIndex) const
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount) || m_slotState[slotIndex] == 0) {
        return 0;
    }

    return m_entries + (m_entrySize * slotIndex);
}

int CachedHashTable::SetAt(const void* entry, unsigned int slotIndex)
{
    if (slotIndex >= static_cast<unsigned int>(m_slotCount)) {
        return -1;
    }

    unsigned char* destination = m_entries + (m_entrySize * slotIndex);
    memmove(destination, entry, m_entrySize);

    if (m_slotState[slotIndex] != 0) {
        return 0;
    }

    ++m_entryCount;
    m_slotState[slotIndex] = 1;
    return 1;
}

int CachedHashTable::GetSlotCount() const
{
    return m_slotCount;
}

int CachedHashTable::GetEntryCount() const
{
    return m_entryCount;
}

void* CachedHashTable::GetEntryAddressUnchecked(unsigned int slotIndex) const
{
    return m_entries + (m_entrySize * slotIndex);
}
```

Notes for later formalization: the C++ above is intentionally source-shaped and omits the SSE/unrolled sum implementation because that is an optimization artifact. The class declaration should use `unsigned char* m_entries` / `unsigned char* m_slotState` or equivalent opaque byte-buffer fields unless caller evidence later proves a concrete entry struct.

## Documentation Updates Recommended

- [UID:00016P]: rename endpoint to `0x004c64e1`, raise to `86/90`, add the PE-aware liveness evidence, correct the tail-helper boundary, keep owner/emitter [UID:0000HZ], and explicitly keep formal C++ blank.
- [UID:00016O]: update the helper-island child range from `0x004c62d0-0x004c64df` to `0x004c62d0-0x004c64e1`; record padding `0x004c64e1-0x004c64f0`; optional score raise `84/88` -> `85/89`.
- [UID:00016Q]: keep names `GetSlotCount` and `GetEntryCount`; optionally raise `84/90` -> `86/91` after adding the PE scan's no-pointer/no-route evidence. Formal C++ can be handled separately because this exact child is safe, but avoid duplicate emission with [UID:00016P].
- [UID:00001F], [UID:0000HZ], and [UID:0001TU]: update open questions to distinguish "no direct/PE route found" from a vague no-xref blocker, and correct the endpoint/padding.
- [UID:0001X6] and [UID:0002M7]: no ownership change; optional evidence refresh can mention the PE scan found only the existing vtable pointer to `0x004c64f0`.
- `by-meta/client_containers.md`: update the `CachedHashTable` line/open question to "source-authored retained utility/legacy candidate; no direct IDA or PE rel32/VA/RVA route found as of 2026-06-17."

## Exact Coverage Report Replacement Text

Placement context: replace the current [UID:00016P] row immediately after [UID:00016O] and before [UID:00016Q] in `by-memory/-coverage-report.md`.

```text
    - [UID:00016P][0x004c62d0-0x004c64e1.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64e1.CachedHashTableRawHelpers.md) 0x004c62d0-0x004c64e1 | raw-function-cluster | CachedHashTableRawHelpers : reconstructable : 86% : strong : B002 2026-06-17 source-quality refresh confirms exact helper island boundaries through the `retn 4` bytes at `0x004c64de-0x004c64e0`, `0xcc` padding at `0x004c64e1-0x004c64f0`, no external PE rel32/VA/RVA pointer route to the helper starts, source-authored retained `CachedHashTable` hash/clear/remove/get/set/count/unchecked-address helper roles, slot-state semantics, and `util/CachedHashTable.cpp` placement; formal C++ remains blank pending exact child split/overlap resolution with [UID:00016Q].
```

Optional [UID:00016O] support-row refresh if the supervisor updates that page in the same pass:

```text
    - [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md) : reconstructable : 85% : strong : Attached to `CachedHashTable.cpp`; B002 2026-06-17 confirms lifecycle/helper boundaries, exact helper child end `0x004c64e1`, padding `0x004c64e1-0x004c64f0`, exact vtable-data child link, and unresolved but PE-checked live-construction caveat.
```

If exact child split is performed later, the supervisor must generate real UIDs before final coverage rows are written. Do not invent UIDs in the shared report.

## Validation Commands

Commands run for this report:

- IDA MCP `idb_open` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `decompile`, and `int_convert` as described above.
- Local PE-section scan over `NexusTK.exe` for direct edges and pointer-table entries.

Recommended supervisor validation after applying documentation changes:

> Executable block R001 was removed from this report and preserved verbatim in [00016P-cached-hash-table-raw-helpers-source-quality-removed.md](00016P-cached-hash-table-raw-helpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the target is renamed, run the validator on the old path only if the rename leaves stale UID/path mappings; otherwise validate the new path and let the validator update UID references.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00016P-cached-hash-table-raw-helpers-source-quality.md`
- Modified: none outside the B002 research folder.
- Not modified by design: by-memory docs, generated reports, generated source, IDA DB, and `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00016P-cached-hash-table-raw-helpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00016P"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016P-cached-hash-table-raw-helpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00016P-cached-hash-table-raw-helpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
