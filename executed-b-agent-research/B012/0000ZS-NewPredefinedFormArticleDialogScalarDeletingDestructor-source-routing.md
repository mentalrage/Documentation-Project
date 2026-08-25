** TARGET-REPORT-UID:0000ZS **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZS NewPredefinedFormArticleDialogScalarDeletingDestructor Source Routing

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000ZS] `0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor` as no-owner, non-emitting, no formal C++.
- Final disposition: reviewed MSVC scalar deleting destructor ABI wrapper over source-level/default `NewPredefinedFormArticleDialog` destruction, not a handwritten NexusTK function body.
- Required action: update the target documentation with the raw PE/export recheck, explicit `flags & 4` no-op guard-path proof, `DialogInSession` cleanup correction, and no-code/source-routing proof. Add or refresh the ignored-ledger entry and replace the by-memory coverage row manually under supervisor ownership.
- Score recommendation: `82/90 -> 85/92`.
- Metadata recommendation:
  - `CANONICAL_OWNER:NONE` stays unchanged.
  - `RECONSTRUCTABLE:FALSE` stays unchanged.
  - `EMITTER_UIDS:` stays blank.
  - `RECONSTRUCTION_CPP CODE` stays blank.
- Confidence: high. Exact bytes, half-open bounds, vtable pointer route, adjustor thunk refs, callees, flag behavior, and compiler/runtime classification are confirmed by local PE scan and exported IDA/Ghidra data. The remaining uncertainty is only original source spelling of an implicit/default destructor and the precise ABI label for the `flags & 4` branch, which should not affect no-code routing.

## Target Paths

- Target UID: `0000ZS`
- Target by-memory path: `source-3/project-documentation/by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing.md`
- Related adjustor thunk page: [UID:0000ZQ] `source-3/project-documentation/by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md`
- Semantic class owner for source-level behavior: [UID:000098] `source-3/project-documentation/by-class/NewPredefinedFormArticleDialog.md`
- Likely source-file route for source-level class code: [UID:0000LT] `source-3/project-documentation/by-file/NewPredefinedFormArticleDialog.md`
- Base cleanup target: [UID:00003S] `source-3/project-documentation/by-class/DialogInSession.md`, function `0x004a1450`
- Delete helper target: [UID:000197] `source-3/project-documentation/by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`

## Evidence Checked

- Read the current target page `by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md`.
- Read related pages:
  - [UID:0000ZQ] adjustor thunks.
  - [UID:000098] `NewPredefinedFormArticleDialog` class.
  - [UID:0000LT] `NewPredefinedFormArticleDialog` file.
  - [UID:0000ZL] `0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog` aggregate.
  - [UID:00003S] `DialogInSession`.
  - [UID:000131] `0x004a0d80-0x004a15f8.DialogSessionCore`.
  - [UID:0001U5] `DialogSessionLayouts`.
  - [UID:0001XD] `DialogSessionVtables`.
  - [UID:000197] `OperatorDeleteWrapper`.
  - [UID:0000ZM] `BulletinMailAlertCompanions`.
  - [UID:0000ZP] `DialogAndAlertDestructorAdjustorThunks`.
  - [UID:0001X4] `BoardArticleDialogVtableFamily`.
  - Nearby accepted scalar deleting destructor siblings [UID:00033N], [UID:00033O], and [UID:00033P].
- Checked current generated/coverage state:
  - `auto-generated/-ag-memory-coverage.md` lists [UID:0000ZS] as `not_reconstructable`, `NONE`, no emitter.
  - `project-level/-auto-completion-stats.md` lists `0000ZS` as `82/90`.
  - `by-memory/-coverage-report.md` row currently marks [UID:0000ZS] as `ignored : 82% : strong`.
- Checked function export data:
  - `hooks-generation/tests/function_data/ida/0x0047ec30.json`
  - `hooks-generation/tests/function_data/ghidra/0x0047ec30.json`
  - `hooks-generation/tests/function_data/combined/functions/0x0047ec30.json`
  - `hooks-generation/tests/function_data/ida/0x0047e931.json`
  - `hooks-generation/tests/function_data/ida/0x004f4ac0.json`
  - `hooks-generation/tests/function_data/ida/0x0041b6a0.json`
  - `hooks-generation/tests/function_data/ida/0x004a1450.json`
  - `hooks-generation/tests/function_data/ghidra/0x004a1450.json`
