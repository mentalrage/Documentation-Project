** TARGET-REPORT-UID:0000ZJ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000ZJ] BoardDialogCommandOneVirtual Source-Quality Report

Assignment: `B006-report-0000ZJ-BoardDialogCommandOneVirtual-source-quality-20260627`  
Mode: report-only research first  
Target: `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md`  
Required report path: `tools/leaser/Agents/Agent-B006/research/0000ZJ-BoardDialogCommandOneVirtual-source-quality.md`

## Current Target State

The target currently records `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HT`, and a blank `EMITTER_POSITION_OPTIONAL`. The formal `RECONSTRUCTION_CPP CODE` block is blank. The body text contains a `## C++ Reconstruction Candidate` section with an illustrative body-only bridge candidate. That is now a rule violation because draft/example/illustrative/rejected C++ must not exist outside the formal `RECONSTRUCTION_CPP CODE` mechanism. Because this report recommends a blank formal block with a no-code proof, implementation must remove or convert that target section into prose-only no-code/source-shape documentation and must not leave any report-only or by-doc C++ body sample.

Current target facts that remain valid:

- The function is the shared command-`'1'` secondary-interface bridge at `0x00472040-0x00472069`.
- The bridge reads an event/action object at stack arg 0, loads the pointer at `event + 0x0c`, tests the first byte against ASCII `'1'` (`0x31`), returns false on mismatch, and otherwise adjusts the secondary subobject pointer by `-0xa0` before tail-jumping through primary vtable slot `+0x5c`.
- The target is installed through multiple secondary vtable slots across Bulletin, board/article, predefined-form article, and mail dialog contexts.
- The target is not a BoardListDialog-only method and not a mail-only method.

Generated support is stale relative to the target: `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` still carries the empty marker for [UID:0000ZJ] with `Completion:80 | Confidence:86`, while the target by-memory page is already `86/90`. No generated or coverage file was edited during this report-only pass.

## Evidence Checked

Live IDA MCP was available and mandatory evidence was gathered from session `80de0a67`.

