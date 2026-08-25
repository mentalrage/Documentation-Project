** TARGET-REPORT-UID:00037A **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00037A **
# 00037A ArgumentedMenuMenuItemListDestructorThunks Source-Routing Report

Agent: B005  
Assignment: report-only source-routing/no-code pass  
Target UID: `00037A`  
Target path: `source-3/project-documentation/by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing.md`

## Final Recommendation

Keep [UID:00037A] non-reconstructable and non-emitting. Change the target score from `83/91` to `87/92` after implementation, keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:FALSE`, keep `EMITTER_UIDS:` blank, and keep the formal C++ block blank.

The source-level owner context is [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md), emitted through [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md). That ownership should be documented as the class/source route for the ordinary destructor declaration and vtable layout, not as emitted source for this target. [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) remains only the mixed compiler-glue aggregate/ledger.

The target is exactly two MSVC `this`-adjustor destructor thunks:

- `0x00520abb-0x00520ac6` half-open: `sub ecx, 0xa0; jmp 0x00520bb0`.
- `0x00520ac6-0x00520ad1` half-open: `sub ecx, 0xa4; jmp 0x00520bb0`.

The filename endpoint `0x00520ad0` is the inclusive final byte of the second 0x0b-byte thunk. If implementation wording discusses half-open ranges, state that the exact byte coverage is `0x00520abb-0x00520ad1` half-open while preserving the existing filename unless the supervisor explicitly asks for a range-style rename.

## Evidence Checked

Repository docs checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `by-structure.md`
- `inference_research.md`
- target [UID:00037A]
- parent aggregate [UID:0001BX]
- jump target [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md)
- class owner context [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- file owner context [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- vtable support [UID:000320][ArgumentedMenuDialogVtables](by-type/by-vtable/ArgumentedMenuDialogVtables.md)
- mixed vtable family [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- adjacent generated-thunk pages for TextMenu/ObjectImage/UserCreate patterns
- B001 executed tail-split report `Agent-B001/research/executed/older/0001BS-argumented-menu-dialogs-tail-split.md`
- `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and the local by-memory coverage row area

Local binary evidence:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Manual PE-section parser plus Capstone disassembly; `pefile` was not installed.
- Sections observed: `.text` `0x00401000-0x0060c4ac`, `.rdata` `0x0060d000-0x0066c0be`, `.data` `0x0066d000-0x0069ce24`, `.rsrc` `0x0069d000-0x006b2c38`.

