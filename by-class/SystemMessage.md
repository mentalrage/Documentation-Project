*** UID:0004SZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GrafPort;
struct RectBounds;

class SystemMessage : public LObject
{
public:
    virtual bool IsHeaderMarker() const { return false; }
    virtual bool IsFooterMarker() const { return false; }
    virtual SystemMessage *Clone() = 0;
    virtual int GetLineCount(GrafPort *drawContext, short width);
    virtual void Draw(GrafPort * /*drawContext*/, RectBounds * /*bounds*/) {}
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Binary-proven fieldless abstract LObject-derived system-message entry base shared by HeaderSystemMessage, FooterSystemMessage, and ColorStringSystemMessage; supplies false marker defaults, pure Clone, exact UID000246 one-line GetLineCount child, and a no-op Draw default while source declarations regenerate all compiler vtables. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SystemMessage

## Status

- Completion/confidence: `92/94`.
- Entity kind: fieldless abstract source class.
- Inheritance: direct public `LObject` base; direct base of
  `HeaderSystemMessage`, `FooterSystemMessage`, and
  `ColorStringSystemMessage`.
- Canonical owner/emitter: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md),
  reconstructed in `NexusTK/social/SystemMessagePanes.cpp`.
- Source order: position 10, before Header position 20, Footer position 30,
  and Color position 40.
- Exact out-of-line child:
  [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md).

## Purpose And Source Contract

`SystemMessage` is the common abstract entry interface used by current and
legacy system-message panes. Fresh RTTI proves that it sits between `LObject`
and all three concrete message-entry classes. It owns no fields and is not
constructed directly. The source contract adds five virtual slots after the
inherited LObject destructor, `GetRuntimeClass`, and `OnChangeMessage` prefix:

| Relative slot | Source contract | Default / override model |
| --- | --- | --- |
| `+0x0c` | `bool IsHeaderMarker() const` | false on this base; Header overrides true |
| `+0x10` | `bool IsFooterMarker() const` | false on this base; Footer overrides true |
| `+0x14` | `SystemMessage *Clone()` | pure virtual; every concrete class supplies its factory/copy behavior |
| `+0x18` | `int GetLineCount(GrafPort *drawContext, short width)` | exact UID000246 base body returns one; Color overrides measured text count |
| `+0x1c` | `void Draw(GrafPort *drawContext, RectBounds *bounds)` | empty base default; Color overrides text drawing |

Header and Footer therefore inherit the same one-line count and empty Draw
defaults. Their paired true/false marker behavior is expressed by minimum
source overrides, not by a free helper or duplicated folded bodies. Color
inherits both false marker defaults and overrides Clone, GetLineCount, and
Draw.

## Layout And Construction

- `SystemMessage` adds no data members to the four-byte LObject shell on the
  32-bit target.
- Header and Footer factories allocate exactly four bytes, construct LObject,
  and install their concrete vptrs.
- Color allocates 16 bytes because it adds an owned wide-text pointer and two
  32-bit color/style fields after this fieldless base.
- No concrete `SystemMessage` constructor call, allocation, vtable, or object
  instance was found. The pure Clone slot and missing concrete base vtable make
  the abstract source model the strongest current disposition.

## RTTI And Vtable Evidence

- `SystemMessage` type descriptor: `0x0067946c`.
- `SystemMessage` base-class descriptor: `0x00650a8c`.
- `SystemMessage` hierarchy descriptor: `0x00650a70`; base array
  `0x00650a80`.
- Header, Footer, and Color hierarchy arrays reference the same base
  descriptor at `0x00650bac`, `0x00650bfc`, and `0x00650c4c`.
- The base descriptor has exactly four observed references: its own base array
  and the three concrete class arrays.
- No `??_7SystemMessage@@6B@` symbol or concrete base vtable was found.
- Header vtable `0x0062d6ac`, Footer vtable `0x0062d6d0`, and Color vtable
  `0x0062d6f4` share the same eight-slot shape. The marker/count/draw
  differences exactly match the source contract above.

## Exact Child And Call Semantics

[UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
is the sole source body emitted through `[[CHILDREN]]`. Its exact bytes are
`b8 01 00 00 00 c2 08 00` (SHA256
`A37F20F22731FA44D5FE0925CE76FBFB5BF2C8A56F260E67AA2F887A08D7F326`),
its CFG is one block with no callees, and its only two pointer hits are Header
and Footer slot `+0x18` at `0x0062d6c4` and `0x0062d6e8`.

System-message pane callers pass the pane/draw context first and widths 160 or
184 second. The Color comparator in the same slot sign-extends the second
argument as a 16-bit width, forwards the draw context to the shared
`GetSingleLineCount` helper, and clamps the result to at least one. These facts
fix the source signature as `int (GrafPort *, short)` rather than a boolean,
width-only method, or free helper.

## Source Placement And Compiler Exclusions

- Source file: `NexusTK/social/SystemMessagePanes.cpp` through UID0000OE.
- `[[CHILDREN]]` follows the complete closing brace so UID000246 emits at
  namespace scope as `SystemMessage::GetLineCount`.
- Exact Header/Footer/Color locator/vtable pages are compiler data. Class
  declarations regenerate those arrays; no absolute-address vtable/RTTI data
  belongs in authored source.
- Physical true/false bodies remain on the shared folded-stub page because
  they are also used by Effects/runtime tables. Their source semantics are the
  inline predicate defaults/overrides declared by this family.
- The broad shared no-op remains LObject-owned; this class's empty Draw may
  fold to it without transferring physical ownership.
- Shared scalar deleting-destructor wrappers remain compiler glue. No deleting
  flags, vptr stores, RTTI arrays, or wrapper code are handwritten here.

## Rejected Alternatives And Negative Evidence

- Rejected direct UID0000OE ownership of the method: the RTTI-proven class is
  the stronger semantic owner; UID0000OE remains the file owner/emitter.
- Rejected Header-only or Footer-only ownership: both concrete vtables point
  to the same body.
- Rejected two authored duplicate overrides or a pure count slot with two
  overrides: possible linker folding does not outweigh the fieldless common
  base and minimum-override model.
- Rejected free `HeaderFooter...` helper: no direct calls or non-vtable address
  refs exist.
- Rejected boolean or `short` return: callers accumulate the EAX result as a
  line count; the constant happens to be one.
- Rejected width-only ABI: `retn 8` and semantic callers prove two explicit
  stack arguments.
- Rejected direct instantiation: no concrete base vtable, construction, or
  allocation was found.

## Score Rationale

- Completion `92`: exact inheritance, fieldless layout, abstractness, all five
  virtual roles, argument order/types, source order, owner/emitter route,
  out-of-line child, compiler exclusions, and rejected alternatives are
  resolved to source-ready form.
- Confidence `94`: exact bytes, vtables, RTTI, concrete allocations, caller
  behavior, and Color comparator agree. Stripped original symbol spelling and
  count-method constness remain unrecoverable, so the page stays below 95.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md)
- [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md)
- [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md)
- [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md)
- [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)

## Changes

- 2026-07-19 B002 UID000246 accepted callback:
  - Registered the binary-proven fieldless abstract `SystemMessage` base as a
    source-emitting class under UID0000OE.
  - Installed the exact five-slot source contract and post-brace child route
    for UID000246 while excluding folded stubs and compiler ABI data.
