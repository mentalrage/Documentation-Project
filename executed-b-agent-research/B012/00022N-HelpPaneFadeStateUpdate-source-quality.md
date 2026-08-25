** TARGET-REPORT-UID:00022N **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022N HelpPaneFadeStateUpdate Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](../../../../../by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) as reconstructable HelpPanes-family source-authored code, direct owner [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md), emitted through [UID:0000JU], but keep the formal `RECONSTRUCTION_CPP CODE` block blank for now with an explicit no-code proof.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JU`, `EMITTER_UIDS:0000JU`, `RECONSTRUCTION_CPP CODE` blank. Generated output may continue to carry the empty emitter marker until a real call/vtable/pointer entry route is proven.
- Required action: update the target and support docs to close the stale field/helper/global/open-question wording, record the exact base-vs-child mode conditions, link the shared float-pool constant [UID:0003AQ], and replace the stale `by-memory/-coverage-report.md` row with the exact supervisor-owned row in this report.
- Score recommendation after implementation: raise from `85/87` to `87/88` only if the implementation incorporates the exact local PE disassembly facts, B013 field-name refinements, no-route proof, and formal no-code decision. If the supervisor wants no target metadata change, still replace the stale coverage row with the current `85/87` content from A002; this report's preferred row uses `87%`.
- Confidence: high for range, bytes, internal behavior, owner/emitter route, field roles, and no direct route; medium-high for the descriptive helper name because original source spelling remains unrecovered.

## Target

- Target UID: `00022N`
- Target path: `source-3/project-documentation/by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`
- Supervisor assignment: `B012-goal2-help-pane-fade-state-update-source-quality-00022N-20260619`
- Current target metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:87`
  - `CANONICAL_OWNER:0000JU`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000JU`
  - formal C++ blank
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists the target as `emits` through `0000JU` to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`; generated `HelpPanes.cpp` contains an empty emitter marker for [UID:00022N].
- Current stale shared coverage row: `by-memory/-coverage-report.md` still shows `80% : strong` for [UID:00022N], even though the target metadata and A002 notes show `85/87`.

## Supervisor Active Recheck

- The current user/supervisor prompt overrides the older B012 `goal.md` active assignment text that still mentions [UID:00021G]. This report handles only [UID:00022N].
- This is report-only. I did not edit by-* docs, generated docs, project-level docs, or `by-memory/-coverage-report.md`.
- The target does not require a split before reporting. It is already an exact half-open raw body between documented padding rows:
  - predecessor padding: `0x004c6ea9-0x004c6eb0`
  - target: `0x004c6eb0-0x004c6f89`
  - successor padding: `0x004c6f89-0x004c6f90`
- No child pages are required inside this range. The report recommends support sync with the adjacent HelpPaneCore and SimpleHelpTextPartPane raw-helper work, not a target split.

## Evidence Status

- IDA MCP endpoint check on 2026-06-19: `http://127.0.0.1:13337/mcp` was unavailable with `Unable to connect to the remote server`.
- Because live IDA was unavailable, this pass does not claim new live IDA evidence.
- Evidence used instead:
  - current by-* documentation with prior live IDA MCP evidence;
  - B001/B002/B013 source-quality reports and executed support docs;
  - generated `-ag-memory-coverage.md` and generated `HelpPanes.cpp` empty marker state;
  - local read-only PE disassembly and byte checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`;
  - local Capstone disassembly for `0x004c6eb0-0x004c6f89`, `0x004c6e50-0x004c6ea9`, and the matching constructor tail at `0x004c6cb1-0x004c6daa`;
  - local absolute-VA pointer scan for target-range addresses, which found no absolute dword pointer to any address in `0x004c6eb0-0x004c6f89`.

## Executive Recommendation

The target is best treated as a raw retained out-of-line copy of HelpPane style-state application logic. It is source-authored project code, and its direct semantic/source-family owner remains [UID:0000JU] `HelpPanes`, but no current evidence proves a live entry route.

The best descriptive source-facing name is:

```text
HelpPane::ApplyStyleState()
```

Second-best acceptable name:

```text
HelpPane::UpdateFadeState()
```

`ApplyStyleState` is stronger than `UpdateFadeState` because the body does more than fading: it applies pane opacity, pane mode, fill/frame paint colors, and embedded text-part opacity/mode from the embedded `FontStyle` block. Keep the filename stable unless the supervisor wants a rename; a documentation rename is not required for this report.

Formal C++ should remain blank despite the active emitter route because:

1. no modeled function object exists at the raw start in prior IDA checks;
2. prior IDA byte-by-byte xref scans found no external xrefs into the body;
3. local PE scan found no absolute dword pointer to any address in the body;
4. the body is a standalone duplicate of constructor-side style-application logic at `0x004c6cb1-0x004c6daa`;
5. no vtable slot or call site proves a source declaration that should currently be emitted;
6. emitting a named method now would invent a source-facing entry that the current binary evidence does not prove.

The target should remain reconstructable because these are real NexusTK executable bytes that represent project HelpPane behavior. The no-code proof only blocks the formal generated source block, not ownership or source-family classification.

## Heuristic / Inference Reanalysis And Validation

### 1. Helper name and source role

- Existing target name: `HelpPaneFadeStateUpdate` / `HelpPane::UpdateFadeState`.
- Best current descriptive name: `HelpPane::ApplyStyleState()`.
- Evidence:
  - Local PE disassembly shows the helper reads `HelpPane +0xfc` as an enabled byte inside the embedded `FontStyle` object.
  - It reads the base opacity at `HelpPane +0x100` (`FontStyle +0x04`).
  - It copies `HelpPane +0x108/+0x10c` (`FontStyle +0x0c/+0x10`) to paint fields `HelpPane +0x11c/+0x120`.
  - It reads `HelpPane +0x220`, which B013 resolved as the embedded text part's borrowed `FontStyle *`, and then reads child/text opacity at `[style + 8]`.
  - It calls [UID:0002V7] `Pane::SetMode` four times to update base and embedded child pane modes.
- Rejected alternatives:
  - `UpdateFadeState` is acceptable as a historical/descriptive filename but narrower than the actual body because colors and child style state are also applied.
  - `TimerUpdate`, `OnTimer`, or `TickFade` are rejected: the body reads no timer id, time delta, event object, or animation counter.
  - `OnPaintFrame` is rejected: paint happens in [UID:00016R] `0x004c6e50-0x004c6ea9`; this target sets fields later consumed by paint.
  - `HelpPane::SimpleHelpTextPartPane::ApplyStyleOpacityState` is rejected for this exact range: the target owns both base HelpPane and embedded text-part updates, while the sibling raw helper at `0x004c6820-0x004c687e` is the text-part-only counterpart.
- Final direction: document as a raw no-entry `HelpPane::ApplyStyleState` / retained `HelpPaneFadeStateUpdate` helper under the HelpPanes source family. Do not require original spelling proof to use the descriptive name in prose, but do not emit formal C++ until entry evidence appears.

### 2. Exact base-pane behavior

Local PE disassembly refines the target page's current broad wording. The base pane half is:

```text
if (!m_fontStyle.enabled)
    return;

