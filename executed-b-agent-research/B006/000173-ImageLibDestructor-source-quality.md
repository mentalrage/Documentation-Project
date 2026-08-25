** TARGET-REPORT-UID:000173 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B006 Report - [UID:000173] ImageLibDestructor Source Quality

Assignment: `B006-report-000173-ImageLibDestructor-source-quality-20260627`

Agent: Agent-B006

Date: 2026-06-27

Scope: report-only research for [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](../../../../../by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md). I edited only this report file. I did not edit by-* docs, generated C++, generated project reports, validator/tool state, coverage reports, or the IDA database.

## Target Recommendation

| Target | Current by-* metadata | Recommended metadata | Owner / emitter | C++ recommendation |
| --- | ---: | ---: | --- | --- |
| [UID:000173] `0x004d0070-0x004d011b.ImageLibDestructor` | `85/90` | `90/92` | keep `CANONICAL_OWNER:00006E`, `EMITTER_UIDS:00006E` | Populate first-draft ordinary destructor C++ in the target formal block. |

The target clears the current code-entry gate: it is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route through [UID:00006E][ImageLib](../../../../../by-class/ImageLib.md) into [UID:0000K2][ImageLib](../../../../../by-file/ImageLib.md), and its current average score is `(85 + 90) / 2 = 87.5`, above the active threshold. The remaining question is source form, not eligibility. Current MCP evidence and accepted support docs now make this an ordinary source-authored destructor body, while [UID:0002IO][ImageLibScalarDeletingDestructor](../../../../../by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) remains the compiler scalar deleting wrapper.

## Evidence Checked

Primary target and support docs:

- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`
- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
- `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`
- `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`
- `by-class/ImageLib.md`
- `by-file/ImageLib.md`
- `by-type/by-struct/ImageLibLayout.md`
- `by-type/by-struct/ResourceLayoutNameRecord.md`
- `by-class/List.md`, `by-file/List.md`, and `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
- `by-class/MemoryMan.md`
- `by-global/g_pEPFLib.md`
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-type/by-vtable/ImageLibVtable.md`
- `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`
- `by-file/ResourceLayoutTable.md` and `by-class/ResourceLayoutTable.md`

Generated/read-only state checked:

- `auto-generated/-ag-research-tracker.md` currently still lists [UID:000173] as `78/88`, `B count 0`, no executed B report path. This is stale relative to the hand-authored target's A003 `85/90` update and should be refreshed only by validator/executed-report lifecycle, not by hand.
- `auto-generated/NexusTK/render/ImageLib.cpp` was refreshed at `2026-06-27T08:55:20-04:00` and still contains only empty emitter markers for [UID:000173] and the ImageLib family. This confirms active generated output has not yet incorporated the ordinary destructor body.

Accepted precedent checked:

- B003 image-library cleanup reports populate ordinary destructor C++ when the body is source-authored and keep scalar deleting wrappers blank.
- B002 [UID:00017O] ItemObjImageLibDestructor keeps C++ blank where the raw ordinary teardown is not a safe standalone source body. That no-code rationale does not apply here because [UID:000173] is an IDA-modeled function with a complete recoverable cleanup loop and scalar-wrapper parity.
- B015 [UID:00018S] LanguageManCleanupDestructor and current MemoryMan docs accept `MemoryMan* memoryMan = GetMemoryMan();` plus `memoryMan->FreeBufferMemory(...)` as first-draft helper spelling. [UID:0001BF] now carries formal `void *MemoryMan::FreeBufferMemory(void *buffer)`.

Existing report search:

- `rg` found no executed B-agent report for [UID:000173]. The tracker row has `B count 0`.
- The prior A003 notes raised the target from `78/88` to `85/90` with boundary and cleanup evidence, but left final C++ blank pending a source-shape pass. This report is that source-shape pass.

## Live IDA MCP Evidence

MCP was available and responsive. I used session/database `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