Live IDA MCP was not available through the current tool surface during this pass, so current-session proof uses local PE/Capstone. Existing support docs record prior live IDA MCP checks against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`; the local PE checks reconfirm the relevant byte, vtable, and pointer facts.

## Raw Bytes And Boundaries

Capstone disassembly at the target:

```asm
00520abb: sub     ecx, 0xa0
00520ac1: jmp     0x520bb0
00520ac6: sub     ecx, 0xa4
00520acc: jmp     0x520bb0
```

Raw bytes:

```text
0x00520abb: 81 e9 a0 00 00 00 e9 ea 00 00 00
0x00520ac6: 81 e9 a4 00 00 00 e9 df 00 00 00
```

Each thunk is exactly 0x0b bytes. The first occupies `0x00520abb-0x00520ac6` half-open, and the second occupies `0x00520ac6-0x00520ad1` half-open. Neighbor evidence:

- Previous generated pair starts at `0x00520aa5`, uses `sub ecx, 0xa0/0xa4`, and jumps to shared default scalar deleting destructor `0x00520b70`.
- The target begins immediately at `0x00520abb`; no padding exists between the previous thunk and this target.
- The next generated pair starts immediately at `0x00520ad1`, uses `sub ecx, 0xa0/0xa4`, and jumps to shared list scalar deleting destructor `0x00520c20`.
- Therefore [UID:00037A] is exactly the `ArgumentedMenuMenuItemList` pair and must not absorb neighboring shared client/spell-list thunks.

## Jump Target And Destructor Relationship

Both thunks jump to [UID:00037B] `0x00520bb0`, the class scalar deleting destructor wrapper for `ArgumentedMenuMenuItemList`.

Relevant `0x00520bb0` local disassembly:

```asm
00520bb0: push    ebp
00520bb1: mov     ebp, esp
00520bb3: push    esi
00520bb4: mov     esi, ecx
00520bb6: mov     dword ptr [esi], 0x61f4c4
00520bbc: mov     dword ptr [esi + 0xa0], 0x61f54c
00520bc6: mov     dword ptr [esi + 0xa4], 0x61f57c
00520bd0: mov     ecx, dword ptr [0x69ae04]
00520bd6: test    ecx, ecx
00520bd8: je      0x520be0
00520bda: mov     eax, dword ptr [ecx]
00520bdc: push    1
00520bde: call    dword ptr [eax]
00520be0: mov     ecx, esi
00520be2: call    0x4f3b60
...
00520bf3: call    0x4f4ac0
...
00520c08: call    0x41b6a0
```

Source-routing inference:

- The target thunks are secondary/tertiary view destructor entries for an object whose complete-object base starts `0xa0` or `0xa4` bytes before those base subobjects.
- The ordinary source concept is `ArgumentedMenuMenuItemList::~ArgumentedMenuMenuItemList()` or an implicit/defaulted equivalent.
- The scalar deleting wrapper and adjustor thunks are compiler-generated ABI support; source docs should not emit a method body equivalent to either thunk.
- If class C++ is later populated, the destructor should appear only as a normal virtual destructor declaration/defaulted destructor in [UID:00000I], not as `sub ecx` or `operator delete` wrapper code.

## Vtable Refs And Store Evidence

Local PE pointer scan:

- Dword `0x00520abb` occurs once, at `0x0061f54c`.
- Dword `0x00520ac6` occurs once, at `0x0061f57c`.
- Dword `0x00520bb0` occurs once, at primary vtable slot `0x0061f4c4`.
- No rel32 code refs target the thunk starts `0x00520abb` or `0x00520ac6`.
- Rel32 refs to `0x00520bb0` are exactly the two thunk jumps at `0x00520ac1` and `0x00520acc`.

Relevant vtable neighborhood:

```text
0x0061f4c4 -> 0x00520bb0  primary scalar deleting destructor slot
0x0061f524 -> 0x0051f720  HandleMouseEvent
0x0061f53c -> 0x0051f5b0  SelectItemAndUpdateText
0x0061f540 -> 0x0051f710  ForwardOwnerStateUpdate
0x0061f544 -> 0x0051f840  DrawMenuItem
0x0061f54c -> 0x00520abb  secondary destructor adjustor thunk
0x0061f57c -> 0x00520ac6  tertiary destructor adjustor thunk
0x0061f588 -> next ArgumentedItemQuantityInputDialogPane vtable family
```

Vtable store/ref evidence for the `ArgumentedMenuMenuItemList` class:

- `0x0051eb7f`, `0x0051eb85`, `0x0051eb8f`: owner/dialog construction path stores `0x0061f4c4`, `0x0061f54c`, `0x0061f57c` into an embedded/list object.
- `0x0051f2b6`, `0x0051f2bc`, `0x0051f2c6`: list copy constructor stores the same three vtables.
- `0x0051f35b`, `0x0051f361`, `0x0051f36b`: raw/context constructor stores the same three vtables.
- `0x0051f383`, `0x0051f389`, `0x0051f393`: duplicate non-deleting destructor-like glue stores the same three vtables before cleanup.
- `0x00520bb6`, `0x00520bbc`, `0x00520bc6`: scalar deleting destructor restores the same three vtables before list/base teardown.

These stores link the target to `ArgumentedMenuMenuItemList`, not to the mixed destructor-island aggregate as a source owner.

## Heuristic / Inference Reanalysis

### Generated-Name And Source-Name Policy

Best source-level names:

- Class/source owner: `ArgumentedMenuMenuItemList`.
- Ordinary source destructor concept: `ArgumentedMenuMenuItemList::~ArgumentedMenuMenuItemList()`.
- Target-specific descriptive names for IDA/comments only:
  - `ArgumentedMenuMenuItemList_secondary_dtor_adjustor_0xa0`
  - `ArgumentedMenuMenuItemList_tertiary_dtor_adjustor_0xa4`

Rejected source names:

- Any `sub_520abb`, `thunk_520abb`, `virt_deldtor`, or raw generated label in final C++.
- A separate `ArgumentedMenuMenuItemListDestructorThunks` source method/function. The page name is a documentation label only.
- Naming the target as `MenuDialogDestructorThunks` ownership. That aggregate is a physical island ledger crossing unrelated classes.

### No-Code Proof

This target should remain no-code because:

- Each function is only `sub ecx, imm32; jmp 0x00520bb0`.
- There is no prologue, local stack frame, field access, branch, cleanup logic, packet/UI behavior, helper call, or source-authored statement.
- Each thunk is referenced only from a vtable slot.
- The same 0xa0/0xa4 adjustor pattern repeats across nearby menu/list/dialog classes, proving an ABI pattern rather than human-written logic.
- By-structure classifies adjustor thunks as `compiler/linker-generated`.
- The necessary source input is the owning class inheritance/vtable/destructor declaration, which belongs in [UID:00000I] / [UID:0000HI].

### Split/Range Policy

The current child page is structurally valid and should not be merged back into [UID:0001BX]. [UID:0001BX] is mixed compiler glue. [UID:00037A] is a focused class-specific child for the exact two adjustor functions. No split is needed inside [UID:00037A] because both functions share one class, one scalar deleting destructor target, one ABI purpose, and adjacent exact boundaries.

### Owner/Emitter Policy

Keep target metadata:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Reason: this page documents generated bytes, not a source-authored item. It should still say, in prose, that the class/source route is [UID:00000I] `ArgumentedMenuMenuItemList` under [UID:0000HI] `ArgumentedMenuDialogs`.

If the supervisor prefers semantic containment metadata for non-reconstructable pages, [UID:00000I] is the only defensible canonical owner candidate. I do not recommend that metadata change here because nearby thunk pages currently keep `CANONICAL_OWNER:NONE`, and the current no-code route is clearer if the generated byte page stays metadata-unowned while source responsibility is recorded in prose.

## Ranked Ownership Analysis

### 1. [UID:00000I] ArgumentedMenuMenuItemList / [UID:0000HI] ArgumentedMenuDialogs

Evidence for:

- Primary/secondary/tertiary vtable slots point to `0x00520bb0`, `0x00520abb`, and `0x00520ac6`.
- Multiple class constructors/raw helpers store vtables `0x0061f4c4`, `0x0061f54c`, `0x0061f57c`.
- The scalar deleting destructor restores the same vtables and calls list cleanup.
- [UID:000320] routes the vtable family to [UID:0000HI].
- [UID:00000I] already lists [UID:00037A] and [UID:00037B] as destructor support.

Evidence against:

- The target bytes are generated ABI thunks, not handwritten class methods.

Decision:

- Best source context. Record it prominently. Do not emit this target as source code.

### 2. [UID:0001BX] MenuDialogDestructorThunks aggregate

Evidence for:

- The target is physically inside the `0x00520abb-0x00520e2b` destructor/thunk island.
- The aggregate records the surrounding generated-thunk/destructor strip and neighboring owner exclusions.

Evidence against:

- The aggregate spans argumented menu, text menu, shared client/spell list, server-item list, object-image, and shared dialog destructor glue.
- No single source class/file owns the whole aggregate.

Decision:

- Keep as parent ledger/coverage container only. It is not the source owner for [UID:00037A].

### 3. [UID:0000OP] TextMenuDialogs or other menu/dialog families

Evidence for:

- Same physical island and same repeated adjustor pattern appear for text-menu classes.

Evidence against:

- Vtable slots `0x0061f54c` and `0x0061f57c`, scalar target `0x00520bb0`, and constructor/destructor stores route specifically to `ArgumentedMenuMenuItemList`.
- The next named vtable `0x0061f588` belongs to argumented item input dialogs, not text menu.

Decision:

- Reject for this child.

## Recommended Implementation Checklist

Do not edit by-* docs until the supervisor sends an implementation callback. If accepted, update these docs:

### Target: `by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md`

- Change score to `COMPLETION:87`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, and formal C++ blank.
- Add exact raw bytes and Capstone disassembly for both functions.
- Clarify endpoint convention: filename ends at inclusive `0x00520ad0`; exact half-open coverage is `0x00520abb-0x00520ad1`.
- Add jump-target relationship to [UID:00037B] `0x00520bb0`.
- Add vtable refs `0x0061f54c` and `0x0061f57c`, primary destructor slot `0x0061f4c4`, and no ordinary caller/no rel32-to-start evidence.
- Add vtable store evidence at `0x0051eb7f/85/8f`, `0x0051f2b6/bc/c6`, `0x0051f35b/361/36b`, `0x0051f383/389/393`, and `0x00520bb6/bc/c6`.
- Add neighboring-boundary proof: previous shared default thunk pair ends immediately before, and `0x00520ad1` starts the shared client/spell list thunk pair.
- Replace compiler-generated label wording with source-routing language: ordinary/defaulted `ArgumentedMenuMenuItemList` destructor belongs on owner docs; this target remains no-code.

### Companion support: `by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md`

- Recommended score after enrichment: `COMPLETION:86`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, and C++ blank unless the supervisor separately decides to model scalar deleting destructors like [UID:00022X]. For the current menu-dialog island pattern, non-reconstructable/no-code is consistent.
- Add the target jump refs from `0x00520ac1` and `0x00520acc`.
- Add primary vtable slot `0x0061f4c4`, vtable restore stores, `g_pItemHelpPane`-style global cleanup at `0x0069ae04`, list cleanup call `0x004f3b60`, delete helper `0x004f4ac0`, and guard helper `0x0041b6a0`.
- State that ordinary destructor source should be expressed on [UID:00000I], not by hand-porting the scalar deleting wrapper.

### Class/file/vtable support

- `by-class/ArgumentedMenuMenuItemList.md`: add a destructor-layout note: primary vtable slot `0x0061f4c4` uses scalar deleting destructor `0x00520bb0`; secondary/tertiary slots `0x0061f54c` and `0x0061f57c` use adjustor thunks [UID:00037A]; source C++ should use an ordinary/defaulted virtual destructor if/when class C++ is populated.
- `by-file/ArgumentedMenuDialogs.md`: add one sentence that destructor support for `ArgumentedMenuMenuItemList` is generated ABI glue and should be rebuilt from the class declaration/vtable layout, not emitted from thunk pages.
- `by-type/by-vtable/ArgumentedMenuDialogVtables.md`: if touched, add slot-level destructor mapping for the list vtables. Current vtable bases and store refs are already correct.
- `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`: update only if the implementation wants the parent aggregate to reflect this exact B005 recheck and coverage-stale correction. The current doc is directionally correct; the coverage row is stale.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during report-only work.

Current coverage around this island is stale: [UID:0001BX] still appears as `reconstructable : 80%`, and [UID:00037A] is absent as an exact child row. If accepted, replace the existing [UID:0001BX] row with:

```markdown
    - [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) 0x00520abb-0x00520e2b | destructor/thunk island | MenuDialogDestructorThunks : ignored/non-emitting : 87% : very strong : Reviewed mixed compiler-generated destructor/thunk ledger, not a source-emitting range. Exact owner-specific children carry the real routes, including [UID:00037A] `ArgumentedMenuMenuItemList` adjustor thunks, [UID:00037B] scalar deleting destructor, text-menu thunk/destructor children, and neighboring shared/item/spell/object-image glue. Local PE/Capstone and existing IDA-backed docs confirm repeated 0x0b adjustor thunks, scalar deleting destructor targets, vtable slots, mixed ownership, and endpoint padding before MessageAndMessageShowPane; no single source owner or C++ body belongs to this aggregate.
