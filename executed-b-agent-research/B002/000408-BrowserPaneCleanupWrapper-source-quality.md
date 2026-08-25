** TARGET-REPORT-UID:000408 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 000408 **
# Agent-B002 Report: [UID:000408] BrowserPane Cleanup Wrapper Source Quality

## Assignment

- Target: [UID:000408] `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneCleanupWrapper.md`
- Required MCP session: `80de0a67`
- Report-only boundary honored: no by-* docs, project-structure docs, generated files, IDA DB state, or coverage reports were edited.
- Output disposition: implementation-ready repair recommendation.

## Executive Disposition

[UID:000408] should be reclassified from "cleanup wrapper pending classification" to the ordinary BrowserPane non-deleting destructor body:

```cpp
BrowserPane::~BrowserPane()
{
}
```

The three refs at `0x005fac2e`, `0x005fad79`, and `0x005fae35` are compiler-generated C++ EH unwind funclet jumps from BrowserDialog, WebBoardDialog, and WebBoardDialogOld constructors. They are not ordinary source callsites and they are not evidence for a standalone helper. The machine body at `0x0046a8a0-0x0046a8bf` is the source-representable `BrowserPane::~BrowserPane()` non-deleting destructor; vtable stores and the tail call to DialogPane cleanup are compiler lowering and must not be written manually.

Recommended implementation:

- Preserve UID `000408`.
- Rename/move the page to `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md`.
- Set metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000019`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`.
- Populate formal C++ with the empty destructor body above.

## MCP Session And Tool Status

MCP was available and responsive. I did not start, stop, restart, save, rename, patch, or otherwise manage IDA.

- `idb_list`: active session `80de0a67`, `NexusTK.exe.i64`, backend `worker`, `is_analyzing:false`.
- `server_health` for `80de0a67`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Read-only MCP evidence used:

- `lookup_funcs`
- `analyze_function`
- `disasm`
- `xrefs_to`
- `callees`
- `get_bytes`
- `trace_data_flow`

## Positive Evidence

### Target Body

`lookup_funcs` reports:

| Address | Function | Size |
| --- | --- | ---: |
| `0x0046a8a0` | `sub_46A8A0` | `0x1f` |
| `0x00470690` | `sub_470690` | `0x55` |
| `0x0049d9f0` | `??1exception@boost@@MAE@XZ_0` | `0xdb` |

`analyze_function 0x0046a8a0` reports this exact body:

```asm
46a8a0  mov dword ptr [ecx], offset ??_7BrowserPane@@6B@
46a8a6  mov dword ptr [ecx+0A0h], offset ??_7BrowserPane@@6B@_0
46a8b0  mov dword ptr [ecx+0A4h], offset ??_7BrowserPane@@6B@_1
46a8ba  jmp ??1exception@boost@@MAE@XZ_0
```

The decompiler renders the callee as `boost::exception::~exception`, but supporting DialogPane docs and MCP behavior show `0x0049d9f0` is the polluted IDA name for the DialogPane cleanup / non-deleting destructor family. The target restores the three BrowserPane vtable views at `0x006132ec`, `0x00613360`, and `0x00613390`, then tail-chains to the base DialogPane cleanup path.

`get_bytes 0x0046a8a0 size 32` confirms the half-open range and padding:

- Body bytes through final jump: `c7 01 ec 32 61 00 c7 81 a0 00 00 00 60 33 61 00 c7 81 a4 00 00 00 90 33 61 00 e9 31 31 03 00`
- Following byte at `0x0046a8bf`: `cc`

So the documented `0x0046a8a0-0x0046a8bf` range is exact, and `0x0046a8bf-0x0046a8c0` remains one byte of padding.

### Three References Classified

`xrefs_to 0x0046a8a0` reports exactly three code refs:

| Ref | Owning function | Classification |
| --- | --- | --- |
| `0x005fac2e` | `sub_46AA40` (`0x0046aa40-0x0046ad0a`) | BrowserDialog constructor EH unwind funclet |
| `0x005fad79` | `sub_46D050` (`0x0046d050-0x0046d324`) | WebBoardDialog constructor EH unwind funclet |
| `0x005fae35` | `sub_46E640` (`0x0046e640-0x0046e8be`) | WebBoardDialogOld constructor EH unwind funclet |

