** TARGET-REPORT-UID:00000B **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00000B AlertPane Source-Quality Research

## Finalized Report / Current Recommendation

Assignment: `B002-goal2-alertpane-source-quality-00000B-20260617`.

Primary target: [UID:00000B] `by-class/AlertPane.md`, current `82/90`, owner/emitter [UID:0000HE] `AlertPanes`.

Recommendation:

- Raise [UID:00000B] `AlertPane` to `88/92`.
- Keep direct owner and emitter [UID:0000HE] `AlertPanes`; generated route remains `NexusTK/ui/dialogs/AlertPanes.cpp`.
- Populate the formal C++ block on [UID:00000B] with a class declaration only. Do not add constructor or method bodies to the class page.
- Update support pages [UID:00012W], [UID:0001WZ], [UID:0002M5], and [UID:00010W] with the resolved action/callback signature and compiler-wrapper policy. [UID:0000HE] `AlertPanes` should get a short no-score-change note; its broader BlueAlertPane/original-filename uncertainty still caps the file page.
- Keep feature-specific alert wrappers out of the base class. `CopyWindow`, `QuitDialog`, `ClanLeaveConfirmDialog`, `ExchangeAlertPane`, reconnect, and board/mail alert wrappers remain with their feature files.

No split is required. This is report-only B-agent work; no by-* docs, generated outputs, source files, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Target

- Target UID: [UID:00000B]
- Target path: `by-class/AlertPane.md`
- Current scores: `82/90`
- Current metadata: `CANONICAL_OWNER:0000HE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HE`
- Main method range: [UID:00012W] `0x0049feb0-0x004a0686.AlertPaneCore`
- Shared destructor support: [UID:00010W] `0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor`
- Vtable/layout support: [UID:0001WZ] `AlertPaneVtables`, [UID:0001TO] `AlertPaneLayout`, [UID:0002M5] `AlertPaneVtableData`

## Executive Recommendation

`AlertPane` is now source-ready enough for a class declaration. The remaining uncertainty is not whether the class belongs in `AlertPanes.cpp`, nor whether the primary/secondary callback slots exist. The remaining uncertainty is method-body detail: exact DialogPane/control helper declarations, exact inherited field names, and constructor local variable names.

Use these source-facing names/signatures:

- Constructor: `AlertPane(const wchar_t* messageText, Pane* layoutReference, const wchar_t* primaryButtonText, const wchar_t* secondaryButtonText)`.
- Action/dismiss virtual: `virtual void DismissDialog(int buttonId, int unused)`.
- Primary callback virtual: `virtual void OnPrimaryButton()`.
- Secondary callback virtual: `virtual void OnSecondaryButton()`.
- Alert-local field at `+0x26c`: `Pane* m_layoutReference` or `Pane* m_layoutPane`. Prefer `m_layoutReference` for now because the pointer is consumed as an anchor/layout reference, not as an owning parent.

`DismissDialog` should keep its current documented name for this page. `OnDialogAction` / `OnButtonAction` is a valid behavior alias for cross-dialog framework notes, but it is not stronger than `DismissDialog` for this class because current target docs, generated active source, and behavior all use the dismiss/slide-close role. The ABI correction is important: it is not a one-argument source virtual in the binary. The function returns with `retn 8`; the first stack argument is the button id and the second is unused by `AlertPane`.

## Heuristic / Inference Reanalysis And Validation

### Constructor Shape

Best source-facing signature:

```cpp
AlertPane::AlertPane(
    const wchar_t* messageText,
    Pane* layoutReference,
    const wchar_t* primaryButtonText,
    const wchar_t* secondaryButtonText);
```

Evidence checked:

