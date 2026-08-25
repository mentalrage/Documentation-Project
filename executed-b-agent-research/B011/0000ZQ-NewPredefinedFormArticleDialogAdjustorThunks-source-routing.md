** TARGET-REPORT-UID:0000ZQ **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZQ NewPredefinedFormArticleDialog Adjustor Thunks Source-Routing Report

Status: FINISHED
Agent: B011
Assignment: B011-goal2-new-predefined-form-article-dialog-adjustor-thunks-source-routing-0000ZQ-20260619
Date: 2026-06-19

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000ZQ] as ignored, non-reconstructable compiler adjustor glue.
- Final disposition: `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
- Score recommendation: raise from `82/90` to `85/93`.
- Score cap: cap completion at `85` because the item is fully understood as no-code ABI glue, but the source-facing declaration/destructor/inheritance model belongs to [UID:000098] / [UID:0000LT] and related vtable/destructor support pages rather than this target. Confidence can rise because the byte/ref evidence is exact.
- Required action: update target/support docs after supervisor review; do not emit C++ for this range.
- Confidence: very strong for the exact two-thunk boundaries, target destructor, vtable-only references, no-code policy, and class/file routing.

## Target

- Target UID: [UID:0000ZQ]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md`
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing.md`
- Current metadata: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`
- Current description: two compiler-generated secondary/tertiary destructor adjustor thunks for `NewPredefinedFormArticleDialog`, tail-jumping to [UID:0000ZS] `0x0047ec30`.

## Evidence Checked

Workflow and standards:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B011/goal.md`
- `by-structure.md` and current code-entry/no-code policy through the active B-agent instructions

Target and direct supports:

- [UID:0000ZQ] `by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md`
- [UID:0000ZS] `by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md`
- [UID:0000ZP] `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md`
- [UID:000098] `by-class/NewPredefinedFormArticleDialog.md`
- [UID:0000LT] `by-file/NewPredefinedFormArticleDialog.md`
- [UID:0000ZL] `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
- [UID:0002UJ] `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`
- [UID:0001X4] `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
- [UID:00024W] `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md`
- [UID:0000VN] `by-memory/-ignored.md`
- `by-memory/-coverage-report.md` current rows
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`
- `wave3_data_issues.md`

IDA MCP status:

- Tried `http://127.0.0.1:13337/mcp` tool discovery.
- Result: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Replacement evidence used in this pass: direct PE/Capstone recheck of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` plus current IDA-backed project docs.

Raw binary evidence:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`
  - `.rdata`: `0x0060d000-0x0066c200`
  - `.data`: `0x0066d000-0x0069ce24`

## Direct Raw Findings

### Exact Function Boundaries

The target covers exactly two adjacent 11-byte thunk bodies:

| Half-open range | Bytes SHA1 | Disassembly | Meaning |
| --- | --- | --- | --- |
| `0x0047e931-0x0047e93c` | `0b1f29fd8120d8e8857413d73b8501cca7f20a68` | `sub ecx, 0xa0; jmp 0x0047ec30` | Secondary-table destructor adjustor. |
| `0x0047e93c-0x0047e947` | `c1978d9d1fe2333660eb9403caad0807e7916bcf` | `sub ecx, 0xa4; jmp 0x0047ec30` | Tertiary-table destructor adjustor. |

Raw bytes:

```asm
0047E931  81 E9 A0 00 00 00    sub ecx, 0A0h
0047E937  E9 F4 02 00 00       jmp 0047EC30h

0047E93C  81 E9 A4 00 00 00    sub ecx, 0A4h
0047E942  E9 E9 02 00 00       jmp 0047EC30h
```

Boundary checks:

- Predecessor `0x0047e91b-0x0047e926` and `0x0047e926-0x0047e931` are the prior MailDialog secondary/tertiary destructor adjustor pair into `0x0047ebf0`.
- Target begins cleanly at `0x0047e931`.
- Successor `0x0047e947-0x0047e950` is nine `0xcc` bytes, SHA1 `2794737e4e5f6c779cb767c3118d06e5deb6681a`.
- `0x0047e950` starts the next scalar deleting destructor strip, not part of [UID:0000ZQ].