float baseOpacity = m_fontStyle.baseOpacity;   // this +0x100, FontStyle +0x04

if (baseOpacity >= 1.0f) {
    Pane::SetMode(1);
} else if (baseOpacity >= 0.0f) {
    Pane::SetMode(3);
    if (baseOpacity <= 1.0f)
        m_alpha = baseOpacity;                 // this +0x90
}

m_fillColor  = m_fontStyle.styleValue0;        // +0x108 -> +0x11c
m_frameColor = m_fontStyle.styleValue1;        // +0x10c -> +0x120
```

Important correction: base mode `1` is selected when base opacity is `>= 1.0f`; base mode `3` is selected for `0.0f <= opacity < 1.0f`; negative base opacity skips the mode write and still proceeds to color/child handling. This differs from the embedded text-part child pattern.

Validation:

- Target disassembly:
  - `0x004c6ec0` loads `[esi + 0x100]`;
  - `0x004c6ec8` loads `1.0f` from `0x006104b4`;
  - `0x004c6ed3 jb 0x004c6ee6` branches only when base opacity is below `1.0f`;
  - `0x004c6ed5/0x004c6ed7` call `Pane::SetMode(1)` on the base pane;
  - `0x004c6eee/0x004c6ef0` call `Pane::SetMode(3)` when base opacity is nonnegative and below `1.0f`;
  - `0x004c6f0a` writes accepted opacity to `[esi + 0x90]`.
- Constructor tail at `0x004c6cb1-0x004c6d21` performs the same base-pane branch shape before copying the same color fields.

Rejected alternative:

- Treating base mode `1` as the `opacity <= 0.0f` path is wrong for this target's base half. That interpretation belongs to the child/text opacity half and to the sibling raw text-part helper.

### 3. Exact embedded text-part behavior

The child half uses `HelpPane +0x220` as the style pointer, then applies the text opacity at `[style + 8]` to the embedded `HelpPane::SimpleHelpTextPartPane` subobject at `HelpPane +0x124`:

```text
FontStyle *textStyle = m_textPart.m_fontStyle; // parent +0x220
if (textStyle == NULL || !textStyle->enabled)
    return;

float textOpacity = textStyle->textOpacity;    // style +0x08

if (textOpacity <= 0.0f) {
    m_textPart.SetMode(1);
    return;
}