- Live IDA MCP `lookup_funcs` confirms `0x0049feb0` is a real function of size `0x6c5`, ending at `0x004a0575`.
- Current `xrefs_to 0x0049feb0` returns `96` constructor xrefs with no truncation, matching existing docs and proving shared infrastructure.
- Constructor stores `AlertPane` primary/secondary/tertiary vtables at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`.
- Existing [UID:00012X] VersatileAlertPane source-quality report shows `VersatileAlertPane` forwards four non-callback arguments to this base constructor and stores its callback separately at `+0x270`.
- Generated `simroot_v2/class_AlertPane.cpp` matches the four logical inputs and the layout/text/button construction flow; generated names were treated as leads, not authority.

Rejected alternatives:

- A feature-local constructor owner is rejected by 96 cross-subsystem xrefs and by `AlertPanes.cpp` family docs.
- A constructor signature using `char*` or narrow strings is rejected because the body measures/copies wide message text and creates wide text controls.
- A constructor-owned callback parameter is rejected; callback storage belongs to `VersatileAlertPane` at `+0x270`, not `AlertPane`.

### Action/Dismiss Virtual

Best source-facing method name/signature:

```cpp
virtual void DismissDialog(int buttonId, int unused);
```

Evidence checked:

- Live IDA MCP `analyze_function 0x004a0580` confirms size `0x106`.
- Disassembly checks `[ebp+arg_0]`, accepts only ids `1` and `2`, and returns with `retn 8`.
- No argument is pushed before the callback calls at `0x004a0661` and `0x004a0666`; callbacks are no-argument methods.
- The second action-handler argument is unused in this body, consistent with other dialog action handlers that carry an unused framework parameter.
- `xrefs_to 0x004a0580` reports only vtable/data refs, including the base AlertPane table entry at `0x00618b48`.

Rejected alternatives:

- `DismissDialog(int buttonId)` is rejected as an exact ABI signature because `retn 8` proves two stack arguments.
- `OnDialogAction` / `OnButtonAction` is rejected as the primary page name only because existing AlertPane documentation and generated active source already use `DismissDialog`; it remains a useful behavior alias.
- `Close()` or `Hide()` is rejected because the method also dispatches primary/secondary callback virtuals before closing.

### Primary And Secondary Callback Names

Best source-facing base names:

```cpp
virtual void OnPrimaryButton();
virtual void OnSecondaryButton();
```

Evidence checked:

- `AlertPane::DismissDialog` dispatches button id `1` to vtable slot `+0x5c` and button id `2` to slot `+0x60`.
- The base `AlertPane` vtable stores `0x0041b6a0` in both slots; live IDA shows this function is a one-byte `retn`, so the base callbacks are no-op extension points.
- `VersatileAlertPane` maps the same slots to `OnAccept` and `OnCancel` and reports callback values `1` and `0`.
- `UrlAlertPane` maps the primary slot to `OnConfirm` and leaves the secondary slot as the base no-op.
- `BlueAlertPane` has a local action handler that performs the same id `1` / id `2` slot dispatch.
- `CopyWindow`, `QuitDialog`, `ClanLeaveConfirmDialog`, and `ExchangeAlertPane` show derived or feature-local semantics that vary by class.

Rejected alternatives:

- Base `OnAccept` / `OnCancel` is rejected because `AlertPane` accepts arbitrary primary/secondary labels and derived classes do not all mean accept/cancel.
- Base `OnConfirm` / `OnCancel` is rejected because `UrlAlertPane` confirms only on primary, while `VersatileAlertPane` and clan/quit/copy wrappers use different feature terms.
- Passing `buttonId` to the callback virtuals is rejected by disassembly: no push occurs before either slot call.

### Layout Field Names

Best source-facing field:

- `+0x26c`: `m_layoutReference` with type direction `Pane*`.

Evidence checked:

- `AlertPane::AlertPane` stores the caller layout reference at `+0x26c` after dialog show/animation.
- `BlueAlertPane` uses the same offset for its layout reference.
- `VersatileAlertPane` and `UrlAlertPane` reuse the next tail offset `+0x270` for their own derived state; this supports `+0x26c` as the base AlertPane tail field.
- Inherited `+0x1fc`, `+0x200`, and `+0x204` fields are DialogPane control-list/default-selection state, not AlertPane-owned fields.

Rejected alternatives:

- `m_parentPane` is too strong; the pointer is an anchor/layout reference, not proven ownership.
- `m_owner` is rejected because feature owners are not stored here uniformly.
- Treating `+0x270` as an AlertPane base field is rejected by derived class evidence.

### Modal And Slide Animation Semantics

Best interpretation:

- Constructor creates controls, sets selection/default indices, shows the dialog, inserts the pane into modal/event dispatch tracking, and runs a five-step slide-in when visible.
- `DismissDialog` runs a five-step slide-out when visible, restores the final rect, dispatches the primary/secondary callback, then calls the pane-manager dismissal path.

Evidence checked:

- Live `DismissDialog` disassembly reads pane height from `+0x50 - +0x48`, calls virtual rect getters/setters, offsets the GrafPort region through `sub_5549D0`, repaints through the root/event context, sleeps `0x18` ms per step, then restores the original rect.
- Generated active source matches the five-step slide-in/out structure but has provisional global/control names.
- The constructor uses `g_screenWidth` / `g_screenHeight` final clamping even though generated comments also mention fixed `800x600`; prefer the documented global screen-dimension names.

Rejected alternatives:

- Treating the animation as feature-local is rejected; it is in the shared constructor/dismiss path and every `AlertPane` consumer inherits it.
- Treating the close path as immediate hide only is rejected; the visible path clearly animates and repaints first.

### Shared Destructor And Adjustor Thunks

Best source policy:

- Declare `virtual ~AlertPane()` in the class.
- Keep [UID:00010W] and [UID:00010V] as compiler-generated ABI evidence, not hand-authored source bodies.

Evidence checked:

- Live `lookup_funcs` confirms `0x0048c550` size `0x3b` and adjustor thunks `0x0048c315` / `0x0048c320` size `0xb`.
- `xrefs_to 0x0048c550` reports two code refs from the adjustor thunks and primary-vtable data refs for ClanLeaveConfirmDialog, AlertPane, BlueAlertPane, CopyWindow, and QuitDialog.
- Existing [UID:00010W] documents the delete-flag flow, `OperatorDeleteWrapper`, guard no-op path, and stale `boost::exception` / `TransferReplyAlert` label pollution.

Rejected alternatives:

- Hand-porting `ScalarDeletingDestructor` is rejected; this is compiler wrapper behavior.
- Assigning the destructor to Clan, CopyWindow, QuitDialog, or BlueAlertPane is rejected because the same wrapper is pooled across the alert family and is installed by the base/derived vtables.
- Modeling `0x0048c315` / `0x0048c320` as source methods is rejected; they are this-adjustor thunks for secondary and tertiary views.

### Derived Wrapper Boundaries

Best boundary:

- `AlertPanes.cpp` owns reusable `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane`.
- Feature-local alert wrappers stay with their feature source files.

Evidence checked:

- [UID:0000HE] already records explicit exclusions for `ExchangeAlertPane`, reconnect alerts, board/mail reply alerts, and `CopyWindow`.
- `CopyWindow` callbacks read and clear `g_pActiveTextEditPane`; this is TextEditPane/CopyWindow behavior, not shared AlertPane behavior.
- `QuitDialog` and `ClanLeaveConfirmDialog` send application/packet-specific actions from their callback slots.
- `ExchangeAlertPane` has its own `ExchangeDialog.cpp` route and singleton/helper semantics.
- `VersatileAlertPane` remains in `AlertPanes.cpp` because it is a generic callback-backed prompt, not feature-specific.

Rejected alternatives:

- Folding all alert-derived constructors/actions into the base class is rejected by feature-specific globals, packets, and singleton state.
- Moving `VersatileAlertPane` out of `AlertPanes.cpp` is rejected by generic callback semantics and source-family adjacency.
- Splitting `AlertPane` into a new standalone `AlertPane.cpp` is rejected because the current file root is already a documented shared alert family with valid output route.

### Generated Output And Existing Docs

Validation of existing docs:

- Existing docs correctly identify the shared owner route, constructor/dismiss ranges, vtable bases, layout reference at `+0x26c`, callback slots `+0x5c/+0x60`, and derived alert boundary concern.
- Existing docs are stale where they say final C++ is blank because of a `95/95` gate. Under the current B-agent gate, the class declaration is eligible when source-quality evidence supports it.
- Existing docs understate the exact `DismissDialog` ABI by documenting only the button id. The source-quality update should include the unused second parameter or explicitly record the ABI note.
- Generated `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp` is currently empty, while `simroot_v2/class_AlertPane.cpp` is useful but uses generated/provisional names. The formal class declaration should be the first source-quality output for this class.

## IDA MCP Facts

IDA session used:

- Session: `b003_00018a_ime_comp_20260617`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Hex-Rays ready: yes

Function lookup:

| Address | IDA name | Size | Meaning |
| --- | --- | --- | --- |
| `0x0049feb0` | `sub_49FEB0` | `0x6c5` | `AlertPane` constructor |
| `0x004a0580` | `sub_4A0580` | `0x106` | `AlertPane::DismissDialog` / action dispatch |
| `0x0048c550` | `sub_48C550` | `0x3b` | shared alert scalar deleting destructor |
| `0x0048c315` | `sub_48C315` | `0x0b` | secondary destructor adjustor thunk |
| `0x0048c320` | `sub_48C320` | `0x0b` | tertiary destructor adjustor thunk |
| `0x0041b6a0` | `@_guard_check_icall_nop@4` | `0x1` | base no-op callback / guard helper, one-byte `retn` |
| `0x004a0720` | `sub_4A0720` | `0x12` | `VersatileAlertPane::OnAccept` |
| `0x004a0740` | `sub_4A0740` | `0x12` | `VersatileAlertPane::OnCancel` |
| `0x00500c30` | `sub_500C30` | `0x40` | `BlueAlertPane` action dispatch |
| `0x00599ba0` | `sub_599BA0` | `0x2f` | `UrlAlertPane::OnConfirm` |
| `0x00554520` | `sub_554520` | `0x16` | `CopyWindow::OnAccept` |
| `0x00554540` | `sub_554540` | `0x0b` | `CopyWindow::OnCancel` |

Xref facts:

- `xrefs_to 0x0049feb0`: `96` constructor xrefs, no truncation.
- `xrefs_to 0x004a0580`: `15` data/vtable refs, including `0x00618b48`.
- `xrefs_to 0x0048c550`: `7` refs, including thunks and five primary-vtable data refs.
- `xrefs_to 0x0048c315` and `0x0048c320`: `5` data refs each from secondary/tertiary alert-family tables.
- `xrefs_to 0x004a0720`: one data ref at `0x00618c00`.
- `xrefs_to 0x004a0740`: one data ref at `0x00618c04`.
- `xrefs_to` the AlertPane vtable bases `0x00618b00`, `0x00618b68`, `0x00618b98`: constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`.

