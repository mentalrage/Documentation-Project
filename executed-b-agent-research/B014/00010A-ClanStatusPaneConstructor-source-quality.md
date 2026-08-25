** TARGET-REPORT-UID:00010A **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00010A ClanStatusPaneConstructor Source-Quality Research

Assignment: `Agent-B014` / `00010A` / `ClanStatusPaneConstructor` source-quality reanalysis.

Primary target: [UID:00010A] `by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md`

Required mode: report-only. I did not edit `by-memory/-coverage-report.md`, by-memory docs, by-class docs, by-file docs, generated source, or the IDA database.

## Final Recommendation

- Raise [UID:00010A] from `84/90` to `87/91`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:00002K` and `EMITTER_UIDS:00002K`.
- Keep source placement through [UID:00002K] `ClanStatusPane` to [UID:0000I8] `NexusTK/social/Clan.cpp`.
- Populate the formal reconstruction block with a first-draft ordinary constructor, using `Pane(1)` / `PaneMode` once the enum spelling is accepted, ordinary child `new` expressions, `Pane::SetMode(1)`, a TextEditPane editable/active-mode call for the info child, and `m_rawAttributeDataLength = 0`.
- Keep [UID:00021B] `0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup` non-reconstructable compiler cleanup with no formal C++.

This target is now first-draft C++ ready. Remaining uncertainty is helper-name polish, not source ownership, source shape, or field identity.

## Evidence Status

Live IDA MCP was not reachable in this session. The MCP HTTP endpoint at `127.0.0.1:13337/mcp` refused connection, so I could not issue fresh live queries. I used the existing IDA-backed target/support docs plus local readonly prewave function exports for raw disassembly/decompile fallback. I did not use Wave2/Wave3 generated source as evidence.

Important current docs checked:

- Target [UID:00010A] constructor page.
- Parent [UID:00002K] `ClanStatusPane`.
- Source root [UID:0000I8] `Clan`.
- Cleanup [UID:00021B].
- Parser [UID:00010B], dispatcher [UID:00021C], frame/input [UID:00010C], rows [UID:00010G], refresh/show helpers [UID:00021O]/[UID:00021P]/[UID:00021Q]/[UID:00021R], destructor [UID:00030P].
- Singleton docs [UID:0002XG]/[UID:0002XH]/[UID:0002B5].
- Vtable docs [UID:0002MQ].
- Child class/raw constructor docs [UID:00002E]/[UID:00002H]/[UID:00002C]/[UID:00002L]/[UID:00021T]/[UID:0002NP].
- UI support docs for `Pane::Pane`, `Pane::SetMode`, `ListPane`, `TextEditPane`, and `IsLegacyAssetMode`.

## Source-Facing Constructor Shape

The source-facing method is:

```cpp
ClanStatusPane::ClanStatusPane()
```

It is an ordinary default constructor. The decompiler-style `int __thiscall sub_484030(int this)` / `return this` shape is compiler/decompiler artifact. The initial call to `0x00544460` is the base initializer `Pane::Pane(unsigned char mode)` / `Pane::Pane(PaneMode mode)` with argument `1`, not a source body call.

The singleton write at `0x00484079/0x00484080` is source:

```cpp
g_pClanStatusPane = this;
```

The decompiler's `this == -248` branch is an adjusted-base artifact from `lea eax, [this+0xf8]; add eax, -0xf8`; it is not a source null check and should not be emitted.

The vtable stores for `ClanStatusPane`, `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` are compiler mechanics from constructing the parent and inlined child constructors. They should be represented by class declarations and constructors, not handwritten vtable assignments.

## Constructor State And Field Names

Accepted source-facing field names:

| Offset | Name | Evidence |
| --- | --- | --- |
| `+0x2510` | `m_infoListPane` | Constructed/stored by this constructor; consumed by parser/refresh/show-info/destructor docs. |
| `+0x2514` | `m_joinListPane` | Constructed/stored by this constructor; consumed by parser/refresh/show-join/destructor docs. |
| `+0x2518` | `m_enlistListPane` | Constructed/stored by this constructor; consumed by parser/refresh/show-enlist/destructor docs. |
| `+0x14e` | `m_rawAttributeDataLength` | Constructor clears it to zero; [UID:00010B] parser later sets and uses it as the raw attribute payload length. |

Fields at `+0xf8`, `+0xf9`, `+0xfa`, status text slots, and management text slots are now resolved by the parser/frame/row reports, but this constructor range does not explicitly initialize them. Do not invent constructor writes for `m_currentClanStatusView`, `m_statusDataVersion`, `m_selectedStatusRow`, or row text storage here.

## Inline Child Construction

The inline setup in this constructor is the correct source reconstruction anchor for runtime construction, but the source expression should remain ordinary child construction. The likely source is parameterless child `new`, with fixed child/base dimensions inside child constructors that the compiler inlined into the parent constructor.

| Child field | Binary allocation/setup | Source-facing shape |
| --- | --- | --- |
| `m_infoListPane` | Allocates `0x174` bytes; calls `TextEditPane` construction with `156,192,156,192,128,0,0,1,2,IsLegacyAssetMode(),1,0`; installs `ClanInfoListPane` vtables; stores at `+0x2510`; calls `Pane::SetMode(1)`; calls `TextEditPane` editable/active setter with `(0,0)`. | `m_infoListPane = new ClanInfoListPane; m_infoListPane->SetMode(1); m_infoListPane->SetTextEditMode(FALSE, FALSE);` with final helper spelling coordinated with TextEditPane docs. |
| `m_joinListPane` | Allocates `0x14c` bytes; calls `ListPane` construction with `32,128,156,24,0,1,1`; installs `ClanJoinListPane` vtables; stores at `+0x2514`; calls `Pane::SetMode(1)`. | `m_joinListPane = new ClanJoinListPane; m_joinListPane->SetMode(1);` |
| `m_enlistListPane` | Allocates `0x14c` bytes; calls `ListPane` construction with `32,128,156,24,0,1,1`; installs `ClanEnlistListPane` vtables; stores at `+0x2518`; calls `Pane::SetMode(1)`. | `m_enlistListPane = new ClanEnlistListPane; m_enlistListPane->SetMode(1);` |

Important wording correction: the target currently says the children are "shown". The direct helper at `0x005446b0` is now accepted as [UID:0002V7] `Pane::SetMode(unsigned char)`, not `Pane::Show`. `Pane::Show` is a separate method at `0x00544730`. The constructor should say the children are put into pane mode/state `1`, not that it calls `Show`.

The `0x0058ea80` helper is a TextEditPane editable/active mode setter. Local prewave fallback decompile shows it toggles TextEditPane flags at `+0x15c`, updates focus/IME-like state through `0x00544ea0` and `0x004e80a0`, then refreshes text invalidation through `0x00591300` or `0x00591370`. Existing StaticText docs independently describe `(0,0)` as disabling editing/activation. Therefore the info child call should be represented as a read-only/inactive text-edit mode setup, with exact method spelling deferred to TextEditPane naming.

## Separate Child Constructor Pages

No child page split or ownership change is needed.

- [UID:00021T] `0x004885a0-0x00488602.ClanInfoListPaneRawConstructor` remains a constructor-shaped raw island with no IDA function and no inbound start xrefs. It matches the inlined TextEditPane/base/vtable construction shape and can stay as evidence for a source-authored `ClanInfoListPane::ClanInfoListPane`, but it should keep formal C++ blank until callable/reachability policy is settled.
- [UID:0002NP] `0x00488630-0x00488674.ClanStringListPaneRawConstructor` likewise remains raw evidence for shared list construction, not a parent-constructor split.
- `ClanJoinListPane` and `ClanEnlistListPane` have only the inline construction evidence in this parent constructor. That supports inlined trivial/fixed constructors, not a need to move the parent constructor bytes to child pages.

The parent constructor's source should use ordinary `new ChildPane` expressions. The fixed `TextEditPane`/`ListPane` numeric arguments should be documented as child constructor/base initializer evidence, not emitted as handwritten parent vtable/base-constructor code.

## Failure Paths And Constructor Unwind

The `operator new` failure branches in the decompilation store null child pointers and then continue into `Pane::SetMode` / TextEditPane setup. This is MSVC new-expression lowering and exception/unwind scaffolding, not proof of source-authored manual null-check handling. The first-draft source should not add manual `if (ptr)` blocks unless a broader project allocator convention later requires it.

[UID:00021B] is the constructor-unwind cleanup for partially constructed `ClanStatusPane` children:

- It restores `ClanStatusPane` vtables.
- It deletes constructed children at `+0x2510`, `+0x2514`, and `+0x2518`.
- It clears `g_pClanStatusPane`.
- It tail-jumps to base `Pane` teardown.

That is compiler-generated EH cleanup for this constructor, not a source method. It should remain `RECONSTRUCTABLE:FALSE`, owner `NONE`, no emitters, no C++ block. It is explained by the ordinary constructor plus destructor/child ownership declarations.

## Relationship To Parser And Dispatcher Work

The accepted parser/dispatcher source-quality updates remove the previous constructor field-name uncertainty:

- [UID:00010B] `ParseClanStatusAttributePacket` confirms `+0x14e` is `m_rawAttributeDataLength`; the constructor's final word clear is exactly `m_rawAttributeDataLength = 0`.
- [UID:00010B], [UID:00021O], and [UID:00021P/Q/R] all use the same child fields `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane`.
- [UID:00021C] dispatcher remains formal-C++ blank because inline dialog construction source shape is not fully settled. That does not block this constructor: this constructor only creates the three status child panes and initializes the raw attribute length.

The constructor's field names should be synchronized with the parser/dispatcher docs rather than carrying separate local names.

## Ranked Ownership

1. [UID:00002K] `ClanStatusPane`: accepted. This is a class constructor that initializes the class singleton, child fields, and parent-owned status panel state.
2. [UID:0000I8] `Clan`: accepted as file/source route, rejected as direct canonical owner because the class page is the narrower semantic owner and clears the gate.
3. Child classes `ClanInfoListPane`, `ClanJoinListPane`, `ClanEnlistListPane`, `ClanStringListPane`: rejected as direct owners for this range. The parent constructor inlines/lowers child construction, but the storage and lifecycle belong to `ClanStatusPane`.
4. `ClanDialogs`, `ClanBank`, packet parser/dispatcher helpers, global singleton pages, and vtable data pages: rejected. They are dependencies, adjacent code, or support data, not the constructor owner.
5. Compiler/EH ownership: rejected for [UID:00010A], accepted only for [UID:00021B] cleanup and vtable/scalar-deleting mechanics.

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence checked | Rejected alternatives | Best inference / decision | Score impact |
| --- | --- | --- | --- | --- |
| Constructor signature | Target decompile/disasm; PaneCore docs identify `0x00544460` as `Pane::Pane(unsigned char mode)`; constructor has no source parameters besides `this`. | `int __thiscall sub_484030(int)` and source `return this`. | Source signature is `ClanStatusPane::ClanStatusPane()`, with base initializer `Pane(1)` / `Pane(PaneMode_Normal)` once enum names are accepted. | Raises completion. |
| Singleton write | Target disasm writes `0x0067ade4`; singleton docs tie `g_pClanStatusPane` to constructor, cleanup, destructor, and clan helpers. | Decompiler `this == -248` null check; storing an interior `this+0xf8` subobject. | Source is `g_pClanStatusPane = this;`; adjusted-base branch is compiler/decompiler artifact. | Raises confidence. |
| Vtable stores | Target and [UID:0002MQ] vtable refs show parent and child vtable stores. Destructor/cleanup mirror stores. | Handwritten vtable assignment source; ownership by vtable data page. | Vtable stores are compiler mechanics from constructor/declarations and inlined child constructors. | Raises source-quality confidence. |
| Child fields | Parser/refresh/show/destructor docs all agree on `+0x2510/+0x2514/+0x2518`; constructor stores only these child pointers. | Generic `m_child1/m_child2/m_child3`; assigning fields to child owner pages. | Use `m_infoListPane`, `m_joinListPane`, `m_enlistListPane`. | Resolves assignment focus. |
| Tail field clear | Parser [UID:00010B] uses `+0x14e` as raw attribute data length; constructor clears the word. | Unnamed tail state, selected row, packet version, arbitrary padding. | Source is `m_rawAttributeDataLength = 0;`. | Raises completion. |
| `Pane::SetMode` call | [UID:0002V7] formal C++ accepts `Pane::SetMode(unsigned char)` for `0x005446b0`; `Pane::Show` is separate at `0x00544730`. | "Shows it" wording; `SetVisible`; `SetEnabled`. | Constructor calls `SetMode(1)` on each child. Use enum later if names stabilize. | Corrects target wording. |
| TextEditPane `(0,0)` setup | Existing StaticText docs say disables editing/activation; prewave fallback decompile toggles TextEditPane flags and updates invalidation/focus state. | `SetPosition(0,0)`; generic layout update; source omission. | Info child is put into read-only/inactive text-edit mode after `SetMode(1)`. Exact method spelling remains a TextEditPane support issue. | Does not block first draft. |
| Inline vs child constructor source | Raw child constructor docs show no IDA function/xrefs at `0x004885a0` / `0x00488630`; target bytes inline the same construction. | Move parent bytes into child pages; write parent as manual `operator new` + vtable stores; discard child raw pages. | Source likely wrote ordinary child constructors; compiler inlined/folded them into parent. Keep child raw pages as evidence, not formal parent splits. | Resolves open shape question. |
| Allocation failure paths | MSVC constructor lowering uses EH state local `[ebp-4]` and null branches around in-place construction. Cleanup fragment handles partial construction. | Source-authored manual null checks; explicit calls on null object by design. | Use ordinary `new` expressions. EH/new lowering and cleanup UID `00021B` explain the binary branches. | Supports C++ readiness. |
| Cleanup UID `00021B` | Cleanup page mirrors child deletion/destructor, no function object, no direct source call route. | Reconstruct as `ClanStatusPane::CleanupConstructorFailure`; merge into constructor source block. | Keep non-reconstructable compiler unwind glue with no code. | No score raise needed for `00021B`; it is already correctly classified. |
| Parser/dispatcher relationship | B012 accepted parser field names and dispatcher no-code choice. | Keep constructor-local field names unresolved; let dispatcher uncertainty block constructor. | Parser validates constructor fields; dispatcher dialog uncertainty is unrelated to this constructor's source. | Raises completion. |
| C++ readiness | Target avg after recommendation is `(87+91)/2 = 89`; owner/emitter route is valid; source shape is ordinary constructor. | Leave code blank because helper enum/name polish remains; emit decompiler scaffolding. | First-draft C++ is ready, with helper names documented as draft spelling. | Main reason for score raise. |

## First-Draft C++ Recommendation

Recommended formal block:

```cpp
ClanStatusPane::ClanStatusPane()
    : Pane(1)
{
    g_pClanStatusPane = this;

    m_infoListPane = new ClanInfoListPane;
    m_infoListPane->SetMode(1);
    m_infoListPane->SetTextEditMode(FALSE, FALSE);

    m_joinListPane = new ClanJoinListPane;
    m_joinListPane->SetMode(1);

    m_enlistListPane = new ClanEnlistListPane;
    m_enlistListPane->SetMode(1);

    m_rawAttributeDataLength = 0;
}
```

Notes for the supervisor/apply pass:

- `Pane(1)` can later become `Pane(PaneMode_Normal)` if the shared enum lands.
- `SetTextEditMode(FALSE, FALSE)` is the recommended draft spelling for the `0x0058ea80` TextEditPane editable/active setter. If TextEditPane support chooses a different method name, only that spelling needs adjustment.
- Do not include explicit vtable writes, `operator new` temporaries, EH state locals, null branches, or `return this`.
- Do not emit child constructor fixed numeric arguments in the parent body. Preserve them in child constructor/support docs.

## Support Changes To Apply

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00002K
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002K
```