if (textOpacity <= 1.0f) {
    m_textPart.SetMode(3);
    if (textStyle->textOpacity <= 1.0f)
        m_textPart.m_alpha = textStyle->textOpacity; // parent +0x1b4, child +0x90
}
```

Validation:

- `0x004c6f2d` loads `[esi + 0x220]`;
- `0x004c6f33/0x004c6f37` reject null or disabled style;
- `0x004c6f3c` loads `[eax + 8]`;
- `0x004c6f41 comiss xmm2, xmm1` compares `0.0f` with text opacity;
- `0x004c6f46/0x004c6f4e` set mode `1` on `this +0x124` when text opacity is not greater than zero;
- `0x004c6f55/0x004c6f58` reject values above `1.0f`;
- `0x004c6f5a/0x004c6f62` set mode `3` on `this +0x124` for `0.0f < textOpacity <= 1.0f`;
- `0x004c6f7f` writes accepted text opacity to `[esi +0x1b4]`, which is child `+0x90`.

Rejected alternative:

- Describing the second half as a simple repeat of the base half loses a material branch difference. The child/text opacity path uses `<= 0.0f` for mode `1`, while the base path uses `>= 1.0f` for mode `1`.

### 4. Field and type names

Best-supported target-side names after B013 and local reanalysis:

| Offset / item | Best current name | Evidence | Caveat |
| --- | --- | --- | --- |
| `HelpPane +0xfc` | `m_fontStyle` / `m_styleData` embedded `FontStyle` | [UID:00005C] and [UID:0001UN] define a 0x20-byte `FontStyle`; constructor and target read the same header. | Shared scalar names in `FontStyleLayout` remain provisional, so use consumer-specific names in this target. |
| `HelpPane +0xfc` byte | `m_fontStyle.enabled` | Target first gates the whole body on this byte. | None for role; exact original member spelling unknown. |
| `HelpPane +0x100` | `m_fontStyle.baseOpacity` / `paneOpacity` | Base pane compares this float to `0.0f` and `1.0f`, and copies accepted values into inherited alpha `+0x90`. | Prefer `baseOpacity` in this target; do not force shared `FontStyleLayout` to that name globally yet. |
| `HelpPane +0x104` / style `+0x08` | `m_fontStyle.textOpacity` | Child style pointer reads `[style + 8]` and writes accepted values to embedded child alpha. B013 resolved this target-specific meaning. | Current target does not directly read `+0x104`; it reads it through `+0x220` alias. |
| `HelpPane +0x108` | `m_fontStyle.fillColor` candidate | Copied into `HelpPane +0x11c`; `OnPaintFrame` pushes `+0x11c`, calls `0x004b9660`, then fill-callback `dword_69B3FC`. | If later GrafPort naming changes color order, keep the exact copy relation. |
| `HelpPane +0x10c` | `m_fontStyle.frameColor` candidate | Copied into `HelpPane +0x120`; `OnPaintFrame` sets draw color and calls frame helper `0x004ba450`. | Source spelling may be `lineColor`, `borderColor`, or similar. |
| `HelpPane +0x11c` | `m_fillColor` / background fill color | `OnPaintFrame` uses it before the global fill callback. | Strong target-local role. |
| `HelpPane +0x120` | `m_frameColor` / border/frame color | `OnPaintFrame` uses it before the frame draw helper. | Strong target-local role. |
| `HelpPane +0x124` | `m_textPart` | Constructor builds embedded [UID:000064] text part here; target passes this address to `Pane::SetMode`. | Strong. |
| `HelpPane +0x1b4` | `m_textPart.m_alpha` / child inherited alpha | `0x1b4 - 0x124 = 0x90`, matching the embedded child's inherited alpha offset from B013/GrafPort evidence. | Strong. |
| `HelpPane +0x220` | `m_textPart.m_fontStyle` borrowed `FontStyle *` alias | Constructor stores `this +0xfc` at `this +0x220`; B013 resolves child `+0xfc` as borrowed `FontStyle *`. | Strong for aliasing; original member name unknown. |
| `0x005446b0` / `sub_5446B0` | `Pane::SetMode(unsigned char mode)` | [UID:0002V7] B002 source-quality pass resolved the method and formal C++. | Mode enum constant names remain provisional. |
| `0x006104b4` / `dword_6104B4` | shared `1.0f` literal-pool constant; prefer link to [UID:0003AQ] instead of raw dword name | [UID:0003AQ] covers `0x006104ac-0x006104f0`; target and HelpPaneCore use the 1.0f cell; docs report broad xrefs. | Not a HelpPanes-owned global; do not create a local `g_` name. |

### 5. Placeholder and generated-name closure

- `sub_5446B0`: closed. Use [UID:0002V7] `Pane::SetMode(unsigned char mode)`.
- `dword_6104B4`: closed for this target. Use "shared `1.0f` literal-pool constant at `0x006104b4`, covered by [UID:0003AQ]" rather than a raw global name.
- `sub_4C6E50`: closed as [UID:00016R] `HelpPane::OnPaintFrame` method body at `0x004c6e50-0x004c6ea9`.
- `sub_4C6F90`: closed as the successor [UID:00016S] `SimpleHelpPanes` cluster starting at `0x004c6f90`, not part of this target.
- `HelpPaneFadeStateUpdate`: acceptable filename/search label, but source-facing prose should use `HelpPane::ApplyStyleState` or `HelpPane style-state raw helper`.
- `AUTOGEN_PARENT_UID` wording in the target: stale legacy wording. Replace with current `CANONICAL_OWNER` / `EMITTER_UIDS` language.

### 6. Caller, reachability, and liveness

Positive reachability facts:

- The body has valid executable instructions and exact padding on both sides.
- It calls a resolved project method [UID:0002V7] `Pane::SetMode` at:
  - `0x004c6ed7`
  - `0x004c6ef0`
  - `0x004c6f4e`
  - `0x004c6f62`
- The ten HelpPane-family `Pane::SetMode` call sites in local PE are:
  - raw text-part helper: `0x004c6841`, `0x004c6857`
  - constructor inline style path: `0x004c6ce1`, `0x004c6cfc`, `0x004c6d56`, `0x004c6d83`
  - this target: `0x004c6ed7`, `0x004c6ef0`, `0x004c6f4e`, `0x004c6f62`

Negative route facts:

- Current target docs record prior live IDA `lookup_funcs` found no modeled function at `0x004c6eb0`.
- Current target docs record prior live IDA `xrefs_to 0x004c6eb0` found no direct xrefs.
- Current target docs record a prior byte-by-byte xref scan across `0x004c6eb0-0x004c6f89` with only internal branch targets and no external code/data xrefs.
- Local PE scan found zero absolute dword pointers to any VA in `0x004c6eb0-0x004c6f89`.
- Local disassembly confirms the next modeled-successor bytes at `0x004c6f90` are a new function prologue; raw byte opcode-like false positives inside successor immediates should not be counted as real branch refs.

Liveness conclusion:

- The range is not proven live. The best current classification is "source-authored retained raw helper with no proven external route."
- Do not call it compiler padding or ignore it: it is a coherent hand-source-style body.
- Do not emit formal C++ yet: the missing route is material because formal generated source would invent a callable `HelpPane` method or static helper not proven by current xrefs.

### 7. Source placement and ownership

Accepted route:

- Direct owner and emitter remain [UID:0000JU] `HelpPanes`.
- Source folder remains `NexusTK/ui/controls/`.
- The surrounding source family includes [UID:000063] `HelpPane`, [UID:000064] `HelpPane__SimpleHelpTextPartPane`, [UID:00016R] `HelpPaneCore`, [UID:00016S] `SimpleHelpPanes`, and the HelpPanes/tooltip destructor and singleton helpers.

Rejected routes:

- [UID:000063] `HelpPane` as direct canonical owner is attractive but should not be applied to this raw target yet. The class page is strong, but the target has no function object, vtable pointer, or call route proving it is a class method rather than file-local retained helper code. Keep the by-file owner until entry evidence resolves class-vs-file direct ownership.
- [UID:000064] `HelpPane__SimpleHelpTextPartPane` is rejected as direct owner because this target updates both the base `HelpPane` and the embedded text part. The text-part-only sibling is the raw helper at `0x004c6820-0x004c687e`.
- [UID:0000JI] `FontStyle` is rejected. `FontStyle` supplies the style object layout, but this target is the HelpPane consumer applying style state to pane fields.
- [UID:0000MC]/[UID:0000A2] `Pane` is rejected as owner. `Pane::SetMode` is a dependency; the target is HelpPanes-specific.
- [UID:0003AQ] shared float constants is rejected as owner. The `1.0f` literal is shared compiler/linker-pooled data, not a source owner for this executable body.

### 8. Range and split decisions

- Keep [UID:00022N] as one exact raw body. No child split is needed inside `0x004c6eb0-0x004c6f89`.
- Keep predecessor/successor padding rows separate and ignored:
  - `0x004c6ea9-0x004c6eb0`
  - `0x004c6f89-0x004c6f90`
- Do not merge [UID:00022N] into [UID:00016R]. It is outside `HelpPaneCore`'s half-open range and starts after a confirmed padding gap.
- Do not merge [UID:00022N] into [UID:00016S]. It ends before the confirmed padding gap and successor function prologue at `0x004c6f90`.
- Cross-link the future/existing `0x004c6820-0x004c687e` text-part raw helper as the embedded text-only counterpart, but do not merge them; the base/child branch conditions differ.

### 9. Existing docs and generated output validation

- Target doc: mostly correct on range, owner route, call sites, and broad behavior. Needs correction/refinement for base-vs-child mode conditions, field names, `dword_6104B4`, stale `AUTOGEN_PARENT_UID`, and formal no-code proof.
- [UID:0002V7] `PaneSetMode`: resolves the old `sub_5446B0` blocker. The target should use that name directly.
- [UID:0003AQ] `SharedRdataFloatVectorConstants`: resolves the `dword_6104B4` placeholder as a shared literal-pool constant. The target should link it or at least cite it.
- [UID:000064] B013 report: resolves child fields strongly enough to name parent `+0x220` as the embedded child's borrowed `FontStyle *` and child `+0x90`/parent `+0x1b4` as inherited alpha.
- Generated `HelpPanes.cpp`: currently has an empty marker for [UID:00022N]. That should remain intentional after no-code proof, not be treated as a missing-source failure.

### 10. Remaining blockers

- Live IDA MCP was unavailable in this session, so no new IDA xref/function metadata could be collected.
- No external entry route is proven. This is a formal C++ blocker and should cap the score below final-audit levels.
- Original helper spelling is unknown. `ApplyStyleState` is a descriptive source-quality name, not original proof.
- Final `PaneMode` enum names for mode values `1` and `3` remain unresolved in [UID:0002V7]/Pane layout. Do not invent `Hidden`, `Visible`, or `Fading` constants for this target.
- Shared `FontStyleLayout` scalar field names remain globally provisional. This target can use consumer-specific `baseOpacity`, `textOpacity`, `fillColor`, and `frameColor` language without forcing those as final shared names.

## IDA / Local PE Facts

### Local target disassembly

```asm
004c6eb0  push    esi
004c6eb1  mov     esi, ecx
004c6eb3  cmp     byte ptr [esi + 0xfc], 0
004c6eba  je      0x4c6f87
004c6ec0  movss   xmm1, dword ptr [esi + 0x100]
004c6ec8  movss   xmm0, dword ptr [0x6104b4]
004c6ed0  comiss  xmm1, xmm0
004c6ed3  jb      0x4c6ee6
004c6ed5  push    1
004c6ed7  call    0x5446b0
004c6edc  movss   xmm0, dword ptr [0x6104b4]
004c6ee4  jmp     0x4c6f12
004c6ee6  xorps   xmm2, xmm2
004c6ee9  comiss  xmm1, xmm2
004c6eec  jb      0x4c6f15
004c6eee  push    3
004c6ef0  call    0x5446b0
004c6ef5  movss   xmm1, dword ptr [esi + 0x100]
004c6efd  movss   xmm0, dword ptr [0x6104b4]
004c6f05  comiss  xmm0, xmm1
004c6f08  jb      0x4c6f12
004c6f0a  movss   dword ptr [esi + 0x90], xmm1
004c6f12  xorps   xmm2, xmm2
004c6f15  mov     eax, dword ptr [esi + 0x108]
004c6f1b  mov     dword ptr [esi + 0x11c], eax
004c6f21  mov     eax, dword ptr [esi + 0x10c]
004c6f27  mov     dword ptr [esi + 0x120], eax
004c6f2d  mov     eax, dword ptr [esi + 0x220]
004c6f33  test    eax, eax
004c6f35  je      0x4c6f87
004c6f37  cmp     byte ptr [eax], 0
004c6f3a  je      0x4c6f87
004c6f3c  movss   xmm1, dword ptr [eax + 8]
004c6f41  comiss  xmm2, xmm1
004c6f44  jb      0x4c6f55
004c6f46  push    1
004c6f48  lea     ecx, [esi + 0x124]
004c6f4e  call    0x5446b0
004c6f53  pop     esi
004c6f54  ret
004c6f55  comiss  xmm0, xmm1
004c6f58  jb      0x4c6f87
004c6f5a  push    3
004c6f5c  lea     ecx, [esi + 0x124]
004c6f62  call    0x5446b0
004c6f67  mov     eax, dword ptr [esi + 0x220]
004c6f6d  movss   xmm0, dword ptr [0x6104b4]
004c6f75  movss   xmm1, dword ptr [eax + 8]
004c6f7a  comiss  xmm0, xmm1
004c6f7d  jb      0x4c6f87
004c6f7f  movss   dword ptr [esi + 0x1b4], xmm1
004c6f87  pop     esi
004c6f88  ret
```

### Boundary bytes

- Local PE bytes at `0x004c6ea9-0x004c6eb0`: seven `0xcc` bytes.
- Local PE bytes at `0x004c6f89-0x004c6f90`: seven `0xcc` bytes.
- These agree with current by-memory documentation and ignored-ledger claims.

### Constructor duplication evidence

The constructor tail at `0x004c6cb1-0x004c6daa` repeats the same style-state application logic:

- base style enabled check at `0x004c6cb1`;
- base opacity branch and `Pane::SetMode(1/3)` at `0x004c6cc8-0x004c6d16`;
- copy style values into `+0x11c/+0x120` at `0x004c6d21-0x004c6d33`;
- child style pointer check through embedded child `+0xfc` at `0x004c6d39-0x004c6d46`;
- child mode `1/3` and alpha copy at `0x004c6d48-0x004c6da2`.

This duplication supports a source-level helper concept but does not prove a callable out-of-line route for the raw target.

### OnPaintFrame color-role evidence

Local PE disassembly of `0x004c6e50-0x004c6ea9` confirms:

- `HelpPane +0x11c` is pushed to `0x004b9660`, then the pane fill callback at `dword_69b3fc` is invoked with the copied bounds.
- `HelpPane +0x120` is pushed to `0x004b9660`, then frame helper `0x004ba450` is called.
- Therefore the target's copies from `+0x108/+0x10c` feed fill/frame paint state.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c6ea9-0x004c6eb0` | [UID:0000VN] `by-memory/-ignored.md` | predecessor alignment padding | false / ignored | n/a | `100/strong` in coverage | Already covered; no edit by B012. |
| `0x004c6eb0-0x004c6f89` | [UID:00022N] target | raw HelpPane style-state helper | true | [UID:0000JU] `HelpPanes` | current `85/87`; recommended `87/88` after implementation | Keep as exact raw body, no split. |
| `0x004c6f89-0x004c6f90` | [UID:0000VN] `by-memory/-ignored.md` | successor alignment padding | false / ignored | n/a | `100/strong` in coverage | Already covered; no edit by B012. |
| `0x004c6820-0x004c687e` | currently inside [UID:00016R], proposed child in B001/B013 | embedded text-part-only raw style-state helper | true if split | [UID:000064] | proposed `85/88` if split | Counterpart helper; not part of this target. |
| `0x005446b0-0x005446d4` | [UID:0002V7] `PaneSetMode` | dependency mode setter | true | [UID:0000A2] `Pane` | `88/92` | Resolved support blocker. |
| `0x006104ac-0x006104f0` | [UID:0003AQ] `SharedRdataFloatVectorConstants` | shared literal-pool constants including `0x006104b4` | false / non-emitting | none | `86/91` | Resolves `dword_6104B4` placeholder. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004c6ed7` | call to `0x005446b0` | Base pane `Pane::SetMode(1)` when base opacity is `>= 1.0f`. |
| `0x004c6ef0` | call to `0x005446b0` | Base pane `Pane::SetMode(3)` when base opacity is nonnegative and below `1.0f`. |
| `0x004c6f4e` | call to `0x005446b0` with `ecx = this +0x124` | Embedded text part `Pane::SetMode(1)` when text opacity is not greater than zero. |
| `0x004c6f62` | call to `0x005446b0` with `ecx = this +0x124` | Embedded text part `Pane::SetMode(3)` when text opacity is greater than zero and at most `1.0f`. |
| `0x004c6ce1/0x004c6cfc/0x004c6d56/0x004c6d83` | constructor calls to `Pane::SetMode` | Inline constructor copy of the same style-state logic. |
| `0x004c6841/0x004c6857` | sibling raw text-part helper calls to `Pane::SetMode` | Text-part-only counterpart in [UID:00016R]. |
| `0x004c6eb0` | no prior IDA direct xrefs; no local absolute pointers | Entry/liveness remains unresolved. |

## Ranked Ownership Analysis

### 1. [UID:0000JU] HelpPanes by-file owner

- Evidence for:
  - Target sits between HelpPane and SimpleHelpPane executable clusters.
  - [UID:0000JU] is `90/86`, projected to `NexusTK/ui/controls/`, and already owns/emits the HelpPane family.
  - The target reads/writes HelpPane fields and embedded HelpPane text-part fields.
  - Generated memory coverage routes it through [UID:0000JU] to `HelpPanes.cpp`.
  - The target has no proven class method route; by-file family ownership is the conservative direct owner for raw retained helper code.
- Evidence against:
  - The body is probably class-scoped HelpPane logic, so a future route could justify [UID:000063] direct owner.
- Decision: accepted as current direct canonical owner and emitter route.

### 2. [UID:000063] HelpPane by-class owner

- Evidence for:
  - The body uses `HelpPane` as `this`.
  - It updates `HelpPane` style data, paint colors, inherited alpha, and embedded text part.
  - The best source-facing helper name is `HelpPane::ApplyStyleState`.
- Evidence against:
  - No modeled function object, call xref, vtable pointer, or absolute function pointer proves it was emitted as a class method.
  - The constructor has an inline duplicate of the same logic, so the out-of-line raw body could be retained dead code or an unreferenced helper from the translation unit.
- Decision: do not switch direct owner to [UID:000063] yet. Mention [UID:000063] as the likely semantic class when describing behavior.

### 3. [UID:000064] HelpPane__SimpleHelpTextPartPane

- Evidence for:
  - The second half updates the embedded text part at `HelpPane +0x124`.
  - `HelpPane +0x220` aliases the child style pointer.
- Evidence against:
  - The first half updates the base `HelpPane`; the target is not a text-part-only body.
  - The true text-part-only raw helper is `0x004c6820-0x004c687e`.
- Decision: rejected as direct owner for [UID:00022N].

### 4. FontStyle / Pane / shared constants

- Evidence for:
  - The target uses `FontStyle`, `Pane::SetMode`, and the shared `1.0f` constant.
- Evidence against:
  - These are dependencies, not owners. The target applies style to HelpPane fields.
- Decision: rejected as owners.

## Open-Question Closure

Current target open question: "Confirm whether this was an unreferenced private helper, a virtual method with currently missing xrefs, or a generated/raw body left in the `.text` section."

- Closure: current evidence supports "retained raw source-authored helper with no proven external route." It is not a virtual method because no vtable/pointer route is known. It is not padding or compiler glue because it is a coherent HelpPane body with real calls and state writes. It may be an unreferenced private helper or out-of-line copy of logic inlined into the constructor, but that cannot be narrowed further without a live entry route.
- Score/C++ impact: this is the exact formal C++ blocker; it should not block reconstructable classification or HelpPanes ownership, but it should keep formal C++ blank and cap scores below final-audit range.

Current target open question: "Final field names for `this + 0xfc`, `this + 0x100`, `this + 0x108/+0x10c`, `this + 0x11c/+0x120`, `this + 0x1b4`, and `this + 0x220` remain provisional."

- Closure:
  - `+0xfc`: embedded `FontStyle m_fontStyle` / enabled byte at field `+0`.
  - `+0x100`: `m_fontStyle.baseOpacity` / pane opacity (`FontStyle +0x04`).
  - `+0x104`: `m_fontStyle.textOpacity` (`FontStyle +0x08`), read through child style pointer at `+0x220`.
  - `+0x108/+0x10c`: style values copied to fill/frame paint color fields.
  - `+0x11c/+0x120`: fill/frame color fields used by `OnPaintFrame`.
  - `+0x1b4`: embedded text part inherited alpha (`m_textPart +0x90`).
  - `+0x220`: embedded text part borrowed `FontStyle *` (`m_textPart.m_fontStyle`), initialized to `this +0xfc`.
- Remaining caveat: original member spellings are unknown, and shared `FontStyleLayout` still keeps scalar names conservative. This should no longer block target-level source-quality prose.

Current target open question: "The nearby raw helper around `0x004c6820` now has the same `PaneSetMode`/style-state shape but belongs to the embedded text-part draw path rather than this base `HelpPane` updater; split or name that helper separately before final C++ reconstruction."

- Closure for this target: B001/B013 already identified the `0x004c6820-0x004c687e` helper as a separate text-part raw helper candidate named `ApplyStyleOpacityState` / `ApplyStyleStateFromFontStyle`. It should be cross-linked as the text-part-only counterpart. It does not require [UID:00022N] to split or wait for final target classification.
- Score/C++ impact: it reinforces the no-code policy for raw no-entry helpers and gives field-name evidence, but it does not block [UID:00022N] documentation improvement.

Current reconstruction note: "Leave `RECONSTRUCTION_CPP` blank until the final private method name, exact call path, `PaneSetMode` source name, and field names are recovered."

- Closure:
  - `PaneSetMode` source name is recovered: [UID:0002V7] `Pane::SetMode(unsigned char)`.
  - Field names are sufficiently resolved for target-level documentation, with exact caveats.
  - Final private method name remains descriptive only.
  - Exact call path remains unresolved and is the remaining formal no-code blocker.

## First-Draft C++ / Exact No-Code Proof

### Formal C++ decision

Do not populate [UID:00022N]'s formal `RECONSTRUCTION_CPP CODE` block in the implementation callback.

Use this target-specific no-code proof:

1. [UID:00022N] is numerically eligible by current metadata (`85/87`, average `86`) and has a valid emitter route to [UID:0000JU], but active code-entry eligibility is a minimum gate, not permission to invent source shape.
2. Prior live IDA evidence recorded in the target found no modeled function at `0x004c6eb0`, no direct xref to `0x004c6eb0`, and no external xrefs into any byte of `0x004c6eb0-0x004c6f89`.
3. This report's local PE scan found no absolute dword pointer to any address inside `0x004c6eb0-0x004c6f89`.
4. The body duplicates constructor-side style-state logic at `0x004c6cb1-0x004c6daa`, which makes a source helper plausible but not live-route proven.
5. No vtable, call site, function pointer table, or import/export record proves a callable source declaration for this exact raw body.
6. A formal emitted `void HelpPane::ApplyStyleState()` method would currently be a documentation invention: semantically plausible, but not proven as generated-output source shape.
7. Therefore the correct formal generated source is still the empty emitter marker, with a target note that the marker is intentional and not a missing-C++ oversight.

### Non-formal source-shape draft for future route proof

This draft is not recommended for the target's formal C++ block yet. It is included only to preserve the source-quality behavior if a future call/vtable/pointer route proves that the out-of-line helper should emit.

```cpp
void HelpPane::ApplyStyleState()
{
    if (!m_fontStyle.enabled)
        return;

    const float baseOpacity = m_fontStyle.baseOpacity;
    if (baseOpacity >= 1.0f) {
        SetMode(1);
    } else if (baseOpacity >= 0.0f) {
        SetMode(3);
        if (baseOpacity <= 1.0f)
            m_alpha = baseOpacity;
    }

    m_fillColor = m_fontStyle.fillColor;
    m_frameColor = m_fontStyle.frameColor;

    FontStyle *textStyle = m_textPart.m_fontStyle;
    if (textStyle == NULL || !textStyle->enabled)
        return;

    const float textOpacity = textStyle->textOpacity;
    if (textOpacity <= 0.0f) {
        m_textPart.SetMode(1);
        return;
    }

    if (textOpacity <= 1.0f) {
        m_textPart.SetMode(3);
        if (textStyle->textOpacity <= 1.0f)
            m_textPart.m_alpha = textStyle->textOpacity;
    }
}
```

Known draft caveats:

- `SetMode(1)` and `SetMode(3)` must remain numeric or use provisional `PaneMode` constants until [UID:0002V7]/Pane enum names are resolved.
- `m_fontStyle.baseOpacity`, `textOpacity`, `fillColor`, and `frameColor` are target-level descriptive names, not proven shared original names.
- The child style pointer is borrowed from the parent embedded `FontStyle`; it must not be deleted by the text part.
- This draft omits any caller because no caller is proven.

## Score And Metadata Recommendation

Preferred target metadata after implementation:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion can rise to `87` only after target docs record the exact base/child branch distinction, field/type names, shared constant ownership, no-route proof, and formal no-code decision. It remains below `90` because no entry route, original helper spelling, final mode enum names, and full HelpPaneCore child split remain open.
- Confidence can rise to `88` because local PE disassembly independently validates the body and constructor duplicate, while B002/B013 support resolves major dependency/field blockers. It should not rise higher because live IDA MCP was unavailable in this session and the entry route is still unproven.
- Owner/emitter route should remain unchanged.
- Formal C++ remains blank.

Conservative alternate if supervisor rejects score movement:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Even under the conservative alternate, update the prose and stale coverage row to close source-quality blockers.

## Exact Supervisor-Owned Coverage Row Text

Do not edit `by-memory/-coverage-report.md` directly in the B-agent report pass.

Placement context: replace the current [UID:00022N] row between the ignored padding row for `0x004c6ea9-0x004c6eb0` and the ignored padding row for `0x004c6f89-0x004c6f90`.

Preferred replacement row if the supervisor accepts the `87/88` implementation recommendation:

```text
    - [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) 0x004c6eb0-0x004c6f89 | raw-function | HelpPaneFadeStateUpdate : reconstructable : 87% : strong : B012 2026-06-19 source-quality reanalysis keeps this exact raw HelpPane style-state helper under HelpPanes owner/emitter [UID:0000JU], refines the source-facing role to `HelpPane::ApplyStyleState`, proves exact base-pane and embedded text-part `Pane::SetMode(1/3)` branch conditions from local PE disassembly, resolves `sub_5446B0` as [UID:0002V7] `Pane::SetMode`, resolves `dword_6104B4` as the shared [UID:0003AQ] `1.0f` literal-pool constant, names the consumed state as embedded `FontStyle` base/text opacity plus fill/frame paint colors, and records an exact no-formal-C++ proof because prior IDA and local PE evidence still show no modeled function, no external entry xref, and no function-pointer/vtable route into the body.
