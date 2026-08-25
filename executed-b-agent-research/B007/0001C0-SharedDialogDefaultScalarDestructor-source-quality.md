** TARGET-REPORT-UID:0001C0 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001C0 SharedDialogDefaultScalarDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001C0] as no-code compiler-generated shared scalar deleting destructor glue.
- Final disposition: non-emitting MSVC deleting-destructor artifact for a shared `DialogPane`-derived default-destructor family; no handwritten NexusTK source body should be added.
- Required action if accepted: update the target page to close the stale "not every consuming class" caveat, replace polluted `boost/base` wording with `DialogPane` cleanup / `OperatorDeleteWrapper`, add the full consumer matrix, and raise metadata while keeping `RECONSTRUCTABLE:FALSE`.
- Confidence: very strong for boundary, flag behavior, caller absence, thunk routes, primary vtable consumers, ordinary destructor callee, delete helper, and source-placement policy; medium-high only for the exact runtime label/name of the `flags & 4` helper at `0x0041b6a0`.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `93` |
| `CANONICAL_OWNER` | keep `NONE` |
| `RECONSTRUCTABLE` | keep `FALSE` |
| `EMITTER_UIDS` | keep blank |
| Formal C++ | keep blank permanently; this is no-code compiler glue |

## Target

- Target UID: [UID:0001C0]
- Target path: `source-3/project-documentation/by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0001C0-SharedDialogDefaultScalarDestructor-source-quality.md`
- Current target score/state: `82/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
- Current coverage row: `ignored : 82% : strong` with stale `boost/base destructor/delete/guard` wording.
- Generated state: `auto-generated/-ag-memory-coverage.md` already reports `not_reconstructable | NONE | | | no`, so metadata direction is already correct; the target page just needs stronger evidence and cleaner names.

## Supervisor Active Recheck

- User assigned a B-preferred report-only source-quality / heuristic pass for [UID:0001C0] `SharedDialogDefaultScalarDestructor`.
- Report-only pass: no target/support by-* docs were edited, no generated/project files were edited, and `by-memory/-coverage-report.md` was not edited.
- Completed reports `000125`, `00015G`, `00018P`, and `00019M` were preserved. This report file did not already exist before creation.
- B001/B002/B007 executed-report folders were searched for `0001C0`, `SharedDialogDefaultScalarDestructor`, `0x00520b70`, `520B70`, and related spellings; no prior executed B-agent report for this UID was found.

## Evidence Standards Used

- Direct binary-derived evidence: existing live IDA notes in target/support docs plus local IDA export `.lst`, `.c`, and `.map` files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.
- Documentation evidence: target page, [UID:0001BW] early thunks, [UID:00023N] late thunks, [UID:00012R] `DialogPane` executable page, [UID:0000IT] `DialogPane` file page, [UID:000197] `OperatorDeleteWrapper`, merchant/menu vtable pages, message/text/proxy dialog file/class/vtable pages, and `by-memory/-ignored.md`.
- Inference guidance: compiler/linker-generated artifacts, thunks, and deleting destructors are documented and excluded; source responsibilities belong to class declarations and ordinary destructors, not to hand-authored scalar deleting wrappers.
- IDA MCP status: a fresh request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. This report therefore relies on existing live-IDA documentation plus local IDA exports.

## IDA / Export Facts

- Local `.lst` export confirms `sub_520B70` at `0x00520b70`, bp-framed, ending with `retn 4` at `0x00520ba8`, followed by alignment at `0x00520bab`; target end-exclusive range `0x00520b70-0x00520bab` is exact.
- Local `.c` export decompiles the wrapper as `boost::exception *__thiscall sub_520B70(boost::exception *Block, char a2)`, calls the polluted `boost::exception::~exception` label, conditionally calls `sub_4F4AC0`, and returns `Block`.
- The `boost::exception` label is not source identity. [UID:00012R] documents `0x0049d9f0-0x0049dacb` as `DialogPane` cleanup / non-deleting destructor body and notes the local IDA name is polluted by nearby exception metadata.
- Assembly body:
  - saves `this` in `esi`;
  - calls `0x0049d9f0` before testing flags;
  - if `(flags & 1) == 0`, returns `this`;
  - if `(flags & 1) != 0` and `(flags & 4) == 0`, calls `0x004f4ac0` with `this`, then returns `this`;
  - if `(flags & 4) != 0`, pushes `0x278` and `this`, calls `0x0041b6a0`, cleans 8 stack bytes, then returns `this`.
- [UID:000197] identifies `0x004f4ac0` as the MemoryMan-backed `OperatorDeleteWrapper` / global `operator delete` wrapper, not a class-local delete helper.
- `callers 0x00520b70` evidence in the target reports no ordinary direct callers.
- Inbound code refs are tail jumps from exactly four adjustor thunks:
  - [UID:0001BW] `0x00520aa5`: `this -= 0xa0`; `jmp 0x00520b70`;
  - [UID:0001BW] `0x00520ab0`: `this -= 0xa4`; `jmp 0x00520b70`;
  - [UID:00023N] `0x005539c3`: `this -= 0xa0`; `jmp 0x00520b70`;
  - [UID:00023N] `0x005539ce`: `this -= 0xa4`; `jmp 0x00520b70`.
- Local `.lst` / `.c` exports confirm primary vtable slots pointing directly at `sub_520B70` for the complete consumer set listed below.

## Complete Consumer / Thunk Matrix

Primary vtable slots call [UID:0001C0] directly. Secondary and tertiary vtable views route through `this`-adjustor thunks. The early thunk pair [UID:0001BW] is reused by menu/message/text consumers; the late thunk pair [UID:00023N] is the `NexonclubProxyDialog` copy.

| Consumer class | Primary vtable -> `0x00520b70` | Secondary route | Tertiary route | Source/support owner |
| --- | --- | --- | --- | --- |
| `MerchantDialogPane` | `0x0061ec10` | `0x0061ec70 -> 0x00520aa5` | `0x0061eca0 -> 0x00520ab0` | [UID:0000L9] `MerchantDialogPane` |
| `ServerItemMenuDialog` | `0x0061eea8` | `0x0061ef08 -> 0x00520aa5` | `0x0061ef38 -> 0x00520ab0` | [UID:0000KF] `ItemMenuDialogs` |
| `ClientItemMenuDialog` | `0x0061f008` | `0x0061f068 -> 0x00520aa5` | `0x0061f098 -> 0x00520ab0` | [UID:0000KF] `ItemMenuDialogs` |
| `ServerSpellMenuDialog` | `0x0061f168` | `0x0061f1c8 -> 0x00520aa5` | `0x0061f1f8 -> 0x00520ab0` | [UID:0000O2] `SpellMenuDialogs` |
| `ClientSpellMenuDialog` | `0x0061f2c8` | `0x0061f328 -> 0x00520aa5` | `0x0061f358 -> 0x00520ab0` | [UID:0000O2] `SpellMenuDialogs` |
| `ArgumentedMenuMenuDialog` | `0x0061f428` | `0x0061f488 -> 0x00520aa5` | `0x0061f4b8 -> 0x00520ab0` | [UID:0000HI] `ArgumentedMenuDialogs` |
| `PursuitMessageDialogPane` | `0x00622428` | `0x00622488 -> 0x00520aa5` | `0x006224b8 -> 0x00520ab0` | [UID:0000BE] class / [UID:0000LA] `MessageDialogs` |
| `MessageDialog` | `0x006224c4` | `0x00622524 -> 0x00520aa5` | `0x00622554 -> 0x00520ab0` | [UID:0000LA] `MessageDialogs` |
| `MessageDialogLarger` | `0x00622560` | `0x006225c0 -> 0x00520aa5` | `0x006225f0 -> 0x00520ab0` | [UID:0000LA] `MessageDialogs` |
| `MenuQuestionDialog` | `0x006225fc` | `0x0062265c -> 0x00520aa5` | `0x0062268c -> 0x00520ab0` | [UID:0000LA] `MessageDialogs` |
| `MenuQuestionDialogLarger` | `0x00622698` | `0x006226f8 -> 0x00520aa5` | `0x00622728 -> 0x00520ab0` | [UID:0000LA] `MessageDialogs` |
| `TextDialog` | `0x00622958` | `0x006229b8 -> 0x00520aa5` | `0x006229e8 -> 0x00520ab0` | [UID:0000OL] `TextDialog` |
| `anonymous namespace::NexonclubProxyDialog` | `0x00622c58` | `0x00622cb8 -> 0x005539c3` | `0x00622ce8 -> 0x005539ce` | [UID:0000LZ] `NexonclubProxyDialog` |

Negative/precision note: adjacent `TextMenuDialog` and `TextInputMenuDialog` are part of the merchant menu vtable family but are not in this `0x00520b70` primary-slot consumer set in the local export search. Do not overstate [UID:0001C0] as every menu-family dialog destructor.

## Heuristic / Inference Reanalysis

### Source-Bearing Versus No-Code

- Best inference: exact no-code compiler glue.
- Evidence: scalar deleting destructor ABI shape (`thiscall`, flag byte/dword stack argument, `retn 4`), primary vtable-only references, adjustor-thunk tail jumps, no ordinary callers, call to the ordinary destructor first, conditional `operator delete`, and no class-specific vtable stores or field cleanup.
- Rejected source-bearing classification: the wrapper has no NexusTK feature behavior. All meaningful work is delegated to `DialogPane::~DialogPane`, `OperatorDeleteWrapper`, or compiler/runtime delete support.
- Rejected single-owner placement: vtable consumers span merchant, item, spell, argumented menu, message, text, and anonymous proxy dialog classes. A `PursuitMessageDialogPane` or `NexonclubProxyDialog` source body would be misleading.
- Rejected helper/source name: `SharedDialogDefaultScalarDestructor` is a documentation label only. Do not create a source symbol with that name, and do not retain `sub_520B70` except as address evidence.

### Ordinary Destructor Placement

- The ordinary cleanup body is [UID:00012R] `0x0049d9f0-0x0049dacb`, documented as `DialogPane` cleanup / non-deleting destructor.
- Source responsibility belongs to [UID:0000IT] `DialogPane` for the common base destructor and to each derived class declaration for virtual destructor shape. If a derived class has no extra cleanup, source can declare/default the destructor and let the compiler emit equivalent deleting wrappers.
- [UID:0001C0] itself has no canonical file owner and should keep `CANONICAL_OWNER:NONE`.

### Object Size `0x278`

- The `flags & 4` branch pushes `0x278` before `this` into the `0x0041b6a0` helper path. Treat this as a compiler deleting-destructor size operand for the shared default dialog family.
- Decimal `0x278` is 632 bytes. Message-dialog wrapper docs confirm `0x278` allocation for `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `TextDialog`, and `NexonclubProxyDialog` constructor paths.
- High-probability inference: the menu-dialog consumers that share this same scalar deleting wrapper also have the same default dialog object size, or at minimum share the compiler-emitted deleting-destructor size contract.
- Do not infer that every object with allocation size `0x278` uses this wrapper. The support docs contain unrelated classes with `+0x278` fields or same-sized allocations.