```

Insert this [UID:00037A] row directly under the [UID:0001BX] aggregate and before the neighboring shared/client-spell thunk row:

```markdown
        - [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) 0x00520abb-0x00520ad1 | compiler-generated destructor adjustor thunks | ArgumentedMenuMenuItemListDestructorThunks : ignored/non-emitting : 87% : very strong : Exact two-function MSVC this-adjustor pair for [UID:00000I] `ArgumentedMenuMenuItemList`: `0x00520abb` subtracts `0xa0` and jumps to [UID:00037B] `0x00520bb0`, while `0x00520ac6` subtracts `0xa4` and jumps to the same scalar deleting destructor. Local PE/Capstone confirms raw bytes `81 e9 a0 00 00 00 e9 ea 00 00 00` and `81 e9 a4 00 00 00 e9 df 00 00 00`, sole dword refs from vtable slots `0x0061f54c`/`0x0061f57c`, no ordinary callers, and exact boundaries between the prior shared default thunks and the next shared client/spell-list thunk at `0x00520ad1`. Source responsibility is the ordinary/defaulted class destructor and vtable layout on [UID:00000I]/[UID:0000HI], not emitted C++ for this no-code page.
```

If the companion scalar deleting destructor page is enriched, also insert/update:

```markdown
        - [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) 0x00520bb0-0x00520c17 | compiler-generated scalar deleting destructor | ArgumentedMenuMenuItemListScalarDeletingDestructor : ignored/non-emitting : 86% : very strong : Class-specific scalar deleting destructor wrapper for [UID:00000I] `ArgumentedMenuMenuItemList`; primary vtable slot `0x0061f4c4` points here and [UID:00037A] thunks jump here from `0x00520ac1`/`0x00520acc`. Local PE/Capstone confirms vtable restores to `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c`, global help-pane cleanup through `0x0069ae04`, list cleanup call `0x004f3b60`, delete helper `0x004f4ac0`, guard helper `0x0041b6a0`, and no ordinary source-authored body. Rebuild through the owner class destructor declaration/vtable layout, not by hand-porting the wrapper.
