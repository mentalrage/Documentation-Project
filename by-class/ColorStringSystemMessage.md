*** UID:000030 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ColorStringSystemMessage : public SystemMessage
{
public:
    ColorStringSystemMessage(const wchar_t *text, int color, int style);
    virtual ~ColorStringSystemMessage();

    virtual SystemMessage *Clone();
    virtual int GetLineCount(GrafPort *drawContext, short width);
    virtual void Draw(GrafPort *drawContext, RectBounds *bounds);

private:
    wchar_t *m_text;
    int m_color;
    int m_style;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete 16-byte concrete SystemMessage entry with owned UTF-16 text at +0x04, color at +0x08, style at +0x0c, public constructor/destructor/Clone/GetLineCount/Draw contracts, inherited false marker predicates, exact vtable evidence, and child-only executable method emission. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ColorStringSystemMessage

## Status

- Completion/confidence: `92/94`; inheritance, 16-byte layout, field order/types,
  public method contract, private state, source order, helper route, child-body
  placement, and compiler exclusions are source-ready.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- Exact vtable data: [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md)
- Source-facing placement: position 40 after Footer in
  `NexusTK/social/SystemMessagePanes.cpp`; executable method bodies remain on
  their exact by-memory children under the post-class `[[CHILDREN]]` route.
- Historical generated-output caveat: older recovered class output existed,
  but the accepted declaration is based on current binary and ordinary-doc
  evidence rather than that stale generated shell.

## Class Purpose

`ColorStringSystemMessage` is a system-message entry object that owns a copied wide string plus color/attribute fields. `SystemMessagePane` and `OldSystemMessagePane` clone and draw these entries while computing line counts for the scrollable message viewport.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0055c1c0-0x0055c1c3` | inferred marker identity false virtuals | Returns false for both marker identity slots: vtable `+0x0c` inferred `IsHeaderMarker()` and vtable `+0x10` inferred `IsFooterMarker()`. Descriptive names are inferred from the Header/Footer/ColorString vtable pattern; the folded body is shared with Effects and runtime uses in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x00587970-0x00587a0f` | constructor | Copies a UTF-16 string into heap-owned storage and stores color/attribute values. |
| `0x00587a70-0x00587ae0` | `Clone` | Allocates a new 16-byte message object and reconstructs it from this entry's text/color/attribute. |
| `0x00587ae0-0x00587b53` | `GetLineCount` | Calls shared constant line-count callback [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with context/text/length/width, then clamps to at least one line; current helper body returns constant `1`. |
| `0x00587b60-0x00587ba4` | `Draw` | Sets the pane text/background color state and draws the stored text in the supplied rectangle. |
| `0x0058ab50-0x0058abe7` | scalar deleting destructor | Frees the text buffer, tears down `LObject`, and conditionally deletes storage. |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). This class is now scored `85/88`, and the direct source-file parent is scored `89/86`, so both sides satisfy the corrected 85/85 gate. The parent is direct because the file page explicitly owns the system-message pane/message-entry family, lists `ColorStringSystemMessage` in proposed contents, and documents the same constructor/clone/line-count/draw/destructor island plus shared boolean virtual helper.

## Evidence Notes

- IDA names the vtable at `0x0062d6f4` as `ColorStringSystemMessage`.
- IDA `xrefs_to 0x00587970` includes construction from `SystemMessagePane` constructor, an insert/helper at `0x005854d0`, a message parsing helper at `0x00586480`, `Clone`, and `OldSystemMessagePane` constructor paths.
- IDA decompilation of `0x00587ae0` differs structurally from the active generated source: the body calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with this entry's text buffer, `wcslen(text)`, and the width argument, then clamps the result to at least one line.
- 2026-05-25 recheck: `0x004bb070` itself decompiles to a literal `return 1`, so the active generated `GetLineCount` stub is behaviorally equivalent but loses the helper-call/source-structure shape. IDA `xrefs_to 0x00587ae0` still shows the method is vtable-referenced at `0x0062d70c`.
- 2026-06-19 B002 accepted [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) source-quality implementation resolves the helper name and call interface. `ColorStringSystemMessage::GetLineCount` at `0x00587ae0-0x00587b53` is vtable-backed at `0x0062d70c`, reads this entry's owned UTF-16 text pointer from field `+0x04`, scans the text length, sign-extends the width argument from a 16-bit value before passing it, loads the pane/context argument into `ecx`, calls `GetSingleLineCount`, and clamps the helper result to at least one row. The same helper is also called by `ColorStringChattingMessage::MeasureLines`, so it is shared color-string/message behavior rather than system-message-private code.
- 2026-06-21 B006 [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) reanalysis clarifies the sibling signature pattern used here too: the first virtual argument is a pane/draw-context receiver forwarded in `ecx` to [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md), and the width-like value is the second virtual argument. The current helper ignores both, so generated behavior is one line, but the source-shape note should say "forwarded context" rather than "unused first argument" without qualification.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the exact modeled method bounds: constructor `0x00587970-0x00587a0f`, clone `0x00587a70-0x00587ae0`, line-count helper `0x00587ae0-0x00587b53`, draw `0x00587b60-0x00587ba4`, and scalar deleting destructor `0x0058ab50-0x0058abe7`.
- The same refresh found seven constructor callers from `SystemMessagePane` construction, insertion/parsing helpers, clone, and old-pane construction paths; vtable words at `0x0062d6f4` include the destructor, shared false boolean slots, clone, line-count, and draw entries.
- B001 2026-06-18 source-placement reanalysis resolves the two shared false boolean slots as descriptive marker identity predicates: vtable `+0x0c` behaves like `IsHeaderMarker()` false and vtable `+0x10` behaves like `IsFooterMarker()` false. These names come from the Header true / Footer false / ColorString false and Header false / Footer true / ColorString false pattern; [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) remains no-owner/non-emitting because the same folded body is shared with Effects and runtime tables.
- 2026-06-12 C001 live IDA MCP split [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) and confirmed this class owns the exact `0x0062d6f0-0x0062d714` locator/vtable child [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md), with 22 vtable data xrefs and a `0x24` / 36-byte range (Verified with `int_convert.py`).

## Score Rationale

- Completion `92`: complete class source, public method declarations, private
  16-byte field layout, exact inheritance, child-body route, source order,
  method inventory, helper dependency, lifecycle, and compiler exclusions are
  all documented and emitted.
- Confidence `94`: constructor/clone/count/draw/destructor bodies, allocation
  size, vtable/RTTI, field reads/writes, width sign extension, caller spread,
  and sibling contracts converge. Stripped original names and unsplit exact
  method children keep the score below 95 without weakening the declaration.

## B011 Declaration-Shell Audit

Historical accepted B011 report
`0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` kept this
class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
but resolved the empty emitter with a formal no-code comment. That disposition
was reasonable before the SystemMessage base/interface and all three field
types were recovered. The audit checked constructor `0x00587970-0x00587a0f`,
`Clone` `0x00587a70-0x00587ae0`, `GetLineCount`
`0x00587ae0-0x00587b53`, `Draw` `0x00587b60-0x00587ba4`, scalar deleting
destructor `0x0058ab50-0x0058abe7`, exact vtable child
[UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md),
shared false marker slots [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md),
shared [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md),
and the text pointer at object offset `+0x04`.

The exact vtable child proves destructor, inherited/runtime slots, two false
marker predicates at `+0x0c/+0x10`, `Clone` at `+0x14`, `GetLineCount` at
`+0x18`, and `Draw` at `+0x1c`. The `+0x04` text pointer is proven by
`GetLineCount`; constructor, clone, and draw fix `m_color` at `+0x08` and
`m_style` at `+0x0c`. The old declaration-shell blocker is superseded by the
RTTI-proven [UID:0004SZ][SystemMessage](by-class/SystemMessage.md) contract and
the source-safe complete class declaration above. `[[CHILDREN]]` is placed only
after the closed class; no unsplit method body is invented.

## Accepted Layout And Source Contract

| Offset | Field | Evidence |
| --- | --- | --- |
| `+0x00` | inherited `SystemMessage`/`LObject` vptr shell | 32-bit concrete vtable and RTTI hierarchy |
| `+0x04` | owned `wchar_t *m_text` | constructor copy, clone source, count `wcslen`, draw source, destructor delete |
| `+0x08` | `int m_color` | constructor store, clone copy, draw color state |
| `+0x0c` | `int m_style` | constructor store, clone copy, draw style/background state |

- Constructor accepts source text, color, and style, allocates/copies the UTF-16
  text, and stores both 32-bit values in the exact order above.
- Destructor is virtual because slot `+0x00` is the concrete deleting-wrapper
  entry; the handwritten destructor body owns only the text cleanup while
  scalar flags, storage deletion, vptr stores, and base teardown remain
  compiler/language lowering on their exact children.
- Clone allocates a 16-byte object and reconstructs it from this entry's text,
  color, and style. Allocation failure returns null through the observed
  factory path.
- GetLineCount forwards draw context, text, length, and signed-short width to
  GetSingleLineCount and clamps the result to at least one. Draw consumes the
  stored text/color/style and supplied rectangle. Neither body is duplicated on
  this class page.
- The two marker predicates are inherited false defaults. Header/Footer-only,
  direct LObject inheritance, public fields, raw-offset declarations,
  handwritten vtable/RTTI/scalar-wrapper code, and inline guessed child bodies
  are rejected.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)