### Guard / Runtime Helper Path

- Local assembly names `0x0041b6a0` as `@_guard_check_icall_nop@4`, but the call site pushes two arguments and cleans 8 bytes. Treat the label as compiler/runtime-path evidence, not a stable source helper name.
- Recommended wording: "compiler/runtime guard-or-vector-delete helper path at `0x0041b6a0` with size operand `0x278`."
- This helper spelling should not block target finalization because no handwritten source should call it.

### Delete Wrapper / Base Destructor Behavior

- `0x004f4ac0` should be named [UID:000197] `OperatorDeleteWrapper` / global `operator delete` wrapper.
- `0x0049d9f0` should be named [UID:00012R] `DialogPane` cleanup / non-deleting destructor body, with an explicit note that local IDA's `boost::exception` label is polluted.
- The scalar wrapper always runs `DialogPane` cleanup before checking delete flags. Deallocation happens only on `flags & 1` without the `flags & 4` path in this body.

## Exact No-Code Proof

Do not emit this as C++. The following is only a proof sketch for why the binary body is compiler glue:

```cpp
// No source body: compiler-emitted scalar deleting destructor wrapper.
// Source responsibility is ordinary class/base destructor declarations.
void *compiler_generated_dialog_scalar_deleting_destructor(void *self, unsigned flags)
{
    DialogPane_non_deleting_destructor(self);        // 0x0049d9f0
    if ((flags & 1) == 0)
        return self;
    if ((flags & 4) != 0) {
        compiler_runtime_delete_helper(self, 0x278); // 0x0041b6a0, label unstable
        return self;
    }
    OperatorDeleteWrapper(self);                     // 0x004f4ac0
    return self;
}
```