The relevant disassembly tails are:

```asm
; BrowserDialog constructor tail chunk
5fac2b  mov ecx, [ebp+var_3C]
5fac2e  jmp sub_46A8A0
5fac33  mov ecx, [ebp+var_3C]
5fac36  add ecx, 278h
5fac3c  jmp sub_470220
...
5fac6d  SEH_46AA40:
5fac88  mov eax, offset stru_6595CC
5fac8d  jmp ___CxxFrameHandler3
```

```asm
; WebBoardDialog constructor tail chunk
5fad76  mov ecx, [ebp+var_50]
5fad79  jmp sub_46A8A0
5fad7e  mov ecx, [ebp+var_50]
5fad81  add ecx, 278h
5fad87  jmp sub_470250
...
5fada2  SEH_46D050:
5fadbd  mov eax, offset stru_659518
5fadc2  jmp ___CxxFrameHandler3
```

```asm
; WebBoardDialogOld constructor tail chunk
5fae32  mov ecx, [ebp+var_4C]
5fae35  jmp sub_46A8A0
5fae3a  mov ecx, [ebp+var_4C]
5fae3d  add ecx, 278h
5fae43  jmp sub_470260
...
5fae69  SEH_46E640:
5fae84  mov eax, offset stru_6594AC
5fae89  jmp ___CxxFrameHandler3
```

`xrefs_to` on the tail labels proves the `jmp sub_46A8A0` sites are EH unwind-map actions, not ordinary direct calls:

| Action label | Data xref | Meaning |
| --- | --- | --- |
| `0x005fac2b` | `0x0065976c` | unwind action in `sub_46AA40` FuncInfo chain |
| `0x005fad76` | `0x006593bc` | unwind action in `sub_46D050` FuncInfo chain |
| `0x005fae32` | `0x006596ec` | unwind action in `sub_46E640` FuncInfo chain |

The EH data slices also show these labels as action addresses in C++ unwind maps:

- `0x0065975c` slice contains `ff ff ff ff 2b ac 5f 00`, then later actions `0x005fac33`, `0x005fac41`, `0x005fac4c`, `0x005fac57`, `0x005fac62`.
- `0x006593ac` slice contains `ff ff ff ff 76 ad 5f 00`, then later actions `0x005fad7e`, `0x005fad8c`, `0x005fad97`.
- `0x006596dc` slice contains `ff ff ff ff 32 ae 5f 00`, then later actions `0x005fae3a`, `0x005fae48`, `0x005fae53`, `0x005fae5e`.

`trace_data_flow backward 0x0046a8a0 depth 2` independently reports the same three `jmp sub_46A8A0` refs and their preceding `mov ecx, [ebp+saved_this]` labels.

### Constructor Context

The three owning constructor functions all install the BrowserPane base vtables before switching to a derived class vtable:

- `sub_46AA40` writes BrowserPane views at `0x0046aa86`, `0x0046aa8c`, `0x0046aa96`, then BrowserDialog views at `0x0046aad2`, `0x0046aad8`, `0x0046aae5`.
- `sub_46D050` writes BrowserPane views at `0x0046d0a0`, `0x0046d0a6`, `0x0046d0b0`, then WebBoardDialog views at `0x0046d0e6`, `0x0046d0ec`, `0x0046d0f6`.
- `sub_46E640` writes BrowserPane views at `0x0046e68a`, `0x0046e690`, `0x0046e69a`, then WebBoardDialogOld views at `0x0046e6e1`, `0x0046e6e7`, `0x0046e6f1`.

This is exactly the C++ constructor/EH pattern: when derived construction fails after the BrowserPane base has completed, the compiler emits unwind funclets that call the completed base destructor.

### Relationship To Scalar Deleting Destructor

`analyze_function 0x00470690` reports the separate BrowserPane scalar deleting destructor:

```asm
470690  push ebp
470691  mov ebp, esp
470693  push esi
470694  mov esi, ecx
470696  mov dword ptr [esi], offset ??_7BrowserPane@@6B@
47069c  mov dword ptr [esi+0A0h], offset ??_7BrowserPane@@6B@_0
4706a6  mov dword ptr [esi+0A4h], offset ??_7BrowserPane@@6B@_1
4706b0  call ??1exception@boost@@MAE@XZ_0
4706b5  mov eax, [ebp+arg_0]
4706b8  test al, 1
4706ba  jz loc_4706DE
4706bc  test al, 4
4706be  jnz loc_4706D0
4706c0  push esi
4706c1  call sub_4F4AC0
...
4706e2  retn 4
```

`xrefs_to 0x00470690` shows code refs only from adjustor thunks `0x004702c0` and `0x004702cb`, plus the vtable data ref at `0x006132ec`. This is the MSVC scalar deleting wrapper and remains no-code compiler glue. The source destructor body at [UID:000408] should not duplicate the wrapper flag/delete logic.

The adjustors are:

```asm
4702ba  sub ecx, 0A0h
4702c0  jmp sub_470690

4702c5  sub ecx, 0A4h
4702cb  jmp sub_470690
```

## Negative Evidence And Rejected Alternatives

| Alternative | Decision | Evidence |
| --- | --- | --- |
| Standalone cleanup helper | Rejected | Body is exact BrowserPane vtable restoration followed by base destructor chaining. It has no independent helper logic and no non-EH callsites. |
| Compiler-only no-code artifact | Rejected for [UID:000408] | This is the ordinary non-deleting destructor body. Project precedent, especially [UID:00032S] `BrowserControlPaneOld::~BrowserControlPaneOld()`, emits an empty destructor body for this exact source shape. The scalar deleting wrapper remains no-code. |
| BrowserDialog ownership | Rejected | BrowserDialog constructor uses the target only as a base-class unwind destructor. Target restores BrowserPane, not BrowserDialog, vtables. |
| WebBoardDialog or WebBoardDialogOld ownership | Rejected | Their constructors use the target only as inherited BrowserPane base cleanup during unwind. Their own source route remains [UID:0000P9] WebBoardDialog. |
| DialogPane ownership | Rejected | DialogPane is only the base cleanup callee at `0x0049d9f0`; the target writes BrowserPane vtable views first. |
| BrowserPane scalar deleting destructor fold-in | Rejected | [UID:00033C] at `0x00470690-0x004706e5` is the separate scalar deleting destructor with flag handling, optional `sub_4F4AC0`, guard/vector-delete branch, and vtable/adjustor refs. |
| Generated `boost::exception` type/source name | Rejected | `0x0049d9f0` is polluted IDA naming for DialogPane cleanup. It is not Boost ownership. |

## Heuristic And Source-Quality Reanalysis

This target matches the MSVC non-deleting destructor pattern for a class with base classes:

- It has no stack frame and no delete flags.
- It writes the current class vtable views.
- It tail-jumps to the immediate base destructor.
- It is reached from derived constructor unwind maps.
- The scalar deleting destructor exists separately and repeats the same base cleanup before handling delete flags.

The source-facing method is therefore `BrowserPane::~BrowserPane()`. The source body is empty because the visible binary work is compiler-generated destructor mechanics:

- BrowserPane vtable restoration is compiler lowering.
- The DialogPane cleanup call is automatic base destructor chaining.
- Derived-constructor EH funclets are compiler-generated from the constructor/destructor graph.
- The scalar deleting wrapper is generated from the virtual destructor declaration/definition and must remain out of handwritten C++.

## Ranked Ownership And Source-Placement Candidates

1. **Accepted: [UID:000019] BrowserPane, emitted through [UID:0000HV] Browser**
   - Best direct semantic owner and current route.
   - Matches existing BrowserPane child pages [UID:00040B] and [UID:000409] that route exact method bodies through the Browser file root.
   - C++: `BrowserPane::~BrowserPane() {}`.

2. **Plausible but weaker: [UID:000019] BrowserPane with class-page emitter [UID:000019]**
   - Semantically valid for a class method.
   - Weaker for this exact page because sibling exact method pages in this split currently use `EMITTER_UIDS:0000HV`; changing the route here would add inconsistency without new source-layout benefit.

3. **Rejected: [UID:000017] BrowserDialog**
   - The BrowserDialog constructor owns one EH caller, but not the target body.

4. **Rejected: [UID:0000P9] WebBoardDialog**
   - Active and old WebBoard constructors own two EH caller sites, but not the inherited BrowserPane base destructor.

