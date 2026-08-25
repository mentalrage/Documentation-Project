** TARGET-REPORT-UID:0001NZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001NZ Weather/Raining Child Split Research

## Final Recommendation

Create five exact executable child pages under [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](../../../../../by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md), then reclassify `0001NZ` as a reviewed non-emitting Weather/Raining migration index under [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md).

Recommended child pages:

| Range | Page name | Direct owner/emitter | Disposition |
| --- | --- | --- | --- |
| `0x005c12a0-0x005c13a1` | `WeatherLayerPaneConstructor` | [UID:0000G1][WeatherLayerPane](../../../../../by-class/WeatherLayerPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x005c13b0-0x005c1408` | `WeatherLayerPaneOnTimerEvent` | [UID:0000G1][WeatherLayerPane](../../../../../by-class/WeatherLayerPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x005c1410-0x005c145a` | `RainingLayerPaneConstructor` | [UID:0000BJ][RainingLayerPane](../../../../../by-class/RainingLayerPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x005c1460-0x005c180c` | `RainingLayerPaneOnPaint` | [UID:0000BJ][RainingLayerPane](../../../../../by-class/RainingLayerPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x005c1810-0x005c1bc7` | `RainingLayerPaneDrawRainOnTarget` | [UID:0000BJ][RainingLayerPane](../../../../../by-class/RainingLayerPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |

After the child split, change `0001NZ` to `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++. This should follow the executed [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](../../../../../by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) precedent: exact children carry source ownership, while the broad mixed weather-family island remains useful as a migration index only.

Do not change class/file emitter routes in this assignment. The correct child owner is the direct class (`0000G1` or `0000BJ`); current class emitters still route through the conservative weather-family owner `0000P8`, and future one-file versus per-layer migration can move the class route without rewriting these child pages.

No IDA DB edit is recommended.

## Assignment Context

- Batch: `B001-goal2-weather-raining-child-split-0001NZ-20260616`.
- Primary target before this report: [UID:0001NZ] `82/86`, `CANONICAL_OWNER:0000P8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8`, blank final C++.
- Current blocker from the accepted source-container report: exact Weather/Rain executable child pages did not yet exist, so `0001NZ` could not safely become a non-emitting migration index.
- Current `by-memory/-coverage-report.md` row still records the temporary source-bearing aggregate disposition at line `3583`.

## Evidence Checked

### Current docs and child gap

`rg --files by-memory` found no exact child pages for `0x005c12a0`, `0x005c13b0`, `0x005c1410`, `0x005c1460`, or `0x005c1810`. The only executable page currently covering the Weather/Rain island is the broad aggregate `0001NZ`.

The direct parent class docs already clear the parent gate:

- [UID:0000G1][WeatherLayerPane](../../../../../by-class/WeatherLayerPane.md) is `86/88`, documents the constructor/timer ranges, derived constructor callers, base vtable stores, and shared timer vtable slots.
- [UID:0000BJ][RainingLayerPane](../../../../../by-class/RainingLayerPane.md) is `86/88`, documents the rain constructor, paint, target draw ranges, `MapPane` weather-setup caller, base-constructor call, rain vtable stores, and render vtable slots.
- [UID:0002Z7][WeatherLayerPaneVtableData](../../../../../by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md) and [UID:0002Z8][RainingLayerPaneVtableData](../../../../../by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md) already use the same direct class ownership model.

The file/source-family docs remain deliberately conservative:

- [UID:0000P8][WeatherLayerPane](../../../../../by-file/WeatherLayerPane.md) is the weather-layer source-family root and keeps the one-file versus split-file question open.
- [UID:0000MY][RainingLayerPane](../../../../../by-file/RainingLayerPane.md) is a valid `map/RainingLayerPane.cpp` candidate, but current class metadata still routes `RainingLayerPane` through `0000P8`.
- [UID:0001ON][RainCoordinateTables](../../../../../by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) is already rain-owned static data at `86/91`, confirming the table side of the rain source family but not proving final class-file placement.

Generated coverage state was checked only as generated-output/pollution context, not as source truth:

- `auto-generated/-ag-memory-coverage.md` still emits `0001NZ` through `0000P8` to `auto-generated/NexusTK/map/WeatherLayerPane.cpp`.
- Exact Snowing children now emit separately under their class routes after the executed `0001O1` split. This is the local precedent for the Weather/Rain split.
- `auto-generated/-ag-class-coverage.md` currently routes Weather/Raining/Snowing/Swallow classes through `0000P8`, while `auto-generated/-ag-file-coverage.md` also has separate file roots for `WeatherLayerPane.cpp` and `RainingLayerPane.cpp`. This confirms the file split is not settled by generated metadata.

### Live IDA MCP

Active session:

- Session: `c001_midiplayer_rdata_20260615`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- Hex-Rays ready: true.

`lookup_funcs` confirms exact half-open child boundaries:

| Address | IDA state |
| --- | --- |
| `0x005c12a0` | `sub_5C12A0`, size `0x101`, end `0x005c13a1` |
| `0x005c13a1` | not a function |
| `0x005c13b0` | `sub_5C13B0`, size `0x58`, end `0x005c1408` |
| `0x005c1408` | not a function |
| `0x005c1410` | `sub_5C1410`, size `0x4a`, end `0x005c145a` |
| `0x005c145a` | not a function |
| `0x005c1460` | `sub_5C1460`, size `0x3ac`, end `0x005c180c` |
| `0x005c180c` | not a function |
| `0x005c1810` | `sub_5C1810`, size `0x3b7`, end `0x005c1bc7` |
| `0x005c1bc7` | not a function |
| `0x005c1bd0` | successor `sub_5C1BD0`, size `0xae` |
| `0x0050db50` | `sub_50DB50`, size `0x163` |

`get_bytes` confirms pure `0xcc` padding between children:

| Gap | Bytes |
| --- | --- |
| `0x005c13a1-0x005c13b0` | 15 bytes `0xcc` |
| `0x005c1408-0x005c1410` | 8 bytes `0xcc` |
| `0x005c145a-0x005c1460` | 6 bytes `0xcc` |
| `0x005c180c-0x005c1810` | 4 bytes `0xcc` |
| `0x005c1bc7-0x005c1bd0` | 9 bytes `0xcc` outside the parent range, already covered by the existing padding row |

`xrefs_to`, vtable bytes, and `callees` confirm ownership and reachability:

- `0x005c12a0` is called only from derived weather constructors at `0x005c141a` (rain), `0x005c1bfb` (snow), and `0x005c225b` (swallow).
- `0x005c13b0` is the shared timer handler target in weather vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.
- `0x005c1410` is called from `MapPane` weather setup at `0x0050dc3b`.
- `0x005c1460` is referenced by the rain paint vtable slot at `0x00631264`.
- `0x005c1810` is referenced by the rain target-draw vtable slot at `0x00631230`.
- Weather vtable stores are at `0x005c12d0 -> 0x00631190`, `0x005c12d6 -> 0x006311e4`, and `0x005c12e0 -> 0x00631214`.
- Rain vtable stores are at `0x005c1424 -> 0x00631220`, `0x005c1433 -> 0x00631274`, and `0x005c143d -> 0x006312a4`.
- Vtable slot bytes confirm `0x00631214+4 -> 0x005c13b0`, `0x006312a4+4 -> 0x005c13b0`, `0x00631230 -> 0x005c1810`, and `0x00631264 -> 0x005c1460`.
- `analyze_component` shows the internal call graph `MapPane weather setup 0x0050db50 -> RainingLayerPane constructor 0x005c1410 -> WeatherLayerPane constructor 0x005c12a0`.
- The same component shows `word_66DA9C` and `word_66DAA0` shared by `MapPane` setup and base weather construction, while `dword_67A764` / `g_activeMapPane` is shared only by the two rain draw paths.

Rain table xrefs are exactly split by the two rain draw methods:

- Target/minimap tables `0x006702c8`, `0x00670478`, and `0x006704d0` are referenced only from `0x005c1810`.
- Main-view tables `0x00670528`, `0x006706d8`, and `0x00670730` are referenced only from `0x005c1460`.

Source/path string evidence remains absent. `find_regex` for `WeatherLayerPane|RainingLayerPane|SnowingLayerPane|SwallowLayerPane|WeatherTables|\.cpp|\.pdb` found only four RTTI/class strings:

- `.?AVWeatherLayerPane@@`
- `.?AVRainingLayerPane@@`
- `.?AVSnowingLayerPane@@`
- `.?AVSwallowLayerPane@@`

No `.cpp`, `.pdb`, linker-map, or source-path string evidence was found that could resolve one `WeatherLayerPane.cpp` versus per-layer source files.

### Local PE scan

Read-only PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`.

Correct section map:

- `.text`: RVA `0x1000`, raw `0x400`, raw size `0x20b600`, virtual size `0x20b4ac`.
- `.rdata`: RVA `0x20d000`, raw `0x20ba00`, raw size `0x5f200`, virtual size `0x5f0be`.
- `.data`: RVA `0x26d000`, raw `0x26ac00`, raw size `0xd800`, virtual size `0x2fe24`.

Exact body uniqueness:

| Body | Result |
| --- | --- |
| `0x005c12a0-0x005c13a1` | one occurrence, at `0x005c12a0` in `.text` |
| `0x005c13b0-0x005c1408` | one occurrence, at `0x005c13b0` in `.text` |
| `0x005c1410-0x005c145a` | one occurrence, at `0x005c1410` in `.text` |
| `0x005c1460-0x005c180c` | one occurrence, at `0x005c1460` in `.text` |
| `0x005c1810-0x005c1bc7` | one occurrence, at `0x005c1810` in `.text` |

Pointer-byte and branch scan:

- No VA/RVA dword hits for constructor starts `0x005c12a0` or `0x005c1410`, matching normal direct call reachability rather than vtable dispatch.
- VA dword hits for virtual methods are only expected vtable slots: `0x005c13b0` at `0x00631218`, `0x006312a8`, and `0x00631338`; `0x005c1460` at `0x00631264`; `0x005c1810` at `0x00631230`.
- Direct relative branches to `0x005c12a0` are exactly calls at `0x005c141a`, `0x005c1bfb`, and `0x005c225b`.
- Direct relative branch to `0x005c1410` is exactly the call at `0x0050dc3b`.
- No external rel32 branch/call targets enter `0x005c13b0`, `0x005c1460`, or `0x005c1810`; these are vtable-dispatched methods.

This scan rules out duplicate retained copies of these bodies and confirms the bodies are live class methods, not unreferenced raw byte islands.

## Source-Placement Analysis

### Why the five child pages are justified

Each proposed child is a complete modeled IDA function with exact half-open bounds, a live source-level route, and a direct class owner that clears the strict parent gate. The internal `0xcc` gaps are alignment padding, not source-bearing code. The PE scan confirms every body is unique in `.text`, and the only pointer/branch evidence is the expected constructor, vtable, or table reachability.

The split also matches existing local precedent:

- Snowing exact child pages under the adjacent island now carry source ownership.
- `0001O1` was executed as a non-emitting source-family migration index after those exact children existed.
- Weather/Rain currently lacks only the equivalent child pages; the evidence quality is at least as strong because all five Weather/Rain bodies are already modeled IDA functions with normal xrefs.

### Why child owners should be direct classes

`WeatherLayerPaneConstructor` and `WeatherLayerPaneOnTimerEvent` should attach to [UID:0000G1] because they are base-class methods, store/read base weather vtables, and are called/used by all derived weather panes.

The three rain methods should attach to [UID:0000BJ] because they are rain class methods: the constructor stores rain vtables, the paint and target-draw bodies are rain vtable slots, and the rain table usage splits exactly between those methods.

Do not attach the children directly to [UID:0000P8] or [UID:0000MY]. Those are file/source-family routes. The direct semantic owner of a method body is the class. Current class emitters route through `0000P8`; if a later final source-layout pass moves `RainingLayerPane` to `0000MY`, these children should follow through the class emitter.

### Why `0001NZ` should become non-emitting after children exist

Once the five child pages and internal padding rows exist, `0001NZ` no longer represents a source-level object, method, table, or declaration. It is a useful address-neighborhood/source-family map over two direct class owners plus padding. Under the `by-structure.md` aggregate rule, exact child pages should carry source ownership while the broad mixed container becomes `RECONSTRUCTABLE:FALSE`.

This is true even if the original project kept both classes in one `WeatherLayerPane.cpp`: the source-bearing units would still be the class methods and static data, not the broad address range page.

Before child pages exist, the accepted prior disposition should remain valid: `0001NZ` stays source-bearing only as a temporary aggregate because it is the only exact page covering the five Weather/Rain executable bodies. This report recommends removing that temporary state by creating the children.

## Child Page Implementation Packets

Use normal supervisor/new-target workflow so the UID ledger assigns UIDs. Replace `<UID-...>` placeholders below with assigned UIDs before committing page links or coverage rows.

### `0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md`

Recommended header:

```text
*** UID:<UID-WEATHER-CTOR> | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended placement/evidence text:

```text
# 0x005c12a0-0x005c13a1 WeatherLayerPane Constructor

## Status

- Disposition: reconstructable WeatherLayerPane constructor evidence; final C++ remains blank.
- Direct owner/emitter: [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md).
- Parent migration index after split: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md).

## Evidence

- Live IDA MCP reports `sub_5C12A0` at `0x005c12a0`, size `0x101`, ending at `0x005c13a1`.
- Direct code callers are derived weather constructors at `0x005c141a`, `0x005c1bfb`, and `0x005c225b`.
- The body calls the Pane/base constructor path and timer/layout helper, installs WeatherLayerPane vtable views at `0x00631190`, `0x006311e4`, and `0x00631214`, uses map tile globals `word_66DA9C` and `word_66DAA0`, and initializes base weather animation state.
- Live xrefs show vtable stores from `0x005c12d0`, `0x005c12d6`, and `0x005c12e0`.
- Local PE scan finds the exact body once, at `0x005c12a0`; no duplicate retained copy was found.
- The successor gap `0x005c13a1-0x005c13b0` is 15 bytes of `0xcc` padding.

## Score Rationale

Completion `86` and confidence `88` are justified by exact live boundaries, direct derived-constructor callers, vtable store evidence, base weather/global behavior, unique PE body evidence, and a direct class parent that clears `85/85`. Final C++ is blocked by field/helper naming and the unresolved final weather source-file split.
```

### `0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md`

Recommended header:

```text
*** UID:<UID-WEATHER-TIMER> | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended placement/evidence text:

```text
# 0x005c13b0-0x005c1408 WeatherLayerPane OnTimerEvent

## Status

- Disposition: reconstructable WeatherLayerPane timer-handler evidence; final C++ remains blank.
- Direct owner/emitter: [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md).
- Parent migration index after split: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md).

## Evidence

- Live IDA MCP reports `sub_5C13B0` at `0x005c13b0`, size `0x58`, ending at `0x005c1408`.
- The method is vtable-referenced by Weather/Rain/Snow weather vtable slots at `0x00631218`, `0x006312a8`, and `0x00631338`.
- Vtable bytes confirm `0x00631214+4 -> 0x005c13b0` and `0x006312a4+4 -> 0x005c13b0`; the Snowing slot is already documented in the neighboring vtable child.
- Behavior advances the animation frame modulo the max-frame byte, invalidates/repaints through owner/parent virtual calls, and reschedules the weather timer through `0x005975e0`.
- Local PE scan finds the exact body once, at `0x005c13b0`; VA dword hits are only the expected vtable slots.
- The predecessor and successor gaps are `0xcc` padding.

## Score Rationale

Completion `86` and confidence `88` are justified by exact function bounds, shared weather vtable-slot refs, unique PE body evidence, and direct WeatherLayerPane class ownership. Final C++ is blocked by exact field/helper names and the final source-file split.
```

### `0x005c1410-0x005c145a.RainingLayerPaneConstructor.md`

Recommended header:

```text
*** UID:<UID-RAIN-CTOR> | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended placement/evidence text:

```text
# 0x005c1410-0x005c145a RainingLayerPane Constructor

## Status

- Disposition: reconstructable RainingLayerPane constructor evidence; final C++ remains blank.
- Direct owner/emitter: [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md).
- Parent migration index after split: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md).

## Evidence

- Live IDA MCP reports `sub_5C1410` at `0x005c1410`, size `0x4a`, ending at `0x005c145a`.
- The constructor is called from `MapPane` weather setup at `0x0050dc3b`.
- The constructor calls `WeatherLayerPane::WeatherLayerPane` at `0x005c141a`.
- Live xrefs show rain vtable stores from `0x005c1424 -> 0x00631220`, `0x005c1433 -> 0x00631274`, and `0x005c143d -> 0x006312a4`.
- It sets rain animation values documented in the parent/class pages: max/timer value `120`, frame step `3`, and enabled flag `1`.
- Local PE scan finds the exact body once, at `0x005c1410`; the only direct rel32 branch to the start is the expected `MapPane` constructor call at `0x0050dc3b`.
- The successor gap `0x005c145a-0x005c1460` is 6 bytes of `0xcc` padding.

## Score Rationale

Completion `86` and confidence `88` are justified by exact bounds, the sole MapPane weather setup caller, base-constructor call, rain vtable stores, rain animation setup, unique PE body evidence, and a direct RainingLayerPane class parent that clears `85/85`.
```

### `0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md`

Recommended header:

```text
*** UID:<UID-RAIN-PAINT> | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended placement/evidence text:

```text
# 0x005c1460-0x005c180c RainingLayerPane OnPaint

## Status

- Disposition: reconstructable RainingLayerPane paint-method evidence; final C++ remains blank.
- Direct owner/emitter: [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md).
- Parent migration index after split: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md).

## Evidence

- Live IDA MCP reports `sub_5C1460` at `0x005c1460`, size `0x3ac`, ending at `0x005c180c`.
- The rain vtable paint slot points to this method at `0x00631264`.
- The method uses [UID:0001OW][ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) / `g_activeMapPane` to check the weather-render gate byte before drawing.
- Main-view rain table xrefs are exclusive to this body: `0x00670528 -> 0x005c14d3`, `0x006706d8 -> 0x005c15ad/0x005c1617`, and `0x00670730 -> 0x005c168d/0x005c16f7/0x005c1761/0x005c17ce`.
- Callees are the expected GrafPort/render callback dependencies: `0x004b9600`, `0x004b9660`, `0x0069b3fc`, `0x0069b3e4`, and `0x0069b3e0`.
- Local PE scan finds the exact body once, at `0x005c1460`; the only VA dword hit is the expected vtable slot at `0x00631264`.
- The successor gap `0x005c180c-0x005c1810` is 4 bytes of `0xcc` padding.

## Score Rationale

Completion `86` and confidence `88` are justified by exact bounds, vtable-slot evidence, exclusive main-view rain table refs, active-map-pane dependency, unique PE body evidence, and direct RainingLayerPane class ownership. Final C++ is blocked by final GrafPort/helper names, field names, table names, and the unresolved final source-file split.
```

### `0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md`

Recommended header:

```text
*** UID:<UID-RAIN-TARGET> | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended placement/evidence text:

```text
# 0x005c1810-0x005c1bc7 RainingLayerPane DrawRainOnTarget

## Status

- Disposition: reconstructable RainingLayerPane target/minimap rain draw evidence; final C++ remains blank.
- Direct owner/emitter: [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md).
- Parent migration index after split: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md).