Recommended target documentation edits:

- Replace "not final-source complete because constructor-local field names and final source text remain below the code-emission gate" with a statement that first-draft source is ready, with only helper enum/method spelling still provisional.
- In the inline child table, replace "shows it" with "`Pane::SetMode(1)`".
- For the info child, describe `0x0058ea80(info, 0, 0)` as TextEditPane read-only/inactive editable/active mode setup, not layout/position.
- Add explicit field names `m_infoListPane`, `m_joinListPane`, `m_enlistListPane`, and `m_rawAttributeDataLength`.
- Add a source-shape note that child constructor bodies appear inlined; parent source should be ordinary child `new` expressions.
- Add a cleanup note that [UID:00021B] stays non-reconstructable compiler unwind glue.

No recommended metadata change for [UID:00021B]. Its current `84/88`, `RECONSTRUCTABLE:FALSE`, owner `NONE`, no-emitter status is correct.

## Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. If applying this report, replace the current [UID:00010A] row with:

```text
    - [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md) : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis resolves source-facing signature as `ClanStatusPane::ClanStatusPane()`, keeps direct owner/emitter [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), names child fields `m_infoListPane`/`m_joinListPane`/`m_enlistListPane` at `+0x2510/+0x2514/+0x2518`, ties final `+0x14e` clear to `m_rawAttributeDataLength = 0`, validates `g_pClanStatusPane` singleton write and ClanStatusPane/list-pane vtable stores as source declaration/inlined-constructor compiler mechanics, corrects child setup from "show" to `Pane::SetMode(1)` plus TextEditPane read-only/inactive setup, treats UID:00021B cleanup as non-reconstructable constructor-unwind glue, and marks first-draft constructor C++ ready using ordinary child `new` construction while preserving documented fixed TextEditPane/ListPane layout arguments.
```

No coverage replacement is required for [UID:00021B] unless a later pass wants to mention this report; its existing compiler-cleanup row is already semantically correct.

## Residual Risk

- Live IDA MCP was unavailable in this session, so this report cannot claim a new live xref/function audit beyond the existing IDA-backed docs and readonly prewave fallback exports.
- Exact final enum name for `Pane` mode value `1` remains open.
- Exact original name for TextEditPane helper `0x0058ea80` remains open. The behavior and arguments are strong enough for first-draft source, but the method spelling should be aligned when TextEditPane receives a dedicated source-quality pass.
- The raw child constructor pages should remain blank until the project decides how to handle unreachable constructor-shaped islands. This does not block the parent constructor source because the parent can express them as ordinary inlined child constructors.

## Files Changed

- Added this report only:
  - `tools/leaser/Agents/Agent-B014/research/00010A-ClanStatusPaneConstructor-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00010A-ClanStatusPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00010A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
