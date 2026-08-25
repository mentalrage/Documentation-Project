*** UID:0000OM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Proposed module: `NexusTK/ui/controls/TextEditControlPane.cpp`; proposed header: `NexusTK/ui/controls/TextEditControlPane.h`.
- Direct class source root: [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md).
- Exact address groups: local source index `0x004988d0-0x00498dd0`, inherited state/border helpers `0x00498dd0-0x00499021`, and compiler scalar-deleting wrapper `0x0049b6c0-0x0049b731`.
- Source route and path remain unchanged. The local aggregate UID00011H is now non-emitting; twelve exact method children emit through the class.

## File Role

This file implements the dialog-facing type-5 `ControlPane` adapter around [UID:0000ON][TextEditPane](by-file/TextEditPane.md). It owns the editor at wrapper `+0x10c`, constructs/configures it, exposes text and state operations, attaches/detaches it with the wrapper, forwards the EventHandler pointer/mouse, key/text, and IME interfaces, synchronizes inherited wrapper/editor state, paints the optional legacy border, and emits the ordinary destructor.

Keep the module separate from TextEditPane.cpp: lower editor storage/layout/selection/serialization logic belongs there, while these wrapper methods have broad dialog/control fan-in and TextEditControlPane vtable/field identity.

## Exact Local Source Inventory

| UID | Range | File content |
| --- | --- | --- |
| [UID:0004K1][0x004988d0-0x00498b8d.TextEditControlPaneConstructors](by-memory/0x004988d0-0x00498b8d.TextEditControlPaneConstructors.md) | `0x004988d0-0x00498b8d` | Retained short constructor and 85-site/34-function full constructor. |
| [UID:0004K2][0x00498b90-0x00498bcf.TextEditControlPaneOrdinaryDestructor](by-memory/0x00498b90-0x00498bcf.TextEditControlPaneOrdinaryDestructor.md) | `0x00498b90-0x00498bcf` | Ordinary source destructor. |
| [UID:0004K3][0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters](by-memory/0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters.md) | `0x00498bd0-0x00498bef` | Max-length/max-lines wrappers. |
| [UID:0004K4][0x00498bf0-0x00498c0f.TextEditControlPaneMaskAndEditState](by-memory/0x00498bf0-0x00498c0f.TextEditControlPaneMaskAndEditState.md) | `0x00498bf0-0x00498c0f` | Mask/edit-active wrappers. |
| [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md) | `0x00498c10-0x00498c1f` | Bounded UTF-16 read, 70 sites/41 functions. |
| [UID:0004K5][0x00498c20-0x00498c38.TextEditControlPaneGetInputText](by-memory/0x00498c20-0x00498c38.TextEditControlPaneGetInputText.md) | `0x00498c20-0x00498c38` | By-value one-pointer wide StringBase hidden-result forwarding. |
| [UID:0004K6][0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization](by-memory/0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization.md) | `0x00498c40-0x00498c5f` | Retained raw encode/decode wrappers. |
| [UID:0004K7][0x00498c60-0x00498c72.TextEditControlPaneIsEmpty](by-memory/0x00498c60-0x00498c72.TextEditControlPaneIsEmpty.md) | `0x00498c60-0x00498c72` | Empty predicate. |
| [UID:0004K8][0x00498c80-0x00498c9d.TextEditControlPaneSelectAll](by-memory/0x00498c80-0x00498c9d.TextEditControlPaneSelectAll.md) | `0x00498c80-0x00498c9d` | Retained raw full selection. |
| [UID:0004K9][0x00498ca0-0x00498ce1.TextEditControlPaneSetText](by-memory/0x00498ca0-0x00498ce1.TextEditControlPaneSetText.md) | `0x00498ca0-0x00498ce1` | Null-preserving text replacement. |
| [UID:0004KA][0x00498cf0-0x00498d66.TextEditControlPaneLayerLifecycle](by-memory/0x00498cf0-0x00498d66.TextEditControlPaneLayerLifecycle.md) | `0x00498cf0-0x00498d66` | Add/remove layer virtuals. |
| [UID:0004KB][0x00498d70-0x00498dc8.TextEditControlPaneEventForwarders](by-memory/0x00498d70-0x00498dc8.TextEditControlPaneEventForwarders.md) | `0x00498d70-0x00498dc8` | Pointer/mouse, key/text, and IME forwarding overrides. |

[UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md) retains the exact aggregate range and complete padding/body ledger but emits no source. This prevents duplicate parent/child bodies.

## Construction And Layout