## Evidence

- Live IDA MCP reports `sub_5C1810` at `0x005c1810`, size `0x3b7`, ending at `0x005c1bc7`.
- The rain vtable target-draw slot points to this method at `0x00631230`.
- The method uses [UID:0001OW][ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) / `g_activeMapPane` to check the same weather-render gate byte used by `OnPaint`.
- Target/minimap rain table xrefs are exclusive to this body: `0x006702c8 -> 0x005c1877`, `0x00670478 -> 0x005c1950/0x005c19bd`, and `0x006704d0 -> 0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- Callees are the expected GrafPort/render dependencies: `0x004b9600`, `0x004b9660`, `0x0069b3e4`, and `0x0069b3e0`.
- Local PE scan finds the exact body once, at `0x005c1810`; the only VA dword hit is the expected vtable slot at `0x00631230`.
- The successor `0x005c1bc7-0x005c1bd0` is 9 bytes of `0xcc` padding before `SnowingLayerPane`.

## Score Rationale

Completion `86` and confidence `88` are justified by exact bounds, vtable-slot evidence, exclusive target/minimap rain table refs, active-map-pane dependency, unique PE body evidence, and direct RainingLayerPane class ownership. Final C++ is blocked by final GrafPort/helper names, field names, table names, and the unresolved final source-file split.
```