5. **Rejected: [UID:0000IT]/DialogPane**
   - DialogPane is the base cleanup target only.

6. **Rejected: no-owner/no-code compiler artifact**
   - Correct for the scalar deleting destructor wrapper, not for this ordinary source destructor body.

## First-Draft C++ Readiness

Recommended formal block for the renamed [UID:000408] page:

```cpp
BrowserPane::~BrowserPane()
{
}
```

Do not write:

- vtable assignments;
- direct calls to `DialogPane` cleanup;
- EH unwind funclets;
- scalar deleting destructor flag tests;
- `operator delete` / `sub_4F4AC0`;
- generated `boost::exception` names.

The empty body is not a placeholder; it is the source representation of a destructor whose visible binary work is vtable/base-chain lowering.

## Score Recommendation

Target [UID:000408]:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 85 | 88 | Exact body, boundary, padding, xrefs, EH unwind route, scalar-wrapper separation, source body, rejected alternatives, and support edits are now documented. |
| Confidence | 88 | 91 | MCP session `80de0a67` proves the three refs are EH unwind-map actions and the scalar deleting destructor is separate. Confidence stays below final-audit levels only because the original source could have declared the destructor explicitly or implicitly; the emitted reconstruction should still use an empty out-of-line destructor to regenerate the observed body. |

Recommended support-score effects:

- [UID:000019] `BrowserPane`: raise to `88/90`. This resolves the cleanup/destructor classification cap; raw constructor entry/signature and key-event field naming still cap the class page below final-audit levels.
- [UID:0000Z5] `BrowserPaneAndDialog`: raise to `89/91`. The split index no longer has a cleanup-classification blocker, but it still records raw constructor and BrowserDialog constructor child limits.
- [UID:0000HV] `Browser`: keep `87/89` unless the supervisor wants coverage wording to reflect source-ready destructor C++. The broader Browser module still has many independent split/source-layout constraints.
- [UID:00033C] `BrowserPaneScalarDeletingDestructor`: optional raise to `86/89` after support wording is synchronized, because its companion ordinary destructor route is now settled.

## Exact Target Edit Recommendation

If accepted for implementation:

1. Lease and rename:
   - From: `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneCleanupWrapper.md`
   - To: `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md`
   - Preserve UID `000408`.

2. Metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:000019`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000HV`

3. Formal C++:

```cpp
BrowserPane::~BrowserPane()
{
}
```

4. Body changes:
   - Title: `0x0046a8a0-0x0046a8bf BrowserPane Non-Deleting Destructor`.
   - Status: ordinary source-level BrowserPane destructor body, not pending cleanup wrapper.
   - Covered range: preserve `0x0046a8a0-0x0046a8bf`; preserve padding `0x0046a8bf-0x0046a8c0`.
   - Evidence: add MCP session `80de0a67`, exact `lookup_funcs`, `analyze_function`, byte, xref, EH tail-label, FuncInfo/unwind-map, and scalar companion facts from this report.
   - Source-quality decision: source-ready empty destructor; compiler-generated vtable/base/EH/scalar-delete mechanics excluded from source.
   - Rejected alternatives: update to the table in this report.
   - Changes: add a dated B002 report-only research note with accepted implementation details pending supervisor callback.

## Exact Support Edit Recommendations

Update these non-coverage docs if the target recommendation is accepted:

- `by-class/BrowserPane.md`
  - Replace the [UID:000408] method row with `BrowserPaneNonDeletingDestructor` and state that it emits an empty `BrowserPane::~BrowserPane()` body.
  - Update live evidence for `sub_46A8A0` to classify refs as EH unwind funclets from `sub_46AA40`, `sub_46D050`, and `sub_46E640`.
  - Remove the cleanup-wrapper classification cap from score rationale; set `88/90`.

- `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md`
  - Update the split-child row to the renamed [UID:000408] page.
  - Replace the stale cleanup-classification wording with "ordinary BrowserPane non-deleting destructor; three refs are compiler EH unwind actions from derived constructors."
  - Update score rationale; set `89/91`.