```

Conservative replacement row if supervisor keeps target metadata at current `85/87`:

```text
    - [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md) 0x004c6eb0-0x004c6f89 | raw-function | HelpPaneFadeStateUpdate : reconstructable : 85% : strong : Current target metadata is 85/87 after A002, with HelpPanes owner/emitter [UID:0000JU]; B012 2026-06-19 source-quality reanalysis refines the role to raw `HelpPane::ApplyStyleState`, resolves `sub_5446B0` as [UID:0002V7] `Pane::SetMode`, resolves `dword_6104B4` as the shared [UID:0003AQ] `1.0f` literal-pool constant, documents exact base and embedded child mode/opacity/color branch behavior, and keeps formal C++ blank because no modeled function, external entry xref, or function-pointer/vtable route into the raw body is proven.
```

## Target / Support Implementation Checklist

### Target doc: [UID:00022N] `by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md`

Apply these changes if the report is accepted:

1. Update metadata to `87/88` if the supervisor accepts the score recommendation; otherwise keep `85/87`.
2. Keep `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
3. Replace or supplement "Current/proposed name" with:
   - filename/search label: `HelpPaneFadeStateUpdate`;
   - best source-facing descriptive name: `HelpPane::ApplyStyleState`;
   - alternate accepted historical/descriptive name: `HelpPane::UpdateFadeState`.