Behavior facts:

- `DismissDialog` tests `(buttonId - 1) <= 1`, so only ids `1` and `2` are handled.
- If visible, it performs the slide-out/repaint/sleep loop, restores the original rect, then dispatches the callback slot.
- Button id `1` calls `[vtable + 0x5c]`; button id `2` calls `[vtable + 0x60]`.
- `VersatileAlertPane::OnAccept` loads `[this + 0x270]`, pushes `1`, and calls callback slot `+0x0c`.
- `VersatileAlertPane::OnCancel` loads `[this + 0x270]`, pushes `0`, and calls callback slot `+0x0c`.
- `BlueAlertPane` action dispatch checks ids `1/2`, calls `[vtable + 0x5c/+0x60]`, and closes through the dialog close helper.
- `UrlAlertPane::OnConfirm` calls `ShellExecuteA` on `[this + 0x270]` and checks byte `+0x274`.
- `CopyWindow::OnAccept` calls `TextEditPane::SelectAll` through the active editor global and clears it; `OnCancel` only clears it.

Range and padding:

- [UID:00012W] remains exact at `0x0049feb0-0x004a0686`.
- Constructor body is `0x0049feb0-0x004a0575`; dismiss/action body is `0x004a0580-0x004a0686`; `0x004a0575-0x004a0580` is the modeled alignment gap between them.
- [UID:00010W] remains exact at `0x0048c550-0x0048c58b`, with existing docs recording five `0xcc` bytes before and after.
- [UID:0002M5] remains exact at `0x00618b00-0x00618ba0`, ending before `VersatileAlertPane` RTTI at `0x00618ba0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Recommendation |
| --- | --- | --- | --- |
| Class | [UID:00000B] `by-class/AlertPane.md` | Shared modal alert base | Raise to `88/92`; populate class declaration C++ |
| `0x0049feb0-0x004a0686` | [UID:00012W] `AlertPaneCore` | Constructor plus dismiss/action virtual | Raise to `88/91`; keep formal method-body C++ blank |
| `0x0048c550-0x0048c58b` | [UID:00010W] `AlertPaneSharedScalarDestructor` | Compiler scalar deleting destructor wrapper | Raise to `86/92`; keep formal C++ blank |
| `0x0048c315-0x0048c32b` | [UID:00010V] `AlertPaneAdjustorThunks` | Compiler this-adjustor thunks | No score change required; remains non-source glue |
| Vtable cluster | [UID:0001WZ] `AlertPaneVtables` | Source-level virtual table evidence | Raise to `88/92`; keep C++ blank |
| `0x00618b00-0x00618ba0` | [UID:0002M5] `AlertPaneVtableData` | Generated-binary vtable data | Raise to `86/92`; keep C++ blank |
| Layout | [UID:0001TO] `AlertPaneLayout` | Alert-family layout notes | No score change required; add `m_layoutReference` and ABI note |
| File root | [UID:0000HE] `AlertPanes` | Shared alert source file | No score change; add B002 note only |

## Ranked Ownership Analysis

### 1. [UID:0000HE] AlertPanes

Evidence for:

- Valid generated source root `NexusTK/ui/dialogs/AlertPanes.cpp`.
- File page already owns reusable AlertPane family classes.
- `AlertPane::AlertPane` has broad, cross-subsystem constructor fan-in.
- `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane` share DialogPane construction, vtables, modal/slide semantics, and destructor ABI patterns.

Evidence against:

- Exact original filename is inferred, not proven.
- `BlueAlertPane` still has reachability/source-shape caveats.

Decision: accepted. These caveats cap [UID:0000HE] but do not block the base class.

### 2. [UID:00003T] DialogPane / [UID:0000IT] DialogPane file

Evidence for:

- `AlertPane` is a `DialogPane` subclass and uses inherited control-list/modal/animation helpers.

Evidence against:

- Constructor installs AlertPane vtables and owns the alert-specific layout/button/callback behavior.
- `+0x26c` alert layout reference and slots `+0x5c/+0x60` are AlertPane-family extension points.

Decision: rejected as direct owner. Keep only as dependency/base class.

### 3. Feature-local alert files

Evidence for:

- Many consumers are feature dialogs.
- Some derived classes share the same destructor wrapper.

Evidence against:

- 96 constructor xrefs prove shared infrastructure.
- Feature-local derived wrappers have packet/singleton/editor/application state that does not belong to `AlertPane`.

Decision: rejected for base ownership. Keep feature-local wrappers with their feature files.

## Score / Metadata Recommendations

| UID | Current | Recommended | Metadata |
| --- | --- | --- | --- |
| [UID:00000B] `AlertPane` | `82/90` | `88/92` | Keep `CANONICAL_OWNER:0000HE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HE`; populate class declaration C++ |
| [UID:00012W] `AlertPaneCore` | `82/90` | `88/91` | Keep owner/emitter [UID:00000B]; formal C++ blank |
| [UID:00010W] `AlertPaneSharedScalarDestructor` | `82/90` | `86/92` | Keep owner/emitter [UID:00000B]; formal C++ blank |
| [UID:0001WZ] `AlertPaneVtables` | `86/90` | `88/92` | Keep owner/emitter [UID:00000B]; formal C++ blank |
| [UID:0002M5] `AlertPaneVtableData` | `82/90` | `86/92` | Keep owner/emitter [UID:00000B]; formal C++ blank |
| [UID:0000HE] `AlertPanes` | `85/88` | no score change | Add support note only |
| [UID:0001TO] `AlertPaneLayout` | `85/89` | no score change | Add support note only |
| [UID:00010V] `AlertPaneAdjustorThunks` | `85/90` | no score change | Non-source compiler glue |

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block on [UID:00000B] `AlertPane.md` with this class declaration. This is declaration-only output for the primary class page. Do not populate [UID:00012W], [UID:00010W], [UID:0001WZ], or [UID:0002M5] formal C++ blocks from this report.

```cpp
class AlertPane : public DialogPane
{
public:
    AlertPane(const wchar_t* messageText,
              Pane* layoutReference,
              const wchar_t* primaryButtonText,
              const wchar_t* secondaryButtonText);
    virtual ~AlertPane();

