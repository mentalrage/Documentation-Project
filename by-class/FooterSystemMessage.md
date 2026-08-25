*** UID:00005D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FooterSystemMessage : public SystemMessage
{
public:
    virtual bool IsFooterMarker() const { return true; }
    virtual SystemMessage *Clone() { return new FooterSystemMessage; }
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FooterSystemMessage

## Status

- Completion/confidence: `92/94`; the class declaration, inheritance, public
  overrides, fieldless layout, factory behavior, inherited defaults, source
  order, and compiler exclusions are source-ready.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Non-contiguous destructor helper: [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- Inherited one-line count: [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
- Exact vtable data: [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md)
- Source-facing placement: position 30 after
  [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md) in
  `NexusTK/social/SystemMessagePanes.cpp`.
- Reconstructable: true; the managed block is the complete minimum-override
  class declaration. Shared scalar-delete/folded bodies remain on their
  existing compiler/physical evidence routes.

## Class Purpose

`FooterSystemMessage` is the sibling marker entry to [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md). It constructs a tiny `LObject`-based marker object and installs the `FooterSystemMessage` vtable for the system-message entry stream.

The class differs from `HeaderSystemMessage` primarily by factory address and vtable pointer. The tiny destructor, boolean virtuals, and default true helper are shared/folded support rather than footer-exclusive source bodies.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00514e60-0x00514e98` | scalar deleting destructor | Shared small marker-entry destructor; calls `LObject` cleanup and conditionally deletes storage. |
| `0x0055c1c0-0x0055c1c3` | inferred `IsHeaderMarker` virtual | Returns false for the marker identity slot at vtable `+0x0c`. Descriptive name inferred from the Header true / Footer false / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x0055c1b0-0x0055c1b3` | inferred `IsFooterMarker` virtual | Returns true for the paired marker identity slot at vtable `+0x10`. Descriptive name inferred from the Header false / Footer true / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x00587900-0x0058796f` | `CreateInstance` | Allocates four bytes, constructs `LObject`, installs `FooterSystemMessage` vtable, and returns the marker object. |
| `0x0058af40-0x0058af48` | inherited `GetLineCount` | Returns integer line count one and consumes draw-context plus signed-short width arguments; used by both header/footer marker vtables. |

## Vtable Layout

The marker vtable starts at `0x0062d6d0` inside [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md):

| Slot | Target | Meaning |
| --- | --- | --- |
| `+0x00` | `0x00514e60` | Shared `LObject` scalar deleting destructor. |
| `+0x04` / `+0x08` | inherited/empty slots | Runtime-class/no-op inherited marker slots. |
| `+0x0c` | `0x0055c1c0` | Inferred `IsHeaderMarker()` false slot; folded body [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `+0x10` | `0x0055c1b0` | Inferred `IsFooterMarker()` true slot; folded body [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `+0x14` | `0x00587900` | Footer marker factory. |
| `+0x18` | `0x0058af40` | Inherited `SystemMessage::GetLineCount` default using `retn 8`. |
| `+0x1c` | `0x0041b6c0` | Inherited no-op `SystemMessage::Draw` body on the established LObject folded route. |

## Evidence Notes

- IDA names the vtable at `0x0062d6d0` as `FooterSystemMessage`.
- The vtable points at the same small destructor helper as `HeaderSystemMessage`, plus factory `0x00587900` and the same tiny boolean helper pair.
- 2026-06-03 IDA MCP recheck resolves the factory as `0x00587900-0x0058796f`: it allocates four bytes through `sub_4F4AA0`, calls the `LObject` shell constructor at `sub_4F4A80`, writes vtable `0x0062d6d0`, and returns null only on allocation failure.
- Vtable slot order from IDA data words is destructor `+0x00`, inherited/empty slots at `+0x04`/`+0x08`, false/true boolean stubs at `+0x0c`/`+0x10`, factory `+0x14`, default true helper `+0x18`, and another null slot at `+0x1c`.
- The shared destructor `0x00514e60` is also referenced by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables, so it is LObject scalar-delete glue reused by several tiny marker/creator classes rather than an exclusive header/footer body.
- Generated output currently exposes only the factory in `class_FooterSystemMessage.cpp`; its inherited/shared destructor and boolean virtual slots are not emitted there.
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) places the `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtables in the `0x0062d6ac-0x0062d6f4` marker/color-message block.
- 2026-06-12 C001 live IDA MCP split [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) and confirmed this class owns the exact `0x0062d6cc-0x0062d6f0` locator/vtable child [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md), with 14 vtable data xrefs and a `0x24` / 36-byte range (Verified with `int_convert.py`).

## Score Rationale

- Completion `92` reflects a complete source declaration, exact inheritance,
  four-byte fieldless layout, public access, source order, factory/clone
  semantics, inherited count/draw/header defaults, true footer override, and
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
recovered. The audit checked factory `0x00587900-0x0058796f`, shared scalar
deleting destructor [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md),
shared true/false marker stubs [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md),
one-line virtual [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md),
and exact vtable child [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md).

The factory allocates four bytes, constructs an `LObject` shell, installs the
`FooterSystemMessage` vtable, and returns null only on allocation failure.
[UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md) proves slot `+0x00` shared destructor, `+0x04/+0x08`
inherited/runtime slots, `+0x0c` false `IsHeaderMarker` pattern, `+0x10` true
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
- Override inventory: true footer predicate and concrete clone only. The false
  header predicate, integer one-line count, and no-op draw are inherited from
  SystemMessage. This is the minimum source model that regenerates the exact
  eight-slot vtable.
- Compiler boundaries: the scalar deleting destructor, vptr store,
  FooterSystemMessage RTTI/vtable bytes, and physically folded boolean/no-op
  bodies are not handwritten here. UID0003GE remains semantic evidence owned
  by this class but becomes a non-emitting compiler-data page.
- Rejected alternatives: a standalone factory helper, free line-count helper,
  two duplicate folded count overrides, extra marker fields, direct LObject
  inheritance, and handwritten ABI arrays would contradict the recovered base,
  four-byte allocation, slot parity, or source policy.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
- [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md)
- [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md)

## Changes

- 2026-07-19 B002 UID000246 accepted callback:
  - Raised `85/88` to `92/94`, set source position 30, and installed the
    complete minimum-override `SystemMessage`-derived declaration.
  - Preserved the exact four-byte allocation/factory, vtable/RTTI, folded
    predicates, inherited count/draw, scalar-wrapper, source placement,
    negative evidence, and historical B011 disposition.
- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for factory `0x00587900`, [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md), shared destructor, marker predicate slots, [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md), and the rejected inherited-default/folded-override choice for `+0x18`.
- 2026-06-18 B001 folded-boolean source-name reanalysis:
  - Score unchanged at `85/88`.
  - Evidence: [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) now records current PE-backed folded true/false evidence and the Header/Footer/ColorString vtable pattern. This class's `+0x0c` slot is best described as inferred `IsHeaderMarker()` false, while `+0x10` is inferred `IsFooterMarker()` true. Names remain descriptive until final source declarations are ready because the physical stubs are also used by Effects and runtime tables.
- 2026-05-28: Corrected the shared scalar deleting destructor endpoint from `0x00514e97` to `0x00514e98`. Evidence: IDA MCP reports `sub_514e60` as `0x00514e60-0x00514e98`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/78`. Summary: marker-entry purpose, vtable membership, factory/destructor/boolean virtuals, and generated-output limitation are documented, but the semantic names of the boolean slots are still not final. Evidence: vtable address `0x0062d6d0`, factory `0x00587900-0x0058796e`, shared destructor `0x00514e60-0x00514e98`, and system-message pane cross-references.
- 2026-06-03: Rechecked the factory and vtable with IDA MCP, corrected the factory half-open endpoint from `0x0058796e` to `0x0058796f`, added the `0x0058af40-0x0058af48` default true helper, and recorded the shared destructor's extra dialog-creator vtable references.
  - Before: completion/confidence `70/78`, reconstructable/parent metadata blank.
  - After: completion/confidence `76/82`, reconstructable true, attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at position 40.
  - C++ remains blank because final source names for the boolean/default virtual slots are not at the 95% reconstruction threshold.
- 2026-06-07 A001 marker evidence refresh:
  - Before: the page summarized the factory/vtable evidence but still carried generated-file wording and did not link the read-only-data block or exact helper child pages.
  - After: raised to `82/86`, added source-facing placement, vtable layout, helper/read-only-data links, sibling relationship, and score rationale.
  - Summary/evidence: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md), [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md), [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md), and [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) agree on the tiny marker-entry role and shared helper caveats.
- 2026-06-12 C001 Batch C001-003 gate refresh:
  - Before: `82/86`; exact vtable children under [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) could not route to the class under the strict `85/85` gate.
  - After: `85/88`; [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md) routes to this class.
  - Summary/evidence: C001 live IDA MCP confirmed the exact locator/vtable child bytes, `??_R4FooterSystemMessage@@6B@`, `??_7FooterSystemMessage@@6B@`, 14 vtable xrefs, and the `0x24` / 36-byte child size (Verified with `int_convert.py`).