- Ran current local PE scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` to recheck raw bytes, padding, absolute VA/RVA hits, and `.text` rel32 call/jump targets.
- Checked IDA MCP availability on 2026-06-19. It was unavailable: `Unable to connect to the remote server`. This report therefore uses local PE bytes plus existing exported IDA/Ghidra function data rather than live MCP output.
- Ran `int_convert.py` for required number conversions:
  - `0x3b` = 59 bytes (Verified with `int_convert.py`).
  - `0x5368` = 21352 bytes (Verified with `int_convert.py`).
  - `0xa0` = 160 bytes (Verified with `int_convert.py`).
  - `0xa4` = 164 bytes (Verified with `int_convert.py`).
  - `0x04` = 4 and `0x01` = 1 (Verified with `int_convert.py`).

## Executive Recommendation

Do not make [UID:0000ZS] source-bearing. The exact target is a compiler-generated scalar deleting destructor wrapper:

- It is reached by the primary `NewPredefinedFormArticleDialog` vtable slot at `0x00614050`.
- It is reached by two compiler adjustor thunks at `0x0047e937` and `0x0047e942`.
- It calls the shared `DialogInSession` non-deleting destructor at `0x004a1450`, then applies deleting-destructor flag handling.
- It calls `OperatorDeleteWrapper` only for the ordinary scalar-delete path.
- Its `flags & 4` branch is not source-authored cleanup in the current binary: it pushes `this` and object size `0x5368` / 21352 (Verified with `int_convert.py`), calls the one-byte `@_guard_check_icall_nop@4` helper, adjusts the stack, and returns.

The source-level semantics belong to [UID:000098] `NewPredefinedFormArticleDialog` and [UID:0000LT] `NewPredefinedFormArticleDialog.cpp`: the ordinary destructor is implicit/default or an empty class-level destructor with no derived-member cleanup. The target page should document that source shape but should not emit any function body. If final class declarations later need a visible destructor, express it on the class/source owner, not here.

## Supervisor Active Recheck

- Assignment: `B012-goal2-new-predefined-form-article-dialog-scalar-dtor-source-routing-0000ZS-20260619`.
- Report-only phase. No by-* docs were edited, and `by-memory/-coverage-report.md` was not edited.
- Split repair is not required. The target range is already exact: `0x0047ec30-0x0047ec6b`, bounded by padding on both sides.
- The existing no-owner/non-emitting disposition is correct, but the target documentation should be strengthened and rescored.

## Inference Research Guidance Check

`by-structure.md` says compiler/linker-generated artifacts such as adjustor thunks, EH/RTTI/security-cookie support, padding, and pure ABI glue should be documented for recognition and exclusion, not hand-ported as source unless source declarations are needed to cause them. It also separates `CANONICAL_OWNER` from `EMITTER_UIDS`.

For this target, the source declaration need is already handled by the class/file docs. The by-memory item itself is not a source-level object:

- `NewPredefinedFormArticleDialog` class/file pages are reconstructable and already route the source-visible class code.
- [UID:0000ZS] is a vtable ABI wrapper generated from class layout/destructor semantics.
- Assigning [UID:0000ZS] to the class or file would not improve source output, because there is no handwritten body to emit.

Existing documentation assumptions were treated as leads:

- Correct lead: target is a scalar deleting destructor wrapper.
- Correct lead: `DialogInSession` cleanup at `0x004a1450` is the real base cleanup target.
- Correct lead: `boost::exception *` in IDA and `ArticleDialog::~ArticleDialog` in Ghidra/generated output are type/name pollution.
- Stale/incomplete lead: current target text says the `flags & 4` path is a no-op/sized-delete path but does not fully record the exact raw branch shape or current binary proof.
- Stale/incomplete lead: `by-memory/-ignored.md` records the adjustor thunk pair and padding, but it does not appear to have an explicit ignored-ledger entry for the scalar deleting destructor wrapper itself.

## Heuristic / Inference Reanalysis And Validation

### Source-bearing versus no-code status

- Best inference: exact no-code proof; keep `RECONSTRUCTABLE:FALSE`, owner `NONE`, emitter blank.
- Evidence: the body has only ABI destructor wrapper actions: base cleanup call, deleting flags, optional delete helper, guard/no-op branch, and return of `this`. There is no class-specific field cleanup, no singleton/global behavior, no packet/UI behavior, no helper logic, and no direct ordinary callers.
- Rejected alternative, source-authored class destructor body: rejected for this exact range. A source-level destructor may exist implicitly or as an empty/default destructor, but this machine body is the deleting wrapper, not the ordinary destructor source body.
- Rejected alternative, class-owned emitting by-memory child: rejected for [UID:0000ZS] under the local BoardArticleDialog family convention. Adjacent accepted pages [UID:00033N], [UID:00033O], and [UID:00033P] keep exact dialog scalar deleting destructor wrappers as `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank C++ while recording the semantic class owner in prose.
- Score impact: documentation can rise to `85/92`, but no emitted code should be added.

### Ordinary destructor placement

- Best inference: the ordinary/source-level destructor for `NewPredefinedFormArticleDialog` has no derived cleanup beyond base `DialogInSession` teardown. It was likely implicit/default or explicitly empty in the class source.
- Evidence: the deleting wrapper calls `0x004a1450` directly and does not call a separate `NewPredefinedFormArticleDialog::~NewPredefinedFormArticleDialog` body. No separate ordinary destructor page/function was found for this class. The class main range `0x004777a0-0x00478f8e` contains constructor, handlers, parser, paint, transfer reply, and submit, but no ordinary destructor body.
- Best source direction: class/file docs may state "ordinary/default destructor semantics are only `DialogInSession` base cleanup; no derived member cleanup is present." Do not put a `RECONSTRUCTION_CPP` body on [UID:0000ZS].
- Rejected alternative, attach `0x004a1450` to `ArticleDialog`: rejected. [UID:00003S], [UID:000131], and [UID:0001XD] identify `0x004a1450` as `DialogInSession` non-deleting destructor; Ghidra's `ArticleDialog` label is propagated owner pollution.