    virtual void DismissDialog(int buttonId, int unused);

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

    Pane* m_layoutReference;

    [[CHILDREN]]
};
```

Do not populate method bodies on [UID:00012W] yet. The constructor body is source-shaped and understood, but final source-quality method output still depends on shared `DialogPane` helper declarations, control-list field names, text measurement helpers, modal-list helper names, and repaint/global names across the dialog framework.

Do not populate compiler-wrapper C++ on [UID:00010W] or [UID:00010V]. The class declaration's virtual destructor is the correct source shape; the scalar deleting destructor and adjustor thunks should be regenerated by the compiler.

Do not populate literal vtable data C++ on [UID:0001WZ] or [UID:0002M5]. The final class declaration should generate the vtables.

## Support-Doc Update Recommendations

Update [UID:00000B] `by-class/AlertPane.md`:

- Replace the open callback-name question with the resolved descriptive names `OnPrimaryButton` and `OnSecondaryButton`.
- Change the dismiss/action signature note to `DismissDialog(int buttonId, int unused)` and mention the ABI `retn 8`.
- Add that `OnDialogAction` / `OnButtonAction` is a cross-dialog behavior alias, not the chosen AlertPane source name.
- Add the first-draft class declaration.
- Raise to `88/92`.

Update [UID:00012W] `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`:

- Raise to `88/91`.
- Replace the `95/95 source-emission gate` language with the current gate.
- Document exact `DismissDialog(int buttonId, int unused)` ABI, callback no-argument calls, and the `0x004a0575-0x004a0580` alignment gap.
- Keep method-body C++ blank for dependency reasons stated above.

Update [UID:0001WZ] `AlertPaneVtables.md` and [UID:0002M5] `AlertPaneVtableData.md`:

- Rename/explain primary slots `+0x5c/+0x60` as base `OnPrimaryButton` / `OnSecondaryButton` no-op extension points.
- Note `0x0041b6a0` is a one-byte `retn` no-op in this slot context.
- Remove stale `95/95` gate wording if present.

Update [UID:00010W] `AlertPaneSharedScalarDestructor.md`:

- Raise to `86/92`.
- Keep final C++ blank and explicitly tie the wrapper to `virtual ~AlertPane()` plus compiler-emitted scalar deleting destructor/thunks.

Update [UID:0001TO] `AlertPaneLayout.md`:

- Add `m_layoutReference` as the preferred base AlertPane field name for `+0x26c`.
- Add the `DismissDialog` ABI note.
- No score change required.

Update [UID:0000HE] `AlertPanes.md`:

- Add a no-score-change note that B002 resolved base AlertPane callback names/signatures and class declaration readiness.
- Keep the file score unchanged because broader file-level uncertainty remains.

## Exact Coverage Row Text

### `by-class/-coverage-report.md`

Replace the existing [UID:00000B] row with:

```markdown
- [UID:00000B][AlertPane](by-class/AlertPane.md) : reconstructable : 88% : strong : Shared modal alert base attached to `AlertPanes.cpp`; B002 2026-06-17 source-quality recheck resolves constructor/dismiss signatures, `DismissDialog(int buttonId, int unused)`, no-argument `OnPrimaryButton`/`OnSecondaryButton` vtable slots, button ids `1/2`, modal slide behavior, layout reference `+0x26c`, base no-op callback slots, shared scalar-destructor/thunk compiler policy, derived-wrapper boundaries, and final class declaration readiness.
```

### `by-file/-coverage-report.md`

No replacement row recommended for [UID:0000HE]. Keep the current `85%` row. If the supervisor adds a no-score-change note, it can mention the B002 AlertPane callback/signature resolution, but file-level scoring should not move on this class-only pass.

### `by-memory/-coverage-report.md`

Replace the [UID:00012W] row with:

```markdown
    - [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md) 0x0049feb0-0x004a0686 | class method cluster | AlertPaneCore : reconstructable : 88% : strong : AlertPane constructor/dismiss cluster attached to AlertPane; B002 2026-06-17 live IDA reconfirmed exact 0x6c5 constructor and 0x106 dismiss ranges, 96 constructor xrefs, three vtable stores, button-id `1/2` dispatch through no-argument primary/secondary slots `+0x5c/+0x60`, `DismissDialog(int buttonId, int unused)` ABI, modal slide behavior, layout-reference store at `+0x26c`, and class-level C++ declaration readiness while method-body C++ stays blank pending DialogPane/control-helper declarations.