This proof body must not be copied into a reconstructed source file. Equivalent binary code should be regenerated by the compiler from `DialogPane` and derived dialog class declarations.

## Recommended Target Doc Changes

### Metadata

Set the target header to:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the reconstruction C++ block blank.

### Behavior Wording

Replace the current behavior paragraph with:

```markdown
The wrapper saves `this`, calls [UID:00012R] `DialogPane` cleanup / non-deleting destructor at `0x0049d9f0`, then interprets the scalar deleting destructor flag argument:

- no `flags & 1`: return the object without freeing it;
- `flags & 1` and no `flags & 4`: pass the object to [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0`, then return it;
- `flags & 4`: call the compiler/runtime guard-or-vector-delete helper path at `0x0041b6a0` with size operand `0x278`, then return it.

Local IDA exports label the `0x0049d9f0` callee as `boost::exception::~exception`, but [UID:00012R] documents that label as polluted; the source-semantic callee is the common `DialogPane` cleanup body.

The body does not restore a class-specific vtable and has no ordinary callers. That makes it shared default scalar deleting destructor glue for the dialog classes listed below, not source-authored behavior for one class.
```

### Add Consumer Matrix

Add the "Complete Consumer / Thunk Matrix" table from this report to the target page, preferably after the IDA evidence list.

### Replace Score Rationale

Replace the score table with:

```markdown
| Score | Rationale |
| --- | --- |
| Completion `88` | Exact function boundary, scalar-delete flag behavior, ordinary destructor/delete/runtime callees, no ordinary callers, four adjustor-thunk routes, full primary vtable consumer matrix, no-code rebuild handling, and source declaration responsibilities are documented. Completion remains below final-audit levels only because the runtime helper label at `0x0041b6a0` is compiler/toolchain-specific and not useful as a source name. |
| Confidence `93` | IDA/export evidence, support docs, vtable data, and thunk pages agree this is shared compiler-generated deleting-destructor glue. Confidence stays below 95 because original source can only declare the owning classes/destructors; the compiler-emitted wrapper has no stable handwritten source spelling. |
```

### Cross-References To Add

Add these cross-references if missing:

```markdown
- [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
```

## Exact Support-Doc Updates

These are recommendations only; this report did not edit support docs.

### `by-memory/-ignored.md`

Replace the existing `0x00520aa5-0x00520abb` / `0x00520b70-0x00520bab` evidence block with:

```markdown
- `0x00520aa5-0x00520abb` and `0x00520b70-0x00520bab` - shared default dialog destructor glue.
  - Why ignored: compiler-generated/shared default destructor thunks and scalar deleting destructor body reused by dialog vtables; not handwritten `PursuitMessageDialogPane`, message-dialog, text-dialog, proxy-dialog, or merchant-menu behavior.
  - Evidence: [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md), [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md), and [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) record the exact thunk/body evidence. Primary vtable consumers are `MerchantDialogPane`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, `ArgumentedMenuMenuDialog`, `PursuitMessageDialogPane`, `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `TextDialog`, and anonymous `NexonclubProxyDialog`; secondary/tertiary views route through `this - 0xa0` and `this - 0xa4` thunks.
  - Replacement/procurement: no source replacement; generated by the compiler from `DialogPane`-derived class declarations/default destructors. The ordinary cleanup body belongs to [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md), and deallocation routes through [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md).
  - Owner docs: [UID:0000IT][DialogPane](by-file/DialogPane.md), [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), [UID:0000OL][TextDialog](by-file/TextDialog.md), and [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
```

### [UID:0001BW] Early Thunks

Add:

```markdown
- 2026-06-19 B007 source-quality pass: [UID:0001C0] now carries the complete primary consumer matrix. These early thunks serve secondary/tertiary vtable views for `MerchantDialogPane`, item/spell/argumented menu dialogs, `PursuitMessageDialogPane`, `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, and `TextDialog`; the later `NexonclubProxyDialog` copy remains in [UID:00023N].
```

### [UID:00023N] Late Thunks

Add:

```markdown
- 2026-06-19 B007 source-quality pass: this late thunk pair is the `NexonclubProxyDialog` secondary/tertiary copy of the same default-dialog destructor route. Primary proxy vtable `0x00622c58` points directly to [UID:0001C0], while `0x00622cb8` and `0x00622ce8` use `this - 0xa0` / `this - 0xa4` before the shared scalar deleting destructor.
```

### [UID:00012R] / [UID:0000IT] `DialogPane`

Add to the destructor evidence:

```markdown
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) calls this `0x0049d9f0` cleanup body before scalar-delete flag handling. The local IDA `boost::exception` label remains polluted; source semantics are common `DialogPane` cleanup shared by default dialog destructors.
```

### [UID:000197] `OperatorDeleteWrapper`

Add:

```markdown
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) is a representative scalar deleting destructor caller: when `flags & 1` is set and the `flags & 4` compiler/runtime path is not taken, it passes the object pointer to this wrapper.
```

### Dialog Source/File Pages

Add the matching bullet to each owner file:

```markdown
- Shared default destructor note: the primary vtable slot for this dialog class uses [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), with secondary/tertiary slots routed through [UID:0001BW] or [UID:00023N] adjustor thunks. This is compiler-generated deleting-destructor glue; source reconstruction should declare/default the dialog destructor and rely on [UID:0000IT] `DialogPane` for ordinary cleanup, not hand-port the wrapper.
```

Recommended recipients: [UID:0000L9] `MerchantDialogPane`, [UID:0000KF] `ItemMenuDialogs`, [UID:0000O2] `SpellMenuDialogs`, [UID:0000HI] `ArgumentedMenuDialogs`, [UID:0000LA] `MessageDialogs`, [UID:0000OL] `TextDialog`, and [UID:0000LZ] `NexonclubProxyDialog`. For [UID:0000LZ], use [UID:00023N] as the secondary/tertiary thunk route; for the rest, use [UID:0001BW].

### [UID:0001Y5] `MerchantMenuDialogVtableFamily`

Add:

```markdown
- Default destructor split: [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) is the primary scalar deleting destructor slot for `MerchantDialogPane`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`; their secondary/tertiary destructor slots route through [UID:0001BW]. Adjacent `TextMenuDialog`/`TextInputMenuDialog` are not included in this exact primary-slot consumer set.
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during the B-agent report pass. If accepted, replace the existing row with exactly:

```markdown
    - [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) 0x00520b70-0x00520bab | shared scalar deleting destructor | SharedDialogDefaultScalarDestructor : ignored : 88% : very strong : IDA/export-verified shared DialogPane-derived default scalar deleting destructor compiler glue; exact 0x3b boundary, no ordinary callers, four adjustor-thunk code refs, complete primary vtable consumer set (MerchantDialogPane, Server/Client ItemMenuDialog, Server/Client SpellMenuDialog, ArgumentedMenuMenuDialog, PursuitMessageDialogPane, MessageDialog, MessageDialogLarger, MenuQuestionDialog, MenuQuestionDialogLarger, TextDialog, NexonclubProxyDialog), secondary/tertiary thunk routes, DialogPane cleanup callee 0x0049d9f0, OperatorDeleteWrapper callee 0x004f4ac0, guard/size 0x278 branch, scalar-delete flags, and no-code rebuild policy documented.