Session provenance:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- Active IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by health check: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready:true`
- `hexrays_ready:true`
- `strings_cache_ready:true`

by-* and support docs read during this pass:

- `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md`
- `by-file/BoardDialogs.md`
- `by-class/BulletinDialog.md`
- `by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md`
- `by-type/by-vtable/BulletinDialogVtables.md`
- `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md`
- `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
- `by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md`
- `by-class/BoardListDialog.md`
- `by-class/ArticleListDialog.md`
- `by-class/ArticleDialog.md`
- `by-class/NewArticleDialog.md`
- `by-class/NewPredefinedFormArticleDialog.md`
- `by-type/by-vtable/MailDialogVtableFamily.md`
- `by-type/by-vtable/MailDialogCoreVtables.md`
- `by-file/MailDialogs.md`
- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
- `by-class/MailListDialog.md`
- `by-class/MailDialog.md`
- `by-class/NewMailDialog.md`
- `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
- `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md`
- `by-memory/-ignored.md`

Historical/support evidence read during this pass:

- `tools/leaser/Agents/Supervisor_notes.md`
- `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md`
- `tools/leaser/Agents/executed-b-agent-research/B014/0000ZI-BulletinDialogRawConstructor-source-quality.md`

The checkout does not currently contain `source-3/simroot_v2`; class-page references to recovered files under that tree were treated as historical leads only and were not used as source proof.

## Live MCP Function And Boundary Evidence

`lookup_funcs` on the relevant addresses in session `80de0a67` showed:

| Address | MCP result |
| --- | --- |
| `0x00472000` | Not a function |
| `0x0047203a` | Not a function |
| `0x00472040` | `sub_472040`, size `0x29` |
| `0x00472069` | Not a function |
| `0x00472070` | `sub_472070`, size `0x7f9` |
| `0x00472870` | `sub_472870`, size `0x28` |
| `0x004729a0` | `sub_4729A0`, size `0x3d` |
| `0x00479110` | `sub_479110`, size `0xc1b` |
| `0x0047b220` | `sub_47B220`, size `0x11e5` |
| `0x0047d050` | `sub_47D050`, size `0x771` |

`get_bytes` confirmed:

- `0x0047203a-0x00472040` is six bytes of `0xcc` padding before the bridge.
- `0x00472040-0x00472069` is exactly 41 bytes:

```text
55 8b ec 8b 45 08 8b 50 0c 80 3a 31 74 06 32 c0
5d c2 04 00 8b 81 60 ff ff ff 81 c1 60 ff ff ff
89 55 08 8b 40 5c 5d ff e0
```

- `0x00472069-0x00472070` is seven bytes of `0xcc` padding before the next IDA function at `0x00472070`.

`disasm` for `0x00472040`:

```asm
0x00472040  push ebp
0x00472041  mov ebp, esp
0x00472043  mov eax, [ebp+arg_0]
0x00472046  mov edx, [eax+0Ch]
0x00472049  cmp byte ptr [edx], 31h ; '1'
0x0047204c  jz short loc_472054
0x0047204e  xor al, al
0x00472050  pop ebp
0x00472051  retn 4
0x00472054  mov eax, [ecx-0A0h]
0x0047205a  add ecx, 0FFFFFF60h
0x00472060  mov [ebp+arg_0], edx
0x00472063  mov eax, [eax+5Ch]
0x00472066  pop ebp
0x00472067  jmp eax
```

`decompile` for `0x00472040`:

```c
char __thiscall sub_472040(_DWORD *this, int a2)
{
  if ( **(_BYTE **)(a2 + 12) == 49 )
    return (*(int (__thiscall **)(_DWORD *, _DWORD))(*(this - 40) + 92))(this - 40, *(_DWORD *)(a2 + 12));
  else
    return 0;
}
```

`analyze_function` reported:

- name: `sub_472040`
- prototype: `char __thiscall(_DWORD *this, int)`
- size: 41 bytes
- strings: empty
- constants: empty
- callees: empty
- callers: empty
- data refs to the function from `0x00613c1c`, `0x00613cbc`, `0x00613e20`, `0x00613f84`, `0x00614024`, `0x006140c4`, `0x006142ac`, `0x00614410`, and `0x006144b0`.

`xref_query` confirmed there are no external code references to `0x00472040`; the only code xref reported from the function body was the internal flow from `0x00472040` to `0x00472041`. `xrefs_to` and `find_bytes` found exactly the same nine data references and no additional VA/RVA pointer route.

`find_bytes` for the little-endian pointer bytes `40 20 47 00` found exactly nine matches:

- `0x00613c1c`
- `0x00613cbc`
- `0x00613e20`
- `0x00613f84`
- `0x00614024`
- `0x006140c4`
- `0x006142ac`
- `0x00614410`
- `0x006144b0`

`get_int` on each of those nine data addresses returned decimal `4661312`, verified by `tools/int_convert.py` as hex `0x00472040`.

`tools/int_convert.py --pretty` verified the main numeric interpretations used in this report:

- `0x29` = 41
- `0xa0` = 160
- `0xa4` = 164
- `0x5c` = 92
- `0x0c` = 12
- `0x10` = 16
- `0x31` = 49, ASCII `1`
- `0x00472040` = 4661312
- decimal `4661312` = hex `0x472040`

## Vtable Contexts

`entity_query` over `0x00613b90-0x006144e0`, `xrefs_to`, `find_bytes`, and `get_int` support the following slot map. Every listed slot stores `0x00472040`; each slot is the secondary-table `+0x10` entry for that class view.

| Slot address | Secondary table | Slot offset | Slot value | Source/documentation context |
| --- | --- | --- | --- | --- |
| `0x00613c1c` | `??_7BulletinDialog@@6B@_0` at `0x00613c0c` | `+0x10` | `0x00472040` | `by-class/BulletinDialog.md`, `by-type/by-vtable/BulletinDialogVtables.md`, `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md` |
| `0x00613cbc` | `??_7BoardListDialog@@6B@_0` at `0x00613cac` | `+0x10` | `0x00472040` | `by-class/BoardListDialog.md`, `by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md` |
| `0x00613e20` | `??_7ArticleListDialog@@6B@_0` at `0x00613e10` | `+0x10` | `0x00472040` | `by-class/ArticleListDialog.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md` |
| `0x00613f84` | `??_7ArticleDialog@@6B@_0` at `0x00613f74` | `+0x10` | `0x00472040` | `by-class/ArticleDialog.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md` |
| `0x00614024` | `??_7NewArticleDialog@@6B@_0` at `0x00614014` | `+0x10` | `0x00472040` | `by-class/NewArticleDialog.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md` |
| `0x006140c4` | `??_7NewPredefinedFormArticleDialog@@6B@_0` at `0x006140b4` | `+0x10` | `0x00472040` | `by-class/NewPredefinedFormArticleDialog.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md` |
| `0x006142ac` | `??_7MailListDialog@@6B@_0` at `0x0061429c` | `+0x10` | `0x00472040` | `by-class/MailListDialog.md`, `by-type/by-vtable/MailDialogVtableFamily.md`, `by-type/by-vtable/MailDialogCoreVtables.md` |
| `0x00614410` | `??_7MailDialog@@6B@_0` at `0x00614400` | `+0x10` | `0x00472040` | `by-class/MailDialog.md`, `by-type/by-vtable/MailDialogVtableFamily.md`, `by-type/by-vtable/MailDialogCoreVtables.md` |
| `0x006144b0` | `??_7NewMailDialog@@6B@_0` at `0x006144a0` | `+0x10` | `0x00472040` | `by-class/NewMailDialog.md`, `by-type/by-vtable/MailDialogVtableFamily.md`, `by-type/by-vtable/MailDialogCoreVtables.md` |

This nine-slot evidence is the strongest current reason not to route [UID:0000ZJ] as a BoardListDialog-specific, ArticleDialog-specific, or MailDialog-specific method. It is one shared body installed into the secondary view of all nine class contexts.

## Data Flow And Behavior

The function receives a secondary-interface `this` in `ecx` and one stack argument at `[ebp+arg_0]`.

1. It loads `event = [ebp+arg_0]`.
2. It loads `commandText = *(event + 0x0c)` into `edx`.
3. It compares `commandText[0]` with ASCII `'1'` (`0x31`).
4. On mismatch, it returns `0` as a `char`/bool-like false result and pops the single stack argument with `retn 4`.
5. On match, it loads the primary vptr from `[ecx - 0xa0]`.
6. It adjusts `ecx` by `-0xa0`, converting the secondary-interface pointer back to the primary object pointer.
7. It overwrites the stack argument with `commandText`.
8. It loads the target from the primary vtable at `+0x5c`.
9. It tail-jumps through that virtual slot.

The `this - 0xa0` adjustment is in bytes in the assembly. The decompiler phrase `this - 40` is because it typed `this` as `_DWORD *`, and `40 * 4 = 160 = 0xa0`.

The body has no direct callees because the successful path is a tail jump through a primary vtable slot. The absence of direct callers is expected because all inbound uses are vtable data references rather than direct calls.

## Source-Quality Disposition

Recommended target metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000HT
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000HT
EMITTER_POSITION_OPTIONAL:
```