- [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md)

## Changes

- 2026-07-19 B002 UID000246 accepted callback:
  - Raised `85/88` to `92/94`, set source position 40, and installed the exact
    complete 16-byte `SystemMessage`-derived declaration with the closing brace
    before `[[CHILDREN]]`.
  - Preserved exact constructor/clone/count/draw/destructor ranges, owned-text
    lifecycle, color/style layout, helper call, width semantics, callers,
    vtable/RTTI, folded predicates, compiler exclusions, negative evidence,
    and historical B011 provenance.
- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for constructor, `Clone`, `GetLineCount`, `Draw`, destructor, [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md), field `+0x04`, shared marker slots, and `GetSingleLineCount`, with explicit rejection of both a `[[CHILDREN]]` shell and guessed virtual declaration shell.
- 2026-06-19 B002 accepted [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) source-quality implementation:
  - Score unchanged at `85/88`.
  - Summary/evidence: refreshed `GetLineCount` naming and evidence to identify `0x004bb070` as `GetSingleLineCount`, record vtable slot `0x0062d70c`, the `+0x04` owned text pointer, UTF-16 length scan, sign-extended 16-bit width argument, hidden `ecx` pane/context, clamp-to-one-line behavior, and the shared caller relationship with `ColorStringChattingMessage::MeasureLines`.