### Target Destructor [UID:0000ZS]

Both thunks tail-jump to [UID:0000ZS] `0x0047ec30-0x0047ec6b`.

Raw scalar wrapper summary:

```asm
0047EC30  push ebp
0047EC31  mov ebp, esp
0047EC33  push esi
0047EC34  mov esi, ecx
0047EC36  call 004A1450h
0047EC3B  mov eax, [ebp+8]
0047EC3E  test al, 1
0047EC40  je 0047EC64h
0047EC42  test al, 4
0047EC44  jne 0047EC56h
0047EC46  push esi
0047EC47  call 004F4AC0h
...
0047EC56  push 5368h
0047EC5B  push esi
0047EC5C  call 0041B6A0h
...
0047EC68  ret 4
```

Interpretation:

- `0x0047ec30` is the primary scalar deleting destructor wrapper for `NewPredefinedFormArticleDialog`.
- It calls `0x004a1450`, the shared `DialogInSession` non-deleting destructor/base cleanup, then applies scalar-delete flags.
- It optionally frees storage through `0x004f4ac0` or the `flags & 4` guarded/sized path using object size `0x5368`.
- The two [UID:0000ZQ] thunks exist only to adjust secondary/tertiary subobject `this` pointers back to the primary object pointer before reusing this scalar wrapper.

### Vtable and Reference Evidence

Direct dword hits from this pass:

| Value | Raw dword hits | Meaning |
| --- | --- | --- |
| `0x0047e931` | `0x006140b4` only | Secondary vtable destructor slot. |
| `0x0047e93c` | `0x006140e4` only | Tertiary vtable destructor slot. |
| `0x0047ec30` | `0x00614050` only | Primary vtable scalar deleting destructor slot. |
| `0x0047e947` | none | End boundary only. |

Direct rel32 refs:

- No rel32 call or jump targets to `0x0047e931`.
- No rel32 call or jump targets to `0x0047e93c`.
- Rel32 jumps to `0x0047ec30` exist only from the two thunk instructions at `0x0047e937` and `0x0047e942`.
- No rel32 calls to `0x0047ec30` in this recheck.

Constructor vtable-store context:

```asm
004777EE  mov dword ptr [esi],       00614050h
004777F4  mov dword ptr [esi+0A0h],  006140B4h
004777FE  mov dword ptr [esi+0A4h],  006140E4h
```

Meaning:

- `this + 0x00` gets the primary `NewPredefinedFormArticleDialog` table whose destructor slot is `0x0047ec30`.
- `this + 0xa0` gets the secondary table whose destructor slot is `0x0047e931`.
- `this + 0xa4` gets the tertiary table whose destructor slot is `0x0047e93c`.
- This proves the `0xa0` and `0xa4` adjustments are class-layout offsets, not source-authored behavior.

Relevant vtable dword windows:

```text
0x00614050 -> 0x0047ec30  primary scalar deleting destructor
0x00614054 -> 0x004f4b10
0x00614058 -> 0x0041b6c0

0x006140b0 -> 0x00643a0c  secondary RTTI locator
0x006140b4 -> 0x0047e931  secondary destructor adjustor
0x006140b8 -> 0x0049e240

0x006140e0 -> 0x00643a20  tertiary RTTI locator
0x006140e4 -> 0x0047e93c  tertiary destructor adjustor
0x006140e8 -> 0x004782b0  routed event-handler method
```

The `0x006140e8 -> 0x004782b0` slot is a useful contrast: the event handler is a source-routed virtual method, while the slot at `0x006140e4` is compiler ABI glue.

## Heuristic / Inference Reanalysis And Validation

### Issue: Are the two bodies source-authored methods?

Conclusion: no.

Evidence:

- Both bodies are exactly 11 bytes and have only two instructions.
- Both bodies perform only `this` pointer adjustment and tail-jump to the scalar deleting destructor.
- Both start addresses are referenced only by vtable/data cells.
- No ordinary code caller, function pointer outside the vtable, or raw pointer hit exists for either start.

Rejected alternative:

- Handwritten forwarding methods. Rejected because human source would not normally contain explicit `sub ecx, offset; jmp scalar deleting destructor` bodies; this shape is MSVC multiple-inheritance destructor adjustor glue.

Source/no-code policy:

- Keep formal C++ blank for [UID:0000ZQ].
- Reconstruct the owning class, base layout, and ordinary destructor semantics in [UID:000098]/[UID:0000LT] and let the compiler regenerate equivalent thunks.

### Issue: Should [UID:0000ZQ] gain owner/emitter metadata?

Conclusion: no.

Evidence:

- The semantic source owner is `NewPredefinedFormArticleDialog`, but this target is not a source-authored entity.
- `CANONICAL_OWNER:NONE` is appropriate for ignored compiler glue.
- `EMITTER_UIDS` must stay blank to avoid emitting a non-source ABI artifact.

Rejected alternatives:

- Assign to [UID:000098] `NewPredefinedFormArticleDialog`: rejected because by-structure owner/emitter metadata would imply source emission for this memory item.
- Assign to [UID:0000LT] `NewPredefinedFormArticleDialog.cpp`: rejected for the same reason.
- Assign to [UID:0000ZS] scalar deleting destructor target: rejected because [UID:0000ZS] is also compiler-generated destructor glue, not a source parent.
- Assign to [UID:0001X4] vtable family: rejected because the vtable family is layout support evidence, not a source owner for this code body.

Recommended language:

- "Generated by MSVC from [UID:000098] `NewPredefinedFormArticleDialog` inheritance/vtable layout; source reconstruction should model the class and destructor normally."

### Issue: Is the target duplicate coverage with broad [UID:0000ZP]?

Conclusion: intentional exact-child coverage, not harmful duplicate source emission.

Evidence:

- [UID:0000ZP] is a broad non-reconstructable thunk island covering `0x0047e855-0x0047e947`.
- [UID:0000ZP] lists all 22 adjacent thunk functions and already calls out the final two [UID:0000ZQ] bodies as the NewPredefined pair.
- [UID:0000ZQ] exists because this class had a specific historical issue: generated/disabled output treated `0x0047e931` as missing code while `0x0047e93c` appeared as a thunk, and the scalar deleting destructor label polluted the base owner.
- [UID:0000ZQ] carries the class-specific source-routing/no-code proof that would be too easy to lose in the broad island.

Recommended disposition:

- Keep both pages.
- Treat [UID:0000ZP] as the broad compiler-thunk island/index.
- Treat [UID:0000ZQ] as the exact NewPredefinedFormArticleDialog pair.
- Do not merge [UID:0000ZQ] back into [UID:0000ZP] and do not split [UID:0000ZQ] further into single-thunk rows.

### Issue: Do split/ignore rows need repair?

Conclusion: no structural repair is required.

Evidence:

- `by-memory/-ignored.md` has a specific entry for `0x0047e931-0x0047e947` naming [UID:0000ZQ].
- `by-memory/-ignored.md` also has a separate `0x0047e855-0x0047e931` entry for the non-predefined portion of the broader thunk strip.
- `by-memory/-coverage-report.md` currently includes both the broad [UID:0000ZP] row and the exact [UID:0000ZQ] row.
- The broad [UID:0000ZP] page already states [UID:0000ZQ] is the exact predefined-form page.

Minor optional cleanup:

- If implementation touches [UID:0000ZP], clarify that it is a non-emitting index/container and that [UID:0000ZQ] is the exact child for the final two thunks. The current text already says this sufficiently, so this is not required.

### Issue: Relationship to `NewPredefinedFormArticleDialog` class/file docs

Conclusion: class/file routing is correct and does not change target metadata.