Rationale:

- Completion should rise from `86` to `88` because live MCP session `80de0a67` resolves the exact function boundary, padding, byte body, no endpoint function at `0x00472069`, no external code xrefs, no direct VA/RVA pointer route beyond the nine vtable slots, all nine slot values, and the board/article/mail secondary-vtable contexts.
- Confidence should rise from `90` to `92` because the binary placement and data-flow evidence is now direct and repeatable from current IDA, with `int_convert.py` verification for the relevant constants and pointer values.
- Completion should not rise to source-final territory because the source-facing secondary interface name, event/action type, `event+0x0c` field name, and primary slot `+0x5c` declaration are still not documented at source-quality level.
- The formal C++ block should remain blank. The target can remain `RECONSTRUCTABLE:TRUE` and routed through [UID:0000HT], but this exact by-memory item should emit no method body until the supporting interface/type declarations are source-quality.

Recommended owner/emitter:

- Keep `CANONICAL_OWNER:0000HT`.
- Keep `EMITTER_UIDS:0000HT`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.

[UID:0000HT] `by-file/BoardDialogs.md` remains the best current route because the target is a shared file-family bridge and no documented narrower source-facing command-interface type owns all nine vtable slots. The current evidence does not support changing ownership to `BulletinDialog`, `BoardListDialog`, any article dialog class, `MailDialogs`, or a no-owner bucket.

## Source-Quality Blocker Closure

