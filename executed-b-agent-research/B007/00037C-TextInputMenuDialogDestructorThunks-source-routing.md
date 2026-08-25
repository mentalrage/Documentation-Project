** TARGET-REPORT-UID:00037C **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00037C **
# B007 Source-Routing Report: [UID:00037C] TextInputMenuDialogDestructorThunks

Report-only assignment. I did not edit the target by-memory page, support by-* pages, or `by-memory/-coverage-report.md`.

## Target

- Target doc: `source-3/project-documentation/by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00037C-TextInputMenuDialogDestructorThunks-source-routing.md`
- Current target metadata: `COMPLETION:83`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.

## Executive Recommendation

Keep [UID:00037C] as exact no-code compiler-generated destructor adjustor glue. Do not assign an emitting owner and do not write C++ for the two thunk functions.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Source-facing responsibility belongs to [UID:0000ER] `TextInputMenuDialog` in [UID:0000OP] `TextMenuDialogs`: declare/model the ordinary `TextInputMenuDialog::~TextInputMenuDialog()` and class inheritance/member layout so MSVC can regenerate the secondary and tertiary deleting-destructor adjustor thunks. The source should not expose `sub_520B29`, `sub_520B34`, or `ScalarDeletingDestructor` as handwritten method names.

## Evidence Checked

- Read target doc [UID:00037C].
- Read support docs:
  - `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
  - `by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md`
  - `by-class/TextInputMenuDialog.md`
  - `by-file/TextMenuDialogs.md`
  - `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
  - `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`
  - `by-type/by-vtable/TextMenuDialogVtables.md`
  - `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
  - `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
  - neighboring thunk docs `0001BZ`, `00037E`, `00037G`
- Checked local IDA exports:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- Checked generated source-quality problem:
  - `source-3/simroot_v2/class_TextInputMenuDialog.cpp`
  - `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`
- Checked `by-memory/-coverage-report.md`: no standalone [UID:00037C] row is currently present; it is only hidden under broader ignored/glue coverage.
- Tried live IDA MCP at `http://127.0.0.1:13337/mcp`; it was unavailable in this session (`Unable to connect to the remote server`). Prior live MCP evidence already recorded in support docs remains consistent with the local exports.

## Exact Thunk Boundary And Behavior

The local IDA `.lst` export shows two adjacent 0x0b-byte functions:

```asm
00520B29 sub_520B29 proc near
00520B29 sub     ecx, 0A0h
00520B2F jmp     sub_520D50
00520B2F sub_520B29 endp

00520B34 sub_520B34 proc near
00520B34 sub     ecx, 0A4h
00520B3A jmp     sub_520D50
00520B3A sub_520B34 endp
```

The decompiler agrees:

```c
void **__thiscall sub_520B29(void **this, char a2)
{
  return sub_520D50(this - 40, a2);
}

void **__thiscall sub_520B34(void **this, char a2)
{
  return sub_520D50(this - 41, a2);
}
```

Resolved boundary:

| Range | Role | Source meaning |
| --- | --- | --- |
| `0x00520b29-0x00520b34` | secondary-vtable adjustor thunk | Adjusts `EventHandler`/secondary-subobject `this` from `+0xa0` back to the complete `TextInputMenuDialog`, then jumps to scalar deleting destructor `0x00520d50`. |
| `0x00520b34-0x00520b3f` | tertiary-vtable adjustor thunk | Adjusts `TimerHandler`/tertiary-subobject `this` from `+0xa4` back to the complete object, then jumps to `0x00520d50`. |

The target page range `0x00520b29-0x00520b3e` names the last byte as inclusive in the filename style; the half-open function coverage is `0x00520b29-0x00520b3f`. Neighboring docs are consistent: [UID:0001BZ] ends at `0x00520b29`, and [UID:00037E] starts at `0x00520b3f`.

## Vtable And RTTI Proof

The `.lst` vtable records identify the target thunks as `TextInputMenuDialog` vtable entries:

```text
0x0061ee0c ??_7TextInputMenuDialog@@6B@   -> sub_520D50
0x0061ee6c ??_7TextInputMenuDialog@@6B@_0 -> sub_520B29
0x0061ee9c ??_7TextInputMenuDialog@@6B@_1 -> sub_520B34
```

Constructor stores at `0x00519950`, `0x00519956`, and `0x00519960` write those three vptrs into the object at offsets `0`, `0xa0`, and `0xa4`.

RTTI confirms the inherited layout:

- `TextInputMenuDialog` class hierarchy has 8 base entries.
- Type descriptor comments show `EventHandler` at member displacement `160` (`0xa0`) and `TimerHandler` at displacement `164` (`0xa4`).
- Complete object locator `_0` has vtable offset `160`; `_1` has vtable offset `164`.

