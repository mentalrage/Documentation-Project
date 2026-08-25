** TARGET-REPORT-UID:0001F7 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001F7 PowerDialogPane Singleton Helpers Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001F7] `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md` from a file-owned mixed helper pair to a direct `PowerDialogPane` class-owned destructor/getter cluster.
- Final disposition: source-authored `PowerDialogPane` destructor body plus static class-style singleton accessor, separated by local padding. The code is not a standalone global utility, not `PowerListPane`, not `DialogPane`, not imported/Boost code, and not constructor-EH one-store cleanup glue.
- Required implementation if accepted: set target metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AP`, keep `EMITTER_POSITION_OPTIONAL` blank, and replace the formal target `RECONSTRUCTION_CPP CODE` marker/block with the exact formal block supplied below.
- Confidence: very strong for boundaries, bytes, global/vtable refs, behavior, class/file route, and stale-label correction. Capped below final audit because no direct caller or original stripped source spelling proves whether the accessor was spelled `GetSingleton`, `GetPowerDialogPane`, or another equivalent static helper.

## Target

- Target UID: [UID:0001F7]
- Target path: `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`
- Assignment id: `B007-report-0001F7-power-dialog-pane-singleton-helpers-source-quality-20260626`
- Report path: `tools/leaser/Agents/Agent-B007/research/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md`
- Current target metadata read in this pass: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000MO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MO`, blank formal C++.
- Current queue row: `auto-generated/-ag-research-tracker.md` still lists [UID:0001F7] as `78/86`, average `82.0`, reconstructable, with no C++; this generated row is stale relative to the current target page `85/88`. The report uses current by-* docs and current MCP evidence as authority.
- Current by-memory coverage row is also stale in places: it still reports [UID:0001F7] at `78%` and [UID:0001PZ] item summary text still says `0xffffffff` even though the current storage docs and current MCP bytes show zero-initialized storage.

## Current Target State

The target already records the exact two modeled functions and local padding:

| Span | Current interpretation | Current issue |
| --- | --- | --- |
| `0x0054a480-0x0054a4a9` | cleanup helper clearing `g_pPowerDialog` and tailing to `DialogPane` cleanup | Source shape is better stated as `PowerDialogPane::~PowerDialogPane()` complete/non-deleting destructor body. |
| `0x0054a4a9-0x0054a4b0` | seven `0xcc` bytes | Correct padding; keep ignored as alignment inside the target range. |
| `0x0054a4b0-0x0054a4b6` | getter returning `g_pPowerDialog` | Source shape is a static class-style singleton accessor, best current spelling `PowerDialogPane::GetSingleton()`. |

Stale or weak current text:

- It keeps direct owner/emitter at file [UID:0000MO] because the range was described as a "mixed cleanup/getter pair." Current evidence shows both routines are class-level `PowerDialogPane` behavior, and [UID:0000AP] clears the parent gate at `86/86`.
- It leaves C++ blank because original helper names and retained-helper reason are not source-quality. Under the current Rule 26/code-entry standard, unresolved original spelling is a score cap, not a reason to leave raw source behavior blank when a realistic source-facing name is defensible.
- It still uses cleanup-helper phrasing that can sound like constructor-EH singleton clear glue. The body is `this`-based, writes three `PowerDialogPane` vtable views, clears the singleton, and jumps to `DialogPane` cleanup. It is ordinary derived destructor source lowering, not a no-`this` one-store EH helper.

## Supervisor Active Recheck

The supervisor assignment requested report-only research for [UID:0001F7] and explicitly required MCP evidence. This report did not edit by-* docs, generated files, project-level files, validator/tool state, IDA DB, or coverage reports. No leases were taken because report-only work in the B007 research folder does not require leases.

MCP availability was checked and live:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Safe flow used: `initialize` -> `tools/list` -> `tools/call`.
- Active session: `80de0a67`.
- `idb_list`: one active worker session, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, pid/worker_pid `26892`, not analyzing.
- `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Evidence Checked

IDA MCP checks in this pass:

- `tools/list` to verify current schemas.
- `server_health`, `idb_list`.
- `lookup_funcs` for `0x0054a472`, `0x0054a480`, `0x0054a4a9`, `0x0054a4b0`, `0x0054a4b6`, `0x0054a4c0`, `0x0054b520`, `0x0049d9f0`, `0x00513b50`, and `0x00513b93`.
- `get_bytes` for `0x0054a472` size `78` and `0x0069ba34` size `4`.
- `xrefs_to` for helper starts, `g_pPowerDialog`, `PowerDialogPane` vtable bases, `DialogPane` cleanup, and scalar deleting destructor.
- `analyze_function` with assembly for `0x0054a480`, `0x0054a4b0`, `0x0049d9f0`, `0x0054b520`, and `0x00513b50`.
- `decompile`/`disasm` for `0x0049d9f0` to verify the stale `boost::exception` label is actually `DialogPane` cleanup.
- `find_bytes` for global/vtable immediate occurrences and for absolute pointers to helper starts/padding endpoints.
- `xref_query` for direct xrefs to helper starts and padding endpoints.

Docs checked:

- Target: `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`
- Aggregate/source module: `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`, `by-file/PowerDialogPane.md`
- Class support: `by-class/PowerDialogPane.md`, `by-class/PowerListPane.md`
- Constructor/global support: `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`, `by-global/g_pPowerDialog.md`, `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md`
- Vtable/thunk support: `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md`, `by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md`
- Base cleanup support: `by-class/DialogPane.md`, `by-file/DialogPane.md`, `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- Precedents: `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md`, `by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md`, one-store EH cleanup pages such as `by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonClear.md` and `by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md`
- Generated/autogen only as leads: `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/by-memory-tool-report.md`.

Numeric conversions verified with `tools/int_convert.py` JSON batch:

- `0x36` = 54 bytes (Verified with `tools/int_convert.py`).
- `0x29` = 41 bytes (Verified with `tools/int_convert.py`).
- `0x6` = 6 bytes (Verified with `tools/int_convert.py`).
- `0xe` = 14 bytes (Verified with `tools/int_convert.py`).
- `0x7` = 7 bytes (Verified with `tools/int_convert.py`).
- `0xa` = 10 bytes (Verified with `tools/int_convert.py`).
- `0xa0` = 160 (Verified with `tools/int_convert.py`).
- `0xa4` = 164 (Verified with `tools/int_convert.py`).
- `0xdb` = 219 bytes (Verified with `tools/int_convert.py`).
- `0x5f` = 95 bytes (Verified with `tools/int_convert.py`).
- `0x2e4` = 740 bytes (Verified with `tools/int_convert.py`).

## IDA MCP Facts

### Function And Boundary Facts

`lookup_funcs` in session `80de0a67` reports:

| Query | Result |
| --- | --- |
| `0x0054a472` | Not a function; constructor-to-helper padding start. |
| `0x0054a480` | `sub_54A480`, size `0x29` / 41 bytes (Verified with `tools/int_convert.py`). |
| `0x0054a4a9` | Not a function; inter-helper padding start. |
| `0x0054a4b0` | `sub_54A4B0`, size `0x6` / 6 bytes (Verified with `tools/int_convert.py`). |
| `0x0054a4b6` | Not a function; getter-to-action padding start. |
| `0x0054a4c0` | `sub_54A4C0`, size `0x1dd`; next `PowerDialogPane` action body. |
| `0x0054b520` | `sub_54B520`, size `0x5f` / 95 bytes (Verified with `tools/int_convert.py`); scalar deleting destructor. |
| `0x0049d9f0` | IDA name `??1exception@boost@@MAE@XZ_0`, size `0xdb` / 219 bytes (Verified with `tools/int_convert.py`), but behavior is `DialogPane` cleanup. |
| `0x00513b50` / `0x00513b93` | Wrapper currently mislabeled `___std_parallel_algorithms_hw_threads@0_2`, size `0x5b`; allocates `0x2e4` / 740 bytes (Verified with `tools/int_convert.py`) and calls the constructor, but has no callers. |

`get_bytes 0x0054a472 size 78` returns the complete local byte window:

```text
0x0054a472: cc cc cc cc cc cc cc cc cc cc cc cc cc cc
0x0054a480: c7 01 58 21 62 00
0x0054a486: c7 81 a0 00 00 00 b8 21 62 00
0x0054a490: c7 81 a4 00 00 00 e8 21 62 00
0x0054a49a: c7 05 34 ba 69 00 00 00 00 00
0x0054a4a4: e9 47 35 f5 ff
0x0054a4a9: cc cc cc cc cc cc cc
0x0054a4b0: a1 34 ba 69 00 c3
0x0054a4b6: cc cc cc cc cc cc cc cc cc cc
```

Boundary decision:

- `0x0054a472-0x0054a480`: 14 bytes of `0xcc` padding after [UID:0001F5] constructor (Verified with `tools/int_convert.py`).
- `0x0054a480-0x0054a4a9`: complete destructor body, `0x29` / 41 bytes (Verified with `tools/int_convert.py`).
- `0x0054a4a9-0x0054a4b0`: seven bytes of `0xcc` local alignment (Verified with `tools/int_convert.py`).
- `0x0054a4b0-0x0054a4b6`: complete getter, `0x6` / 6 bytes (Verified with `tools/int_convert.py`).
- `0x0054a4b6-0x0054a4c0`: ten bytes of `0xcc` padding before `OnDialogAction` (Verified with `tools/int_convert.py`).
- Full target range `0x0054a480-0x0054a4b6` is `0x36` / 54 bytes (Verified with `tools/int_convert.py`).

### Helper Behavior

`analyze_function 0x0054a480 include_asm=true`:

```asm
54a480  mov dword ptr [ecx], offset ??_7PowerDialogPane@@6B@
54a486  mov dword ptr [ecx+0A0h], offset ??_7PowerDialogPane@@6B@_0
54a490  mov dword ptr [ecx+0A4h], offset ??_7PowerDialogPane@@6B@_1
54a49a  mov dword ptr unk_69BA34, 0
54a4a4  jmp ??1exception@boost@@MAE@XZ_0
```

Decompiler output writes the three `PowerDialogPane` vtable views, clears `unk_69BA34`, and calls/tail-jumps through the stale `boost::exception` label. Source interpretation: complete/non-deleting `PowerDialogPane::~PowerDialogPane()` body with a source-visible global clear and compiler-inserted vtable/base-destructor lowering.

`analyze_function 0x0054a4b0 include_asm=true`:

```asm
54a4b0  mov eax, dword ptr unk_69BA34
54a4b5  retn
```

Decompiler output is `return unk_69BA34;`. Source interpretation: static class-style singleton accessor returning `g_pPowerDialog`.

`analyze_function 0x0049d9f0` / `decompile 0x0049d9f0` proves the imported-looking `??1exception@boost@@MAE@XZ_0` name is stale:

- Writes `DialogPane` primary/secondary/tertiary vtables at `this+0`, `this+0xa0`, and `this+0xa4`.
- Decrements `unk_69B380` / active dialog count.
- Walks and releases the dialog control manager at `this+0x1fc`.
- Tears down tile/background state through `sub_458500((int)this + 572)` and final pane cleanup `sub_544580(this)`.

So the `0x0054a480` tail is a base `DialogPane` destructor cleanup, not Boost exception runtime code.

`analyze_function 0x0054b520 include_asm=true` shows the scalar deleting destructor duplicates the same source destructor effects before delete-flag handling:

- Writes the same three `PowerDialogPane` vtable views at `0x0054b526`, `0x0054b52c`, `0x0054b536`.
- Clears `unk_69BA34` at `0x0054b540`.
- Calls the same base cleanup at `0x0054b54a`.
- Conditionally calls delete helper `sub_4F4AC0` or guard path according to the scalar deleting destructor flag byte.