This pass did not stop at a generic "names unknown" blocker. It checked the concrete routes that could make a formal source declaration safe and closed them as follows.

Shared secondary-interface owner/type:

- Evidence checked: live `entity_query` names for `0x00613b90-0x006144e0`; exact `xrefs_to`, `find_bytes`, and `get_int` for all nine function-pointer slots; `by-type/by-vtable/BulletinDialogVtables.md`; `by-type/by-vtable/BoardArticleDialogVtableFamily.md`; `by-type/by-vtable/MailDialogVtableFamily.md`; `by-type/by-vtable/MailDialogCoreVtables.md`; and the class/file pages for every consuming dialog.
- Result: IDA names the consuming secondary tables as class-specific decorated vtables, not as a recovered named common interface. The same bridge is present in BulletinDialog, BoardListDialog, ArticleListDialog, ArticleDialog, NewArticleDialog, NewPredefinedFormArticleDialog, MailListDialog, MailDialog, and NewMailDialog secondary views. No support doc establishes a separate source type that owns all nine slots.
- Best descriptive prose name: "shared secondary command bridge" or "command-'1' secondary bridge."
- Why this still blocks formal C++: those prose names describe the binary role but do not identify a source class/interface declaration. Inserting a formal method under one invented interface would create a new source-facing type not proven by the docs or symbols.

Event/action type and `+0x0c` field:

- Evidence checked: IDA decompile/disassembly for `0x00472040`; `analyze_function` strings/constants/callees; the target page's prior behavior notes; related board/article/mail class pages; and available type/layout docs in the assignment scope.
- Result: the only current proof is structural: the stack argument points to an object whose `+0x0c` field is a pointer to a NUL-style command string, and the bridge tests that string's first byte against ASCII `'1'`. The function has no strings, named callees, or type references that identify the object type or field name.
- Best descriptive prose names: "event/action object" for the argument and "command string at `event+0x0c`" for the field.
- Why this still blocks formal C++: a formal body would need to declare a parameter type and field/member access. Current evidence supports the offset and data flow, not a source-quality type or member name.

Primary slot `+0x5c` target name:

- Evidence checked: target disassembly/decompile; primary/secondary vtable support pages; BoardListDialog, BulletinDialog, article, predefined-form article, and mail class pages; and nearby board/article/mail memory pages.
- Result: the successful path adjusts the secondary `this` by `-0xa0`, rewrites the stack argument with the command string pointer, and tail-jumps through primary vtable slot `+0x5c`. The inspected support docs do not provide one source-quality virtual name/prototype for that primary slot that is valid across all nine consuming classes.
- Best descriptive prose name: "primary vtable `+0x5c` command-dispatch slot."
- Why this still blocks formal C++: naming the destination as a member such as a handler/command method would be an invented declaration. The safe documentation fact is the slot dispatch and argument replacement, not the member name.

Owner/emitter route:

- Evidence checked: `by-file/BoardDialogs.md`, `by-file/MailDialogs.md`, `by-class/BulletinDialog.md`, all nine consuming class pages, and board/article/mail vtable family pages.
- Result: [UID:0000HT] remains the least-wrong current file-level route because it already owns the target and the board/article dialog family context, while the mail pages prove consumer slots rather than a mail-specific body. A class owner would overclaim; no documented interface owner exists; no-owner would discard a stable route.
- Best descriptive prose owner language: "file-routed shared secondary command bridge under [UID:0000HT], with mail-side consumer slots documented in support pages."
- Why this still blocks formal C++: owner routing is sufficient for documentation and generated marker placement, but it does not supply the missing source class/interface/event declarations needed for source-shaped C++.

Closure: the current safe implementation is not a deferred "needs investigation" state. The investigated evidence supports a stronger no-code proof, target score movement to `88/92`, and richer target/support documentation, but it still does not support a formal source body in this by-memory page without invented declarations or ABI-shaped pointer adjustment code.

## Formal C++ Decision

Do not insert a formal `RECONSTRUCTION_CPP CODE` block for [UID:0000ZJ] in this implementation callback. The correct implementation edit is to preserve a blank formal block and replace or supersede the current illustrative candidate with an explicit no-code proof.

No-code proof:

- The function is source-authored behavior, not a pure compiler-generated adjustor thunk, because it reads an event/action object, tests `commandText[0] == '1'`, returns false on mismatch, and only then dispatches through another virtual slot.
- The body is nevertheless not safe as source-facing C++ in this by-memory page because the binary body is the ABI view of a secondary-interface method. A literal reconstruction would need to encode a manual cast-and-subtract adjustment from `this` by `0xa0`, which is a compiler layout artifact and should instead be represented by proper multiple-inheritance/interface declarations once those declarations are documented.
- The current docs do not source-quality identify the secondary interface or method name. Names such as `DialogCommandOneBridge`, `DialogEvent`, `commandText`, and `HandleCommandOne` are explanatory names, not recovered source names.
- The event/action object type and its `+0x0c` string field are not documented enough to declare a formal parameter or field access.
- The primary vtable slot `+0x5c` target declaration is not source-quality named here. The bridge can be described as dispatching to primary slot `+0x5c`, but a formal source body should not invent a member name for that slot.
- The function is installed in nine secondary vtables across BoardDialogs, a dedicated NewPredefinedFormArticleDialog context, and MailDialogs contexts. A single class-local formal C++ method would overclaim ownership unless a support type establishes the shared secondary command/action interface.

Rejected formal body shape:

- Do not write a body-only sample under names such as `DialogCommandOneBridge`, `DialogEvent`, `commandText`, `DialogBase`, or `HandleCommandOne`. Those names are descriptive at best and are not recovered source declarations.
- Do not write a body that manually subtracts `0xa0` from `this`. That expression describes the compiled secondary-subobject adjustment, not the human-written source shape.
- Do not write an explanatory source body anywhere in the report or target/support prose unless it is exact formal-block-ready content for `RECONSTRUCTION_CPP CODE`. Under this report's recommendation, the formal block remains blank and the target receives prose-only no-code proof.

## Rejected Alternatives

Compiler-only adjustor thunk:

- Rejected. `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md` documents pure adjustor thunks that only subtract `0xa0` or `0xa4` and tail-jump to scalar deleting destructors. [UID:0000ZJ] is different: it performs an event string read, ASCII comparison, false return path, stack-argument replacement, and conditional virtual dispatch.

BoardListDialog-only owner:

- Rejected. BoardListDialog contributes only one of nine secondary-table slots, `0x00613cbc`. The pointer search and xref set include BulletinDialog, article dialog classes, predefined-form article dialog, and mail dialog classes.

BulletinDialog class owner:

- Rejected for this pass. BulletinDialog is an important shared context and its support docs already mention [UID:0000ZJ], but the nine-slot set includes mail and predefined-form contexts. The current docs do not prove that a BulletinDialog class declaration is the original source owner for the shared secondary-interface method.

Article or NewPredefinedFormArticleDialog owner:

- Rejected. Article and predefined-form contexts are consumers of the shared bridge, not unique owners. `NewPredefinedFormArticleDialog` has dedicated file evidence for other members, but its secondary slot at `0x006140c4` is one of nine identical entries.

MailDialogs owner:

- Rejected as primary ownership. MailListDialog, MailDialog, and NewMailDialog consume the same bridge through secondary slots `0x006142ac`, `0x00614410`, and `0x006144b0`, but the shared body is not mail-specific and is also present in six board/article/predefined contexts.

Split into nine duplicated by-memory targets:

- Rejected. IDA has one function at `0x00472040`, `find_bytes` finds exactly nine data slots pointing at that one VA, and there are no distinct per-class bridge implementations.

No-owner/no-emitter route:

- Rejected. The target has a stable file route through [UID:0000HT] and is reconstructable as documented behavior even if the formal C++ block must remain blank until supporting type names are source-quality.

Generated C++ placeholder names:

- Do not introduce or preserve source-facing placeholders such as `sub_472040`, `func_472040`, `dword_613c1c`, `unk_event`, or invented class/member names in target/support prose. The accepted by-* docs should use descriptive documentation names only, with explicit caveats where a source-facing name is unknown.

## Support Doc Impact

If this report is accepted for implementation, apply the following by-* changes at report-level detail.