This resolves the source roles of the two thunks as secondary/tertiary vtable destructor adjustors. They are not ordinary call targets and should not become source methods.

## Scalar Deleting Destructor Target

The target thunks tail-jump to [UID:00037D] `0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor`.

Local `.lst` export for `sub_520D50`:

```asm
00520D56 lea     ecx, [esi+280h]
00520D5C call    sub_582B30
00520D61 mov     ecx, esi
00520D63 call    ??1exception@boost@@MAE@XZ_0
00520D6B test    al, 1
00520D6D jz      loc_520D91
00520D6F test    al, 4
00520D71 jnz     loc_520D83
00520D74 call    sub_4F4AC0
00520D83 push    284h
00520D89 call    @_guard_check_icall_nop@4
00520D95 retn    4
00520D98 align 10h
```

Local decompiler:

```c
void **__thiscall sub_520D50(void **Block, char a2)
{
  sub_582B30(Block + 160);
  boost::exception::~exception((boost::exception *)Block);
  if ((a2 & 1) == 0 || (a2 & 4) != 0)
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

Interpretation:

- `Block + 160` is byte offset `0x280`, matching the initialized extra/string-like member near the end of the `0x284`-byte object.
- The wrapper then calls the shared/base destructor routine currently named by IDA as `boost::exception::~exception`; the source-facing owner is the dialog base chain, not a `boost` source method on this class.
- The delete flag path calls `sub_4F4AC0(Block)` only when scalar delete bit `1` is set and vector/placement bit `4` is clear.
- The `0x284` size in the guarded branch matches `MenuDialogFactoryHelpers` allocation size for `TextInputMenuDialog`.

This is compiler-generated deleting-destructor output with the ordinary destructor body effectively inlined into the deleting wrapper. The source should model the ordinary destructor/inheritance/member cleanup, not hand-port the scalar wrapper.

## Source Placement And Ownership

Best-supported source placement:

1. [UID:0000ER] `TextInputMenuDialog` is the class context.
2. [UID:0000OP] `TextMenuDialogs` is the source file context.
3. [UID:0001BX] `MenuDialogDestructorThunks` remains the physical mixed compiler-glue aggregate.
4. [UID:00031Y] `TextMenuDialogVtables` and [UID:0001Y5] `MerchantMenuDialogVtableFamily` carry the vtable/source-owner evidence.

Rejected alternatives:

- Assign [UID:00037C] to [UID:0000ER] or [UID:0000OP] as an emitting child: rejected because the exact two functions are compiler adjustor thunks, not handwritten code.
- Merge [UID:00037C] into [UID:00037D]: rejected because the thunk pair has exact standalone function starts and secondary/tertiary vtable refs, while [UID:00037D] is the primary scalar deleting destructor wrapper.
- Merge [UID:00037C] into the broad [UID:0001BX] page only: rejected because exact child docs already exist and are useful for coverage and validator routing.
- Treat `sub_520B29`/`sub_520B34` as source-facing helper names: rejected; they are raw IDA names for compiler thunks.

## Source-Quality Inferences

Recommended source-facing declaration shape:

```cpp
class TextInputMenuDialog : public MerchantDialogPane {
public:
    virtual ~TextInputMenuDialog();