## Parent Target Actions

In `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`, after creating and validating the five child pages, replace header values with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `EMITTER_POSITION_OPTIONAL` blank and keep final C++ blank.

Recommended status wording:

```text
- Disposition: reviewed non-emitting WeatherLayerPane/RainingLayerPane migration index/source-family map.
- Reconstruction handling: `RECONSTRUCTABLE:FALSE`; keep [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) as the semantic weather-family owner, but do not emit source from this broad mixed Weather/Rain address island. Exact WeatherLayerPane and RainingLayerPane child pages carry source ownership and any future C++.
```

Recommended change-log note:

```text
- 2026-06-16 B001 child-split review:
  - After creation of exact Weather/Rain child pages, changed from `82/86`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P8` to `86/88`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Summary/evidence: live IDA MCP, local PE body/pointer/branch scans, support docs, generated coverage, and the executed `0001O1` precedent show that this broad range is a mixed WeatherLayerPane/RainingLayerPane migration index. The exact children carry the five source-bearing function bodies and internal padding rows carry alignment state, so no aggregate final C++ should emit from this range.
```

## Support Doc Actions

The existing support docs are adequate to create the child pages: [UID:0000G1] and [UID:0000BJ] clear the direct parent gate, and [UID:0000P8]/[UID:0000MY] document the source-family/file split caveat. Recommended follow-up edits are for discoverability and consistency only.

Recommended targeted support updates after child UIDs are assigned:

- In `by-class/WeatherLayerPane.md`, update the Method Map rows to link the two new child pages. Keep scores and metadata unchanged.
- In `by-class/RainingLayerPane.md`, update the Method Map rows to link the three new child pages. Keep scores and metadata unchanged.
- In `by-file/WeatherLayerPane.md`, add the five child pages to the main memory docs/proposed contents next to `0001NZ`. Keep the one-file versus per-layer caveat.
- In `by-file/RainingLayerPane.md`, replace the broad main memory range reference with the three rain child page links plus the parent `0001NZ` migration-index link. Keep scores and metadata unchanged.

Do not change class emitters or file ownership in this assignment. The unresolved final source-file split remains documented and does not block child creation.

## Shared Coverage Row Actions

B001 must not edit `by-memory/-coverage-report.md` directly. Supervisor should replace the current `0001NZ` row immediately after the `0x005c129a-0x005c12a0` padding row and before the existing `0x005c1bc7-0x005c1bd0` padding row.

Use this replacement block after creating child pages and substituting assigned child UIDs:

```text
    - [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) 0x005c12a0-0x005c1bc7 | migration index | WeatherAndRainingLayerPanes : not_reconstructable : 86% : strong : B001 2026-06-16 child-split review reclassifies this WeatherLayerPane/RainingLayerPane executable island as a non-emitting weather-family migration index under [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md); exact WeatherLayerPane constructor/timer and RainingLayerPane constructor/paint/target-draw child pages carry source ownership, while internal padding rows carry alignment state, so no aggregate final C++ should emit from this range.
        - [UID:<UID-WEATHER-CTOR>][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) 0x005c12a0-0x005c13a1 | constructor | WeatherLayerPaneConstructor : reconstructable : 86% : strong : Exact WeatherLayerPane constructor; live IDA reports size 0x101, derived constructor callers at 0x005c141a/0x005c1bfb/0x005c225b, base weather vtable stores at 0x005c12d0/0x005c12d6/0x005c12e0, map tile globals, unique PE body evidence, and 0xcc successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c13a1-0x005c13b0 | padding | WeatherLayerPane constructor to timer alignment : ignored : 100% : strong : Live IDA `get_bytes` confirms fifteen `0xcc` alignment bytes.
        - [UID:<UID-WEATHER-TIMER>][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md) 0x005c13b0-0x005c1408 | method | WeatherLayerPaneOnTimerEvent : reconstructable : 86% : strong : Exact WeatherLayerPane timer handler; live IDA reports size 0x58, weather/rain/snow vtable slots at 0x00631218/0x006312a8/0x00631338, timer reschedule behavior through 0x005975e0, unique PE body evidence, and 0xcc successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c1408-0x005c1410 | padding | WeatherLayerPane timer to RainingLayerPane constructor alignment : ignored : 100% : strong : Live IDA `get_bytes` confirms eight `0xcc` alignment bytes.
        - [UID:<UID-RAIN-CTOR>][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) 0x005c1410-0x005c145a | constructor | RainingLayerPaneConstructor : reconstructable : 86% : strong : Exact RainingLayerPane constructor; live IDA reports size 0x4a, sole MapPane weather-setup caller at 0x0050dc3b, base WeatherLayerPane constructor call at 0x005c141a, rain vtable stores at 0x005c1424/0x005c1433/0x005c143d, rain animation setup, unique PE body evidence, and 0xcc successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c145a-0x005c1460 | padding | RainingLayerPane constructor to OnPaint alignment : ignored : 100% : strong : Live IDA `get_bytes` confirms six `0xcc` alignment bytes.
        - [UID:<UID-RAIN-PAINT>][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) 0x005c1460-0x005c180c | method | RainingLayerPaneOnPaint : reconstructable : 86% : strong : Exact RainingLayerPane paint method; live IDA reports size 0x3ac, rain paint vtable slot 0x00631264, active-map-pane weather gate use, exclusive main-view rain table refs at 0x00670528/0x006706d8/0x00670730, expected GrafPort/render callees, unique PE body evidence, and 0xcc successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c180c-0x005c1810 | padding | RainingLayerPane OnPaint to target draw alignment : ignored : 100% : strong : Live IDA `get_bytes` confirms four `0xcc` alignment bytes.
        - [UID:<UID-RAIN-TARGET>][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) 0x005c1810-0x005c1bc7 | method | RainingLayerPaneDrawRainOnTarget : reconstructable : 86% : strong : Exact RainingLayerPane target/minimap rain draw method; live IDA reports size 0x3b7, rain target-draw vtable slot 0x00631230, active-map-pane weather gate use, exclusive target/minimap rain table refs at 0x006702c8/0x00670478/0x006704d0, expected GrafPort/render callees, unique PE body evidence, and 0xcc padding before SnowingLayerPane.