Evidence:

- [UID:0000LT] file doc places the source module at `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, with `ArticleDialogs.cpp` only as a compact legacy alternative.
- [UID:000098] class doc lists [UID:0000ZQ] as compiler-generated vtable thunks, ignored for handwritten source.
- [UID:0000ZL] aggregate documents constructor vtable stores, class method children, [UID:0000ZQ], and [UID:0000ZS].
- [UID:0002UJ] constructor page confirms stores at `0x004777ee`, `0x004777f4`, and `0x004777fe`.
- [UID:0001X4] vtable family lists the primary/secondary/tertiary table bases for `NewPredefinedFormArticleDialog`.

Recommended support-doc posture:

- Keep `NewPredefinedFormArticleDialog.cpp` as the source-placement answer.
- Keep [UID:0000ZQ] out of generated source.
- If source-level C++ is later added for the class/destructor, it should be ordinary class inheritance/destructor code, not adjustor-thunk code.

### Issue: First-draft C++ readiness

Conclusion: no formal C++ for [UID:0000ZQ].

Exact no-code proof:

- The target is `RECONSTRUCTABLE:FALSE`.
- It has no source-authored logic.
- It is referenced only by vtable data cells.
- The only executable action is to normalize `this` from secondary/tertiary subobject offsets and tail-jump into [UID:0000ZS].
- Source C++ should not contain these bodies.

Source-level implication for class docs:

```cpp
// Do not emit this in [UID:0000ZQ].
// Equivalent machine code should be regenerated by the compiler from
// NewPredefinedFormArticleDialog's inheritance layout and destructor.
```

If the class eventually gets final source C++, the relevant source-level shape is an ordinary destructor declaration/definition on `NewPredefinedFormArticleDialog`; [UID:0000ZQ] remains blank.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner/emitter | Recommended score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0047e931-0x0047e93c` | part of [UID:0000ZQ] | Secondary destructor adjustor, `this -= 0xa0` then jump to `0x0047ec30` | false | none | covered by target | Keep ignored. |
| `0x0047e93c-0x0047e947` | part of [UID:0000ZQ] | Tertiary destructor adjustor, `this -= 0xa4` then jump to `0x0047ec30` | false | none | covered by target | Keep ignored. |
| `0x0047ec30-0x0047ec6b` | [UID:0000ZS] | Primary scalar deleting destructor wrapper | false | none | support page can be separately raised if reviewed | Target of both thunks. |
| `0x0047e855-0x0047e947` | [UID:0000ZP] | Broad adjustor-thunk island/index | false | none | no change required | Keep as broad context; [UID:0000ZQ] is exact child. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x006140b4 -> 0x0047e931` | dword vtable slot | Only direct reference to secondary thunk start. |
| `0x006140e4 -> 0x0047e93c` | dword vtable slot | Only direct reference to tertiary thunk start. |
| `0x0047e937 -> 0x0047ec30` | rel32 jump | Secondary thunk tail-jump into scalar deleting destructor. |
| `0x0047e942 -> 0x0047ec30` | rel32 jump | Tertiary thunk tail-jump into scalar deleting destructor. |
| `0x00614050 -> 0x0047ec30` | dword vtable slot | Primary vtable destructor slot for `NewPredefinedFormArticleDialog`. |
| `0x004777f4 -> 0x006140b4` | constructor vtable-base store | Secondary subobject table stored at `this + 0xa0`. |
| `0x004777fe -> 0x006140e4` | constructor vtable-base store | Tertiary subobject table stored at `this + 0xa4`. |

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE`, no emitters, ignored compiler glue

Evidence for:

- Exact compiler adjustor shape.
- Vtable-only start references.
- No direct code callers.
- No source-authored behavior.
- Class/source docs already model the real source owner separately.

Evidence against:

- None material. This is the correct by-structure outcome for no-code ABI glue.

Decision:

- Accepted.

### 2. Assign to [UID:000098] `NewPredefinedFormArticleDialog`