- `by-file/Browser.md`
  - Update the B002 split paragraph and BrowserPane class row so [UID:000408] is no longer described as cleanup-blank.
  - State that `NavigateToUrl`, `OnCommand`, and `BrowserPane::~BrowserPane()` are source-ready child bodies; raw constructor, key event, timer-facet declaration, and BrowserDialog constructor remain separate limits.

- `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`
  - Replace "pending EH/ordinary-destructor ref classification" with "ordinary destructor body is settled at [UID:000408]."
  - Preserve blank C++ and no-code compiler wrapper policy.
  - Optionally raise to `86/89`.

- `by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md`
  - Add an EH/unwind note: the tail chunk at `0x005fac2b-0x005fac32` loads saved BrowserDialog/BrowserPane `this` and jumps to [UID:000408] during constructor unwind; data xref `0x0065976c` points to this action.
  - Do not change constructor C++ solely for this note.

- `by-memory/0x0046d050-0x0046d324.WebBoardDialog.md`
  - Add an EH/unwind note: the tail chunk at `0x005fad76-0x005fad7d` loads saved `this` and jumps to [UID:000408] during active WebBoardDialog constructor unwind; data xref `0x006593bc` points to this action.
  - Do not change existing constructor C++ solely for this note.

- `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md`
  - Add an EH/unwind note: the tail chunk at `0x005fae32-0x005fae39` loads saved `this` and jumps to [UID:000408] during old WebBoardDialog constructor unwind; data xref `0x006596ec` points to this action.
  - Do not change existing constructor C++ solely for this note.

- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
  - Optional support sync: identify [UID:000408] as the non-deleting destructor body reached by EH unwind maps, while vtable slot `0x006132ec` routes deleting destruction to [UID:00033C].

- `by-memory/-ignored.md`
  - Update the two padding rows adjacent to [UID:000408] to link `BrowserPaneNonDeletingDestructor` if the file is renamed.
  - Preserve padding facts: `0x0046a89b-0x0046a8a0` and `0x0046a8bf-0x0046a8c0`.

No `by-project-structure` or `by-meta` support edit is required by the current search: no current references to UID `000408`, `BrowserPaneCleanupWrapper`, or `0x0046a8a0` were found under those folders.

## Supervisor-Owned Coverage Text

Do not edit coverage reports in the implementation callback unless the supervisor explicitly owns that step. If coverage refresh is requested, use these exact replacement lines.

### `by-memory/-coverage-report.md`

Replace the existing [UID:000408] row with:

```md
    - [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md) 0x0046a8a0-0x0046a8bf | ordinary destructor body | BrowserPaneNonDeletingDestructor : reconstructable : 88% : very strong : B002 2026-06-23 source-quality pass resolves this as the BrowserPane ordinary non-deleting destructor body, not a pending cleanup helper: MCP session 80de0a67 confirms BrowserPane vtable restores at 0x006132ec/0x00613360/0x00613390, tail jump to DialogPane cleanup at 0x0049d9f0, exact padding byte at 0x0046a8bf, and exactly three compiler EH unwind funclet refs from BrowserDialog/WebBoardDialog/WebBoardDialogOld constructors at 0x005fac2e/0x005fad79/0x005fae35 via unwind-map action labels. Formal C++ emits empty BrowserPane::~BrowserPane(); vtable stores, base destructor chaining, EH funclets, and [UID:00033C] scalar deleting destructor flag/delete logic remain compiler-generated.
```

### `by-class/-coverage-report.md`

Replace the [UID:000019] row with:

```md
- [UID:000019][BrowserPane](by-class/BrowserPane.md) : reconstructable : 88% : very strong : B002 2026-06-23 source-quality pass keeps BrowserPane under [UID:0000HV][Browser](by-file/Browser.md), resolves it as a DialogPane-derived browser command/key/TimerHandler-facet base, preserves B012 raw constructor byte truth 0x0046a860-0x0046a89b with ret 8 and padding, and closes the cleanup-wrapper blocker by classifying [UID:000408] 0x0046a8a0-0x0046a8bf as the ordinary BrowserPane non-deleting destructor with compiler EH unwind refs from BrowserDialog/WebBoardDialog/WebBoardDialogOld constructors. OnCommand remains source-ready, OnKeyEvent field names and raw constructor signature still cap final quality, BrowserPanePlaySound wording remains rejected in favor of TimerHandler-facet CancelTimer, 0x0046ad80 stays BrowserDialog-owned, and shared DialogPane helpers remain inherited infrastructure.
```