```

Keep the existing outer padding row after this block:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c1bc7-0x005c1bd0 | padding | RainingLayerPane to SnowingLayerPane alignment : ignored : 100% : strong : IDA MCP/raw-byte check shows nine `0xcc` alignment bytes.
```

Do not manually edit `auto-generated/*`. Regenerate/validate through the normal supervisor flow after the by-memory pages and manual coverage row are applied.

## IDA DB Decision

No IDA DB repair is safe or useful for this assignment.

Reasons:

- All five proposed child starts are already modeled IDA functions with exact sizes.
- Padding endpoints are correctly not functions.
- Xrefs and vtable slots are already sufficient for ownership and reachability.
- Renaming IDA functions would be cosmetic and broader than this research assignment.
- There are no raw no-function helper bodies in `0001NZ`; the raw no-function issue belongs to the adjacent Swallow helper page [UID:0001O3], not this split.

## Unresolved Issues

### One file versus per-layer weather source

Status: unresolved, but no longer blocks the child split.

Evidence checked:

- `by-project-structure/proposed-source-tree.md` lists `WeatherLayerPane.cpp`, `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` under `map/`.
- [UID:0000P8] intentionally acts as the weather-layer source-family root.
- [UID:0000MY] is a plausible standalone `RainingLayerPane.cpp` file root.
- Current class routes still emit Weather/Raining/Snowing/Swallow through `0000P8`.
- Live IDA string search found RTTI class strings only, not `.cpp`, `.pdb`, source path, or linker-map evidence.
- Local PE scan did not reveal compilation-unit metadata.