- 2026-06-21 B006 sibling measure-call sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: added the `ColorStringChattingMessage::MeasureLines` comparison to clarify that this class's `GetLineCount` also follows the receiver/context plus width pattern. The first virtual argument is forwarded in `ecx`; it is only unused by the constant helper body, not absent from the source call shape.
- 2026-06-18 B001 folded-boolean source-name reanalysis:
  - Score unchanged at `85/88`.
  - Evidence: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) now records current PE-backed folded true/false evidence and the Header/Footer/ColorString vtable pattern. This class's two false slots are best described as inferred `IsHeaderMarker()` false and `IsFooterMarker()` false, while the physical false stub remains shared with Effects/runtime use and is not class-owned source.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/84`.
  - Summary/evidence: the class role, vtable, construction/cloning/draw/destructor methods, helper call shape, and core cross-references are documented from IDA-backed address ranges; remaining uncertainty is mostly final source naming/signature detail and exact helper source structure.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x00587970`, `0x00587a70`, `0x00587ae0`, `0x00587b60`, and `0x0058ab50`, with constructor callers from `SystemMessagePane` and related message insertion/parsing paths.
- 2026-06-07 A008 Batch 082 class-coverage pass:
  - Before: `78/84`, `AUTOGEN_PARENT_UID:` blank.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000OE`.
  - Evidence: current IDA MCP reconfirmed exact method half-open ranges, constructor caller spread, vtable slots, and the direct source-family parent [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at `89/86`.
- 2026-06-12 C001 Batch C001-003 vtable split note:
  - Score remains `85/88`; [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md) now carries the exact locator/vtable data and routes to this class after the child `88/93` and this direct parent clear the strict gate.
  - Summary/evidence: C001 live IDA MCP confirmed `??_R4ColorStringSystemMessage@@6B@`, `??_7ColorStringSystemMessage@@6B@`, 22 vtable xrefs, the forced-inform successor boundary, and the `0x24` / 36-byte child size (Verified with `int_convert.py`).