4. Replace broad behavior text with exact base/child branch logic:
   - base opacity `>= 1.0f`: `Pane::SetMode(1)`;
   - base opacity `0.0f <= value < 1.0f`: `Pane::SetMode(3)` and copy to `HelpPane +0x90`;
   - base opacity `< 0.0f`: no base mode write, still copies colors and checks child style;
   - child/text opacity `<= 0.0f`: child `Pane::SetMode(1)` and return;
   - child/text opacity `0.0f < value <= 1.0f`: child `Pane::SetMode(3)` and copy to child alpha at parent `+0x1b4`;
   - child/text opacity `> 1.0f`: no child mode/alpha write.
5. Update the touched-state table:
   - `+0xfc`: embedded `FontStyle m_fontStyle`, enabled byte at `FontStyle +0`;
   - `+0x100`: base/pane opacity (`FontStyle +0x04`);
   - `+0x104`: text opacity (`FontStyle +0x08`, usually reached through `+0x220`);
   - `+0x108/+0x10c`: style values copied to fill/frame paint color fields;
   - `+0x11c/+0x120`: fill/frame color fields consumed by `OnPaintFrame`;
   - `+0x220`: embedded text part borrowed `FontStyle *`;
   - `+0x1b4`: embedded text part inherited alpha (`+0x90` inside child).