Source conclusion: do not hand-author scalar deleting destructor flag logic. Source should author `PowerDialogPane::~PowerDialogPane() { g_pPowerDialog = 0; }`; compiler lowering regenerates vtable restore/base cleanup/scalar deleting destructor support.

### Xrefs And Negative Route Evidence

`xrefs_to` and `xref_query` results:

- `0x0054a480`: zero inbound xrefs.
- `0x0054a4b0`: zero inbound xrefs.
- `0x0054a4a9`: zero inbound xrefs to padding start.
- `0x0054a4b6`: zero inbound xrefs to padding/end.
- `0x0054b520`: three inbound refs: adjustor thunk code refs from `0x0054b4f6` and `0x0054b501`, plus primary vtable data at `0x00622158`.

`find_bytes` for absolute helper/padding pointers found no hits:

| Pattern | Meaning | Hits |
| --- | --- | ---: |
| `80 A4 54 00` | absolute VA `0x0054a480` | 0 |
| `B0 A4 54 00` | absolute VA `0x0054a4b0` | 0 |
| `A4 A4 54 00` | absolute VA `0x0054a4a4` tail-jump instruction address | 0 |
| `A9 A4 54 00` | absolute VA `0x0054a4a9` padding start | 0 |
| `B6 A4 54 00` | absolute VA `0x0054a4b6` getter end/padding start | 0 |

This confirms the no-direct-route caveat. It does not prove non-source code; exact `DescPane::GetSingleton()` precedent shows a no-direct-caller singleton accessor can still be source-authored and code-emitting when body, owner, and emitter route are clear.

### Global And Vtable Evidence