### Callee identities

| Address | Best name | Evidence | Source impact |
| --- | --- | --- | --- |
| `0x004a1450` | `DialogInSession` non-deleting destructor | [UID:00003S] and [UID:000131] document three `DialogInSession` vtable restores and `DialogPane` base teardown; exported IDA xrefs show sibling dialog wrappers call it. | Correct stale `ArticleDialog::~ArticleDialog` wording. |
| `0x004f4ac0` | `OperatorDeleteWrapper` | [UID:000197] documents the MemoryMan-backed global delete wrapper calling `GetMemoryMan` and `FreeBufferMemory`; exported IDA reports broad fanout. | This is storage free only on ordinary scalar-delete path. |
| `0x0041b6a0` | `@_guard_check_icall_nop@4` / `GuardCheckIcallNop` | `by-memory/-ignored.md` and exported IDA data show a one-byte no-op helper; raw PE scan found 360 rel32 call targets. | `flags & 4` branch is compiler/runtime ABI support, not NexusTK cleanup. |

### Flag behavior and `flags & 4`

- Exact branch shape:
  - Call `DialogInSession` cleanup first.
  - Load `flags` from `[ebp+8]`.
  - If `(flags & 1) == 0`, return `this`.
  - If `(flags & 4) == 0`, call `OperatorDeleteWrapper(this)`, then return `this`.
  - If `(flags & 4) != 0`, push object size `0x5368` / 21352 (Verified with `int_convert.py`), push `this`, call `0x0041b6a0`, add `esp, 8`, and return `this`.
- Best inference: this is MSVC deleting-destructor ABI support for an alternate sized/vector-delete style flag state, but in this binary the target is the CFG guard-check no-op and no storage free occurs on that branch.
- Rejected alternative, source-level helper call: rejected. No NexusTK helper is reached; `0x0041b6a0` is documented as compiler/runtime no-op.
- Rejected alternative, ordinary `delete[]` or vector destructor body: rejected for final C++. The bytes prove only the binary branch shape, not a source-authored vector delete routine. The final source should let the compiler generate equivalent ABI code.

### Vtable ownership and adjustor thunk refs

- The primary vtable slot at `0x00614050` points to `0x0047ec30`.
- The secondary and tertiary vtable slots at `0x006140b4` and `0x006140e4` point to adjustor thunks `0x0047e931` and `0x0047e93c`.
- The two adjustor thunks subtract `0xa0` / 160 and `0xa4` / 164 from `ecx` (Verified with `int_convert.py`) and jump to `0x0047ec30`.
- Raw PE scan found constructor-side immediate uses of the three vtable bases at `.text` VAs `0x004777f0`, `0x004777fa`, and `0x00477804`, consistent with the class constructor installing `NewPredefinedFormArticleDialog` primary/secondary/tertiary vtables.
- Best inference: these are compiler-generated from the class inheritance/vtable layout documented by [UID:000098], [UID:0000LT], [UID:0000ZQ], and [UID:0001X4].

### Source file routing

- Best source route for human source: [UID:0000LT] `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, with class [UID:000098].
- Best route for this by-memory target: none; no owner/emitter metadata.
- If forced to name a semantic owner in prose: [UID:000098] `NewPredefinedFormArticleDialog`.
- Rejected alternative, route to [UID:00003S] `DialogInSession`: rejected as canonical owner for this wrapper. `DialogInSession` owns the callee cleanup body, but the vtable slot and object-size constant are `NewPredefinedFormArticleDialog`-specific.
- Rejected alternative, route to [UID:000197] `OperatorDeleteWrapper` or MemoryMan: rejected. MemoryMan owns the delete helper, not the destructor wrapper.
- Rejected alternative, route to [UID:0000ZM] `BulletinMailAlertCompanions`: rejected. That page is a mixed overlap/index map; it does not own the exact child wrapper.

### Compiler-generated/raw names

- `sub_47EC30`: source-facing descriptive name should be `NewPredefinedFormArticleDialog_ScalarDeletingDestructor` for documentation/IDA comments only. Do not imply original handwritten source.
- `sub_47E931`: `NewPredefinedFormArticleDialog_SecondaryScalarDtorAdjustor` or `NewPredefinedFormArticleDialog_DestructorAdjustorA0`.
- `sub_47E93C`: `NewPredefinedFormArticleDialog_TertiaryScalarDtorAdjustor` or `NewPredefinedFormArticleDialog_DestructorAdjustorA4`.
- `sub_4A1450`: use `DialogInSession_NonDeletingDestructor` / `DialogInSession::~DialogInSession` cleanup, not `ArticleDialog`.
- `sub_4F4AC0`: `OperatorDeleteWrapper`, already documented.
- `@_guard_check_icall_nop@4`: keep as MSVC CFG guard-check no-op.

## Raw PE And Export Facts

Raw PE scan context:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`