6. Replace `dword_6104B4` wording with "shared `1.0f` literal-pool constant at `0x006104b4`, covered by [UID:0003AQ]."
7. Replace `sub_5446B0` wording with [UID:0002V7] `Pane::SetMode(unsigned char mode)`.
8. Replace legacy `AUTOGEN_PARENT_UID` language in Reconstruction Notes with current `CANONICAL_OWNER` and `EMITTER_UIDS` wording.
9. Add a "Formal C++ no-code proof" section using the exact proof above, and explicitly state that the generated empty emitter marker is intentional for now.
10. Add this report path in `## Changes` with summary:
    - source-quality reanalysis;
    - exact branch conditions;
    - field/global/helper name closure;
    - no-route/no-code proof;
    - optional score change.

### Support doc: [UID:0000JU] `by-file/HelpPanes.md`

Recommended sync:

1. In Proposed Contents, update [UID:00022N]'s row from "raw help-pane fade/state updater" to "raw no-entry HelpPane style-state application helper; formal C++ intentionally blank until entry route is proven."
2. Mention that B012 resolved the target's dependency names (`Pane::SetMode`, shared `1.0f` constant) and target-local `FontStyle` fields, but did not resolve an entry route.
3. Keep file score `90/86` unless the supervisor wants a small confidence bump after broader HelpPanes updates. This target alone does not require changing the file score.