```

Replace the [UID:00010W] row with:

```markdown
    - [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) 0x0048c550-0x0048c58b | scalar-deleting-destructor | AlertPaneSharedScalarDestructor : reconstructable : 86% : strong : Assigned to AlertPane; live IDA confirms exact 0x3b shared alert-family scalar deleting destructor, five-byte padding before/after, adjustor-thunk and primary-vtable refs for ClanLeaveConfirmDialog/AlertPane/BlueAlertPane/CopyWindow/QuitDialog, DialogPane cleanup chaining despite stale Boost/TransferReply labels, ordinary delete branch through OperatorDeleteWrapper, guarded 0x270 compiler path, and final C++ intentionally blank because the source shape is `virtual ~AlertPane()` plus compiler-generated wrapper/thunks.
```

Replace the [UID:0002M5] row with:

```markdown
        - [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md) 0x00618b00-0x00618ba0 | vtable-data | AlertPaneVtableData : reconstructable : 86% : strong : Assigned to AlertPane; exact AlertPane primary/secondary/tertiary vtable-data subrange with constructor stores, key slot targets, `0x00618ba0` boundary before `VersatileAlertPane` RTTI, B002-resolved `OnPrimaryButton`/`OnSecondaryButton` no-op base callback slots at `+0x5c/+0x60`, and final C++ intentionally blank because the compiler should generate these dwords from the class declaration.
