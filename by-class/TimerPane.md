*** UID:0000F3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum TimerDisplayFormat
{
    kTimerDisplaySeconds = 0,
    kTimerDisplayMinutesSeconds = 1,
    kTimerDisplayHoursMinutesSeconds = 2
};

enum TimerMode
{
    kTimerModeStatic = 0,
    kTimerModeCountUp = 1,
    kTimerModeCountDown = 2,
    kTimerModeInactive = 3
};

class TimerPane : public Pane
{
public:
    TimerPane(int x, int y, TimerDisplayFormat displayFormat);
    virtual ~TimerPane();

    void SetTimer(TimerMode mode, unsigned int seconds);

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    static Point GetDisplaySize(TimerDisplayFormat displayFormat);
    void DrawDigit(int x, int y, short frameIndex);
    void UpdateDisplaySeconds();

    __time64_t m_startTime;
    __time64_t m_endTime;
    TimerDisplayFormat m_displayFormat;
    int m_positionX;
    int m_positionY;
    TimerMode m_timerMode;
    unsigned int m_displaySeconds;
};

extern TimerPane *g_pTimerPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TimerPane

## UID00029O Status-Layer Dependency - 2026-07-21

The constructor's sole parent-layer expression uses independent `g_pStatusPaneLayer`. The complete TimerPane inheritance, singleton, timer/event facets, digit resources, SetTimer/OnTimer/OnPaint methods, display helpers, destructor/thunks, fields, and current formal declarations remain unchanged; only the old aggregate dependency spelling is superseded.

## Status

- Implemented score: `91/93`; source owner/emitter remains [UID:0000OU][TimerPane](by-file/TimerPane.md) at `NexusTK/map/TimerPane.cpp`.
- Exact code family: [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) plus eight source children UID0004MG-UID0004MN and four compiler-only children UID0004MO-UID0004MR.
- Singleton: [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) at `0x0069b4d8`.
- Historical `source-3/simroot_v2/class_TimerPane.cpp`, blank class output, ten-function inventory, and unresolved source placement are superseded source-recovery states, not current destinations.
- The class closes before `[[CHILDREN]]`, so every exact child definition emits at namespace scope.

## Class Purpose

`TimerPane` is a server-controlled timer display pane for the live map UI. It supports static display, count-up, countdown, and delete modes, and draws the timer as sprite digits from `NUMBER.EPF` or `NUMBER.EPD`.

The source class inherits only `Pane`. Pane's concrete `0xf8` layout already includes EventHandler and TimerHandler facets at `+0xa0/+0xa4`; the secondary and tertiary vtable views do not justify extra source bases.

## Method Notes

| Source child | Exact role and behavior |
| --- | --- |
| [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md) | `Pane(1)`, early singleton publication, exact 2/5/8 geometry, status-layer/render setup, start-time capture, 100 ms schedule. It intentionally omits initialization of `m_endTime` and `m_displaySeconds`. |
| [UID:0004MH][0x00598850-0x00598878.TimerPaneDestructor](by-memory/0x00598850-0x00598878.TimerPaneDestructor.md) | Ordinary virtual source body only clears `g_pTimerPane`; vptr restoration and Pane teardown are compiler/base effects. |
| [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md) | Void `(TimerMode,unsigned int)` setter. It performs the second time read/update before assigning the new end time, preserving the old-end countdown behavior across six MapPane calls. |
| [UID:0004MJ][0x00598900-0x00598959.TimerPaneOnTimer](by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md) | Inherited TimerHandler override `(int,int,int) -> bool`; invalidates/reschedules while active, marks for deletion on expiry, and always returns true. |
| [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md) | Primary Pane slot `+0x44`; unsigned HH/MM/SS math, exact 2/5/8 fall-through glyph sequence, colon frame 10, and no invalid-format default. |
| [UID:0004ML][0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw](by-memory/0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw.md) | Retained no-xref private static helper returning Point height 70 and width `2/5/8 * 35`; complete body duplicated in the constructor. |
| [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md) | Void member `(int,int,short)` selecting NUMBER.EPF only for asset flag 1, otherwise NUMBER.EPD, then directly calling `g_pfnBlitSprite`. |
| [UID:0004MN][0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw](by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md) | Retained no-xref private member helper; low-32-bit elapsed/remaining seconds for modes 1/2, no change for modes 0/3, duplicated in SetTimer and OnPaint. |

Compiler-only children [UID:0004MO][0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton](by-memory/0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton.md), [UID:0004MP][0x00598c3b-0x00598c45.TimerPaneEventHandlerDestructorAdjustorThunk](by-memory/0x00598c3b-0x00598c45.TimerPaneEventHandlerDestructorAdjustorThunk.md), [UID:0004MQ][0x00598c46-0x00598c50.TimerPaneTimerHandlerDestructorAdjustorThunk](by-memory/0x00598c46-0x00598c50.TimerPaneTimerHandlerDestructorAdjustorThunk.md), and [UID:0004MR][0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor](by-memory/0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor.md) document constructor unwind, `-0xa0/-0xa4` destructor adjustors, and the scalar deleting wrapper. They remain non-reconstructable with blank formal code; the constructor, Pane-only inheritance, and virtual destructor generate them.