Target `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:92`, keeping owner/emitter fields unchanged.
- Add the MCP session `80de0a67` proof for exact `0x29` body size, full bytes, padding before and after, no function at `0x00472069`, next function at `0x00472070`, no external code xrefs, no direct callees, no direct VA/RVA pointer route beyond the nine vtable slots, and exact slot values.
- Update the vtable evidence table so all nine slots explicitly list the secondary base name, slot `+0x10`, and slot value `0x00472040`.
- Preserve the `event+0x0c` command-string load, ASCII `'1'` comparison, secondary `this - 0xa0` adjustment, primary slot `+0x5c` dispatch, and stack-argument replacement details.
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank.
- Remove or convert the current `## C++ Reconstruction Candidate` section because body-only C++ outside `RECONSTRUCTION_CPP CODE` is a rule violation. Replace it with prose-only no-code proof and source-shape disposition, so generated output does not treat the sketch as source-ready C++.
- Do not introduce any new draft/example/illustrative/rejected C++ body in the target or support docs outside `RECONSTRUCTION_CPP CODE`.
- Add rejected alternatives and score rationale sufficient for Rule 26 review.

`by-file/BoardDialogs.md`:

- Add current-session evidence that [UID:0000ZJ] is one shared secondary command bridge spanning Bulletin, board/article, predefined-form article, and mail secondary vtables.
- Preserve [UID:0000HT] as the current file-level owner/emitter route, while documenting why the route is provisional around the missing source-facing secondary interface/type.
- Explicitly note that the bridge should not be duplicated into the individual class pages or promoted to a formal C++ block until interface/event/slot declarations are resolved.

`by-class/BulletinDialog.md`:

- Update or verify the shared method row/evidence for [UID:0000ZJ] with session `80de0a67` proof.
- Document that the body is not a pure compiler adjustor, but also not class-owned formal source C++ yet because the shared secondary-interface owner is unresolved.

`by-type/by-vtable/BulletinDialogVtables.md`:

- Verify or update the secondary `+0x10` entry for [UID:0000ZJ] at `0x00613c1c`, including current session proof that the slot value is `0x00472040`.

`by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md`:

- Verify or update the `0x00613c1c` row with current session proof and keep the data page non-emitting.

`by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md`:

- Verify or update the `0x00613cbc` secondary slot row with current session proof and distinguish it from BoardListDialog's primary command handlers.

`by-type/by-vtable/BoardArticleDialogVtableFamily.md`:

- Update shared slot notes for the six board/article/predefined slots: `0x00613c1c`, `0x00613cbc`, `0x00613e20`, `0x00613f84`, `0x00614024`, and `0x006140c4`.
- Preserve the recommendation not to duplicate [UID:0000ZJ] into each consuming class during source migration.

`by-class/ArticleListDialog.md`, `by-class/ArticleDialog.md`, `by-class/NewArticleDialog.md`, and `by-class/NewPredefinedFormArticleDialog.md`:

- Verify or add concise class support notes that their secondary vtable view consumes [UID:0000ZJ] through the corresponding slot.
- Preserve existing class-level C++ blankness and source-split caveats.

`by-type/by-vtable/MailDialogVtableFamily.md` and `by-type/by-vtable/MailDialogCoreVtables.md`:

- Add the currently missing explicit mail-side slot proof: MailListDialog secondary `0x0061429c + 0x10`, MailDialog secondary `0x00614400 + 0x10`, and NewMailDialog secondary `0x006144a0 + 0x10` all store `0x00472040`.
- Document that these are consumer slots of the shared bridge and do not move target ownership to MailDialogs.

`by-file/MailDialogs.md`, `by-class/MailListDialog.md`, `by-class/MailDialog.md`, and `by-class/NewMailDialog.md`:

- Add or verify support notes that the mail dialog secondary command/action views consume [UID:0000ZJ].
- Preserve MailDialogs as the source owner for mail-specific methods, not the owner for this shared bridge.

No manual coverage files should be edited by B006. If a manual `by-memory/-coverage-report.md` row is still needed after acceptance, that is supervisor-owned under the assignment restriction. Generated tracker/coverage staleness should be handled by validators/generation, not by hand edits.

## Expected Validators After Implementation

Run validators from `source-3/project-documentation` after the accepted edits. At least one target validation should use `--wait-generated` so generated freshness for `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` can be checked.