Bounds and bytes:

| Range | Classification | Bytes / evidence |
| --- | --- | --- |
| `0x0047e931-0x0047e93c` | secondary adjustor thunk | `81 e9 a0 00 00 00 e9 f4 02 00 00` |
| `0x0047e93c-0x0047e947` | tertiary adjustor thunk | `81 e9 a4 00 00 00 e9 e9 02 00 00` |
| `0x0047e947-0x0047e950` | padding before destructor strip | nine `0xcc` bytes |
| `0x0047ec2b-0x0047ec30` | predecessor padding | five `0xcc` bytes |
| `0x0047ec30-0x0047ec6b` | target body | `0x3b` / 59 bytes (Verified with `int_convert.py`) |
| `0x0047ec6b-0x0047ec70` | successor padding | five `0xcc` bytes |

Target body bytes:

```text
55 8b ec 56 8b f1 e8 15 28 02 00 8b 45 08 a8 01
74 22 a8 04 75 10 56 e8 74 5e 07 00 83 c4 04 8b
c6 5e 5d c2 04 00 68 68 53 00 00 56 e8 3f ca f9
ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Instruction-level shape from the bytes:

```asm
0047ec30  push ebp
0047ec31  mov  ebp, esp
0047ec33  push esi
0047ec34  mov  esi, ecx
0047ec36  call 0x004a1450
0047ec3b  mov  eax, [ebp+8]
0047ec3e  test al, 1
0047ec40  je   0x0047ec64
0047ec42  test al, 4
0047ec44  jne  0x0047ec56
0047ec46  push esi
0047ec47  call 0x004f4ac0
0047ec4c  add  esp, 4
0047ec4f  mov  eax, esi
0047ec51  pop  esi
0047ec52  pop  ebp
0047ec53  ret  4
0047ec56  push 0x5368
0047ec5b  push esi
0047ec5c  call 0x0041b6a0
0047ec61  add  esp, 8
0047ec64  mov  eax, esi
0047ec66  pop  esi
0047ec67  pop  ebp
0047ec68  ret  4
```

Pointer and branch route recheck:

| Target | Raw PE result |
| --- | --- |
| `0x0047ec30` | one absolute VA hit at `.rdata:0x00614050`; no RVA hits; two `.text` rel32 jumps at `0x0047e937` and `0x0047e942`. |
| `0x0047e931` | one absolute VA hit at `.rdata:0x006140b4`; no RVA hits; no `.text` rel32 branch/call targets. |
| `0x0047e93c` | one absolute VA hit at `.rdata:0x006140e4`; no RVA hits; no `.text` rel32 branch/call targets. |
| `0x004a1450` | six `.text` rel32 refs: `0x0047e850`, `0x0047e956`, `0x0047e996`, `0x0047ea16`, `0x0047ebf6`, and `0x0047ec36`. |
| `0x004f4ac0` | 2129 `.text` rel32 call refs; broad global delete/helper fanout. |
| `0x0041b6a0` | 360 `.text` rel32 call refs; one-byte compiler/runtime guard-check no-op. |

Exported function data agrees:

- IDA export for `0x0047ec30`: name `sub_47EC30`, size 59, not thunk, xrefs from `0x0047e937`, `0x0047e942`, and data offset `0x00614050`; callees `0x004a1450`, `0x004f4ac0`, and `0x0041b6a0`.
- Ghidra export for `0x0047ec30`: name `~NewPredefinedFormArticleDialog`, size 59, callers `0x0047e931` and `0x0047e93c`, callees `0x004a1450`, `0x004f4ac0`, and guard-check.
- IDA export for `0x0047e931`: size 11, decompile `return sub_47EC30(this - 160, flags)`, data xref from `0x006140b4`.
- IDA export for `0x004a1450`: size 31, xrefs from sibling board/article/mail dialog destructor wrappers and the `0x0047e850` jump thunk.
- IDA export for `0x0041b6a0`: size 1, decompiles to an empty body.

## Ranked Ownership Analysis

### 1. No-owner, non-emitting compiler wrapper, with semantic owner in prose

- Evidence for:
  - Exact body is ABI deleting-destructor glue.
  - Adjacent BoardArticleDialog scalar destructor pages use this convention.
  - No source-authored behavior exists inside the target beyond generated destructor mechanics.
  - Class/file docs already own the source-visible dialog.
  - `by-structure.md` permits `RECONSTRUCTABLE:FALSE` for compiler/linker-generated pages with blank emitters and C++.
- Evidence against:
  - The primary vtable slot is class-specific, and a rebuilt class declaration must cause equivalent wrapper bytes.
  - Some other project scalar deleting destructor pages are marked reconstructable/source-declared/generated-binary when they include class-specific destructor semantics or use a different family convention.
- Decision: accept for this exact target. Preserve `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters. Record [UID:000098] as semantic owner in body text, not metadata.

