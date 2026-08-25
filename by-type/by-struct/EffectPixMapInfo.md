*** UID:0001UA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectPixMapInfo
{
    int frameRemapOrPaletteSlot;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectPixMapInfo

## Status

- Confidence: strong for size, owning array offsets, loader/read pattern, renderer consumption, and `EffectObjImageLib` ownership; medium for final source-facing typedef/member name.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Source resource: `EFFECT.FRM`.
- Size: `0x04` bytes.
- Owner/emitter route: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), because this record is source-declared/generated with the effect image-library resource loader. It emits at position `3`, before the global singleton declaration and methods that consume remap entries.

## Layout

```text
EffectPixMapInfo
  +0x00  int frameRemapOrPaletteSlot
```

## Notes

- Current generated output calls this protected-array element `EffectPixMapInfo`, but IDA proves each entry is a single four-byte value read from `EFFECT.FRM`; it may become a typedef or a one-field record in final source.
- `EffectObjImageLib` stores the `EFFECT.FRM` count at object offset `+0x4c`, the entry buffer pointer at `+0x50`, and the fallback entry at `+0x58`.
- `RenderEffectFrame` indexes this array by animation frame and passes the selected value as the palette/remap slot for palette category `11`.
- Object offset `+0x58` stores a fallback `EffectPixMapInfo` value initialized to `-1`.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms `EFFECT.FRM` begins with a four-byte count and then reads one four-byte value per remap entry.
- IDA MCP `decompile 0x004de190` indexes object offset `+0x50` by `4 * frameIndex`, falls back to object offset `+0x58`, and passes the selected value to the palette lookup with category `11`.
- 2026-06-04 live IDA MCP `lookup_funcs` confirms `sub_4DE7D0` at `0x004de7d0` is `0x453` bytes and `sub_4DE190` at `0x004de190` is `0x110` bytes.
- 2026-06-04 live IDA MCP xrefs and `py_eval` confirm wide-string globals `aEffectTbl` at `0x0061c230` and `aEffectFrm` at `0x0061c248`; `aEffectFrm` has its loader data xref at `0x004deb48`.
- In the loader, live IDA disassembly shows `0x004deb3c` initializes `this+0x58` to `-1`, `0x004deb5c-0x004deb68` reads the four-byte `EFFECT.FRM` count, `0x004deb80-0x004deb8f` allocates `4 * count`, and `0x004debc4/0x004debca` stores the count and pointer at `this+0x4c/+0x50`.
- In the loader loop, live IDA shows each destination selected as `this+0x50 + index * 4` with fallback to `this+0x58`, then read with `sub_49C310(..., 4)` at `0x004debeb-0x004debf4`.
- In the renderer, live IDA shows `0x004de1d4-0x004de1ec` selecting `this+0x50 + frameIndex * 4` or fallback `this+0x58`, and `0x004de213-0x004de218` passes the selected dword to palette lookup `sub_543E40` with category `0x0b`.
- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reconfirmed loader `0x004de7d0` size `0x453`, render helper `0x004de190` size `0x110`, constructor `0x004ddf60` size `0xee`, ordinary destructor `0x004de050` size `0x13a`, and scalar deleting destructor `0x004e62f0` size `0x166`.
- 2026-06-14 live decompilation of `0x004de7d0` shows `EFFECT.FRM` opened at `0x004deb57`, count read with `sub_49C310(&v53, 4)`, array allocation as `4 * count`, count/pointer stores at `this+0x4c/+0x50`, fallback initialization at `this+0x58 = -1`, and per-entry reads of exactly four bytes into either `this+0x50 + index * 4` or fallback `this+0x58`.
- 2026-06-14 live decompilation of `0x004de190` shows render-time remap selection from `this[20] + 4 * frameIndex` or `this + 22`, then passes the selected dword to `sub_543E40(11, value, 0)`. Live `xrefs_to 0x0061c248` returns the single `EFFECT.FRM` loader xref at `0x004deb48`.

## Score Rationale

- Completion is `87` because the page now has current IDA confirmation for the owning class lifecycle methods, the exact loader/read pattern, the single `EFFECT.FRM` string xref, renderer consumption, owner/emitter route, emitter order, and formal one-field declaration.
- Confidence is raised from `88` to `91` because the type is only one dword and live loader/render evidence agrees with [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md). It stays below final-audit levels because the final source may choose a typedef, a one-field struct, or a differently named member.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)

## Changes

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `85/91`, blank formal block and no emitter position.
  - After: `87/91`, formal one-field `EffectPixMapInfo` declaration attached at emitter position `3` under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, `EFFECT.FRM` count/read proof, `+0x4c/+0x50/+0x58` count/pointer/fallback storage, renderer remap/fallback selection, and palette category `11` consumption to emit the one-dword support type. Final typedef/member spelling remains provisional.

- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `70/84`.
  - Summary/evidence: IDA MCP loader and render checks confirm this is a four-byte resource-derived remap/palette-slot value; the final source-facing name is still provisional.
- 2026-06-04 live IDA MCP evidence and parent assignment:
  - Before: scores were `70/84` and the page was not attached to its owning file.
  - After: scores set to `82/88` and `AUTOGEN_PARENT_UID:0000IY`.
  - Summary/evidence: live IDA MCP confirmed exact loader/render function sizes, the `aEffectFrm` wide-string global and xref, `this+0x4c/+0x50/+0x58` count/pointer/fallback storage, `4 * count` allocation, per-entry four-byte reads, renderer fallback selection, and palette category `0x0b` consumption. B008's 2026-06-30 callback later attached the formal one-field declaration while keeping typedef/member spelling provisional.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, with legacy parent wording and older live evidence.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:91`, current owner/emitter wording, and live IDA evidence for loader/render/lifecycle sizes, `EFFECT.FRM` xref, exact four-byte reads, and palette category `11` consumption.
  - Summary/evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed `+0x4c/+0x50/+0x58` count/pointer/fallback storage and render-time selection. B008's 2026-06-30 callback later attached formal first-draft C++ with the final typedef/member name still provisional.