## Timer Modes

| Mode | Behavior |
| --- | --- |
| `0` | Static value mode. Map packet handling ignores this mode if no timer pane exists. |
| `1` | Count-up display. Draw computes `now - startTime`. |
| `2` | Countdown display. Draw computes `endTime - now`. |
| `3` | Initial/delete mode. Constructor initializes to `3`; map packet mode `3` marks the pane for deletion. |

## Layout Notes

Exact object size is `0x120`, closed by source declaration order without raw-layout members:

| Offset / extent | Declaration and evidence |
| --- | --- |
| `+0x000..+0x0f7` | Inherited `Pane`, exactly `0xf8`; its inherited facets account for vtable views at `+0xa0/+0xa4`. |
| `+0x0f8..+0x0ff` | `__time64_t m_startTime`; constructor and SetTimer write it. |
| `+0x100..+0x107` | `__time64_t m_endTime`; SetTimer writes, OnTimer/count-down read. |
| `+0x108..+0x10b` | Four-byte `TimerDisplayFormat m_displayFormat`. |
| `+0x10c..+0x10f` | `int m_positionX`. |
| `+0x110..+0x113` | `int m_positionY`. |
| `+0x114..+0x117` | Four-byte `TimerMode m_timerMode`. |
| `+0x118..+0x11b` | `unsigned int m_displaySeconds`. |
| `+0x11c..+0x11f` | Natural tail padding required by eight-byte alignment; no source member and no explicit padding field. |

Public constructor/SetTimer, protected virtual callbacks, and private helpers/fields are the highest-probability access model from callers and virtual routes. Exact access spellings remain a score cap, not a layout blocker. See [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md).

## Evidence Notes

- IDA MCP confirms the six modeled source starts and four compiler starts; raw starts `0x00598af0` and `0x00598be0` are complete executable bodies that IDA does not model and that have no xrefs.
- Constructor/SetTimer callers are from live MapPane opcode `0x67` and retained duplicate `0x005140a0`. The latter has no inbound xref/pointer route and remains MapPane-owned retained packet code.
- `DrawDigit` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`: EPF mode uses `NUMBER.EPF`, legacy mode uses `NUMBER.EPD`.
- `0x00598cc0` is the next class (`TotemFrame`), not part of `TimerPane`.
- Vtable/data/string pages are compiler/source-covered evidence only; no raw vtable, exact storage, pooled string array, or layout duplicate belongs in this class block.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md)
- [UID:0004MH][0x00598850-0x00598878.TimerPaneDestructor](by-memory/0x00598850-0x00598878.TimerPaneDestructor.md)
- [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md)
- [UID:0004MJ][0x00598900-0x00598959.TimerPaneOnTimer](by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md)
- [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md)
- [UID:0004ML][0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw](by-memory/0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw.md)
- [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md)
- [UID:0004MN][0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw](by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md)

## Changes

- 2026-07-13 B003 UID0001KB callback:
  - Raised `88/90 -> 91/93` while preserving owner/emitter UID0000OU and blank optional position.
  - Inserted the exact era-consistent Pane-only `0x120` class declaration with two enums, eight source declarations, global extern, natural tail padding, and `[[CHILDREN]]` after the class close.
  - Linked all source children, documented both retained no-xref helpers, separated four compiler children, corrected OnTimer/OnPaint names and ABIs, preserved timing/constructor omissions/resource callback/MapPane duplicate history, and rejected raw layout/vtable/compiler emissions.

- 2026-06-07 Batch 058 parent-chain repair:
  - Before: `AUTOGEN_PARENT_UID:` blank, so [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) reported `autogen_parent_unknown` for direct parent `0000F3`.
  - After: `AUTOGEN_PARENT_UID:0000OU`.
  - Evidence: [UID:0000OU][TimerPane](by-file/TimerPane.md) was refreshed to `87/86` with exact TimerPane memory, singleton, resource, packet, and boundary evidence, satisfying the corrected 85/85 child-and-parent gate for this class route.
- 2026-06-07 A008 alias cleanup: normalized the `DrawDigit` `byte_66DA97` branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from IDA-confirmed method starts, timer modes, layout offsets, singleton behavior, resource references, packet-handling construction evidence, and exact next-class boundary note.
- 2026-05-31: Reconstructable metadata was blank and the memory range reference still used the one-past-end address.
  - Before: `RECONSTRUCTABLE:` and `0x005986e0-0x00598cbf`.
  - After: `RECONSTRUCTABLE:TRUE` and [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md).
  - Summary/evidence: IDA MCP rechecked the complete TimerPane function set and confirmed the scalar deleting destructor ends at `0x00598cbe`, with `0x00598cbf` belonging to alignment padding before `TotemFrame`.