### 2. Assign to [UID:000098] NewPredefinedFormArticleDialog

- Evidence for:
  - Vtable slot `0x00614050` belongs to `NewPredefinedFormArticleDialog`.
  - Adjustor thunks are specific to this class's secondary/tertiary views.
  - Object-size immediate `0x5368` / 21352 (Verified with `int_convert.py`) is class-specific.
  - Class parent [UID:000098] and file [UID:0000LT] now clear the active gate.
- Evidence against:
  - Exact target is still compiler-generated ABI glue, not a handwritten method.
  - Adjacent accepted ArticleDialog/ArticleListDialog/BulletinDialog scalar destructor pages keep `NONE/FALSE/blank` metadata with semantic owner in prose.
  - Assigning the wrapper would invite decompiler-shaped formal C++ or duplicate source semantics already owned by the class.
- Decision: reject as metadata change for [UID:0000ZS]. Mention as semantic owner only.

### 3. Route through [UID:0000LT] NewPredefinedFormArticleDialog file

- Evidence for:
  - File [UID:0000LT] is the source root for the class and parser.
  - The wrapper is generated from that class's source declaration and inheritance layout.
- Evidence against:
  - `CANONICAL_OWNER` should be the narrowest true semantic owner when used; if this were source-bearing, the class would be narrower than the file.
  - The exact target should not emit source through any route.
- Decision: reject for metadata. Keep [UID:0000LT] as the source-level class/file route in support prose.

### 4. Route through [UID:00003S] DialogInSession

- Evidence for:
  - The only real cleanup callee is `DialogInSession` non-deleting destructor `0x004a1450`.
- Evidence against:
  - The vtable slot, adjustor thunks, and object size are `NewPredefinedFormArticleDialog`-specific.
  - `DialogInSession` owns the callee cleanup, not the derived wrapper's vtable slot.
- Decision: reject.

### 5. Route through MemoryMan / OperatorDeleteWrapper

- Evidence for:
  - Normal scalar-delete branch calls [UID:000197] `OperatorDeleteWrapper`.
- Evidence against:
  - `OperatorDeleteWrapper` is only a global delete dependency.
  - It has thousands of callers and does not own individual destructor wrappers.
- Decision: reject.

## Recommended Target Doc Changes

Apply these only after supervisor acceptance. Do not edit during report review.

### Metadata

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep formal C++ blank.

### Status / Scope Text

Recommended replacement or addition:

```markdown
## Status

- Disposition: reviewed MSVC compiler-generated scalar deleting destructor wrapper over source-level/default `NewPredefinedFormArticleDialog` destruction.
- Entity kind: scalar deleting destructor ABI wrapper, not handwritten NexusTK source logic.
- Semantic owner: [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md), with source-level class code under [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).
- Metadata owner/emitter decision: keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters/C++ because this exact by-memory body should be regenerated by the compiler from the class declaration/destructor layout, not hand-emitted.
- Confidence: very strong for exact bytes, bounds, vtable route, adjustor thunk refs, callees, flag behavior, and source exclusion; capped below final audit by original source destructor spelling and exact ABI label for the `flags & 4` path.
```

### Behavior Text

Recommended replacement or addition:

```markdown
## Behavior

The wrapper receives `this` in `ecx` and deleting-destructor flags at `[ebp+8]`. It calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) non-deleting destructor `0x004a1450` first. It then checks the flags:

- `(flags & 1) == 0`: return `this` without freeing storage.
- `(flags & 1) != 0 && (flags & 4) == 0`: call [UID:000197][OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) at `0x004f4ac0` on `this`, then return `this`.
- `(flags & 1) != 0 && (flags & 4) != 0`: push object size `0x5368` / 21352 bytes (Verified with `int_convert.py`), push `this`, call the one-byte MSVC guard-check no-op at `0x0041b6a0`, clean two pushed arguments with `add esp, 8`, and return `this`.

The `flags & 4` branch should be documented as compiler/runtime ABI support for an alternate sized/vector-delete flag state in this build, not as source-authored cleanup. The current binary does not free object storage on that branch.
```

### Raw Evidence Addition

Recommended addition:

```markdown
## 2026-06-19 B012 Raw PE / Export Recheck

Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms image base `0x00400000`, `.text` `0x00401000-0x0060c600`, and exact target body `0x0047ec30-0x0047ec6b`, `0x3b` / 59 bytes (Verified with `int_convert.py`). Predecessor padding `0x0047ec2b-0x0047ec30` and successor padding `0x0047ec6b-0x0047ec70` are five `0xcc` bytes each.

Target bytes:

```text
55 8b ec 56 8b f1 e8 15 28 02 00 8b 45 08 a8 01
74 22 a8 04 75 10 56 e8 74 5e 07 00 83 c4 04 8b
c6 5e 5d c2 04 00 68 68 53 00 00 56 e8 3f ca f9
ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Raw pointer/branch scan found one absolute VA pointer to `0x0047ec30` at `.rdata:0x00614050`, no RVA hits, and two `.text` rel32 jumps from `0x0047e937` and `0x0047e942`. It found one absolute VA pointer to adjustor thunk `0x0047e931` at `.rdata:0x006140b4` and one to `0x0047e93c` at `.rdata:0x006140e4`; neither thunk start has direct `.text` call/jump targets. The `0x004a1450` cleanup target has six `.text` rel32 refs, including this wrapper at `0x0047ec36` and sibling board/article/mail dialog destructor wrappers.