Evidence for:

- The thunks are generated from this class's vtable layout.
- Constructor stores the secondary/tertiary tables at `this+0xa0` and `this+0xa4`.

Evidence against:

- The item itself should not emit as source.
- Owner/emitter assignment would pollute source output with compiler thunks.

Decision:

- Rejected for target metadata. Reference the class as semantic/source-layout context only.

### 3. Assign to [UID:0000LT] `NewPredefinedFormArticleDialog.cpp`

Evidence for:

- Correct source file for the class that caused the compiler to generate these thunks.

Evidence against:

- Same no-code concern as above.
- The source file should emit class declarations/methods, not explicit thunk bodies.

Decision:

- Rejected for target metadata. Keep as likely source module context in prose.

### 4. Merge into [UID:0000ZP]

Evidence for:

- [UID:0000ZP] already spans the full thunk strip and lists this pair.

Evidence against:

- [UID:0000ZQ] captures a real class-specific historical source-routing issue.
- The exact page prevents regenerated-output/missing-code confusion around `0x0047e931`.
- No source duplication risk because both are non-emitting ignored pages.

Decision:

- Rejected. Keep [UID:0000ZQ] as exact child/audit page.

## Exact Recommended Doc Changes

### Target [UID:0000ZQ]

Recommended metadata:

```text
COMPLETION:85
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:
```

Recommended content updates:

- Add the 2026-06-19 B011 raw PE/Capstone recheck:
  - binary SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
  - exact `0x0047e931-0x0047e93c` and `0x0047e93c-0x0047e947` byte ranges
  - bytes/disassembly for both thunks
  - predecessor MailDialog thunk pair at `0x0047e91b-0x0047e931`
  - successor `0x0047e947-0x0047e950` `0xcc` padding
  - dword-only references at `0x006140b4` and `0x006140e4`
  - rel32 jumps into [UID:0000ZS] at `0x0047e937` and `0x0047e942`
  - constructor stores at `0x004777f4` and `0x004777fe`
- Replace any remaining "likely" wording about source policy with target-specific proof:
  - secondary/tertiary vtable destructor adjustors
  - offsets are `this + 0xa0` and `this + 0xa4`
  - thunks are not source-authored and should stay formal-C++ blank
- Keep cross-references to [UID:000098], [UID:0000LT], [UID:0000ZL], [UID:0000ZS], [UID:0000ZP], [UID:0001X4], and [UID:0000VN].

### [UID:0000ZS] Scalar Deleting Destructor Support

Recommended support update:

- Add B011's direct raw confirmation that the only rel32 jumps into `0x0047ec30` from the target scope are `0x0047e937` and `0x0047e942`.
- Keep no-code policy: [UID:0000ZS] is scalar deleting destructor glue, not a source-authored destructor body.
- Preserve the correction that `0x004a1450` is `DialogInSession` cleanup, not an `ArticleDialog`-owned destructor.

Optional score follow-up:

- [UID:0000ZS] has similar exact proof and could be separately reviewed for a small increase, but this report does not require changing it. If changed during implementation, use a separate coverage-row update.

### [UID:0000ZP] Broad Thunk Island

Recommended support update:

- No structural split required.
- If edited, state explicitly that [UID:0000ZP] is the broad non-emitting thunk-island index and [UID:0000ZQ] is the exact NewPredefined pair.
- No score change required for [UID:0000ZP].

### [UID:000098] Class and [UID:0000LT] File Docs

Recommended support update:

- No owner/emitter metadata change required.
- Keep `NewPredefinedFormArticleDialog.cpp` as the source route for the owning class.
- Add or preserve the statement that [UID:0000ZQ] is compiler-generated destructor dispatch glue and must not appear as source code.
- If class/file C++ is later populated, model an ordinary destructor/inheritance layout and do not manually write adjustor thunk methods.

### [UID:0001X4] Vtable Family

Recommended support update:

- Existing table bases and constructor stores are correct.
- If edited, add the destructor-slot detail:
  - primary `0x00614050 -> 0x0047ec30`
  - secondary `0x006140b4 -> 0x0047e931`
  - tertiary `0x006140e4 -> 0x0047e93c`
- Preserve the rebuild handling that vtable data is emitted from class declarations/layout, not hand-authored tables.

### [UID:0000VN] Ignored Ledger

Recommended support update:

- No repair required. It already contains:
  - exact [UID:0000ZQ] ignored entry `0x0047e931-0x0047e947`
  - separate non-predefined thunk entry `0x0047e855-0x0047e931`
  - broader overlap-container entry that mentions `0x0047e855-0x0047e947`
- If touched, add the 2026-06-19 raw PE recheck date to the exact [UID:0000ZQ] entry, but this is optional.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly during this assignment.

Recommended exact replacement row for [UID:0000ZQ]:

```text
    - [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) 0x0047e931-0x0047e947 | compiler-thunk pair | NewPredefinedFormArticleDialogAdjustorThunks : ignored : 85% : very strong : B011 2026-06-19 raw PE/Capstone recheck confirms the exact two `0x0b`-byte secondary/tertiary `NewPredefinedFormArticleDialog` destructor adjustors: `0x0047e931-0x0047e93c` subtracts `0xa0` and jumps to `0x0047ec30`, `0x0047e93c-0x0047e947` subtracts `0xa4` and jumps to `0x0047ec30`; the starts have only vtable dword refs at `0x006140b4`/`0x006140e4`, constructor stores place those tables at `this+0xa0`/`this+0xa4`, `0x0047e947-0x0047e950` is `0xcc` padding, [UID:0000ZS] is the scalar-deleting destructor target, and formal C++ must stay blank because source reconstruction should express the class destructor/inheritance layout and let MSVC regenerate the adjustor glue.
```

No other `by-memory/-coverage-report.md` replacement is required for this target. If support docs [UID:0000ZS] or [UID:0000ZP] are rescored in a later implementation callback, produce separate exact rows for those changes.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum target validation:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md](0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md](0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the pending coverage row:

> Executable block R003 was removed from this report and preserved verbatim in [0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md](0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Autogen refresh is not required merely because [UID:0000ZQ] stays non-reconstructable/no-emitter. It is useful after coverage-row changes or if any metadata changes affect generated reports.

## IDA Rename / Comment Recommendations

High confidence comments:

- `0x0047e931`: `NewPredefinedFormArticleDialog secondary destructor adjustor; this -= 0xa0; jump to scalar deleting destructor 0x0047ec30; compiler generated; no source emission`.
- `0x0047e93c`: `NewPredefinedFormArticleDialog tertiary destructor adjustor; this -= 0xa4; jump to scalar deleting destructor 0x0047ec30; compiler generated; no source emission`.
- `0x006140b4`: `NewPredefinedFormArticleDialog secondary vtable destructor slot -> 0x0047e931`.
- `0x006140e4`: `NewPredefinedFormArticleDialog tertiary vtable destructor slot -> 0x0047e93c`.

Naming guidance:

- It is acceptable for analysis labels to use `NewPredefinedFormArticleDialog_secondary_scalar_deleting_destructor_adjustor` and `NewPredefinedFormArticleDialog_tertiary_scalar_deleting_destructor_adjustor`.
- Do not use these as source C++ method names or emit them in reconstructed output.

## Remaining Issues and Impact

- Exact final `NewPredefinedFormArticleDialog` source C++ remains blocked on class-wide issues already documented elsewhere: dynamic control field names, parser record declarations, packet/helper types, alert/helper visibility, and retained-helper emission policy.
- Those class-wide issues do not affect [UID:0000ZQ]'s no-code decision. The thunks are fully classified as compiler glue.
- No split repair, owner reassignment, emitter assignment, or formal C++ insertion is warranted for [UID:0000ZQ].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0000ZQ"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000ZQ-NewPredefinedFormArticleDialogAdjustorThunks-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