- Wrapper-private state is `m_useThousandsSeparator +0x108`, `m_drawBorder +0x109`, owned `TextEditPane* +0x10c`, and cached child mode `+0x110`; bytes `+0xff-0x104` remain inherited [UID:0000IG][ControlPane](by-file/ControlPane.md) state.
- The full constructor uses exact horizontal/vertical 12-pixel deductions, scaled content width, style bits `2/0x100`, `IsLegacyAssetMode()` as TextEditPane argument ten, constant true default alignment as argument eleven, and `m_useThousandsSeparator` as argument twelve. It then applies deliberate wrapper limits `1024/1` over the lower constructor's `30000/30000` defaults, local/inset bounds, edit/mode setup, optional initial text, and cached mode in binary order.
- TextEditPane `+0x16c/+0x16e` are max length/max lines, not delete indexes. Historical `fontId` argument-ten wording is rejected.

## Text, Serialization, And Event Types

- `GetInputText` returns exact one-pointer `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` by value. The wrapper forwards the Microsoft x86 hidden result to lower TextEditPane `GetText`; lower initialization and four caller-owned temporary lifecycles reject the stale explicit output-reference source shape, provisional `WideString`, and 24-byte SSO-7 `SimpleUString`.
- The raw short constructor, encode/decode wrappers, and SelectAll have zero entry routes/pointer forms but complete coherent source bodies. They remain in this translation unit; no fake call route is introduced.
- The `0x00498d70/90/b0` family is EventHandler pointer/mouse, key/text, and IME forwarding. Historical show/hide/focus names are false. Compiler receiver adjustments do not become source.

## Shared Helpers And Destructor Policy

[UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) remains one exact inherited helper band. StaticTextControlPane and ExchangeMoneyEditControlPane consume it through TextEditControlPane inheritance proven by RTTI; emit it once through this source route, not through a standalone TextControl file or multiple concrete consumers.

The file emits ordinary source cleanup from UID0004K2:

```cpp
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}
```

[UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) stays blank formal C++. Scalar-delete flags, operator-delete/CFG paths, adjustor thunks, vptr stores, EH cleanup, and implicit `Pane::~Pane()` chaining are compiler-generated.

## Source Ownership Rejections

- TextEditPane owns lower editor internals only; ControlPane/Pane supply base behavior; StaticText/ExchangeMoney inherit/override; dialogs are consumers.
- Do not create a new helper file, duplicate the aggregate, migrate wrappers to caller modules, or emit raw `sub_*`, decompiler fields, vtable stores, padding, or ABI machinery.
- Exact private symbols/access/header factoring remain confidence caps rather than source blockers.
- `inputMode` is rejected as a stale generic alias for `+0x108`; the bounded source route forwards the byte only to TextEditPane's thousands-grouping flag and transfers no constructor ownership into this wrapper file.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `91` | Exact class and twelve-child source inventory, route, final-byte semantics, field/type corrections, raw methods, event names, shared helpers, and compiler exclusions are complete. |
| Confidence | `93` | Direct caller/vtable/lower-helper/RTTI, constructor forwarding, unique grouping use, and hidden-result lifecycle evidence establish module ownership and contents; original private symbols retain the final cap. |

## Changes

- 2026-07-19 B001 UID0002ZY accepted implementation callback: changed `90/92 -> 91/93`; synchronized `m_useThousandsSeparator` and exact argument-twelve forwarding, recorded TextEditPane `30000/30000` defaults versus wrapper `1024/1` limits, preserved the source path/FILE owner and complete twelve-child/shared-helper union, and retained lower constructor implementation ownership in TextEditPane.cpp.

- 2026-07-14 B003 UID0003R9 implementation support sync: preserved `90/92`, route/path, exact twelve-child inventory, shared helpers, raw retention, source/compiler policy, and unrelated history; corrected only UID0004K5 to the applied by-value StringBase hidden-result source shape and rejected the stale output-reference API.
- 2026-06-05/12 history: established this reusable wrapper module and separated the exact shared-helper successor band.
- 2026-06-19/21 history: resolved ordinary versus scalar-deleting destructor source ownership and inherited StaticText slots.
- 2026-06-22 history: retained the no-owner caution as superseded evidence while accepting the RTTI-backed single TextEditControlPane route.
- 2026-07-13 B003 UID00011H callback: changed `86/88 -> 90/92`; preserved path and FILE ownership; replaced stale aggregate/show-hide-focus/source-blocker wording with the exact twelve-child inventory, raw retention, StringBase/max-limit/legacy-argument corrections, ordinary/compiler destructor policy, and generated-output contract.