    TextInputMenuDialog(bool hasExtraString, const Rect& bounds,
                        const uint8_t* packet, uint8_t dialogType);
    void OnButtonPress(int controlId) override;
    void ValidateInput() override;

private:
    // offset 0x280, destroyed before the MerchantDialogPane/DialogPane base chain
    LObject m_extraText;
};
```

Notes:

- The exact parameter types above are source-quality guidance, not a replacement for the current target doc. The target thunk page should not emit this C++.
- The current `simroot_v2/class_TextInputMenuDialog.cpp` has a generated `TextInputMenuDialog::ScalarDeletingDestructor(int flags)` method. That is a stale compiler-generated-name artifact. Replace the source-facing concept with `~TextInputMenuDialog()` in class documentation and keep the scalar wrapper as no-code compiler glue.
- `sub_520B29` and `sub_520B34` are best named in IDA/comments as `TextInputMenuDialog` secondary/tertiary destructor adjustor thunks, not source methods.

## Open Questions And Resolutions

| Question | Resolution |
| --- | --- |
| Are the target boundaries exact? | Yes. Local `.lst` shows `sub_520B29` and `sub_520B34` as two adjacent 0x0b functions; previous and next child pages bound the range at `0x00520b29` and `0x00520b3f`. |
| Are the functions source-bearing? | No. Each function is only `sub ecx, offset; jmp scalar_deleting_destructor`; no locals, no branch logic, no source behavior. |
| Which scalar deleting destructor is targeted? | `0x00520d50` [UID:00037D], primary `TextInputMenuDialog` deleting destructor. |
| Which vtables reference the thunks? | Secondary `TextInputMenuDialog` vtable `0x0061ee6c` references `0x00520b29`; tertiary `0x0061ee9c` references `0x00520b34`. |
| What are the adjusted subobjects? | High confidence: inherited `EventHandler` at offset `0xa0` and `TimerHandler` at `0xa4`, from RTTI comments and complete-object-locator offsets. |
| Where should ordinary destructor placement be documented? | On [UID:0000ER] `TextInputMenuDialog` and [UID:00037D], as source responsibility for `~TextInputMenuDialog()`/member cleanup, while [UID:00037C] stays no-code. |
| Should the target get an emitter? | No. Keep `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:FALSE`; reference `TextInputMenuDialog` only as context. |

## Recommended Exact By-* Implementation Checklist

### Target: `by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md`

- Change score to `88/92`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Add a covered-range table:

```markdown
| Range | IDA body | Source role |
| --- | --- | --- |
| `0x00520b29-0x00520b34` | `sub ecx, 0xa0; jmp 0x00520d50` | Secondary/EventHandler-subobject destructor adjustor thunk for `TextInputMenuDialog`. |
| `0x00520b34-0x00520b3f` | `sub ecx, 0xa4; jmp 0x00520d50` | Tertiary/TimerHandler-subobject destructor adjustor thunk for `TextInputMenuDialog`. |
```

- Add exact no-code proof:

```markdown
These are MSVC-generated vtable adjustor thunks. They contain no source logic beyond adjusting `this` from inherited subobject offsets `0xa0` and `0xa4` back to the complete `TextInputMenuDialog` object and tail-jumping to the scalar deleting destructor at `0x00520d50`. Rebuild through the `TextInputMenuDialog` class declaration/destructor and inherited `EventHandler`/`TimerHandler` layout; do not hand-port `sub_520B29` or `sub_520B34`.
```

- Add vtable evidence:

```markdown
Constructor `0x005198e0` stores `TextInputMenuDialog` vptrs at object offsets `0`, `0xa0`, and `0xa4` from `0x00519950`, `0x00519956`, and `0x00519960`. The corresponding vtables are `0x0061ee0c` -> `0x00520d50`, `0x0061ee6c` -> `0x00520b29`, and `0x0061ee9c` -> `0x00520b34`. RTTI complete-object locators record vtable offsets `160` and `164`, matching the thunk adjustments.
```

### Support: `by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md`

- Recommended score after implementation: `88/92`.
- Keep no-code/non-emitting metadata.
- Add scalar target details:

```markdown
The scalar deleting destructor performs the actual generated teardown body for `TextInputMenuDialog`: it destroys the member at byte offset `0x280` via `sub_582B30`, calls the shared/base dialog destructor currently named by IDA as `boost::exception::~exception`, and conditionally deletes the complete object with `sub_4F4AC0` when the scalar-delete flag is set and flag `4` is clear. The guarded branch uses object size `0x284`, matching the factory allocation size for `TextInputMenuDialog`.
```

- Add source-policy note:

```markdown
There is no separate source-facing `ScalarDeletingDestructor` method. The source model should declare/define `TextInputMenuDialog::~TextInputMenuDialog()` as part of the class, with compiler-generated deleting-destructor wrappers left blank.
```

### Support: `by-class/TextInputMenuDialog.md`

- Add/adjust the destructor row:

```markdown
| Source destructor | `~TextInputMenuDialog` | Source-level ordinary destructor responsibility; compiler emits primary scalar deleting destructor `0x00520d50` plus secondary/tertiary adjustor thunks `0x00520b29`/`0x00520b34`. |
```

- Add source-quality note:

```markdown
Generated names such as `ScalarDeletingDestructor`, `sub_520B29`, and `sub_520B34` are compiler/IDA artifacts. Source reconstruction should expose `~TextInputMenuDialog()` and the inherited `EventHandler`/`TimerHandler` subobject layout only.
```

### Support: `by-file/TextMenuDialogs.md`

- Add a migration note under `TextInputMenuDialog`:

```markdown
Destructor glue for `TextInputMenuDialog` is non-emitting compiler output: secondary/tertiary thunks at `0x00520b29`/`0x00520b34` and scalar deleting wrapper `0x00520d50`. The source file should carry the class destructor declaration/definition if needed, not source methods named after those wrappers.
```

### Support: `by-type/by-vtable/TextMenuDialogVtables.md`

- Add the first-slot mapping if not already considered sufficient:

```markdown
`TextInputMenuDialog` primary vtable `0x0061ee0c` starts with scalar deleting destructor `0x00520d50`; secondary `0x0061ee6c` starts with adjustor thunk `0x00520b29`; tertiary `0x0061ee9c` starts with adjustor thunk `0x00520b34`. Constructor stores at `0x00519950`, `0x00519956`, and `0x00519960` materialize the three views.
```

## Exact Pending Coverage Text

Insert this standalone child row in `by-memory/-coverage-report.md` after [UID:0001BZ] and before [UID:0001C0] if the supervisor accepts the implementation:

```markdown
    - [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) 0x00520b29-0x00520b3e | compiler thunk pair | TextInputMenuDialogDestructorThunks : ignored : 88% : strong : Compiler-generated TextInputMenuDialog secondary/tertiary destructor adjustor thunks; local IDA export and prior live MCP evidence confirm two exact 0x0b-byte bodies, `this` adjustments `0xa0`/`0xa4`, tail-jump target `0x00520d50`, secondary/tertiary vtable refs `0x0061ee6c`/`0x0061ee9c`, primary deleting-destructor slot `0x0061ee0c`, constructor vptr stores at `0x00519956`/`0x00519960`, and rebuild through normal `TextInputMenuDialog` destructor/inheritance declarations rather than handwritten thunk functions.