Minimum target command:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZJ-BoardDialogCommandOneVirtual-source-quality-removed.md](0000ZJ-BoardDialogCommandOneVirtual-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run scoped file validation for every support by-* file edited. Likely commands include:

> Executable block R002 was removed from this report and preserved verbatim in [0000ZJ-BoardDialogCommandOneVirtual-source-quality-removed.md](0000ZJ-BoardDialogCommandOneVirtual-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the target validator with `--wait-generated`, inspect generated freshness for `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`. Expected result if this report is implemented as recommended: generated metadata should refresh from stale `80/86` to the accepted target metadata, but [UID:0000ZJ] should remain an empty emitter marker with no formal `BoardDialogCommandOneVirtual` C++ body.

## Implementation Tracking Checklist

- [x] Target metadata updated in `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md` to the accepted scores, with `CANONICAL_OWNER:0000HT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HT`, and blank emitter position preserved. Verified in target header: `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter unchanged.
- [x] Target evidence/status updated with MCP session `80de0a67` proof: exact `0x29` body, full bytes, no function at `0x00472069`, next function at `0x00472070`, padding before and after, decompile/disasm cleanup sequence, no external code xrefs, no direct callees, no VA/RVA pointer route beyond the nine vtable slots, and `int_convert.py` checks. Verified present in target `## Evidence`, `## Raw Code Evidence`, and `## No-Code Source-Shape Proof`.
- [x] Target vtable evidence table updated with all nine secondary slots, base names, `+0x10` offsets, and verified `0x00472040` slot values. Verified in target `## Vtable Evidence`.
- [x] Target behavior/data-flow retains the `event+0x0c` command-string load, ASCII `'1'` comparison, false return, secondary `this - 0xa0` adjustment, stack-argument replacement, and primary slot `+0x5c` tail-jump. Verified in target `## Behavior`.
- [x] Target formal `RECONSTRUCTION_CPP CODE` block intentionally remains blank; the existing `## C++ Reconstruction Candidate` body-only section is removed or converted to prose-only no-code proof/source-shape disposition because C++ outside `RECONSTRUCTION_CPP CODE` is prohibited. Verified formal inline/multiline code fields are blank and the page now uses `## No-Code Source-Shape Proof`.
- [x] Target/support edits do not introduce any new draft/example/illustrative/rejected C++ body outside `RECONSTRUCTION_CPP CODE`. Verified by text inspection and support edits; added only prose notes.
- [x] Target rejected alternatives and score rationale updated for Rule 26 review: not compiler-only adjustor glue, not BoardListDialog-only, not BulletinDialog-owned at current evidence level, not article/predefined-only, not mail-owned, not nine duplicated targets, and not no-owner/no-emitter. Verified in target `## Rejected Alternatives`, `## Reconstruction Guidance`, and `## Score Rationale`.
- [x] `by-file/BoardDialogs.md` updated or verified at same-or-greater detail for [UID:0000ZJ] as the current shared file-route bridge and for the missing source-facing secondary interface/type caveat. Verified already present in `Proposed Contents`, `IDA MCP Evidence`, `Ownership Notes`, and `Changes`; no additional edit needed in this callback.
- [x] `by-class/BulletinDialog.md` updated or verified at same-or-greater detail for the [UID:0000ZJ] shared secondary command bridge and non-class-owned formal C++ caveat. Verified existing B006 support note for `0x00613c1c -> 0x00472040`; no edit needed in this callback.
- [x] `by-type/by-vtable/BulletinDialogVtables.md` updated or verified for the `0x00613c1c` secondary `+0x10` slot. Verified existing B006 support note and slot row; no edit needed in this callback.
- [x] `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md` updated or verified for the `0x00613c1c` vtable data row. Verified existing B006 row and evidence note; no edit needed in this callback.
- [x] `by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md` updated or verified for the `0x00613cbc` vtable data row and BoardListDialog primary-command distinction. Verified existing B006 row and distinction from `0x00613c90`; no edit needed in this callback.
- [x] `by-type/by-vtable/BoardArticleDialogVtableFamily.md` updated or verified for the six board/article/predefined consumer slots. Verified existing B006 notes for `0x00613c1c`, `0x00613cbc`, `0x00613e20`, `0x00613f84`, `0x00614024`, and `0x006140c4`; no edit needed in this callback.
- [x] Article-side class pages updated or verified as needed: `by-class/ArticleListDialog.md`, `by-class/ArticleDialog.md`, `by-class/NewArticleDialog.md`, and `by-class/NewPredefinedFormArticleDialog.md`. Added B006 consumer-slot notes and change entries for `0x00613e20`, `0x00613f84`, `0x00614024`, and `0x006140c4`, preserving class-level C++ blankness and source-split caveats.
- [x] Mail vtable support updated or verified: `by-type/by-vtable/MailDialogVtableFamily.md` and `by-type/by-vtable/MailDialogCoreVtables.md` document mail secondary `+0x10` slots to [UID:0000ZJ]. Added B006 notes/table for `0x006142ac`, `0x00614410`, and `0x006144b0`, all storing `0x00472040`.
- [x] Mail class/file support updated or verified as needed: `by-file/MailDialogs.md`, `by-class/MailListDialog.md`, `by-class/MailDialog.md`, and `by-class/NewMailDialog.md`. Added B006 support notes that these mail secondary command/action views consume [UID:0000ZJ] while MailDialogs keeps ownership of mail-specific methods only.
- [x] No manual coverage file edited by B006; any manual coverage row remains supervisor-owned if still required. Verified no `-coverage-report.md` files were edited.
- [x] Scoped validators run from `source-3/project-documentation` for the target and every edited support by-* file, recording command, command_id, command_timestamp, exit code, and ok count.
  - `python .\tools\validator.py --mode file --file by-memory\0x00472040-0x00472069.BoardDialogCommandOneVirtual.md --apply --queue-timeout 240 --wait-generated` -> command_id `000000004155`, command_timestamp `2026-06-27T11:18:02-04:00`, exit `0`, ok `1`, generated_refresh `completed`.
  - `python .\tools\validator.py --mode file --file by-class\ArticleListDialog.md --apply --queue-timeout 240` -> command_id `000000004159`, command_timestamp `2026-06-27T11:18:47-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\ArticleDialog.md --apply --queue-timeout 240` -> command_id `000000004160`, command_timestamp `2026-06-27T11:18:49-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\NewArticleDialog.md --apply --queue-timeout 240` -> command_id `000000004161`, command_timestamp `2026-06-27T11:18:51-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\NewPredefinedFormArticleDialog.md --apply --queue-timeout 240` -> command_id `000000004162`, command_timestamp `2026-06-27T11:18:54-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\MailDialogVtableFamily.md --apply --queue-timeout 240` -> command_id `000000004163`, command_timestamp `2026-06-27T11:18:56-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\MailDialogCoreVtables.md --apply --queue-timeout 240` -> command_id `000000004164`, command_timestamp `2026-06-27T11:18:57-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-file\MailDialogs.md --apply --queue-timeout 240` -> command_id `000000004165`, command_timestamp `2026-06-27T11:18:59-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\MailListDialog.md --apply --queue-timeout 240` -> command_id `000000004166`, command_timestamp `2026-06-27T11:19:06-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\MailDialog.md --apply --queue-timeout 240` -> command_id `000000004167`, command_timestamp `2026-06-27T11:19:08-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class\NewMailDialog.md --apply --queue-timeout 240` -> command_id `000000004168`, command_timestamp `2026-06-27T11:19:10-04:00`, exit `0`, ok `1`, generated_refresh `deferred`.
- [x] Target or final validator run with `--wait-generated`; generated `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` freshness checked and recorded. Target run `000000004155` completed generated refresh; later deferred refresh advanced the generated header to `validator-command-id: 000000004161`, `validator-refreshed-at: 2026-06-27T11:18:51-04:00`, which is newer than the target command. Generated output contains [UID:0000ZJ] as `Completion:88 | Confidence:92 | Empty Emitter Marker`, with no `BoardDialogCommandOneVirtual` C++ body.
- [x] All B006 leases released after edit/validator batches; shared lease report shows no active B006 rows. Leased and released the target plus edited support docs in one immediate batch; post-release `tools/leaser/Agents/current_leases.md` contains no `B006` entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0000ZJ-BoardDialogCommandOneVirtual-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000ZJ-BoardDialogCommandOneVirtual-source-quality.md","timestamp":"2026-06-27T11:27:12","uid":"0000ZJ"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZJ-BoardDialogCommandOneVirtual-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0000ZJ-BoardDialogCommandOneVirtual-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
