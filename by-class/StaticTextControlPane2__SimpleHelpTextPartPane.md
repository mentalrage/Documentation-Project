*** UID:0000E5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete nested declaration is emitted once by StaticTextControlPane2. Preserve all
// accepted UID00011U exact method children here without duplicating the class definition.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2::SimpleHelpTextPartPane

## Status

- Source identity: exact nested class `StaticTextControlPane2::SimpleHelpTextPartPane`.
- Base: Pane; object extent `0x10c` bytes.
- Direct file owner/emitter: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md), source position `30`.
- Complete declaration owner: [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md), emitted earlier at source position `20`.
- Core split: [UID:00011U][0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore.md), exact `0x00499fe0-0x0049a403`.
- Reconstructable with qualified child definitions; this page intentionally does not emit a
  duplicate class shell.

Decorated RTTI and vtable names prove the nested spelling. The outer class owns one instance
by value, so a forward declaration is insufficient. UID0000E4 emits the complete nested type
inside the outer class, closes `StaticTextControlPane2`, then expands its outer children.
This page follows at position `30` with a declaration-covered comment and `[[CHILDREN]]`,
which yields legal namespace-scope qualified nested method definitions.

## Class Purpose And Layout

The nested Pane owns the display string and draws multiline styled help text inside the
outer StaticTextControlPane2 bounds. Its post-Pane layout is:

| Offset | Field | Meaning/lifetime |
| --- | --- | --- |
| `+0xf8` | `SimpleUString m_text` | owned text; constructed and destroyed by this class |
| `+0xfc` | `int m_horizontalPadding` | x inset from current bounds |
| `+0x100` | `int m_verticalPadding` | initial y inset after line height |
| `+0x104` | `int m_lineSpacing` | extra interline advance |
| `+0x108` | `FontStyle *m_fontStyle` | borrowed pointer to outer-owned style |

The outer constructor initializes these fields directly because it is declared a friend.
The borrowed FontStyle pointer is never destroyed by the nested scalar teardown.

## Exact Method And Compiler Families

| UID | Range | Source/ABI role |
| --- | --- | --- |
| [UID:0004L7][0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor](by-memory/0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor.md) | `0x00499fe0-0x0049a080` | exact source constructor, position `10` |
| [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md) | `0x0049a080-0x0049a298` | exact source `OnPaint`, position `20` |
| [UID:0004L9][0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw](by-memory/0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw.md) | `0x0049a2a0-0x0049a2c2` | raw layout stores; source covered by UID00011V |
| [UID:0004LA][0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw](by-memory/0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw.md) | `0x0049a2d0-0x0049a32e` | raw style/opacity transition; source covered by UID00011V |
| [UID:0004LB][0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine](by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md) | `0x0049a330-0x0049a403` | private source `DrawTextLine`, position `30` |
| [UID:0004LC][0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks](by-memory/0x0049afed-0x0049b003.StaticTextControlPane2SimpleHelpTextPartPaneAdjustorThunks.md) | `0x0049afed-0x0049b003` | false/no-code secondary-view adjustors |
| [UID:0004LD][0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor.md) | `0x0049b560-0x0049b5a8` | scalar deleting wrapper marker, position `40` |

The source surface is constructor, inline virtual destructor, virtual `OnPaint`, and private
`DrawTextLine(const FontStyleRule&, int, int, const wchar_t *, short)`. No callable source
method is invented for either raw body.

## Text And Style Behavior

- OnPaint clears current bounds and initializes fallback FontStyleRule values `0x8f`,
  `0x80`, effect `0`, alignment `0`.
- CR, LF, and tab are equal delimiters. Consecutive delimiters produce empty segments, and
  the final segment is always dispatched.
- Point initialization follows y-then-x ABI order: line height plus vertical padding, then
  horizontal padding. Each break advances by line height plus line spacing.
- Null or disabled style uses plain MoveTo/DrawWideText. Enabled style calls GetRule; an
  out-of-range index preserves the current fallback/previous rule.