`xrefs_to 0x0069ba34`:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x0054a44c` | `0x00549c20` constructor | Constructor publishes `this` to `g_pPowerDialog`. |
| `0x0054a49a` | `0x0054a480` destructor body | Complete destructor clears `g_pPowerDialog`. |
| `0x0054a4b0` | `0x0054a4b0` getter | Accessor returns `g_pPowerDialog`. |
| `0x0054b010` | `0x0054b000` `PowerListPane::OnMouseEvent` | Embedded list reads owner dialog to access sibling list controls. |
| `0x0054b540` | `0x0054b520` scalar deleting destructor | Scalar deleting destructor clears `g_pPowerDialog`. |

`get_bytes 0x0069ba34 size 4` in this pass returns `00 00 00 00`. This matches the current storage table in `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md` and supersedes older `0xffffffff` summary wording.

`xrefs_to` vtable bases:

| Vtable base | Xrefs |
| --- | --- |
| `0x00622158` primary | constructor store `0x00549c7a`, target destructor store `0x0054a480`, scalar deleting destructor store `0x0054b526` |
| `0x006221b8` secondary | constructor store `0x00549c80`, target destructor store `0x0054a486`, scalar deleting destructor store `0x0054b52c` |
| `0x006221e8` tertiary | constructor store `0x00549c8a`, target destructor store `0x0054a490`, scalar deleting destructor store `0x0054b536` |

`find_bytes` immediate scan independently corroborates the confined global/vtable usage:

- `34 BA 69 00`: five operand hits at `0x54a44e`, `0x54a49c`, `0x54a4b1`, `0x54b011`, `0x54b542`.
- `58 21 62 00`: three operand hits at `0x549c7c`, `0x54a482`, `0x54b528`.
- `B8 21 62 00`: three operand hits at `0x549c86`, `0x54a48c`, `0x54b532`.
- `E8 21 62 00`: three operand hits at `0x549c90`, `0x54a496`, `0x54b53c`.

## Positive Evidence Summary

- Current MCP proves two real modeled functions at exactly `0x0054a480-0x0054a4a9` and `0x0054a4b0-0x0054a4b6`, with padding before, between, and after.
- The first function has an implicit `this` receiver, writes three `PowerDialogPane` vtable views, clears the `PowerDialogPane` singleton, and transfers to `DialogPane` destructor cleanup. That is the source-shape of `PowerDialogPane::~PowerDialogPane()`, not an arbitrary helper.
- The second function is the exact six-byte singleton getter. The `DescPane::GetSingleton()` precedent shows that a no-direct-caller six-byte singleton accessor can carry formal first-draft C++ when owner/emitter and global name are resolved.
- `g_pPowerDialog` xrefs are confined to the constructor/destructor/getter/scalar-destructor/list-control island and support `PowerDialogPane`, not `PowerListPane`, as the owning class.
- Vtable xrefs tie this target to `PowerDialogPane` constructor and scalar deleting destructor stores, supporting class ownership.
- `PowerDialogPane` class [UID:0000AP] and file [UID:0000MO] clear the current parent/emitter gates. Direct class ownership is now safe.
- Current `DialogPane` support has resolved the `0x0049d9f0` stale `boost::exception` label as common `DialogPane` cleanup and has a declaration-level class route, removing the older mail-cluster style blocker that base-destructor spelling was too weak.

## Negative Evidence Summary

- No direct code/data xrefs point to `0x0054a480` or `0x0054a4b0`; no absolute pointer bytes for either helper start were found. This caps final confidence but does not block first-draft C++ because the source behavior and class route are exact.
- No xrefs point into the local padding starts `0x0054a4a9` or `0x0054a4b6`; do not split padding into source or merge it with adjacent methods.
- `PowerListPane` ownership is rejected: the target writes `PowerDialogPane` vtables and `g_pPowerDialog`; `PowerListPane` only reads the singleton in `OnMouseEvent` to coordinate sibling list controls.
- `DialogPane` ownership is rejected: `DialogPane` is only the base destructor dependency reached after the derived destructor body. The derived vtable stores and singleton clear belong to `PowerDialogPane`.
- Global-owner assignment to [UID:0000S0] is rejected for code: the global page owns the storage declaration, but the code body is class destructor/accessor behavior.
- File [UID:0000MO] as direct owner is weaker than the class page now that [UID:0000AP] clears the gate. The file remains the source root through `NexusTK/ui/dialogs/PowerDialogPane.cpp`.
- No-owner/non-emitting is rejected: the target is not padding, not CRT/library code, not a generated thunk-only range, and not an unreachable raw blob with unknown owner.
- Constructor-EH one-store cleanup classification is rejected: unlike `BackStoryDialogPaneSingletonClear` or `StaffsDialogPaneSingletonClear`, this body has a `this` receiver, vtable restores, and a base destructor tail, and no EH xref to the helper start.
- Scalar deleting destructor merge is rejected: `0x0054b520-0x0054b57f` is separate compiler ABI deletion support with flag handling and vtable refs. Source should author the ordinary destructor once and let the compiler regenerate scalar deleting wrapper behavior.

## Heuristic / Inference Reanalysis And Validation

| Issue | Decision | Evidence | Remaining cap |
| --- | --- | --- | --- |
| `sub_54A480` name | Use source-facing `PowerDialogPane::~PowerDialogPane()` in formal code; keep `PowerDialogPane_ClearSingletonHelper` only as a historical/search alias. | `this` receiver, three class vtable writes, singleton clear, base `DialogPane` cleanup tail, scalar deleting destructor duplicate. | No original symbol proves destructor spelling, but C++ destructor syntax is forced by source shape. |
| `sub_54A4B0` name | Use `PowerDialogPane::GetSingleton()` as inferred static class-style accessor. | Six-byte return of `g_pPowerDialog`, class-specific singleton island, `DescPane::GetSingleton()` precedent. | Exact original spelling could have been `GetPowerDialogPane()` or a file-local helper. |
| `unk_69BA34` / `dword_69BA34` | Use `g_pPowerDialog`. | by-global and memory pages resolve the singleton; current xrefs and immediate scan are confined to the power dialog/list island. | Final linkage spelling (`static`, file-scope versus extern) remains a global-declaration support cap, not target code blocker. |
| `??1exception@boost@@MAE@XZ_0` | Treat as stale IDA/import naming; source dependency is `DialogPane::~DialogPane()`. | Decompile/disasm writes `DialogPane` vtables, decrements active dialog count, releases control manager, tears down tile/background/pane state. | Exact base method body remains owned by DialogPane docs. |
| File owner versus class owner | Change direct owner/emitter from [UID:0000MO] file to [UID:0000AP] class. | Both functions are class-specific; [UID:0000AP] now clears `86/86`; similar `MailDeleteReplyAlert` and `DescPane` pages use class owner for destructor/getter or getter. | File [UID:0000MO] remains source root. |
| First-draft C++ | Insert exact formal destructor/getter block. | Active gate clears, behavior is source-level, names can be inferred without raw labels, and target range exactly maps to these source functions plus padding. | Confidence capped because no direct caller and exact accessor spelling is inferred. |

## Ranked Ownership Analysis

### 1. [UID:0000AP] PowerDialogPane class - Accepted

Evidence for:

- Target writes the `PowerDialogPane` primary, secondary, and tertiary vtable views.
- Target clears and returns `g_pPowerDialog`, whose constructor/destructor/list xrefs are confined to this dialog/list feature island.
- `PowerDialogPane` class page now clears the direct-owner gate at `86/86`.
- Similar class singleton accessors/destructor clusters route through class pages, not directly through file pages, once the class clears the gate.

Evidence against:

- No direct caller to either helper start.
- Exact getter spelling remains inferred.

Decision: accepted as direct canonical owner and emitter. The no-caller fact is a confidence cap, not a class-owner blocker.

### 2. [UID:0000MO] PowerDialogPane file - Valid source root, weaker direct owner

Evidence for:

- The final source file remains `NexusTK/ui/dialogs/PowerDialogPane.cpp`.
- The file groups `PowerDialogPane`, feature-private `PowerListPane`, singleton storage, and `.rdata` children.
- Current target metadata points here.

Evidence against:

- The target is not mixed across dialog/list classes. Both functions are class-specific `PowerDialogPane` behavior.
- The class page now clears the gate, so bypassing to the file is no longer necessary.

Decision: keep as file source root through the class route, but replace direct owner/emitter with [UID:0000AP].

### 3. [UID:0000S0] g_pPowerDialog - Rejected for code owner

Evidence for:

- Both functions touch the singleton global.

Evidence against:

- The cleanup function is a `this`-based class destructor body with vtable writes and base cleanup.
- The global page owns storage declaration/name, not class method bodies.

Decision: support page only.

### 4. [UID:0000AQ] PowerListPane - Rejected

Evidence for:

- `PowerListPane::OnMouseEvent` reads `g_pPowerDialog`.

Evidence against:

- Target writes `PowerDialogPane` vtables, not `PowerListPane` vtables.
- The singleton stores the containing dialog pointer; the list read is a consumer used for sibling selection coordination.

Decision: no target ownership or emitter role.

### 5. [UID:00003T] DialogPane / [UID:0000IT] DialogPane file - Rejected

Evidence for:

- `0x0054a480` tails into `0x0049d9f0` base cleanup.

Evidence against:

- Base cleanup is called after derived `PowerDialogPane` destructor work; the derived vtable writes and singleton clear are not common `DialogPane` behavior.

Decision: base dependency only.

### 6. Compiler/EH cleanup-only, padding, ignored, or no-owner - Rejected

Evidence for:

- No direct callers and no pointer refs.

Evidence against:

- The body is a normal derived destructor lowering, not a no-`this` one-store EH funclet; the getter is exact source-shaped singleton accessor; neither span is padding or thunk-only.

Decision: keep reconstructable and emitting.

## Range / Split / Padding / Reclassification Analysis

No by-memory split is recommended. Keep the target range `0x0054a480-0x0054a4b6` as one destructor/getter cluster because:

- Both functions are adjacent class support functions over the same singleton and class.
- The seven-byte middle padding is local alignment and already nested under the target.
- The predecessor padding `0x0054a472-0x0054a480` belongs outside this target after the constructor.
- The successor padding `0x0054a4b6-0x0054a4c0` belongs outside this target before `OnDialogAction`.
- Creating a separate six-byte getter page is not required because the cluster already has an exact target UID and can emit both source-level functions cleanly.

Do not merge with:

- [UID:0001F5] constructor: separated by 14 bytes of padding and different function/source role.
- `OnDialogAction`: separated by ten bytes of padding.
- `0x0054b520` scalar deleting destructor: separate ABI wrapper with delete-flag behavior.
- [UID:0001F8] adjustor thunks: compiler-generated, non-reconstructable ignored range.

## First-Draft C++ Recommendation

Eligible for formal C++: yes.

Reasons:

- Target is reconstructable and should emit through class [UID:0000AP] to file [UID:0000MO].
- Current score recommendation clears the combined code-entry gate.
- Both source functions can be represented with realistic mid-2000s C++ without raw IDA labels, explicit vtable stores, explicit base destructor calls, or scalar deleting destructor flags.
- The compiler should regenerate vtable restores, `DialogPane` base destructor call, scalar deleting destructor, and local padding from the destructor declaration/body and class layout.

Exact formal target block content to insert or replace in `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PowerDialogPane::~PowerDialogPane()
{
    g_pPowerDialog = 0;
}

