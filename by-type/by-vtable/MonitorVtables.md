*** UID:00052D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Monitor Vtables

## Type Summary

This page records the two compiler-generated one-slot vtables and their self-only RTTI for [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md). The exact cells are owned by [UID:000528][0x0061fbe4-0x0061fbf4.MonitorVtableData](by-memory/0x0061fbe4-0x0061fbf4.MonitorVtableData.md).

## Monitor Virtual Layout

- Complete-object locator: `0x0064c56c`, referenced by prefix cell `0x0061fbe4`.
- Vtable address: `0x0061fbe8`, decorated name `??_7Monitor@@6B@`.
- Sole slot: scalar-deleting destructor `0x005288a0`.
- Constructor/destructor/wrapper stores: `0x0052860e`, `0x005286d6`, `0x005288a9`.
- Inheritance: Monitor only; no base-class chain, secondary view, or additional virtual slot is present.

## MonitorCondition Virtual Layout

- Complete-object locator: `0x0064c5b4`, referenced by prefix cell `0x0061fbec`.
- Vtable address: `0x0061fbf0`, decorated name `??_7MonitorCondition@@6B@`.
- Sole slot: scalar-deleting destructor `0x005288f0`.
- Constructor/destructor/wrapper stores: `0x00528774`, `0x005287f6`, `0x005288f9`.
- Inheritance: MonitorCondition only; the stored Monitor pointer is composition, not inheritance.

## Source Disposition

The source declarations use virtual ordinary destructors. Visual C++ generates both scalar wrappers, vtables, complete-object locators, class hierarchy descriptors, base arrays, and type descriptors. This page must remain non-reconstructable/non-emitting with blank formal CPP/H; explicit compiler arrays would be reverse-engineered scaffolding rather than plausible original source.

## Score Rationale

Exact cells, slot targets, vptr stores, RTTI identities, and self-only inheritance are direct. Completion/confidence remain below 100 only because compiler layout is toolchain output rather than human source and final build equivalence belongs to a later rebuild pass.

## Changes

- 2026-08-15 B004 UID0000LI callback: created paired type-level vtable/RTTI coverage and declaration-generated no-code proof.