- `server_health(database=80de0a67)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reports `0x004d0070` as `sub_4D0070`, size `0xab` / 171 bytes, and `0x004d011b` as not a function. It reports `0x004d0120` as the next function, `sub_4D0120`, size `0x1c5`.
- The same lookup reports scalar deleting destructor `0x004e64a0` as `sub_4E64A0`, size `0xd2` / 210 bytes, and `0x004e6572` as not a function.
- `int_convert` confirmed key values used below: `0xab = 171`, `0xd2 = 210`, `0x2c = 44`, `0x28 = 40`, `0x10 = 16`, and `0x0c = 12`.
- `get_bytes` confirmed `0x004d011b-0x004d0120` is five `0xcc` bytes, `0x004e6572-0x004e6580` is fourteen `0xcc` bytes, and `0x0061b650-0x0061b660` contains RTTI plus vtable dwords `0x006486d4`, `0x004e64a0`, `0x004f4b10`, and `0x0041b6c0`.

Target decompile, with address facts preserved in prose:

- `sub_4D0070` sets the ImageLib vtable at `0x004d009a`.
- It calls `sub_516030` / `GetMemoryMan` at `0x004d00a0` before testing the `this+0x0c` list field.
- If the list exists, it snapshots `*(list + 0x0c)` as the loop count at `0x004d00b4`.
- It calls the list virtual slot `+0x10` at `0x004d00c6`, matching `List::GetElementAt(index)`.
- It reads each row's `+0x28` pointer at `0x004d00cb`; if non-null, it calls `sub_516170` / `MemoryMan::FreeBufferMemory` at `0x004d00d6` and writes the returned zero/null back to `row+0x28` at `0x004d00db`.
- After the loop it deletes the list through its virtual destructor with flag `1` at `0x004d00ed-0x004d00ef`, clears `this+0x0c` at `0x004d00f1`, clears `dword_67A744` / `g_pEPFLib` at `0x004d00fa`, and calls base cleanup `sub_4F4A90` at `0x004d0104`.

Scalar deleting destructor comparison:

- `decompile 0x004e64a0` shows the same vtable reset, `GetMemoryMan`, list loop, row `+0x28` free-and-null, list deleting destructor, `this+0x0c` clear, `g_pEPFLib` clear, and `sub_4F4A90` base cleanup.
- The scalar wrapper then adds only delete-flag behavior: if `(a2 & 1) != 0 && (a2 & 4) == 0`, it calls `sub_4F4AC0(Block)`. That branch is compiler-generated wrapper behavior and should not be hand-authored into `ImageLib::~ImageLib`.

Liveness and pointer-route checks:

- `xrefs_to 0x004d0070` returns zero xrefs. This confirms no direct modeled caller or pointer route to the ordinary destructor start.
- `find_bytes` found zero matches for absolute VA pattern `70 00 4D 00` and zero matches for RVA pattern `70 00 0D 00`.
- Positive control `find_bytes A0 64 4E 00` finds exactly `0x61b654`, the vtable slot pointer to scalar deleting destructor `0x004e64a0`; the RVA pattern `A0 64 0E 00` has no matches.
- `xrefs_to 0x004e64a0` returns exactly one data xref from `0x0061b654`, the vtable slot.
- `xrefs_to 0x0061b654` returns three vtable stores: constructor `0x004d0009`, ordinary destructor `0x004d009a`, and scalar deleting destructor `0x004e64d1`.
- `xrefs_to 0x0067a744` returns 231 xrefs. In the ImageLib lifecycle range, owner writes/clears include constructor `0x004cffef`/`0x004cfff6`, ordinary destructor clear `0x004d00fa`, and scalar deleting destructor clear `0x004e652c`.

The no-direct-route result is not a blank-C++ blocker for this target. The function is modeled, bounded, and behavior-complete; the vtable slot naturally points to the scalar deleting destructor, while the ordinary destructor body is represented as the source destructor cleanup that the wrapper reuses.

## Source-Form Decision

[UID:000173] should receive formal first-draft C++.

Reasons:

- The binary behavior is a source-authored resource cleanup loop, not only ABI glue. The compiler vtable store, SEH/security-cookie setup, and base destructor call are compiler lowering around the source destructor, but the list-row payload loop, list deletion, member nulling, and singleton clear are source-level lifecycle statements.
- `ResourceLayoutNameRecord` already documents the 44-byte row and `entries` at `+0x28`. The destructor touches no unresolved fields outside that row payload pointer.
- `ImageLib` and `ImageLibLayout` already document the `+0x0c` list as `m_pEntryList` / `entryList`, constructed by `List::List(44, 10)`. The exact final private spelling remains a class confidence cap but is good enough for a first-draft method body.
- List support docs and existing project C++ use `GetCount()` and `GetElementAt()` as source-facing APIs for the `List` count and slot `+0x10` element accessor.
- Current MemoryMan docs accept `GetMemoryMan()` plus `MemoryMan::FreeBufferMemory(void*)`; the helper returns zero specifically for caller field-clearing patterns, matching this destructor's `record->entries = FreeBufferMemory(record->entries)` data flow.
- The open `ImageLib` / `ResourceLayoutTable` API split and the constructor's second argument do not affect this destructor body. They remain support-level caveats for class/header polish, not blockers for this exact child.

Recommended exact formal block for `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ImageLib::~ImageLib()
{
    MemoryMan* memoryMan = GetMemoryMan();

    if (m_pEntryList != 0) {
        const int count = m_pEntryList->GetCount();

        for (int index = 0; index < count; ++index) {
            ResourceLayoutNameRecord* record =
                static_cast<ResourceLayoutNameRecord*>(m_pEntryList->GetElementAt(index));

            if (record->entries != 0) {
                record->entries =
                    static_cast<ResourceLayoutEntry*>(memoryMan->FreeBufferMemory(record->entries));
            }
        }

        delete m_pEntryList;
        m_pEntryList = 0;
    }

    g_pEPFLib = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not add vtable stores, SEH/security-cookie code, a manual `LObject` destructor call, a manual scalar-deleting wrapper, or optional `delete this`. Those are compiler/base behaviors represented by the class declaration and [UID:0002IO], not by the source destructor body.

## Rejected Alternatives

- Keep C++ blank because generated output currently omits the body: rejected. Generated output is stale empty-marker state; it should follow by-* source metadata after supervisor acceptance and validator refresh.
- Keep C++ blank because there are no xrefs to `0x004d0070`: rejected. Ordinary non-deleting destructors commonly have no direct vtable route; the vtable uses the scalar deleting destructor. The modeled ordinary body is still the source cleanup.
- Put the cleanup body on [UID:0002IO] instead: rejected. The scalar deleting destructor is the vtable compiler wrapper and adds delete flags; source cleanup should emit once through [UID:000173].
- Merge this target into `ResourceLayoutTable`: rejected. `ResourceLayoutTable` methods consume the same object/list, but the constructor/destructor/vtable/global ownership is `ImageLib`.
- Assign ownership to `List`, `ResourceLayoutNameRecord`, `MemoryMan`, `g_pEPFLib`, or `LObject`: rejected. Those are field/helper/global/base dependencies, not the outer method owner.
- Hand-author `GetMemoryMan()->FreeBufferMemory` without assigning the return to `record->entries`: weaker. Existing helper semantics and target data flow specifically free-and-null the row payload field by storing the helper return value.
- Replace `m_pEntryList` with a new standalone `ResourceLayoutStore` field/type: rejected. Existing docs treat `ResourceLayoutStore` and `ResourceLayoutBucket` as aliases over the `List` of `ResourceLayoutNameRecord` rows.

## Target Doc Change Recommendations

### `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`

- Change `COMPLETION:85` to `COMPLETION:90`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00006E`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00006E`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Replace the blank `RECONSTRUCTION_CPP CODE` block with the exact formal block above.
- Update the summary/status/source-readiness text to state that current MCP session `80de0a67` resolves the ordinary destructor as source-ready; generated output omission is stale, not a source blocker.
- Add the current MCP evidence: health/session, `lookup_funcs` size `0xab`, no function at `0x004d011b`, five-byte padding, decompile/disasm cleanup sequence, `xrefs_to 0x004d0070` zero, VA/RVA pointer-pattern negatives, scalar-wrapper parity, vtable-slot route to [UID:0002IO], and global clear xrefs.
- Update score rationale: completion rises because formal source body, helper names, row field, list API, source-vs-wrapper split, and no-route interpretation are now resolved. Confidence rises modestly but remains below final audit because exact private member spelling and broader `ImageLib`/`ResourceLayoutTable` header split remain open.

Suggested concise item summary:

```text
Source-ready ordinary `ImageLib::~ImageLib` destructor; live MCP confirms exact `0xab` body, no direct start refs or VA/RVA pointer route, 44-byte ResourceLayoutNameRecord row payload free-and-null loop, List virtual deletion, `m_pEntryList` clear, `g_pEPFLib` clear, implicit base cleanup, scalar-deleting wrapper parity, and formal first-draft C++.
```

## Support Doc Recommendations

Make these support updates only where the current page does not already carry the same-or-greater detail.

- `by-class/ImageLib.md`: update the `ImageLib::~ImageLib` method note and Autogen Status. State that the exact ordinary destructor child now owns first-draft C++; class-level C++ remains blank only because constructor declaration, `ResourceLayoutTable` API membership, and header/private-field factoring remain broader class issues.
- `by-file/ImageLib.md`: replace the stale "ordinary destructor omitted/blank pending rewrite-quality pass" wording with the current decision: [UID:000173] should emit the ordinary destructor body through `NexusTK/render/ImageLib.cpp`, while [UID:0002IO] remains compiler wrapper/no-code.
- `by-type/by-struct/ImageLibLayout.md`: add the current destructor source-shape resolution for `+0x0c` as the list field used by formal C++ as `m_pEntryList`, with row cleanup of `ResourceLayoutNameRecord::entries` and `delete m_pEntryList`. Keep the `ResourceLayoutTable` alias caveat.
- `by-type/by-struct/ResourceLayoutNameRecord.md`: add [UID:000173] as direct destructor evidence that `entries` at `+0x28` is an owned payload pointer freed before the list itself is destroyed.
- `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`: update the ordinary destructor row/notes to say [UID:000173] is source-ready and has formal C++; the lifecycle cluster itself remains non-emitting.
- `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`: update source-readiness/no-code proof to state that the source-authored cleanup is emitted through [UID:000173] and this target remains blank compiler scalar deleting wrapper glue with optional delete flag handling.
- `by-type/by-vtable/ImageLibVtable.md` and `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`: ensure the vtable slot remains documented as `0x0061b654 -> 0x004e64a0`; do not point the vtable at the ordinary destructor. Add only a note, if absent, that no direct pointer route to `0x004d0070` is expected after the source-wrapper split.
- `by-global/g_pEPFLib.md` and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`: ensure they record current ordinary destructor clear at `0x004d00fa`, scalar wrapper clear at `0x004e652c`, and source-facing `g_pEPFLib = 0;` in `ImageLib::~ImageLib`.
- `by-class/List.md` / `by-file/List.md`: no required metadata change. Only add an optional cross-reference if the implementation needs to clarify that this target uses `List::GetCount`, virtual slot `+0x10` / `GetElementAt`, and virtual deleting-destructor semantics.

No support metadata score changes are required by this report. Support scores can stay unchanged unless the implementer finds stale text that materially conflicts with the accepted target update.

## Generated And Coverage Handling

- Do not hand-edit `auto-generated/NexusTK/render/ImageLib.cpp`. After target/support implementation, the scoped target validator should refresh generated output or queue a generated refresh. If it reports deferred generated work, use `python .\tools\validator.py --queue-status` and record the final refresh state.
- Do not edit `auto-generated/-ag-research-tracker.md` or any other generated report. The supervisor's eventual `execute_report` lifecycle updates the tracker.
- Do not edit any `-coverage-report.md` during the B-agent implementation callback unless the supervisor explicitly overrides the normal exclusion.

If the supervisor still maintains a manual `by-memory/-coverage-report.md` row for this exact target outside validator-owned generated coverage, the suggested replacement text after implementation is:

```text
        - [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) 0x004d0070-0x004d011b | destructor | ImageLib::~ImageLib : reconstructable : 90% : very-strong : Current MCP session `80de0a67` confirms exact `0xab` ordinary destructor body, no direct start refs or absolute/RVA pointer route to `0x004d0070`, five-byte post-body padding, ImageLib vtable reset as compiler lowering, `GetMemoryMan` setup, `m_pEntryList` / `List` count snapshot, virtual `GetElementAt` over 44-byte `ResourceLayoutNameRecord` rows, `entries` at `+0x28` free-and-null through `MemoryMan::FreeBufferMemory`, virtual list deletion with flag 1, `m_pEntryList` clear, `g_pEPFLib` clear, implicit `LObject` base cleanup, scalar-deleting wrapper parity with [UID:0002IO], class owner/emitter [UID:00006E], and formal first-draft `ImageLib::~ImageLib` C++.
```

## Validator Plan For Accepted Implementation

Run scoped validators from `source-3/project-documentation` after edits. Expected commands:

> Executable block R001 was removed from this report and preserved verbatim in [000173-ImageLibDestructor-source-quality-removed.md](000173-ImageLibDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If any optional support file is inspected and found already equivalent, record "no edit required, already same-or-greater detail" in the checklist rather than touching it.

## Open Questions And Limits

- Exact original private member spelling for `m_pEntryList` is still inferred. It is the best current source-facing name because the constructor docs already use it and the field is definitely the `+0x0c` `List*`.
- Exact public type boundary for `g_pEPFLib` remains `ImageLib*` versus `ResourceLayoutTable` facet/base/helper split. That does not change this destructor's ownership or body.
- The constructor's second argument is still not explained by the destructor. This remains a constructor/class declaration issue only.
- Exact final header spelling for `MemoryMan` helper calls remains below final-audit confidence, but current accepted MemoryMan children make `GetMemoryMan()` and `MemoryMan::FreeBufferMemory(void*)` strong enough for first-draft C++.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current `Agent-B006/goal.md`.
- [x] Read and applied the project-level `ntk-b-agent-workflow` skill and required references.
- [x] Confirmed report-only scope and did not edit by-* docs, generated files, project-level generated files, coverage reports, validator/tool state, or IDA DB.
- [x] Confirmed live IDA MCP availability: session/database `80de0a67`, `server_health` status `ok`, Hex-Rays ready.
- [x] Rechecked target function inventory with MCP `lookup_funcs`: `0x004d0070` modeled as size `0xab`, `0x004d011b` not a function, next function `0x004d0120`, scalar wrapper `0x004e64a0` size `0xd2`.
- [x] Rechecked numeric conversions with MCP `int_convert`: `0xab`, `0xd2`, `0x2c`, `0x28`, `0x10`, and `0x0c`.
- [x] Rechecked target decompile/disassembly with MCP and recorded exact cleanup sequence.
- [x] Rechecked scalar deleting destructor comparison with MCP `decompile 0x004e64a0`.
- [x] Rechecked xrefs/liveness with MCP: no xrefs to `0x004d0070`, one vtable data xref to `0x004e64a0`, three vtable-store xrefs to `0x0061b654`, and lifecycle global refs to `0x0067a744`.
- [x] Rechecked no-pointer-route evidence with MCP `find_bytes`: no VA or RVA pointer matches for ordinary destructor start; positive control found scalar wrapper pointer at `0x0061b654`.
- [x] Rechecked padding/vtable bytes with MCP `get_bytes`.
- [x] Checked target/support docs, current generated `ImageLib.cpp`, stale generated tracker row, and accepted B-agent precedents.
- [x] Produced this report at `tools/leaser/Agents/Agent-B006/research/000173-ImageLibDestructor-source-quality.md`.

Accepted implementation callback pass:

- [x] Lease exact edit set immediately before editing and release immediately after the edit/validator batch.
  - Proof: edit lease was acquired for the target/support by-* docs before edits. Proof-fix validator lease was acquired for the changed docs at `2026-06-27T14:13:05Z`: target, `by-class/ImageLib.md`, `by-file/ImageLib.md`, `by-type/by-struct/ImageLibLayout.md`, `by-type/by-struct/ResourceLayoutNameRecord.md`, lifecycle cluster, scalar deleting destructor, vtable page/data, `g_pEPFLib` global/memory pages, and optional `by-class/List.md`. `python leaser.py B006 unlease` released all listed B006 paths successfully after validators; final `current_leases.md` reports "No active leases."
- [x] Update [UID:000173] target metadata to `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:00006E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006E`, blank emitter position.
  - Proof: `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md` header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006E`, and blank `EMITTER_POSITION_OPTIONAL`. Validator: `python .\tools\validator.py --mode file --file by-memory\0x004d0070-0x004d011b.ImageLibDestructor.md --apply --queue-timeout 240 --wait-generated`, `command_id 000000004072`, `command_timestamp 2026-06-27T10:13:12-04:00`, exit code `0`, `ok: 1`.
- [x] Insert the exact formal `ImageLib::~ImageLib` C++ block from this report into the target `RECONSTRUCTION_CPP CODE` block.
  - Proof: `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md` formal block now contains `ImageLib::~ImageLib()`, `MemoryMan* memoryMan = GetMemoryMan();`, `m_pEntryList->GetCount()`, `GetElementAt(index)`, `ResourceLayoutNameRecord::entries`, `FreeBufferMemory`, `delete m_pEntryList`, `m_pEntryList = 0`, and `g_pEPFLib = 0;`. Same validator proof as target command `000000004072`, exit `0`, `ok: 1`.
- [x] Update target evidence/status/source-readiness with current MCP session `80de0a67`, exact boundary/padding/decompile/disasm/xref/pointer-route/scalar-wrapper facts from this report.
  - Proof: target `Status`, `Behavior Summary`, `Evidence`, and `Autogen Status` now record session/database `80de0a67`, exact `0xab` / 171-byte body, no function at `0x004d011b`, five `0xcc` padding bytes to `0x004d0120`, disassembly cleanup sequence, no xrefs to `0x004d0070`, no VA/RVA pointer route, positive scalar-wrapper pointer at `0x0061b654`, scalar-wrapper parity, vtable slot to [UID:0002IO], and `g_pEPFLib` clears. Validator `000000004072`, exit `0`, `ok: 1`.
- [x] Preserve and update rejected alternatives: no-owner, ResourceLayoutTable/List/MemoryMan/global/base ownership, scalar-wrapper merge, blank-C++ generated-output/stale-gate rationale, and manual ABI/base/delete-this code.
  - Proof: target section `Source Placement And Rejected Alternatives` documents why owner/emitter remains [UID:00006E], why ResourceLayoutTable/List/MemoryMan/global/base do not own the source body, why scalar-wrapper merge is rejected, why stale generated omission is not a source blocker, and why raw ABI/base/delete-this artifacts are excluded from formal C++. Validator `000000004072`, exit `0`, `ok: 1`.
- [x] Update target score rationale to explain why source C++ is now safe and why confidence remains below final audit.
  - Proof: target `Score Rationale` now states completion `90` because boundary, body size, padding, cleanup loop, wrapper relationship, no-pointer-route evidence, owner/emitter route, and formal C++ are documented; confidence `92` remains below final due to inferred private member spelling, final `g_pEPFLib` public type/header boundary, and `ImageLib`/`ResourceLayoutTable` API split. Validator `000000004072`, exit `0`, `ok: 1`.
- [x] Update `by-class/ImageLib.md` or record already-sufficient proof. Required detail: ordinary destructor child now emits first-draft C++; class-level C++ remains blank only for broader constructor/API/header issues.
  - Proof: `by-class/ImageLib.md` method table, `Autogen Status`, and `2026-06-27 Destructor Source Split` now state UID000173 owns first-draft `ImageLib::~ImageLib()` C++; class-level C++ remains blank only for constructor declaration, unused second argument, ResourceLayoutTable API membership, header placement, and private field names. Validator: `python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240`, `command_id 000000004073`, `command_timestamp 2026-06-27T10:13:53-04:00`, exit `0`, `ok: 1`; warning: stale missing ref target UID000172 old `0x004cffb0-0x004e6572.ImageLib.md` path.
- [x] Update `by-file/ImageLib.md` or record already-sufficient proof. Required detail: `ImageLib.cpp` should emit UID000173 ordinary destructor; scalar deleting wrapper remains compiler/no-code.
  - Proof: `by-file/ImageLib.md` class-boundary text and change log now state `NexusTK/render/ImageLib.cpp` should emit UID000173 as source `ImageLib::~ImageLib()`, while UID0002IO remains compiler scalar deleting wrapper/no-code. Validator: `command_id 000000004074`, `command_timestamp 2026-06-27T10:13:55-04:00`, exit `0`, `ok: 1`; warning: stale missing ref target UID000172 old path.
- [x] Update `by-type/by-struct/ImageLibLayout.md` or record already-sufficient proof. Required detail: `+0x0c` list field source use as `m_pEntryList`, row `entries` cleanup, and list deletion/nulling.
  - Proof: `by-type/by-struct/ImageLibLayout.md` `Registry Field`, `2026-06-27 Destructor Field-Use Resolution`, and changes now document `+0x0c` as `m_pEntryList`, `GetCount`, `GetElementAt`, `ResourceLayoutNameRecord::entries` at `+0x28`, `delete m_pEntryList`, and nulling. Validator: `command_id 000000004075`, `command_timestamp 2026-06-27T10:13:57-04:00`, exit `0`, `ok: 1`; warning: stale missing ref target UID000172 old path.
- [x] Update `by-type/by-struct/ResourceLayoutNameRecord.md` or record already-sufficient proof. Required detail: UID000173 is destructor evidence for owned `entries` at `+0x28`.
  - Proof: `by-type/by-struct/ResourceLayoutNameRecord.md` layout notes and changes now cite UID000173 as direct destructor evidence that `entries` at `+0x28` is caller-owned payload freed before list deletion. Validator: `command_id 000000004076`, `command_timestamp 2026-06-27T10:14:03-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md` or record already-sufficient proof. Required detail: child UID000173 source-ready while cluster remains non-emitting.
  - Proof: lifecycle cluster function row, evidence notes, Autogen Status, and changes now state UID000173 is source-ready with formal C++, while the cluster remains `RECONSTRUCTABLE:FALSE` and non-emitting. Validator: `command_id 000000004077`, `command_timestamp 2026-06-27T10:14:05-04:00`, exit `0`, `ok: 1`; warnings are broad pre-existing/stale missing ref targets, including coverage/ignored old paths.
- [x] Update `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md` or record already-sufficient proof. Required detail: cleanup emits through UID000173; this target remains compiler scalar deleting wrapper/no-code.
  - Proof: scalar deleting destructor `Evidence`, `Autogen Status`, and changes now say source-authored cleanup emits through UID000173 and this target remains compiler ABI support with delete-flag/optional-delete handling; formal C++ stays blank. Validator: `command_id 000000004078`, `command_timestamp 2026-06-27T10:14:09-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-type/by-vtable/ImageLibVtable.md` / `ImageLibVtableData` only if needed. Required detail: vtable slot remains scalar deleting destructor, not ordinary destructor; no ordinary start pointer route is expected.
  - Proof: `by-type/by-vtable/ImageLibVtable.md` `2026-06-27 Destructor Source Route` records `0x0061b654 -> 0x004e64a0`, no pointer route to `0x004d0070`, and expected MSVC destructor split. Validator: `command_id 000000004080`, `command_timestamp 2026-06-27T10:14:17-04:00`, exit `0`, `ok: 1`; warning: stale missing ref target UID00025H old read-only aggregate path. `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md` `2026-06-27` evidence/reconstruction notes record the same concrete slot route and no ordinary-pointer route. Validator: `command_id 000000004081`, `command_timestamp 2026-06-27T10:14:18-04:00`, exit `0`, `ok: 1`; warning: stale missing ref target UID00025H old path.
- [x] Update `by-global/g_pEPFLib.md` and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` or record already-sufficient proof. Required detail: ordinary destructor source clears `g_pEPFLib = 0;` at `0x004d00fa`.
  - Proof: `by-global/g_pEPFLib.md` lifetime evidence and changes now state UID000173 clears at `0x004d00fa` as source `g_pEPFLib = 0;`, while scalar wrapper clears at `0x004e652c`. Validator: `command_id 000000004082`, `command_timestamp 2026-06-27T10:14:20-04:00`, exit `0`, `ok: 1`. `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` storage/lifetime evidence and change log record the same clear and wrapper parity. Validator: `command_id 000000004083`, `command_timestamp 2026-06-27T10:14:21-04:00`, exit `0`, `ok: 1`.
- [x] Optional List support checked/applied.
  - Proof: `by-class/List.md` `Core Methods`, `ResourceLayout Evidence`, and changes now document `List::GetCount` as source-facing accessor for direct `m_count` reads, plus UID000173 use of `GetCount`, virtual `GetElementAt`, and virtual list deletion over `List(44, 10)` records. Validator: `command_id 000000004084`, `command_timestamp 2026-06-27T10:14:23-04:00`, exit `0`, `ok: 1`. `by-file/List.md` was inspected and not edited because existing file-level utility/consumer ownership already covers the needed placement; no validator required for that unmodified file.
- [x] Do not edit generated files, generated reports, validator/tool state, IDA DB, or any `-coverage-report.md` unless the supervisor explicitly overrides this report's exclusion.
  - Proof: no manual edits were made to generated/project-level/coverage/tool-state/IDA DB files. Validator command `000000004072` performed validator-owned generated/report refresh side effects (`autogen_cpp_update`, `memory_auto_coverage_update`, `research_tracker_update`, `projected_stats_update`, registry refresh) as expected; no manual coverage-report edits were made.
- [x] Run scoped validators listed in `Validator Plan For Accepted Implementation`; record command, command id, timestamp, exit code, `ok` count, generated refresh status, and any warnings.
  - Proof: validators passed with exit code `0`, `ok: 1` for every changed by-* file: target `000000004072` at `2026-06-27T10:13:12-04:00` (`--wait-generated`, generated completed); ImageLib class `000000004073`; ImageLib file `000000004074`; ImageLibLayout `000000004075`; ResourceLayoutNameRecord `000000004076`; lifecycle cluster `000000004077`; scalar deleting destructor `000000004078`; ImageLibVtable `000000004080`; ImageLibVtableData `000000004081`; g_pEPFLib global `000000004082`; g_pEPFLib memory `000000004083`; List class `000000004084`. Recorded warnings above are stale/missing-reference diagnostics unrelated to the accepted UID000173 implementation.
- [x] If generated refresh is deferred, use `python .\tools\validator.py --queue-status` until generated state is complete or record the exact deferred state for supervisor follow-up.
  - Proof: support validators initially reported deferred generated refresh. Queue checks: `command_id 000000004087` at `2026-06-27T10:14:43-04:00` showed 7 queued/1 processing generated refresh jobs; `000000004088` and `000000004090` showed progress; `000000004091` showed only one processing generated refresh; final `python .\tools\validator.py --queue-status`, `command_id 000000004092`, `command_timestamp 2026-06-27T10:15:35-04:00`, showed `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- [x] Confirm `auto-generated/NexusTK/render/ImageLib.cpp` regenerated from validator now contains the UID000173 `ImageLib::~ImageLib` body, if generated refresh completed.
  - Proof: after queue drain, `auto-generated/NexusTK/render/ImageLib.cpp` header reports `validator-command-id: 000000004083`, `validator-refreshed-at: 2026-06-27T10:14:21-04:00`; file contains `// UID:000173 | by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md | Completion:90 | Confidence:92`, `ImageLib::~ImageLib()`, `m_pEntryList->GetCount()`, `m_pEntryList->GetElementAt(index)`, `delete m_pEntryList`, `m_pEntryList = 0`, and `g_pEPFLib = 0;`.
- [x] Release all B006 leases immediately after validators and verify no active B006 leases remain.
  - Proof: `python leaser.py B006 unlease` returned `Success` for all 12 validator-lease paths. Final read of `tools/leaser/Agents/current_leases.md` after release reports "No active leases."

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/000173-ImageLibDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/000173-ImageLibDestructor-source-quality.md","timestamp":"2026-06-27T10:19:12","uid":"000173"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000173-ImageLibDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/000173-ImageLibDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000173"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