PowerDialogPane *PowerDialogPane::GetSingleton()
{
    return g_pPowerDialog;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not add explicit calls to `DialogPane::~DialogPane()`, explicit vtable assignments, delete-flag branches, or manual `0xcc` padding. Those are compiler output, not handwritten source.

## Recommended Target Doc Changes

Update `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`:

- Set `COMPLETION:88`, `CONFIDENCE:91`.
- Change `CANONICAL_OWNER` from `0000MO` to `0000AP`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS` from `0000MO` to `0000AP`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Replace the entire formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal block above.
- Replace stale file-owned/mixed-helper rationale with class-owned destructor/getter rationale.
- Record B007 current MCP evidence: session `80de0a67`, health status ok, active IDB path, function sizes, byte window, xrefs, no-direct-route checks, and `find_bytes` negative pointer evidence.
- Add exact range/padding table with all int-convert-verified sizes.
- Rename source-facing roles:
  - `sub_54A480` / `PowerDialogPane_ClearSingletonHelper` historical alias -> `PowerDialogPane::~PowerDialogPane()` source body.
  - `sub_54A4B0` / `PowerDialogPane_GetSingleton` historical alias -> `PowerDialogPane::GetSingleton()` inferred static class accessor.
  - `unk_69BA34` / `dword_69BA34` -> `g_pPowerDialog`.
  - `??1exception@boost@@MAE@XZ_0` -> stale IDA label for `DialogPane` cleanup.
- Preserve the no-direct-caller caveat as a confidence cap, not a C++ blocker.
- Add rejected alternatives: file direct owner, `PowerListPane`, `g_pPowerDialog` global owner, `DialogPane`, no-owner/non-emitting, constructor-EH one-store cleanup, scalar deleting destructor merge, and padding/split candidates.
- Add score rationale for `88/91`.
- Add B007/session `80de0a67` change note.

Validator after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Recommended Support Doc Changes

### `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`

Update the [UID:0001F7] row/source-module partition:

- Change [UID:0001F7] status from file-owned cleanup/getter helpers with blank C++ to class-owned destructor/getter cluster, `88/91`, formal child C++ through [UID:0000AP].
- Preserve the aggregate as file-owned and blank-C++ because it spans `PowerDialogPane`, private `PowerListPane`, padding, thunks, and multiple exact children.
- Carry current B007 facts: `0x0054a480` is `PowerDialogPane::~PowerDialogPane()` complete destructor body; `0x0054a4b0` is `PowerDialogPane::GetSingleton()`; no direct xrefs or absolute pointers to starts; scalar deleting destructor remains separate compiler ABI support at `0x0054b520`.

Validator:

> Executable block R002 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### `by-class/PowerDialogPane.md`

Update the method notes:

- Replace the [UID:0001F7] row text with class-owned `~PowerDialogPane()` complete destructor body plus static `GetSingleton()` accessor.
- State formal first-draft C++ now lives in the exact [UID:0001F7] child.
- Preserve broad class C++ blank because the class declaration/constructor/action/list source still has packet-row/config/private-list final-name caps; do not paste the [UID:0001F7] function bodies into the broad class page.
- Carry `g_pPowerDialog` lifecycle: constructor publish, destructor/getter/scalar destructor/list read.
- Replace stale "no direct callers/xrefs blocks C++" wording with "no direct callers/xrefs caps final-audit confidence."

Validator:

> Executable block R003 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### `by-file/PowerDialogPane.md`

Update the proposed contents and evidence notes:

- State [UID:0001F7] emits through the class [UID:0000AP] into `NexusTK/ui/dialogs/PowerDialogPane.cpp`, while this broad file root stays blank.
- Preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
- Replace stale direct-file-owner rationale for [UID:0001F7] with direct class-owner/source-root route.
- Mention current B007 MCP confirms no direct helper caller, no absolute helper-start pointer, and exact destructor/getter body.
- Keep `PowerListPane` in the same file only as a feature-private list class; do not move [UID:0001F7] to `PowerListPane`.

Validator:

> Executable block R004 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`

Update only support wording:

- Remove or supersede obsolete "blank final C++ under the 95/95 code gate" wording in the item summary/status.
- State constructor C++ remains blank for target-specific reasons: packet-reader locals, row-record names, config-field names, control construction details, and reviewed unreferenced wrapper shape, not because of an obsolete global code gate.
- Add one support note that [UID:0001F7] now owns formal destructor/getter C++ and [UID:0001F5] still only publishes `g_pPowerDialog` at `0x0054a44c`.

Validator:

> Executable block R005 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### `by-global/g_pPowerDialog.md`

Update support wording:

- State [UID:0001F7] now recommends formal first-draft C++ using `g_pPowerDialog` in `PowerDialogPane::~PowerDialogPane()` and `PowerDialogPane::GetSingleton()`.
- Keep final global declaration C++ blank unless the supervisor specifically wants the global page to emit a declaration; the target C++ can reference the existing source-facing name.
- Preserve current zeroed-byte correction and reject `g_activePowerListPane`.

Validator:

> Executable block R006 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md`

Update support wording:

- Fix the stale `Item Summary` phrase `initialized to 0xffffffff`; current storage table and current B007 MCP bytes show `00 00 00 00` / initial `0`.
- Keep historical notes that older reads saw/suggested `0xffffffff` only as superseded evidence.
- Add B007 current confirmation: `get_bytes 0x0069ba34 size 4` returned zeros; `xrefs_to` and `find_bytes` reconfirm exactly five singleton-address references.
- State [UID:0001F7] should now emit the class destructor/getter body using this global, while the global page itself remains blank unless global declaration policy is separately accepted.

Validator:

> Executable block R007 was removed from this report and preserved verbatim in [0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md](0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## No-Edit Proof / Support Pages Already Sufficient

Do not edit these pages in the implementation callback unless the supervisor expands scope or a direct contradiction is found during implementation:

- `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md`: already records the exact three `PowerDialogPane` vtable bases, constructor/helper/destructor store xrefs, and vtable-slot relationships. Current B007 xrefs match the page.
- `by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md`: already classifies the four `0xb` adjustor thunks as compiler-generated, non-reconstructable, with `this-0xa0`/`this-0xa4` jumps to scalar deleting destructors. No target change needed.
- `by-class/PowerListPane.md`: already rejects `g_activePowerListPane`, states `g_pPowerDialog` is the containing dialog pointer, and keeps `PowerListPane` as feature-private under `PowerDialogPane.cpp`. The target is not list-owned.
- `by-class/DialogPane.md`, `by-file/DialogPane.md`, `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`: already document `0x0049d9f0` as common `DialogPane` cleanup and identify the stale local `boost::exception` label as polluted. No new DialogPane ownership or source-shape repair is needed for this target.
- `by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md` and the aggregate scalar destructor row already explain scalar deleting destructor support enough for this target. No exact `0x0054b520-0x0054b57f` child page is required for this implementation because current MCP uses the scalar deleting destructor only as corroborating compiler-ABI support for the ordinary source destructor, not as a separate emitted source owner.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `88` | Current pass resolves direct class owner, source-facing destructor/getter names, formal C++ disposition, exact current MCP evidence, pointer-negative evidence, stale support assumptions, and support-edit list. |
| `CONFIDENCE` | `88` | `91` | Behavior, boundaries, vtable/global refs, and source route are direct MCP facts; confidence is capped by no direct callers and inferred exact accessor spelling. |
| `CANONICAL_OWNER` | `0000MO` | `0000AP` | Direct semantic owner is the class; file remains source root. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | NexusTK project source behavior. |
| `EMITTER_UIDS` | `0000MO` | `0000AP` | Emit through class route to `PowerDialogPane.cpp`. |
| C++ | blank | formal destructor/getter block | Active gate clears and source behavior is exact enough. |

Reason not higher:

- No direct caller, vtable slot, or absolute pointer route to `0x0054a480` or `0x0054a4b0` is known.
- Exact original spelling for the static accessor is inferred.
- The scalar deleting destructor remains deliberately documented as compiler-ABI corroborating support rather than target source output; existing support is sufficient for this target, but this compiler wrapper detail still caps final audit.
- Final global declaration/linkage spelling for `g_pPowerDialog` is still a support-file cap.

## Open Questions With Attempted Resolution

- Is `0x0054a480` source-authored or compiler-only? Best current resolution: source-authored destructor semantics. Evidence: `this` receiver, vtable stores, singleton clear, base cleanup tail. Compiler emits vtable/base destructor mechanics, but source body is `PowerDialogPane::~PowerDialogPane() { g_pPowerDialog = 0; }`.
- Is `0x0054a4b0` reachable? Current route search remains negative: no xrefs and no absolute pointer hits. Resolution: treat as retained source-level static accessor with no current caller, like `DescPane::GetSingleton`; no-route caps confidence but does not block formal C++.
- Is the getter a class static or free helper? Best current resolution: class static `PowerDialogPane::GetSingleton()` because the owner/emitter is the class, the global is class-specific, and `DescPane::GetSingleton()` is the closest project precedent. Free `GetPowerDialogPane()` is a plausible but weaker alternate; document as rejected/weaker.
- Should the page stay file-owned because it has two functions? No. Both are `PowerDialogPane` class functions. The file remains source root but no longer needs to be the direct owner.
- Should target be split? No. The two functions are adjacent class support functions over the same singleton, and the local padding is exact. Splitting would add administrative overhead without improving source reconstruction.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report edit is requested for B007. Do not edit `by-memory/-coverage-report.md` or any `-coverage-report.md` file. The implementation callback should update source by-* metadata and run scoped validators only. Validator-owned generated reports should refresh from source metadata during the normal supervisor/validator lifecycle.

If a supervisor later wants a manual legacy coverage row, derive it from the updated target `Item Summary` after acceptance rather than from this report directly.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after by-* edits.

| Path | Command | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md --apply --queue-timeout 240` | `000000002812` | `2026-06-26T15:25:38-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002812`, `generated_refresh_timestamp: 2026-06-26T15:25:38-04:00` |
| `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md --apply --queue-timeout 240` | `000000002813` | `2026-06-26T15:25:46-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002813`, `generated_refresh_timestamp: 2026-06-26T15:25:46-04:00` |
| `by-class/PowerDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/PowerDialogPane.md --apply --queue-timeout 240` | `000000002815` | `2026-06-26T15:26:30-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002815`, `generated_refresh_timestamp: 2026-06-26T15:26:30-04:00` |
| `by-file/PowerDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/PowerDialogPane.md --apply --queue-timeout 240` | `000000002817` | `2026-06-26T15:27:07-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002817`, `generated_refresh_timestamp: 2026-06-26T15:27:07-04:00` |
| `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md --apply --queue-timeout 240` | `000000002818` | `2026-06-26T15:27:15-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002818`, `generated_refresh_timestamp: 2026-06-26T15:27:15-04:00` |
| `by-global/g_pPowerDialog.md` | `python .\tools\validator.py --mode file --file by-global/g_pPowerDialog.md --apply --queue-timeout 240` | `000000002819` | `2026-06-26T15:27:24-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002819`, `generated_refresh_timestamp: 2026-06-26T15:27:24-04:00` |
| `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md --apply --queue-timeout 240` | `000000002820` | `2026-06-26T15:27:33-04:00` | `0` | `1` | `generated_refresh: deferred`, `generated_refresh_command_id: 000000002820`, `generated_refresh_timestamp: 2026-06-26T15:27:33-04:00` |

Warnings repaired before final validator rows:

- Initial target validator `000000002810` reported missing stale cross-reference target `[UID:000266]`; the target cross-reference was changed to the existing `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md` path.
- Follow-up target validator `000000002811` reported missing registry UID `0003CF`; the target support link was kept as a plain path link because validator state is tool-owned and was not manually edited.
- Initial class validator `000000002814` and file validator `000000002816` reported stale registry UID tags `0003CF`, `0003CG`, and/or `0003CH`; those references were converted to plain path links and rerun cleanly as `000000002815` and `000000002817`.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B007/research/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md`

Modified:

- `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`
- `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`
- `by-class/PowerDialogPane.md`
- `by-file/PowerDialogPane.md`
- `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`
- `by-global/g_pPowerDialog.md`
- `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md`
- `tools/leaser/Agents/Agent-B007/research/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md`

Leases:

- B007 leased the seven edited by-* docs before editing. Release command after validation reported `Rejected[No active lease]` for all seven, and the B007 `current_leases.md` check at `2026-06-26T15:27:58.8629066-04:00` showed no B007 leases present. The report file was leased only for this checklist update and is released after this write in the final implementation cleanup.

## Implementation Tracking Checklist

Leave these unchecked during report-only review. Check them only during a supervisor-approved implementation callback after applying or explicitly no-edit-proving the item, running the scoped validator where applicable, and recording proof.

- [x] Edit `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`.
  - Set `COMPLETION:88`, `CONFIDENCE:91`.
  - Change `CANONICAL_OWNER` to `0000AP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Change `EMITTER_UIDS` to `0000AP`.
  - Keep `EMITTER_POSITION_OPTIONAL` blank.
  - Replace the entire formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal block from this report, including marker lines and without the Markdown fence.
  - Carry current MCP session `80de0a67`, health/IDB proof, lookup function sizes, byte/padding table, raw disassembly, decompile interpretation, global/vtable xrefs, `find_bytes` immediate/pointer evidence, no-xref/no-pointer negative evidence, stale `boost::exception` correction, source-facing names, rejected alternatives, and score rationale.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md --apply --queue-timeout 240`
  - Proof: metadata changed to `88/91`, direct owner/emitter changed to `0000AP`, formal destructor/getter C++ inserted between the formal markers, current B007 session/health/IDB evidence, exact byte/padding table, source-facing names, global/vtable refs, no-route evidence, stale `boost::exception` correction, rejected alternatives, and score rationale were incorporated. Final validator `000000002812` at `2026-06-26T15:25:38-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`.
  - Update the [UID:0001F7] row/status to `88/91`, class-owned, formal child C++ through [UID:0000AP].
  - Preserve aggregate owner/emitter [UID:0000MO] and blank aggregate C++.
  - Carry destructor/getter source-shape, no-route caveat as confidence cap, scalar deleting destructor support note, and rejected merge/split alternatives.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md --apply --queue-timeout 240`
  - Proof: [UID:0001F7] row/status now says `88/91`, class-owned, formal child C++ through [UID:0000AP]; aggregate owner/emitter and blank aggregate C++ remain [UID:0000MO]; no-route confidence cap, scalar deleting destructor support, and rejected merge/split rationale were carried. Validator `000000002813` at `2026-06-26T15:25:46-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-class/PowerDialogPane.md`.
  - Update the [UID:0001F7] method row to `PowerDialogPane::~PowerDialogPane()` plus static `PowerDialogPane::GetSingleton()`.
  - State formal child C++ now lives in [UID:0001F7].
  - Keep broad class C++ blank and preserve remaining constructor/action/private-list final-source caps.
  - Carry `g_pPowerDialog` lifecycle and no-direct-caller confidence cap.
  - Validator:
    `python .\tools\validator.py --mode file --file by-class/PowerDialogPane.md --apply --queue-timeout 240`
  - Proof: [UID:0001F7] method row now documents `PowerDialogPane::~PowerDialogPane()` and static `PowerDialogPane::GetSingleton()` with formal child C++ on [UID:0001F7]; broad class C++ stays blank with constructor/action/private-list caps; `g_pPowerDialog` lifecycle and no-direct-route confidence cap were carried. Stale registry-only UID tags for read-only-data support were converted to plain links. Final validator `000000002815` at `2026-06-26T15:26:30-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-file/PowerDialogPane.md`.
  - Update proposed contents/evidence so [UID:0001F7] emits through [UID:0000AP] into `NexusTK/ui/dialogs/PowerDialogPane.cpp`.
  - Preserve broad file C++ blank and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Carry no-direct-route evidence, exact source roles, and `PowerListPane` rejection for this target.
  - Validator:
    `python .\tools\validator.py --mode file --file by-file/PowerDialogPane.md --apply --queue-timeout 240`
  - Proof: proposed contents/evidence now route [UID:0001F7] through [UID:0000AP] into `NexusTK/ui/dialogs/PowerDialogPane.cpp`; broad file C++ and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain; no-direct-route evidence, exact destructor/getter roles, and `PowerListPane` rejection were carried. Stale registry-only UID tags for `.rdata` support were converted to plain links. Final validator `000000002817` at `2026-06-26T15:27:07-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`.
  - Replace obsolete `95/95` code-gate wording in summary/status.
  - Preserve the constructor's own blank C++ rationale using target-specific blockers: packet-reader locals, row-record names, config-field names, control construction details, and unreferenced wrapper shape.
  - Add support note that [UID:0001F7] now owns formal destructor/getter C++ and this constructor only publishes `g_pPowerDialog`.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md --apply --queue-timeout 240`
  - Proof: obsolete summary/status `95/95` gate wording was replaced with target-specific blank-C++ blockers: packet-reader locals, row-record names, config-field names, control construction details, and unreferenced wrapper shape. Added that [UID:0001F7] now owns formal destructor/getter C++ and this constructor only publishes `g_pPowerDialog`. Validator `000000002818` at `2026-06-26T15:27:15-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-global/g_pPowerDialog.md`.
  - Add B007 support note that [UID:0001F7] formal C++ uses `g_pPowerDialog` in `PowerDialogPane::~PowerDialogPane()` and `PowerDialogPane::GetSingleton()`.
  - Preserve rejection of `g_activePowerListPane`.
  - Keep global C++ blank unless supervisor explicitly expands scope to global declaration emission.
  - Validator:
    `python .\tools\validator.py --mode file --file by-global/g_pPowerDialog.md --apply --queue-timeout 240`
  - Proof: added B007 support note that [UID:0001F7] formal C++ uses `g_pPowerDialog` in `PowerDialogPane::~PowerDialogPane()` and `PowerDialogPane::GetSingleton()`; preserved `g_activePowerListPane` rejection and blank global C++ pending declaration/linkage policy. Validator `000000002819` at `2026-06-26T15:27:24-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Edit `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md`.
  - Fix stale Item Summary wording from `initialized to 0xffffffff` to current zero-initialized storage.
  - Add B007 current MCP proof: `get_bytes` returns `00 00 00 00`; `xrefs_to` and `find_bytes` reconfirm exactly five singleton references.
  - State [UID:0001F7] now emits formal destructor/getter C++ using this global.
  - Validator:
    `python .\tools\validator.py --mode file --file by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md --apply --queue-timeout 240`
  - Proof: stale Item Summary now says current zero-initialized storage; B007 proof records `get_bytes 0x0069ba34 size 4` as `00 00 00 00`, five singleton references by `xrefs_to`/`find_bytes`, and [UID:0001F7] formal destructor/getter use of this global. Validator `000000002820` at `2026-06-26T15:27:33-04:00` exited `0`, `ok: 1`, generated refresh deferred.

- [x] Record no-edit proof for `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md`.
  - Proof to record: already has three vtable bases and constructor/helper/destructor store xrefs that match current B007 MCP.
  - Proof: no edit required; current page already records vtable bases `0x00622158`, `0x006221b8`, `0x006221e8` and constructor/helper/destructor store xrefs `0x00549c7a`/`0x0054a480`/`0x0054b526`, `0x00549c80`/`0x0054a486`/`0x0054b52c`, and `0x00549c8a`/`0x0054a490`/`0x0054b536`.

- [x] Record no-edit proof for `by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md`.
  - Proof to record: already classifies the four adjustor thunks as compiler-generated/non-reconstructable and identifies the scalar deleting destructor targets.
  - Proof: no edit required; current page is `RECONSTRUCTABLE:FALSE`, classifies the four `0xb` adjustor thunks as compiler-generated, identifies PowerDialogPane thunk targets `0x0054b520`, PowerListPane targets `0x0054b580`, and records the `this-0xa0`/`this-0xa4` adjustments.

- [x] Record no-edit proof for `by-class/PowerListPane.md`.
  - Proof to record: already rejects `g_activePowerListPane` and keeps the list as a feature-private consumer of `g_pPowerDialog`, not the target owner.
  - Proof: no edit required; current page states `g_activePowerListPane` should not remain list-owned, identifies the storage as `g_pPowerDialog`, and says `OnMouseEvent` reads it only to access the containing dialog's sibling list controls.

- [x] Record no-edit proof for `by-class/DialogPane.md`, `by-file/DialogPane.md`, and `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`.
  - Proof to record: already document `0x0049d9f0` as common `DialogPane` cleanup and stale `boost::exception` label pollution.
  - Proof: no edit required; class/file/aggregate pages already document `0x0049d9f0` as ordinary/common `DialogPane` destructor cleanup, stale/polluted local `boost::exception` label, vtable restore/control-manager teardown behavior, and compiler ABI policy for destructor wrappers/thunks.

- [x] Do not edit generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: only the seven accepted by-* files and this B007 report were manually edited. Validator output reported projected stats/generated refresh side effects as validator-owned deferred refresh; no generated, project-level, coverage-report, validator/tool state, or IDA DB files were manually edited.

- [x] Use no leases during report-only work. During implementation callback, lease only the immediate edit batch and release immediately after validators.
  - Proof: B007 leased the seven accepted by-* docs immediately before edits, ran validators, then attempted release; `unlease` reported `Rejected[No active lease]` for each and `current_leases.md` showed no B007 leases at `2026-06-26T15:27:58.8629066-04:00`. The report file was leased only for this checklist update and is released in final cleanup after this write.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md","timestamp":"2026-06-26T15:36:44","uid":"0001F7"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001F7-PowerDialogPaneSingletonHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001F7-PowerDialogPaneSingletonHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001F7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