### Support doc: [UID:000063] `by-class/HelpPane.md`

Recommended sync:

1. Update the method note for [UID:00022N]:
   - source-facing role `ApplyStyleState` / raw retained helper;
   - no direct entry route;
   - no formal C++ yet.
2. Add field notes:
   - embedded `FontStyle` at `+0xfc`;
   - base opacity at `FontStyle +0x04`;
   - text opacity at `FontStyle +0x08`;
   - fill/frame paint colors at `+0x11c/+0x120`;
   - embedded text part at `+0x124`;
   - child borrowed `FontStyle *` alias at parent `+0x220`.
3. Keep class score `85/89` unless the implementation also incorporates broader B013/B001 class-child split details.

### Support doc: [UID:000064] `by-class/HelpPane__SimpleHelpTextPartPane.md`

Recommended sync:

1. Cross-link [UID:00022N] as the parent `HelpPane` counterpart to the text-part raw style-state helper.
2. Preserve B013's stronger field direction:
   - `+0xf8` `SimpleUString m_text`;
   - `+0xfc` borrowed `FontStyle *m_fontStyle`;
   - `+0x90` inherited alpha;
   - parent `HelpPane +0x220` aliases this child `+0xfc`.
3. Do not make [UID:00022N] a child-owned method.

### Support doc: [UID:00016R] `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`

