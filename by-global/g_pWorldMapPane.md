*** UID:0004T9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WorldMapPane;
WorldMapPane *g_pWorldMapPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pWorldMapPane

## Status

- Completion: 92.
- Confidence: 94.
- Source owner and emitter: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md), reconstructed as `NexusTK/map/WorldMapPane.cpp`.
- Physical storage: [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md).
- Source disposition: the sole zero-initialized source definition for the active `WorldMapPane` singleton. The physical storage page records the address and binary evidence but does not emit a duplicate definition.

## Source Definition

The source-authored object is one file-scope pointer initialized to null:

```cpp
class WorldMapPane;
WorldMapPane *g_pWorldMapPane = 0;
```

The forward declaration is retained in this destination-specific block so the definition remains independently valid when assembled before the complete class declaration. [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) supplies the complete class and matching `extern WorldMapPane *g_pWorldMapPane;` declaration.

## Physical Storage And Initialization

- The exact slot is `[0x0069b454,0x0069b458)`, four bytes wide, in the virtual tail of `.data`.
- The image base is `0x00400000`; the slot RVA is `0x0029b454`. The `.data` section starts at RVA `0x0026d000`, has virtual size `0x0002fe24`, raw size `0x0000d800`, and raw pointer `0x0026ac00`.
- The slot lies at section offset `0x0002e454`, beyond the raw-backed end RVA `0x0027a800` but before the virtual end RVA `0x0029ce24`. The loader therefore supplies `00 00 00 00` zero fill.
- Fresh live IDA bytes at `0x0069b454` also read `00 00 00 00`. Older `ff ff ff ff` documentation came from an unbacked-tail database artifact and is preserved only as superseded history on the physical page.
- The source initializer `= 0` is therefore behaviorally exact and does not duplicate a raw storage array or address-bound declaration.

## Lifecycle And Xrefs

Six direct binary references define the complete lifecycle:

- The [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) publishes `this` to the slot and clears it on the constructor-failure path.
- The ordinary WorldMapPane destructor clears the slot during source-authored teardown.
- The compiler cleanup path also clears the slot while unwinding partially completed construction; that compiler lowering is evidence for the source global but is not handwritten C++.
- Two live read sites obtain the active world-map pane through this slot.

The constructor's early publication and failure clear agree with the `Singleton<WorldMapPane>` base relationship. They do not justify an explicit raw store in the human constructor: the base/source singleton contract and this global definition express the source cause.

## Ownership And Source Placement

The semantic global belongs to WorldMapPane.cpp because all publication, teardown, cleanup, and live-use evidence concerns the active `WorldMapPane` instance. It is not owned by the broad executable aggregate, MapPane's packet parser/factory, resource libraries, or the read-only-data parent. The file page is the narrowest defensible source owner and the only emitter route.

Adjacent IME, startup-logo, and image-library globals are separate objects. No evidence supports merging their storage or moving this definition to a generic globals translation unit.

## Negative Evidence

- No nonzero source initializer exists; `0xffffffff` is rejected by live bytes and PE section mapping.
- No second semantic definition, alias object, import, or independently owned global was found.
- No raw address, byte array, linker directive, vtable/RTTI body, exception state, or compiler cleanup body belongs in the source definition.
- No evidence supports ownership by MapPane.cpp, ImageLib.cpp, PaletteLib.cpp, or the broad WorldMapPane executable aggregate.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md)
- [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md)