```

## Validator Needs / Commands

Recommended validation once IDA MCP is reachable:

```text
lookup_funcs 0x00520b70
disasm 0x00520b70
decompile 0x00520b70
xrefs_to 0x00520b70
callers 0x00520b70
callees 0x00520b70
xrefs_to 0x00520aa5
xrefs_to 0x00520ab0
xrefs_to 0x005539c3
xrefs_to 0x005539ce
```

Recommended local/export/documentation checks:

> Executable block R001 was removed from this report and preserved verbatim in [0001C0-SharedDialogDefaultScalarDestructor-source-quality-removed.md](0001C0-SharedDialogDefaultScalarDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator expectations:

- Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank C++ even though the average score is above the final-source numeric gate; no-code compiler artifacts are excluded by classification.
- Confirm no generated source file contains a hand-authored `SharedDialogDefaultScalarDestructor`, `sub_520B70`, or equivalent source body.
- Allow source owner pages to reference this wrapper as vtable/layout evidence only.

## Open Questions / Resolved Non-Blockers

- Runtime helper name at `0x0041b6a0`: leave as compiler/runtime guard-or-vector-delete helper path. Exact source spelling is not needed because this wrapper is no-code.
- Original physical file split for all consuming class declarations: not a target blocker. The owning file/class pages handle final source split; [UID:0001C0] remains ownerless compiler glue.
- Local IDA `boost::exception` label: resolved as polluted. Use `DialogPane` cleanup semantics from [UID:00012R].
- Compiler-generated name: use `SharedDialogDefaultScalarDestructor` only as documentation title. Do not introduce this as a source symbol.

## Implementation Readiness

- Ready for supervisor implementation callback as documentation-only changes.
- No first-draft C++ should be emitted. The exact no-code proof is sufficient and stronger than source-bearing reconstruction.
- Target/support changes above are precise enough to apply without further research. The only optional validation improvement is a live IDA MCP rerun when the endpoint is available.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001C0-SharedDialogDefaultScalarDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0001C0"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001C0-SharedDialogDefaultScalarDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001C0-SharedDialogDefaultScalarDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001C0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