Why not resolved safely:

No debug/source metadata proves the original compilation-unit split. Moving class emitters from `0000P8` to per-layer files would affect the whole weather family and should be a separate source-layout decision. The child pages should therefore use direct class owner/emitter UIDs and let the existing class route decide the output file.

### Final C++ eligibility

Status: unresolved for all five children; keep C++ blank.

Evidence checked:

- Live IDA confirms behavior and boundaries.
- Support docs document class roles, vtables, globals, and table layouts.
- Generated output has low fidelity scores and unresolved helper names.
- GrafPort/render callbacks, field names, table names, and the final weather source-file layout remain provisional.

Why not resolved safely:

The children clear reconstructable/source-ownership gates but not final source-quality gates. Writing final C++ now would bake in non-final field/helper/table names and possibly the wrong file-level layout.

### Parent source-bearing status

Status: resolved conditionally.

If child pages are not created, keep the accepted prior state: `0001NZ` remains temporary source-bearing aggregate evidence. If the five child pages and internal padding rows are created, reclassify `0001NZ` to `RECONSTRUCTABLE:FALSE`, because no source-level construct corresponds to the whole mixed Weather/Rain address range.

## Validation Order For Supervisor

1. Create the five new child pages with UID-ledger-assigned UIDs using the metadata/evidence packets above.
2. Validate/apply each new child page.
3. Update and validate/apply `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`.
4. Apply the manual `by-memory/-coverage-report.md` replacement block with real child UIDs, then validate/apply the coverage report.
5. Apply optional support-doc link updates, then validate/apply each touched support doc.
6. Regenerate or refresh generated coverage through the normal supervisor flow; do not hand-edit `auto-generated/*`.

Suggested validation commands after files exist:

> Executable block R001 was removed from this report and preserved verbatim in [0001NZ-child-split-weather-raining-removed.md](0001NZ-child-split-weather-raining-removed.md). The archived block is non-authoritative and must not be executed.

## No Recommended Changes

- No IDA DB edit.
- No direct class/file emitter-route change.
- No final C++ for the parent or children.
- No split/merge with [UID:0001O1] or adjacent Snowing/Swallow pages.
- No direct edit by B001 to `by-memory/-coverage-report.md`, by-* docs, generated reports, or IDA DB.

## Changed Files

- Created this report: `tools/leaser/Agents/Agent-B001/research/0001NZ-child-split-weather-raining.md`.
- No by-* docs changed by B001.
- No generated reports changed by B001.
- IDA DB untouched.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001NZ-child-split-weather-raining.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001NZ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001NZ-child-split-weather-raining-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001NZ-child-split-weather-raining.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001NZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