```

Optional stale parent aggregate coverage replacement, if the same implementation pass refreshes [UID:0001BX]:

```markdown
    - [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) 0x00520abb-0x00520e2b | destructor/thunk island | MenuDialogDestructorThunks : ignored : 87% : strong : Mixed compiler-generated destructor/thunk island; exact child pages route argumented/text-menu thunk pairs and scalar deleting destructors while neighboring client/spell/object-image/server-item glue remains separately documented/ignored; no single reconstructable source parent owns the whole physical span, so rebuild through owning class destructor declarations and leave the aggregate non-emitting.
```

## Validation Commands Needed

After supervisor-approved doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [00037C-TextInputMenuDialogDestructorThunks-source-routing-removed.md](00037C-TextInputMenuDialogDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

When IDA MCP is reachable, re-run:

```text
lookup_funcs 0x00520b29 0x00520b34 0x00520d50
get_bytes 0x00520b29 size 0x16
xrefs_to 0x00520d50
xrefs_to 0x0061ee0c
xrefs_to 0x0061ee6c
xrefs_to 0x0061ee9c
```

Expected results:

- `0x00520b29` and `0x00520b34` are 0x0b-byte functions.
- Bytes decode to `sub ecx,0xa0; jmp 0x00520d50; sub ecx,0xa4; jmp 0x00520d50`.
- `0x00520d50` is the primary scalar deleting destructor.
- Vtable refs match `0x0061ee0c`, `0x0061ee6c`, `0x0061ee9c`.

## IDA Rename / Type / Comment Recommendations

High confidence:

- `sub_520B29` -> `TextInputMenuDialog_EventHandler_dtor_adjustor_thunk`
- `sub_520B34` -> `TextInputMenuDialog_TimerHandler_dtor_adjustor_thunk`
- `sub_520D50` -> `TextInputMenuDialog_scalar_deleting_destructor`

Suggested types:

```c
void *__thiscall TextInputMenuDialog_scalar_deleting_destructor(TextInputMenuDialog *this, unsigned int flags);
void *__thiscall TextInputMenuDialog_EventHandler_dtor_adjustor_thunk(EventHandler *this, unsigned int flags);
void *__thiscall TextInputMenuDialog_TimerHandler_dtor_adjustor_thunk(TimerHandler *this, unsigned int flags);
```

Suggested comments:

- At `0x00520b29`: `Compiler adjustor thunk: ECX is TextInputMenuDialog+0xa0 EventHandler view; subtract 0xa0 and tail-jump to scalar deleting destructor.`
- At `0x00520b34`: `Compiler adjustor thunk: ECX is TextInputMenuDialog+0xa4 TimerHandler view; subtract 0xa4 and tail-jump to scalar deleting destructor.`
- At `0x00520d50`: `Compiler scalar deleting destructor for TextInputMenuDialog; destroys +0x280 member, base dialog chain, then optional delete for 0x284-byte object.`

Confidence is high for the adjustor offsets and class identity. The only caveat is the exact human names of the inherited secondary/tertiary interfaces; RTTI strongly indicates `EventHandler` and `TimerHandler`, but use comments rather than source declarations if the local type system is not ready.

## Implementation Readiness

Ready for supervisor implementation callback. This target has exact no-code proof, resolved source-owner routing, resolved scalar target behavior, resolved vtable refs, resolved inheritance offset meaning, and exact coverage text. No first-draft C++ should be emitted for [UID:00037C]; the only source-facing C++ belongs to the ordinary `TextInputMenuDialog` class destructor/declaration on the class/file pages.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00037C","source_path":"executed-b-agent-research/B007/00037C-TextInputMenuDialogDestructorThunks-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