Exported IDA/Ghidra function data agrees on size 59, xrefs from the two adjustor jumps plus primary vtable data, and callees `0x004a1450`, `0x004f4ac0`, and `0x0041b6a0`.
```

### No-Code Proof

Recommended addition:

```markdown
## No-Code Proof

Do not populate this page's formal `RECONSTRUCTION_CPP CODE` block. The exact range is compiler-generated deleting-destructor glue. Source reconstruction should express the `NewPredefinedFormArticleDialog` class and ordinary/default destructor semantics under [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md) / [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), then let MSVC regenerate the primary scalar deleting destructor and secondary/tertiary adjustor thunks.

The source-level destructor spelling remains inferred: it may have been implicit/default, explicitly defaulted, or an empty destructor definition. The binary proves there is no derived cleanup body in this wrapper beyond calling the shared `DialogInSession` cleanup. Handwriting the deleting-wrapper flag checks, guard branch, and delete-helper call in final C++ would be decompiler-shaped ABI code rather than plausible mid-2000s source.
```

### Score Rationale

Recommended replacement/addition:

```markdown
## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | Exact range, bytes, padding, vtable route, adjustor thunk refs, callee identities, scalar-delete flags, `flags & 4` guard/no-op path, source-level destructor placement, and no-code policy are documented. Completion is capped because this exact target is compiler-generated and original source destructor spelling is not recoverable from the binary. |
| Confidence | 92 | Local PE bytes, exported IDA/Ghidra function data, supporting class/vtable docs, and adjacent accepted destructor-wrapper pages agree. Confidence remains below final-audit levels because live MCP was unavailable in this pass and the exact ABI label for the `flags & 4` path is inferred as compiler/runtime support rather than original source proof. |
| Reconstructable | false | This wrapper should be regenerated by the compiler from class declarations/destructor semantics, not hand-authored as NexusTK source. |
```

### Changes Entry

Recommended addition:

```markdown
- 2026-06-19 B012 source-routing recheck:
  - Recommended score `82/90 -> 85/92`; metadata owner/emitter/reconstructable state remains `NONE` / `FALSE` / blank.
  - Summary/evidence: raw PE scan and exported IDA/Ghidra data reconfirmed exact `0x0047ec30-0x0047ec6b` body, five-byte pre/post padding, primary vtable data ref `0x00614050`, adjustor jumps from `0x0047e937` and `0x0047e942`, `DialogInSession` cleanup call `0x004a1450`, ordinary scalar-delete free through `0x004f4ac0`, and `flags & 4` guard/no-op path through `0x0041b6a0` with object size `0x5368` / 21352 (Verified with `int_convert.py`). Corrected decompiler/generated `ArticleDialog` and `boost::exception` type/name pollution and kept formal C++ blank because source should express ordinary/default class destructor semantics under [UID:000098]/[UID:0000LT].
```

## Recommended Support Doc Changes

Do not apply these until supervisor acceptance. Scores below are recommendations only unless explicitly stated as unchanged.

### `by-memory/-ignored.md`

Add a dedicated ignored-ledger entry near the existing `0x0047e931-0x0047e947` thunk entry or near the `0x0047ec6b-0x0047ec70` padding entry:

```markdown
- `0x0047ec30-0x0047ec6b` - `NewPredefinedFormArticleDialog` scalar deleting destructor wrapper.
  - Why ignored: MSVC compiler-generated scalar deleting destructor ABI glue over source-level/default `NewPredefinedFormArticleDialog` destruction; not handwritten predefined-form article dialog logic.
  - Evidence: [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) records the B012 2026-06-19 raw PE/export recheck: exact `0x3b` / 59-byte body (Verified with `int_convert.py`), five-byte pre/post padding, primary vtable/data ref `0x00614050`, adjustor jumps from `0x0047e937` and `0x0047e942`, `DialogInSession` cleanup call `0x004a1450`, normal scalar-delete `OperatorDeleteWrapper` call `0x004f4ac0`, and `flags & 4` no-op guard path through `0x0041b6a0` with object size `0x5368` / 21352 (Verified with `int_convert.py`).
  - Replacement/procurement: model the `NewPredefinedFormArticleDialog` class and ordinary/default destructor semantics in source; let MSVC regenerate this scalar deleting destructor and the secondary/tertiary adjustor thunks.
  - Owner docs: [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md), [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md), [UID:00003S][DialogInSession](by-class/DialogInSession.md).
