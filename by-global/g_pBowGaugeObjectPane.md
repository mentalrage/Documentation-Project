*** UID:0000QA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BowGaugeObjectPane;

BowGaugeObjectPane *g_pBowGaugeObjectPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pBowGaugeObjectPane

## Status

- Address: `0x0069ba24`
- Primary memory doc: [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- Exact type: `BowGaugeObjectPane *`.
- Owner class: [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- Owner source: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md); historical private [UID:0000P1][UserPane](by-file/UserPane.md) grouping is retained only as a weaker rejected placement alternative.
- Linkage/position: one externally linked definition at BowGauge source position 0; the class declaration carries the matching `extern` declaration.
- Confidence: very strong.

## Symbol Role

`g_pBowGaugeObjectPane` stores the active local-player bow gauge child pane. `BowGaugeObjectPane::BowGaugeObjectPane` writes it, the scalar deleting destructor clears it, and `UserPane` show/hide/destructor paths use it to position, hide, remove timers from, or mark the bow-gauge pane for deferred deletion.

## 2026-07-21 B002 One-Definition And Lifetime Resolution

### Definition and physical storage

- This page owns the only source definition. [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) is the exact loader-zeroed four-byte physical backing page and is now false/non-emitting.
- The external definition precedes the complete class and method emission at source position 0. A forward declaration makes the pointer definition compile-visible before the full class declaration.
- Explicit `= 0` is period-plausible, source-ready, and generates the proven virtual-tail zero storage. File bytes cannot distinguish explicit from implicit zero initialization; that lexical uncertainty caps confidence but does not affect behavior.
- External linkage is required by separate UserPane construction, show/hide/update, and destructor consumers. `static`, anonymous namespace, header definition, local static, and accessor-only alternatives are rejected.

### Exact 13-reference lifecycle

- [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) publishes through compiler-generated empty Singleton base lowering at `0x00538be4`; no explicit source assignment is added there.
- The BowGauge scalar deleting destructor clears storage at `0x0053cfe6` through compiler/template cleanup before Pane teardown and storage release.
- UserPane nondeleting destructor reads at `0x005a2d1b`/`0x005a2d2d`, ShowNameLabel at `0x005a8e97`/`0x005a8ea2`/`0x005a8ef2`/`0x005a8f0e`/`0x005a8f3f`, HideNameLabel at `0x005a8f71`, AdvanceMovementSendTick at `0x005a8fe5`, and scalar destructor at `0x005b82f2`/`0x005b8304`.
- The destructor paths remove pending timers and mark the pane for deferred deletion; ShowNameLabel shows/positions/starts animation; HideNameLabel cancels timers; movement update forwards the adjusted tick to [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md).

### Ownership and negative routes

- BowGauge owns the semantic global because its constructor/destructor template lifecycle publishes/clears it and its dedicated class/file/resource/vtable family identifies the pointed type.
- UserPane is the sole lifecycle consumer family but not the definition owner. ObjectPane, AttachedObjectPane, the broad mixed aggregate, Balloon pool storage, and Parcel/Patch successor storage are rejected owners.
- VA-immediate/data-reference scans find exactly the 13 code operand routes. No RVA literal, raw-offset pointer, non-code table, duplicate slot, pointer-to-pointer, integer-sentinel, or alternate global exists.
- The current executable's physical target is loader-zeroed `.data` virtual tail, disproving historical `0xffffffff` initializer text.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069ba24` reports constructor write evidence at `0x00538be4` and destructor clear evidence at `0x0053cfe6`.
- The same xrefs include `UserPane` non-deleting destructor, `ShowNameLabel`, `HideNameLabel`, and scalar deleting destructor paths.
- The tiny timer cleanup helper at [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) is called only through these `UserPane` cleanup/hide paths.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed exactly 13 xrefs to `0x0069ba24`: constructor publish at `0x00538be4`, scalar deleting destructor clear at `0x0053cfe6`, two non-deleting `UserPane` destructor cleanup refs at `0x005a2d1b`/`0x005a2d2d`, five show/position refs inside `0x005a8e70`, one hide/timer-cleanup ref at `0x005a8f71`, one draw/progress ref at `0x005a8fe5`, and two scalar deleting `UserPane` destructor cleanup refs at `0x005b82f2`/`0x005b8304`.
- 2026-06-14 decompilation confirms constructor `sub_538BC0` (`0x4a` / 74 bytes, Verified with int_convert.py) initializes the pane base, publishes the singleton, and installs the three `BowGaugeObjectPane` vtable views.
- 2026-06-14 decompilation confirms scalar deleting destructor `sub_53CFE0` (`0x45` / 69 bytes, Verified with int_convert.py) clears the singleton, calls base cleanup, and conditionally frees the object. The timer cleanup helper `sub_538C40` is `0xb` / 11 bytes (Verified with int_convert.py) and removes pending timer state through the `+0xa4` subobject.
- 2026-06-14 UserPane consumer refresh: `sub_5A8E70` (`0xea` / 234 bytes, Verified with int_convert.py) positions and shows the bow gauge using local-player state, `sub_5A8F60` (`0x2c` / 44 bytes, Verified with int_convert.py) hides it and removes pending timers, `sub_5A8FC0` (`0x32` / 50 bytes, Verified with int_convert.py) advances the displayed gauge value, and `sub_5B8230` (`0x165` / 357 bytes, Verified with int_convert.py) mirrors the destructor cleanup in the scalar deleting `UserPane` path.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), which surfaces to `auto-generated/NexusTK/ui/panels/BowGaugeObjectPane.cpp` without a dead end.
- Completion is `92` because the page records the exact type/name/address, current zero storage, complete 13-reference lifecycle, compiler publication/clear, external one-definition policy, standalone source order, UserPane consumers, boundaries, negative routes, and final formal definition.
- Confidence is `94` because MCP/PE/xref/class/resource evidence converges on identity, linkage, and owner. It is capped only because stripped source cannot prove explicit-zero formatting or the exact original lexical declaration style.

## Cross-References

- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)

## Changes

- 2026-07-21 B002 UID0001PY implementation: raised `87/90` to `92/94`, fixed position 0, installed the sole external zero-initialized definition, resolved physical UID0001PY as non-emitting storage, added complete lifetime/xref/linkage/source-order/negative evidence, and historicalized private-UserPane and `0xffffffff` uncertainty.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, memory page, owner class/source, singleton role, constructor/destructor xrefs, UserPane consumers, timer cleanup helper, and refs.
- 2026-06-05: Marked reconstructable under [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md). Evidence: live IDA MCP reports constructor/destructor xrefs plus UserPane consumers for `0x0069ba24`; decompilation confirms `0x00538bc0` writes `dword_69BA24` and `0x0053cfe0` clears it.
- 2026-06-14 A003 goal2 score pass: raised `86/84` to `87/90`.
  - Evidence: live IDA MCP reconfirmed the 13-ref singleton map, constructor/destructor/timer helper bodies, UserPane show/hide/progress/destructor consumers, and non-dead-ended BowGaugeObjectPane owner/emitter route.
  - Code-entry decision: no reconstruction C++ was added; the route and numeric gate are present, but final declaration spelling and UserPane integration/source split remain below source-quality evidence.