Recommended sync:

1. In references to [UID:00022N], use `HelpPane::ApplyStyleState` / raw style-state helper wording.
2. Add that the raw target's base mode branch differs from the embedded text-part raw helper:
   - target base mode `1` for base opacity `>= 1.0f`;
   - text-part mode `1` for text opacity `<= 0.0f`.
3. If B001's split is later implemented, cross-link the proposed `0x004c6820-0x004c687e` child as text-part counterpart, not as part of [UID:00022N].

### Support doc: [UID:0001UN] `by-type/by-struct/FontStyleLayout.md`

Optional support note only:

1. Add a consumer-specific note that [UID:00022N]/[UID:000063]/[UID:000064] strengthen this interpretation for HelpPane:
   - `FontStyle +0x04` is base/pane opacity in HelpPane;
   - `FontStyle +0x08` is embedded text opacity in HelpPane;
   - `FontStyle +0x0c/+0x10` feed HelpPane fill/frame color fields.
2. Do not globally rename the shared scalar fields unless a broader FontStyle consumer audit accepts those names across StaticText, MiniMap, and other users.

### Support doc: [UID:0003AQ] `by-memory/0x006104ac-0x006104f0.SharedRdataFloatVectorConstants.md`

No edit required. The page already covers `0x006104b4` as a broad shared literal-pool constant. The target should link/cite it rather than rename the constant locally.

## Validation Commands For Implementation Callback

From `E:\NTK\GhidraBridge\source-3\project-documentation`, after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [00022N-HelpPaneFadeStateUpdate-source-quality-removed.md](00022N-HelpPaneFadeStateUpdate-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation does not edit one of the optional support docs, skip that file-specific validator command and record the reason.

`by-memory/-coverage-report.md` remains supervisor-owned. After the target/support docs validate, the supervisor should apply the exact row from this report and validate/refresh according to supervisor workflow.

## Validator Results

- No validator commands were run in this report-only pass.
- No by-* docs were edited.
- No generated reports were edited.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00022N-HelpPaneFadeStateUpdate-source-quality.md`
- Modified:
  - none
- Renamed:
  - none
- Moved to executed:
  - none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00022N-HelpPaneFadeStateUpdate-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00022N"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022N-HelpPaneFadeStateUpdate-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00022N-HelpPaneFadeStateUpdate-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