```

If the supervisor keeps the existing broad [UID:0000VN] ignored rows, they should be narrowed or annotated so they do not appear to supersede the exact [UID:00037A] child. The exact child row should be the authoritative coverage for `0x00520abb-0x00520ad0`.

## Validation Commands Needed After Implementation

No validator was run in this report-only pass because no by-* docs were edited. After an implementation callback, run from `source-3/project-documentation` for every touched doc:

> Executable block R001 was removed from this report and preserved verbatim in [00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing-removed.md](00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Run only the commands for docs actually edited. The supervisor owns `by-memory/-coverage-report.md`; if it is later edited by the supervisor, validate it under the supervisor workflow.

## IDA Rename/Type/Comment Recommendations

Do not rename these as source methods. If IDA comments are added, use generated-glue comments:

- `0x00520abb`: `ArgumentedMenuMenuItemList secondary destructor adjustor thunk; this -= 0xa0; jumps to scalar deleting destructor 0x00520bb0`.
- `0x00520ac6`: `ArgumentedMenuMenuItemList tertiary destructor adjustor thunk; this -= 0xa4; jumps to scalar deleting destructor 0x00520bb0`.
- `0x00520bb0`: `ArgumentedMenuMenuItemList scalar deleting destructor wrapper; generated; source destructor belongs on class declaration`.
- `0x0061f4c4`: primary destructor slot for `ArgumentedMenuMenuItemList`.
- `0x0061f54c`: secondary destructor slot pointing to `0x00520abb`.
- `0x0061f57c`: tertiary destructor slot pointing to `0x00520ac6`.

If function names are required for IDA navigation, prefer descriptive generated-glue names such as `ArgumentedMenuMenuItemList_dtor_adjustor_a0` and `ArgumentedMenuMenuItemList_dtor_adjustor_a4`, not final source-facing method names.

## Remaining Issues

- No live IDA MCP call was available in this current pass, but existing IDA-backed docs and local PE/Capstone agree on every target-critical fact.
- Exact original source spelling of the destructor is not recoverable from these bytes. The best source-facing representation is ordinary/defaulted virtual destructor declaration on [UID:00000I].
- Project-wide consistency for `CANONICAL_OWNER` on non-reconstructable class-specific generated-thunk pages remains a policy choice. This report recommends keeping `NONE` for [UID:00037A] to match nearby thunk pages while documenting the class source route in prose.

## Changed Files

Report-only. Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing.md`

No target/support by-* docs and no coverage docs were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00037A","source_path":"executed-b-agent-research/B005/00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