```

### [UID:0000ZQ] Adjustor Thunks

Score can stay `82/90`. Add a short sync note:

```markdown
- 2026-06-19 B012 sync: [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) was rechecked as exact non-emitting compiler scalar-deleting-destructor glue. The two thunks still subtract `0xa0` / 160 and `0xa4` / 164 (Verified with `int_convert.py`) and jump to that wrapper; no source C++ should be emitted for either the thunks or the wrapper.
```

### [UID:000098] Class Page

Score can stay `85/86`. Update the scalar destructor method row or evidence note to avoid implying a source-bearing destructor body:

```markdown
| scalar deleting destructor | [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) | Compiler-generated deleting wrapper over ordinary/default class destruction. It calls `DialogInSession` cleanup at `0x004a1450`, conditionally calls `OperatorDeleteWrapper`, and has a `flags & 4` guard/no-op path; source should model the class destructor normally and let MSVC regenerate this wrapper. |
```

Add to evidence notes:

```markdown
- 2026-06-19 B012 rechecked the deleting destructor companion. The ordinary/source-level `NewPredefinedFormArticleDialog` destructor has no derived cleanup body proven by the binary; the exact wrapper at `0x0047ec30` calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) cleanup directly, then runs compiler deleting-destructor flag handling. Treat `ArticleDialog::~ArticleDialog` and `boost::exception` spellings from decompilers/generated output as type/name pollution.
```

### [UID:0000LT] File Page

Score can stay `88/85`. Add to boundary/migration notes:

```markdown
- 2026-06-19 B012 rechecked [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md): keep it non-emitting and do not migrate it as a handwritten source function. The source-level class should use implicit/default or empty destructor semantics, with the shared `DialogInSession` cleanup reached through normal inheritance; the compiler will regenerate the scalar deleting destructor and adjustor thunks.
```

### [UID:0000ZL] Main Memory Aggregate

Score can stay `85/90`. Add a companion-range sync note:

```markdown
- 2026-06-19 B012 raw PE/export recheck confirms the companion deleting destructor [UID:0000ZS] is exact compiler ABI glue: `0x0047ec30-0x0047ec6b`, primary vtable slot `0x00614050`, adjustor refs from [UID:0000ZQ], `DialogInSession` cleanup, optional `OperatorDeleteWrapper`, and `flags & 4` guard/no-op path. It should remain outside the aggregate's formal C++ and be represented by source-level class destructor/default semantics.
```

### [UID:0000ZM] BulletinMailAlertCompanions

Score can stay `84/90`. The existing inventory row for [UID:0000ZS] is broadly correct. If updated, add the `flags & 4` no-op and `DialogInSession` pollution correction:

```markdown
| [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) | non-emitting compiler wrapper | Exact `NewPredefinedFormArticleDialog` scalar deleting destructor ABI glue; semantic owner is [UID:000098], but wrapper source should be regenerated from class/default destructor semantics. |
```

### [UID:0001X4] BoardArticleDialogVtableFamily

Score can stay `85/91`. Optional update to the `NewPredefinedFormArticleDialog` core row or shared slot notes:

```markdown
- B012 2026-06-19 confirms `NewPredefinedFormArticleDialog` primary table slot `0x00614050` points to non-emitting scalar deleting destructor wrapper [UID:0000ZS], while secondary/tertiary slots `0x006140b4` and `0x006140e4` point to adjustor thunks [UID:0000ZQ]. These should be regenerated from class declarations, not emitted as handwritten source.
```

### No Change Needed

- [UID:000197] `OperatorDeleteWrapper`: already documents MemoryMan-backed global delete wrapper and broad fanout.
- [UID:00003S] `DialogInSession`: already documents `0x004a1450` as non-deleting destructor and notes sibling board/article wrappers call it.
- [UID:000131], [UID:0001U5], [UID:0001XD]: already support the `DialogInSession` destructor/vtable interpretation.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0000ZS].

If a review artifact is needed to explain binary behavior, use pseudocode only in notes, not in `RECONSTRUCTION_CPP CODE`:

```cpp
// Binary behavior only: do not hand-emit this wrapper as source.
NewPredefinedFormArticleDialog *NewPredefinedFormArticleDialog_scalar_deleting_destructor(
    NewPredefinedFormArticleDialog *self,
    unsigned int flags)
{
    // Source-level cleanup is ordinary/default destruction, represented by the class.
    self->DialogInSession::~DialogInSession();

    if ((flags & 1) != 0) {
        if ((flags & 4) == 0) {
            OperatorDeleteWrapper(self);
        } else {
            GuardCheckIcallNop(self, 0x5368);
        }
    }

    return self;
}
```

Source-level direction for [UID:000098]/[UID:0000LT], if needed later:

```cpp
// Preferred source-shape direction, not target formal C++.
NewPredefinedFormArticleDialog::~NewPredefinedFormArticleDialog()
{
}
```

An even more source-faithful final declaration may omit the destructor body or default it if surrounding class declarations permit that. The binary does not prove which spelling the original source used.

## Exact Coverage-Report Text

Do not edit `by-memory/-coverage-report.md` directly during B-agent report review.

Current row to replace:

```markdown
    - [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) 0x0047ec30-0x0047ec6b | scalar deleting destructor | NewPredefinedFormArticleDialogScalarDeletingDestructor : ignored : 82% : strong : IDA-verified compiler destructor glue for NewPredefinedFormArticleDialog; exact vtable reference, adjustor thunks, shared DialogInSession cleanup target, raw flags logic, and decompiler type-leak caveat documented.