### `by-file/-coverage-report.md`

Replace the [UID:0000HV] row with:

```md
- [UID:0000HV][Browser](by-file/Browser.md) : reconstructable : 87% : strong : Browser source root with exact BrowserPane/BrowserDialog split children from [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), including B012 BrowserPane refinements for raw constructor body 0x0046a860-0x0046a89b, TimerHandler-facet ScheduleTimer/CancelTimer pairing, stale BrowserPanePlaySound rejection, and BrowserDialog ownership of 0x0046ad80. B002 2026-06-23 resolves [UID:000408] as source-ready BrowserPane::~BrowserPane() with compiler EH unwind refs, so this file now emits source-ready NavigateToUrl, OnCommand, and BrowserPane destructor bodies while preserving blank-C++ gates for raw constructor, event-field, timer-facet declaration, and constructor-helper issues.
```

## Validator Plan For Accepted Implementation

After any accepted implementation edits, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` using absolute file paths. Minimum expected target/support set if all recommendations are accepted:

> Executable block R001 was removed from this report and preserved verbatim in [000408-BrowserPaneCleanupWrapper-source-quality-removed.md](000408-BrowserPaneCleanupWrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the target page is renamed, the first validator run should be on the renamed path so UID mapping and reverse links update. If the validator reports a rename/UID conflict, stop and report the exact output instead of manually editing `tools/validator.ini`.

## Implementation Tracking Checklist

- [x] Lease and rename [UID:000408] to `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md`; preserve UID `000408`.
  - Proof: leased the old target and support batch as B002, deleted `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneCleanupWrapper.md`, created `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md`, and validator `path_update` recorded UID `000408` moved from the old path to the new path.
- [x] Update [UID:000408] metadata to `88/91`, owner `000019`, reconstructable true, emitter `0000HV`.
  - Proof: target header now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000019`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HV`.
- [x] Replace [UID:000408] title/status/body with ordinary `BrowserPane::~BrowserPane()` non-deleting destructor classification and MCP session `80de0a67` evidence.
  - Proof: target title is `BrowserPane Non-Deleting Destructor`; status identifies an ordinary source-level `BrowserPane::~BrowserPane()` non-deleting destructor; evidence cites MCP session `80de0a67`.
- [x] Populate [UID:000408] formal C++ with empty `BrowserPane::~BrowserPane()` body.
  - Proof: target formal C++ block contains `BrowserPane::~BrowserPane() { }`.
- [x] Add positive evidence: exact bytes, padding, vtable stores, base DialogPane cleanup target, three xrefs, EH tail chunks, unwind-map data refs, and scalar deleting destructor separation.
  - Proof: target records `lookup_funcs`, `analyze_function`, `get_bytes`, `0x0046a8bf-0x0046a8c0` padding, BrowserPane vtable restores `0x006132ec/0x00613360/0x00613390`, polluted-IDA DialogPane cleanup at `0x0049d9f0`, xrefs `0x005fac2e/0x005fad79/0x005fae35`, EH action labels/data refs `0x005fac2b -> 0x0065976c`, `0x005fad76 -> 0x006593bc`, `0x005fae32 -> 0x006596ec`, and separate [UID:00033C] scalar wrapper facts.
- [x] Add negative evidence and rejected alternatives from this report.
  - Proof: target has rejected alternatives for standalone helper, compiler-only no-code artifact, BrowserDialog/WebBoard/DialogPane ownership, scalar wrapper fold-in, and polluted Boost naming.
- [x] Update `by-class/BrowserPane.md` method row, evidence, score rationale, and score to `88/90`.
  - Proof: class page header is `88/90`; method row links [UID:000408] as `BrowserPaneNonDeletingDestructor`; evidence/score rationale include EH unwind refs and scalar-wrapper separation.
- [x] Update `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md` split row, evidence, score rationale, and score to `89/91`.
  - Proof: split page header is `89/91`; row links [UID:000408] as `BrowserPaneNonDeletingDestructor`; evidence and score rationale include session `80de0a67`, EH action labels, and source-ready destructor C++.
- [x] Update `by-file/Browser.md` BrowserPane/source-root text to include source-ready destructor and remove cleanup-blank wording.
  - Proof: Browser class row and split paragraph now state `BrowserPane::~BrowserPane()` emits through [UID:000408] and that Browser emits `NavigateToUrl`, `OnCommand`, and the destructor while preserving other blank gates.
- [x] Update `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` to reference settled ordinary destructor and keep no-code scalar wrapper policy.
  - Proof: scalar page now scores `86/89`, references [UID:000408] as the settled ordinary destructor, and keeps the formal C++ blank with no-code scalar wrapper/adjustor policy.
- [x] Add EH unwind notes to `by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md`.
  - Proof: page records tail chunk `0x005fac2b-0x005fac32`, jump `0x005fac2e`, and unwind-map data ref `0x0065976c`.
- [x] Add EH unwind notes to `by-memory/0x0046d050-0x0046d324.WebBoardDialog.md`.
  - Proof: page records tail chunk `0x005fad76-0x005fad7d`, jump `0x005fad79`, and unwind-map data ref `0x006593bc`.
- [x] Add EH unwind notes to `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md`.
  - Proof: page records tail chunk `0x005fae32-0x005fae39`, jump `0x005fae35`, and unwind-map data ref `0x006596ec`.
- [x] Optionally update `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` with non-deleting vs scalar-deleting BrowserPane destructor route.
  - Proof: page now has a `BrowserPane Destructor Route` section: [UID:000408] is the ordinary destructor reached by EH unwind maps; [UID:00033C] remains primary-vtable scalar deleting dispatch from `0x006132ec`.
- [x] Update `by-memory/-ignored.md` adjacent padding links after rename.
  - Proof: ignored rows now link [UID:000408] as `BrowserPaneNonDeletingDestructor`, preserve `0x0046a89b-0x0046a8a0`, and preserve `0x0046a8bf-0x0046a8c0`.
- [x] Update extra stale-link support page `by-memory/0x0046a860-0x0046a898.BrowserPaneRawConstructor.md`.
  - Proof: successor link and vtable-parity evidence now point to [UID:000408] `BrowserPaneNonDeletingDestructor`.
- [x] Do not edit any `-coverage-report.md` file unless explicitly supervisor-owned; use the exact replacement text above.
  - Proof: no manual coverage implementation was applied. The first validator pass attempted a UID-link path update in `by-memory/-coverage-report.md`; that validator side effect was reverted back to the pre-callback stale coverage row so coverage remains supervisor-owned. The exact supervisor-owned replacement coverage text remains in this report above.
- [x] Run scoped validators for every changed by-* support doc and report command, exit code, and `ok` count.
  - Proof: see validator results below; every scoped validator exited `0` with `ok=1`.
- [x] Release all leases immediately after edit/validator batches.
  - Proof: B002 unleased the target/support batch after validators; `tools/leaser/Agents/current_leases.md` reported no active leases.

## Implementation Validator Results

All commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| File | Command | Exit | ok |
| --- | --- | ---: | ---: |
| `by-memory\0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md --apply --queue-timeout 240` | 0 | 1 |
| `by-class\BrowserPane.md` | `python .\tools\validator.py --mode file --file by-class\BrowserPane.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md --apply --queue-timeout 240` | 0 | 1 |
| `by-file\Browser.md` | `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x0046d050-0x0046d324.WebBoardDialog.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046d050-0x0046d324.WebBoardDialog.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | `python .\tools\validator.py --mode file --file by-memory\0x006131b4-0x006139df.BrowserVtablesAndStrings.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\-ignored.md` | `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240` | 0 | 1 |
| `by-memory\0x0046a860-0x0046a898.BrowserPaneRawConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0046a860-0x0046a898.BrowserPaneRawConstructor.md --apply --queue-timeout 240` | 0 | 1 |

Validator side effects observed and accepted as validator-owned: UID path update for `000408`, `validator.ini` registry rebuild, generated `Browser.cpp` refresh/noops on later runs, and projected stats updates. Known pre-existing validator warnings remained for missing registered `0003E6` / `00026U` paths; they did not fail the scoped validators.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 000408","source_path":"executed-b-agent-research/B002/000408-BrowserPaneCleanupWrapper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
