*** UID:000061 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HeaderSystemMessage : public SystemMessage
{
public:
    virtual bool IsHeaderMarker() const { return true; }
    virtual SystemMessage *Clone() { return new HeaderSystemMessage; }
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HeaderSystemMessage

## Status

- Completion/confidence: `92/94`; the class declaration, inheritance, public
  overrides, fieldless layout, factory behavior, inherited defaults, source
  order, and compiler exclusions are source-ready.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Non-contiguous destructor helper: [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- Inherited one-line count: [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
- Exact vtable data: [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md)
- Source-facing placement: position 20 after
  [UID:0004SZ][SystemMessage](by-class/SystemMessage.md) in
  `NexusTK/social/SystemMessagePanes.cpp`.
- Reconstructable: true; the managed block is the complete minimum-override
  class declaration. Shared scalar-delete/folded bodies remain on their
  existing compiler/physical evidence routes.

## Class Purpose

`HeaderSystemMessage` is a tiny marker entry used by the system-message pane list. The object is only four bytes in the recovered constructor path: it constructs the `LObject` shell and installs the `HeaderSystemMessage` vtable.

The class is paired with [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md). The two marker entries differ primarily by factory address and vtable pointer; they share the tiny scalar-deleting destructor glue, boolean virtual bodies, and default true helper.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00514e60-0x00514e98` | scalar deleting destructor | Shared small marker-entry destructor; calls `LObject` cleanup and conditionally deletes storage. |
| `0x0055c1b0-0x0055c1b3` | inferred `IsHeaderMarker` virtual | Returns true for the marker identity slot at vtable `+0x0c`. Descriptive name inferred from the Header true / Footer false / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x0055c1c0-0x0055c1c3` | inferred `IsFooterMarker` virtual | Returns false for the paired marker identity slot at vtable `+0x10`. Descriptive name inferred from the Header false / Footer true / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x00587890-0x005878ff` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `HeaderSystemMessage` vtable, and returns the marker object. |
| `0x0058af40-0x0058af48` | inherited `GetLineCount` | Returns integer line count one and consumes draw-context plus signed-short width arguments; used by both header/footer marker vtables. |

## Vtable Layout

The marker vtable starts at `0x0062d6ac` inside [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md):

| Slot | Target | Meaning |
| --- | --- | --- |
| `+0x00` | `0x00514e60` | Shared `LObject` scalar deleting destructor. |
| `+0x04` / `+0x08` | inherited/empty slots | Runtime-class/no-op inherited marker slots. |
| `+0x0c` | `0x0055c1b0` | Inferred `IsHeaderMarker()` true slot; folded body [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `+0x10` | `0x0055c1c0` | Inferred `IsFooterMarker()` false slot; folded body [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `+0x14` | `0x00587890` | Header marker factory. |
| `+0x18` | `0x0058af40` | Inherited `SystemMessage::GetLineCount` default using `retn 8`. |
| `+0x1c` | `0x0041b6c0` | Inherited no-op `SystemMessage::Draw` body on the established LObject folded route. |

## Evidence Notes

- IDA names the vtable at `0x0062d6ac` as `HeaderSystemMessage`.
- The vtable points at `0x00514e60`, boolean helpers `0x0055c1b0` and `0x0055c1c0`, factory `0x00587890`, and another shared helper at `0x0058af40`.
- 2026-06-03 IDA MCP recheck resolves the factory as `0x00587890-0x005878ff`: it allocates four bytes through `sub_4F4AA0`, calls the `LObject` shell constructor at `sub_4F4A80`, writes vtable `0x0062d6ac`, and returns null only on allocation failure.
- Vtable slot order from IDA data words is destructor `+0x00`, inherited/empty slots at `+0x04`/`+0x08`, true/false boolean stubs at `+0x0c`/`+0x10`, factory `+0x14`, default true helper `+0x18`, and another null slot at `+0x1c`.
- The shared destructor `0x00514e60` is also referenced by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables, so it is LObject scalar-delete glue reused by several tiny marker/creator classes rather than an exclusive header/footer body.
- Generated output currently exposes only the destructor wrapper and factory; the boolean virtual slots are not in `class_HeaderSystemMessage.cpp`.
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) places the `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtables in the `0x0062d6ac-0x0062d6f4` marker/color-message block.
- 2026-06-12 C001 live IDA MCP split [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) and confirmed this class owns the exact `0x0062d6a8-0x0062d6cc` locator/vtable child [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md), with 14 vtable data xrefs and a `0x24` / 36-byte range (Verified with `int_convert.py`).

## Score Rationale

- Completion `92` reflects a complete source declaration, exact inheritance,
  four-byte fieldless layout, public access, source order, factory/clone
  semantics, inherited count/draw/footer defaults, true header override, and
  explicit compiler-source exclusions.
- Confidence `94` reflects exact allocation size, constructor/vptr sequence,
  vtable/RTTI identity, concrete slot parity, shared folded-body evidence, and
  the common SystemMessage contract. Original symbol spelling is stripped, so
  the semantic method names remain below 95 despite cross-family agreement.

## B011 Declaration-Shell Audit

Historical accepted B011 report
`0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` kept this
class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
but resolved the empty emitter with a formal no-code comment. That disposition
was reasonable before the real SystemMessage RTTI/base declaration was
recovered. The audit checked factory `0x00587890-0x005878ff`, shared scalar
deleting destructor [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md),
shared true/false marker stubs [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md),
one-line virtual [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md),
and exact vtable child [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md).

The factory allocates four bytes, constructs an `LObject` shell, installs the
`HeaderSystemMessage` vtable, and returns null only on allocation failure.
[UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md) proves slot `+0x00` shared destructor, `+0x04/+0x08`
inherited/runtime slots, `+0x0c` true `IsHeaderMarker` pattern, `+0x10` false
`IsFooterMarker` pattern, `+0x14` factory, `+0x18` inherited one-line count at
`0x0058af40`, and `+0x1c` inherited no-op draw. The old declaration-shell
blocker is superseded: [UID:0004SZ][SystemMessage](by-class/SystemMessage.md)
now supplies the exact inherited defaults, while this class emits only its two
source-authored differences.

## Accepted Source Model

- Inheritance and access: public `SystemMessage` with public virtual overrides.
  No extra fields, constructor body, or explicit destructor is required in the
  handwritten declaration.
- Object lifecycle: clone/factory behavior allocates four bytes, invokes the
  inherited LObject shell construction, installs the concrete vptr through
  compiler lowering, and returns null only if allocation fails.
- Override inventory: true header predicate and concrete clone only. The false
  footer predicate, integer one-line count, and no-op draw are inherited from
  SystemMessage. This is the minimum source model that regenerates the exact
  eight-slot vtable.
- Compiler boundaries: the scalar deleting destructor, vptr store,
  HeaderSystemMessage RTTI/vtable bytes, and physically folded boolean/no-op
  bodies are not handwritten here. UID0003GD remains semantic evidence owned
  by this class but becomes a non-emitting compiler-data page.
- Rejected alternatives: a standalone factory helper, free line-count helper,
  two duplicate folded count overrides, extra marker fields, direct LObject
  inheritance, and handwritten ABI arrays would contradict the recovered base,
  four-byte allocation, slot parity, or source policy.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
- [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md)
- [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md)

## Changes

- 2026-07-19 B002 UID000246 accepted callback:
  - Raised `85/88` to `92/94`, set source position 20, and installed the
    complete minimum-override `SystemMessage`-derived declaration.
  - Preserved the exact four-byte allocation/factory, vtable/RTTI, folded
    predicates, inherited count/draw, scalar-wrapper, source placement,
    negative evidence, and historical B011 disposition.
- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for factory `0x00587890`, [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md), shared destructor, marker predicate slots, [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md), and the rejected inherited-default/folded-override choice for `+0x18`.
- 2026-06-18 B001 folded-boolean source-name reanalysis:
  - Score unchanged at `85/88`.
  - Evidence: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) now records current PE-backed folded true/false evidence and the Header/Footer/ColorString vtable pattern. This class's `+0x0c` slot is best described as inferred `IsHeaderMarker()` true, while `+0x10` is inferred `IsFooterMarker()` false. Names remain descriptive until final source declarations are ready because the physical stubs are also used by Effects and runtime tables.
- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, four-byte object shape, vtable membership, shared destructor, boolean virtual helpers, and factory are documented; final semantic names for the boolean slots remain medium-confidence. Evidence: vtable `0x0062d6ac`, factory `0x00587890-0x005878fe`, shared destructor `0x00514e60-0x00514e98`, and `SystemMessagePanes` cross-references.
- 2026-06-03: Rechecked the factory and vtable with IDA MCP, corrected the factory half-open endpoint from `0x005878fe` to `0x005878ff`, added the `0x0058af40-0x0058af48` default true helper, and recorded the shared destructor's extra dialog-creator vtable references.
  - Before: completion/confidence `70/78`, reconstructable/parent metadata blank.
  - After: completion/confidence `76/82`, reconstructable true, attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at position 30.
  - C++ remains blank because final source names for the boolean/default virtual slots are not at the 95% reconstruction threshold.
- 2026-06-07 A001 marker evidence refresh:
  - Before: the page summarized the factory/vtable evidence but still carried generated-file wording and did not link the read-only-data block or exact helper child pages.
  - After: raised to `82/86`, added source-facing placement, vtable layout, helper/read-only-data links, sibling relationship, and score rationale.
  - Summary/evidence: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md), [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md), [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md), and [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) agree on the tiny marker-entry role and shared helper caveats.
- 2026-06-12 C001 Batch C001-003 gate refresh:
  - Before: `82/86`; exact vtable children under [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) could not route to the class under the strict `85/85` gate.
  - After: `85/88`; [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md) routes to this class.
  - Summary/evidence: C001 live IDA MCP confirmed the exact locator/vtable child bytes, `??_R4HeaderSystemMessage@@6B@`, `??_7HeaderSystemMessage@@6B@`, 14 vtable xrefs, and the `0x24` / 36-byte child size (Verified with `int_convert.py`).