```

Replacement row:

```markdown
    - [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) 0x0047ec30-0x0047ec6b | scalar deleting destructor wrapper | NewPredefinedFormArticleDialogScalarDeletingDestructor : ignored : 85% : very-strong : B012 2026-06-19 raw PE/export recheck confirms exact `0x3b` / 59-byte MSVC deleting-destructor wrapper (Verified with `int_convert.py`), five-byte pre/post padding, primary vtable slot `0x00614050`, adjustor jumps from `0x0047e937`/`0x0047e942`, `DialogInSession` cleanup call `0x004a1450`, `OperatorDeleteWrapper` call only for `(flags & 1) != 0 && (flags & 4) == 0`, flag-4 no-op guard path through `0x0041b6a0` with object size `0x5368` / 21352 (Verified with `int_convert.py`), decompiler `ArticleDialog`/`boost::exception` name pollution rejected, and blank formal C++ because source should express ordinary/default class destructor semantics under [UID:000098]/[UID:0000LT] and let MSVC regenerate this ABI wrapper.
```

No child/split coverage rows are needed. Existing neighboring rows for [UID:0000ZQ], [UID:00033N], [UID:00033O], [UID:00033P], padding `0x0047ec6b-0x0047ec70`, and [UID:0000ZU] remain structurally correct.

## Validator Needs After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after supervisor-approved edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md](0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md](0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the manual coverage replacement row:

> Executable block R003 was removed from this report and preserved verbatim in [0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md](0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No autogen C++ validation is needed for [UID:0000ZS] because the target remains `RECONSTRUCTABLE:FALSE` and non-emitting.

## IDA Rename / Type / Comment Recommendations

These are optional IDA hygiene recommendations, not documentation edits required for this report:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x0047ec30` | Rename/comment as `NewPredefinedFormArticleDialog_ScalarDeletingDestructor` or `NewPredefinedFormArticleDialog_scalar_deleting_destructor`; type as `NewPredefinedFormArticleDialog *__thiscall(NewPredefinedFormArticleDialog *this, unsigned int flags)`. | High for descriptive name and signature shape; original spelling is compiler-generated. |
| `0x0047e931` | Rename/comment as `NewPredefinedFormArticleDialog_SecondaryScalarDtorAdjustor` / `...AdjustorA0`; note subtracts `0xa0` / 160 (Verified with `int_convert.py`). | High. |
| `0x0047e93c` | Rename/comment as `NewPredefinedFormArticleDialog_TertiaryScalarDtorAdjustor` / `...AdjustorA4`; note subtracts `0xa4` / 164 (Verified with `int_convert.py`). | High. |
| `0x004a1450` | Prefer `DialogInSession_NonDeletingDestructor` over `ArticleDialog::~ArticleDialog` or `boost::exception` type propagation. | High. |
| `0x004f4ac0` | Keep/use `OperatorDeleteWrapper`. | High. |
| `0x0041b6a0` | Keep/use `GuardCheckIcallNop` / `@_guard_check_icall_nop@4`; comment as one-byte MSVC CFG no-op. | High. |
| `0x00614050` | Comment as `NewPredefinedFormArticleDialog` primary vtable scalar deleting destructor slot. | High. |
| `0x006140b4` / `0x006140e4` | Comment as secondary/tertiary destructor adjustor thunk slots. | High. |

## Open Questions And Closure

- Exact original destructor spelling: unresolved but bounded. The binary cannot distinguish implicit/default destructor, explicitly defaulted destructor, or empty destructor definition. This does not block source routing because all options generate class-level destructor semantics, not a handwritten by-memory wrapper body.
- Exact ABI name for `flags & 4` branch: unresolved but bounded. The branch resembles MSVC alternate sized/vector-delete flag handling, but the current binary target is the documented one-byte guard-check no-op. Treating it as compiler/runtime support is sufficient for no-code proof.
- Whether broader project policy should mark all source-declared/generated-binary scalar deleting destructors as reconstructable class-owned pages: out of scope for a one-off target. Local accepted BoardArticleDialog sibling pages use `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank C++ for comparable wrappers, so [UID:0000ZS] should stay aligned with that family unless the supervisor initiates a wider convention change.

## Implementation Readiness

- Target page update: ready after supervisor acceptance.
- Support docs: ready as optional sync edits listed above.
- Formal C++: not recommended.
- Coverage: exact replacement row provided above for supervisor-owned application.
- Split/rename: not needed.
- Owner/emitter: no change.

## Changed Files

- Created report only:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing.md`
- Not modified:
  - Target by-memory doc.
  - Support by-* docs.
  - `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0000ZS"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0000ZS-NewPredefinedFormArticleDialogScalarDeletingDestructor-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