```

### `by-type/by-vtable/-coverage-report.md`

If supervisor updates [UID:0001WZ], replace its row with:

```markdown
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md) : reconstructable : 88% : strong : IDA-confirmed three-view `AlertPane` vtable cluster attached to [UID:00000B][AlertPane](by-class/AlertPane.md), at `0x00618b00`, `0x00618b68`, and `0x00618b98`, with constructor stores, exact vtable-data child range, `DismissDialog` at primary slot `+0x48`, and B002-resolved no-argument `OnPrimaryButton`/`OnSecondaryButton` extension slots at `+0x5c/+0x60`.
```

## Validation Commands

Recommended supervisor validation after applying accepted doc/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [00000B-alertpane-source-quality-removed.md](00000B-alertpane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/00000B-alertpane-source-quality.md`

No leases were used because this report is inside the assigned Agent-B002 research folder. No by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited.

## Blockers / Remaining Risk

- No blocker to raising [UID:00000B] and entering class-declaration C++.
- Method-body C++ for [UID:00012W] should remain blank until the shared `DialogPane` and control helper APIs have source-quality names.
- The exact original file name `AlertPanes.cpp` remains inferred, but the current owner/emitter route is strong enough and already valid.
- The exact original name of `DismissDialog` is not proven from symbols. The report keeps existing target terminology and documents `OnDialogAction` / `OnButtonAction` only as aliases.

## Next Useful Follow-Up

The next high-value follow-up is a `DialogPane` action-handler naming pass that normalizes `DismissDialog`, `OnDialogAction`, `OnButtonAction`, and `OnButtonClick` names across exact dialog action children. That should be framework-wide rather than folded into this `AlertPane` report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00000B-alertpane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00000B"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00000B-alertpane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00000B-alertpane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00000B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