- DrawTextLine copies alignment and colors, constructs the 12-pixel line rectangle, and
  dispatches effects `0/1/3` to normal, outlined, and shadowed drawing.
- The style-state inlined path selects Pane mode `1` for opacity `<=0`, mode `3` and alpha
  for `(0,1]`, and no update for values above one or unordered/NaN paths.

## Vtables And Lifetime

Primary, secondary, and tertiary vtable roots are `0x0061857c`, `0x006185c8`, and
`0x006185f8`. OnPaint occupies the primary callback route with data reference
`0x006185c0`. The inline empty virtual destructor is the human source declaration; compiler
lowering regenerates the scalar-deleting wrapper and both secondary-view adjustors.

The scalar wrapper destroys the owned SimpleUString and Pane base and conditionally deletes
storage. It does not destroy FontStyle. No ordinary standalone destructor body exists in the
bounded class island.

## Raw Liveness And Source Emission

MCP byte-xref checks and PE transfer/pointer scans found no external call, jump, relocation,
vtable, or stored-pointer route to `0x0049a2a0` or `0x0049a2d0`. UID00011V's outer
constructor contains behavior-identical child setup. The raw pages therefore emit only the
exact covered-by-UID00011V comment. This class route emits constructor, OnPaint,
DrawTextLine, and the scalar generated-binary marker; it emits no raw helper body, adjustor
body, or handwritten scalar wrapper.

## Ownership And Shared Helpers

Outlined and shadowed text effects remain [UID:00005V][GrafPort](by-class/GrafPort.md)-owned GrafPort helpers. This nested
class is a confirmed caller, not their semantic owner. Point/rectangle helpers, Pane mode,
and Surface FillRect similarly remain with their established owners. The source route is the
existing `NexusTK/ui/controls/StaticTextControlPane.cpp`; no standalone nested-class source
file is introduced.

## Rejected Alternatives And Historical Corrections

- The earlier provisional nested spelling is superseded by decorated RTTI/vtable evidence.
- Tabs are delimiters, not inline formatting commands.
- Raw layout endpoint `0x0049a2c0` is superseded by exclusive `0x0049a2c2`.
- `m_fontStyle` is borrowed, not owned.
- Shared outlined/shadowed helpers are consumers, not nested-class-owned methods.
- A second class declaration, ordinary destructor body, callable raw helper methods, and
  handwritten MSVC ABI wrappers are rejected by C++ legality and exact liveness/lifecycle
  evidence.

## Cross-References

- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md) Complete outer/nested declaration and by-value layout.
- [UID:00011U][0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a403.SimpleHelpTextPartPaneCore.md) Corrected core split and exhaustive range/liveness evidence.
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md) Inlined child setup and complete outer method split.
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md) Source-file route and deterministic emitter order.
- [UID:00005C][FontStyle](by-class/FontStyle.md) Complete FontStyle declaration and accessors.
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) Exact FontStyleRule layout.
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md) Shared outlined/shadowed text effects.
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) Pane mode transition helper.
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) Point/RectBounds helpers.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The complete legal source route, fields, methods, exact children, behavior, lifetime, raw dispositions, vtables, and shared ownership are documented. |
| Confidence | 93 | Nested identity, layout, and behavior are strongly binary-backed; private spelling and compiler optimization remain inferred. |

## Changes

- 2026-07-13 B005 accepted UID00011U callback:
  - Before: `86/88`, blank formal block, no emitter position, provisional spelling and
    formatting claims, broad method rows, and no exact child route.
  - After: `91/93`, file position `30`, legal declaration-covered `[[CHILDREN]]` route,
    seven exact source/evidence/compiler children, complete layout/lifetime/behavior, and
    explicit rejected alternatives.
  - Evidence: decorated RTTI/vtables, exact modeled/raw ranges, outer by-value construction,
    caller/callee and field analysis, exhaustive raw liveness, and B002's executed complete
    UID0000E4 declaration baseline.
