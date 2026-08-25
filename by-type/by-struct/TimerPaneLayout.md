*** UID:0001WE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TimerPaneLayout

## Status

- Type kind: exact non-emitting class/layout evidence. [UID:0000F3][TimerPane](by-class/TimerPane.md) owns the single source declaration.
- Direct owner: [UID:0000F3][TimerPane](by-class/TimerPane.md). [UID:0000OU][TimerPane](by-file/TimerPane.md) remains the source-module owner.
- Implemented metadata is `90/94`, owner UID0000F3, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal. Duplicate class emission is intentionally excluded.
- Pane-only inheritance and every byte through size `0x120` are closed. Original lexical/access spellings remain confidence caps only.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `90` | Exact `0x120` extent, Pane base/facets, all members, types, field users, constructor omissions, natural tail padding, class-source coverage, and no-duplicate-emission disposition are documented. |
| Confidence | `94` | Allocation size, vtable adjustments, field accesses, x86 alignment, and the accepted class block agree byte-for-byte. Only stripped lexical/access spellings remain uncertain. |

## Working Layout

IDA and generated source agree that `TimerPane` is allocated with size `288` bytes (`0x120`).

| Offset / extent | Source declaration | Exact evidence and disposition |
| --- | --- | --- |
| `+0x000..+0x0f7` | inherited `Pane` | Concrete Pane base is exactly `0xf8`. Primary vptr is at `+0`; Pane's inherited EventHandler and TimerHandler facets place secondary/tertiary vptrs at `+0xa0/+0xa4`. TimerPane does not redeclare those bases or fields. |
| `+0x0f8..+0x0ff` | `__time64_t m_startTime` | Constructor and SetTimer write it; count-up reads it. Eight-byte aligned. |
| `+0x100..+0x107` | `__time64_t m_endTime` | SetTimer writes it; OnTimer and count-down read it. Eight-byte aligned. Constructor intentionally does not initialize it. |
| `+0x108..+0x10b` | `TimerDisplayFormat m_displayFormat` | Values `0/1/2` select `SS`, `MM:SS`, or `HH:MM:SS`. Four-byte enum. |
| `+0x10c..+0x10f` | `int m_positionX` | Constructor screen x and initial bounds input. |
| `+0x110..+0x113` | `int m_positionY` | Constructor screen y and every DrawDigit y input. |
| `+0x114..+0x117` | `TimerMode m_timerMode` | Values `0/1/2/3` are static/count-up/count-down/inactive. Four-byte enum. |
| `+0x118..+0x11b` | `unsigned int m_displaySeconds` | Packet seed and low-32-bit elapsed/remaining display value. Constructor intentionally does not initialize it. |
| `+0x11c..+0x11f` | natural tail padding | No read/write. Eight-byte class alignment from `__time64_t` closes allocation size `0x120`; no source field or explicit raw padding member. |

## Evidence

- `MapPane::HandlePacket` allocates `288` bytes before calling `TimerPane::TimerPane`.
- `TimerPane::TimerPane` writes vtables at `+0`, `+0xa0`, and `+0xa4`.
- Source-facing `TimerPane::OnTimer` operates on the inherited `+0xa4` facet and compares `base + 0x100` against current time; `OnTimerTick` is historical naming only.
- Source-facing `TimerPane::OnPaint` reads `+0x108`, `+0x110`, `+0x114`, and `+0x118`; `OnDraw` is historical naming only.
- `TimerPane::SetTimer` writes `+0x0f8`, `+0x100`, `+0x114`, and `+0x118`.
- 2026-05-31 IDA MCP recheck confirms the constructor at `0x005986e0` writes `g_pTimerPane`, installs vtables at `+0x00/+0xa0/+0xa4`, writes `posX`/`posY` at `+0x10c/+0x110`, initializes mode `+0x114` to `3`, writes display format `+0x108`, initializes `startTime` at `+0x0f8`, and schedules the timer callback through `this + 0xa4`.
- 2026-05-31 IDA MCP recheck confirms `SetTimer` at `0x00598880` writes mode `+0x114`, displayed seconds `+0x118`, start time `+0x0f8`, and end time `+0x100`.
- 2026-05-31 IDA MCP recheck confirms source-facing `OnPaint` at `0x00598960` reads display format `+0x108`, `posY` `+0x110`, mode `+0x114`, and displayed seconds `+0x118`, then emits `SS`, `MM:SS`, or `HH:MM:SS`.
- 2026-05-31 IDA MCP boundary check confirms the final `TimerPane` executable byte is `0x00598cbe`; `0x00598cbf-0x00598cc0` is the one-byte alignment gap before `TotemFrame`.
- 2026-06-08 live IDA MCP rechecked the TimerPane function boundaries: constructor `0x005986e0-0x00598842`, destructor body `0x00598850-0x00598879`, `SetTimer` `0x00598880-0x005988f7`, tick callback `0x00598900-0x0059895a`, draw `0x00598960-0x00598ae4`, digit draw `0x00598b40-0x00598bd5`, scalar deleting destructor `0x00598c60-0x00598cbf`, and a single `0xcc` byte at `0x00598cbf` before `TotemFrame`.
- 2026-06-08 live IDA MCP also rechecked [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) at `0x0069b4d8`: eight xrefs across seven functions, including constructor writes at `0x00598731`/`0x00598738`, destructor clear at `0x0059886a`, explicit clear helper `0x00598c30`, scalar deleting destructor clear at `0x00598c80`, and MapPane-side packet helpers.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)
- [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md)
- [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md)
- [UID:0004MJ][0x00598900-0x00598959.TimerPaneOnTimer](by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md)
- [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md)
- [UID:0004MN][0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw](by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md)

## Changes

- 2026-07-13 B003 UID0001KB callback:
  - Raised `86/91 -> 90/94`, set non-reconstructable with blank emitter/formal, and preserved owner UID0000F3.
  - Closed exact Pane-only `0x120` layout, inherited `+0xa0/+0xa4` facets, two 64-bit times, enum/int/unsigned fields, constructor omissions, and natural `+0x11c..+0x11f` tail padding.
  - Historicalized OnTimerTick/OnDraw and unknown-`+0x11c` wording; the class R1 declaration now provides source coverage without duplicate layout emission.

- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, and no parent assignment.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, and `AUTOGEN_PARENT_UID:0000F3`.
  - Summary/evidence: live IDA MCP rechecked TimerPane method boundaries, singleton xrefs, and the `0xcc` byte immediately after the scalar deleting destructor; the direct class parent [UID:0000F3][TimerPane](by-class/TimerPane.md) already clears `88/90`, so the layout now routes to the actual class owner.
- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor/configure/tick/draw/destructor field use and corrected the memory page reference to the last executable byte `0x00598cbe`. The score remains below final-source level because base-class inheritance names and final source split from `MapPane` remain open.
