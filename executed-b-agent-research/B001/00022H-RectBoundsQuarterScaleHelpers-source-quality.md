** TARGET-REPORT-UID:00022H **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022H RectBoundsQuarterScaleHelpers Source-Quality Research

Assignment: `B001-00022H-RectBoundsQuarterScaleHelpers-source-quality`  
Agent: `Agent-B001`  
Target: `[UID:00022H] source-3/project-documentation/by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00022H-RectBoundsQuarterScaleHelpers-source-quality.md`  
Current target score: `85/86`

## Final Recommendation

Raise the target to `89/90`, keep `RECONSTRUCTABLE:TRUE`, and change the direct owner/emitter from the file page to the `RectBounds` class:

```text
CANONICAL_OWNER:0000BU
EMITTER_UIDS:0000BU
```

The current binary label `RectBoundsQuarterScaleHelpers` can remain as the stable file/link name for this implementation pass, but the prose and row names should be corrected. The first helper at `0x004b7af0` does inset by one quarter of the source span on each side, yielding a half-size centered rectangle. The second helper at `0x004b7b90` does not use `0.25f`; it loads `0x006104b0 == 0.5f` and outsets by one half of the source span on each side, yielding a double-size rectangle.

Best source-facing names and signatures:

```cpp
RectBounds *RectBounds::InsetByQuarter(RectBounds *outBounds) const;
RectBounds *RectBounds::OutsetByHalf(RectBounds *outBounds) const;
```

Conceptual aliases such as `MakeHalfSize` / `MakeDoubleSize` are plausible, but the edge-operation names above best match the current RectBounds style (`Inset`, `Offset`, `InflateRect`) and the actual instruction-level edge math.

Formal C++ should be added. This target is source-authored, class-owned geometry code with a valid emitter route. The lack of direct xrefs is now a liveness note, not a no-code blocker.

## Report-Only Compliance

No target, support, source, generated, IDA DB, or coverage files were edited. This report is the only intended changed file for this assignment.

Existing completed B001 reports (`0002NQ`, `00013I`, `00016R`, `00019L`, `0001C1`, `000250`) were not modified. I did not use or coordinate with A/C agents.

Fresh IDA/CacheCaller probe status from this shell:

```text
CacheCaller IDA commands requiring the online connector failed because the Python environment is missing requests.
```

Therefore this report combines the existing live-IDA-backed target/support docs with a fresh section-aware PE byte/disassembly scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Evidence Checked

Primary docs:

- `by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`
- `by-memory/-coverage-report.md` current `00022H` row
- `auto-generated/-ag-memory-coverage.md` current route for `00022H`
- `auto-generated/NexusTK/ui/core/RectBounds.cpp` current empty marker

RectBounds support docs:

- `by-file/RectBounds.md`
- `by-class/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`
- `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
- `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`
- `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`
- `by-memory/-ignored.md`

Local binary evidence:

- Parsed PE headers from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Mapped `.text` image base `0x00400000`; target bytes are in `.text`.
- Extracted bytes for `0x004b7ae8-0x004b7c30`.
- Disassembled both helper bodies with Capstone.
- Scanned the whole file for literal VA and RVA encodings of `0x004b7af0` and `0x004b7b90`.
- Scanned executable sections for direct rel8/rel32 branches or calls to either helper start and to any address inside either helper body.
- Read float constants at `0x0061a880` and `0x006104b0`.
- Scanned whole file for literal references to the two float constants as a cross-check.

Conversions checked with `source-3/project-documentation/tools/int_convert.py`:

- `0x98` = 152 bytes.
- `0x91` = 145 bytes.
- `0x8` = 8 bytes.
- `0xf` = 15 bytes.
- `0x131` = 305 bytes.
- `0x148` = 328 bytes.

## Exact Bytes, Starts, Ends, And Padding

The current address split is correct and should not be merged or extended:

| Span | Length | Fresh PE finding |
| --- | ---: | --- |
| `0x004b7ae8-0x004b7af0` | `0x8` / 8 bytes | All `0xcc` padding before the first raw helper. |
| `0x004b7af0-0x004b7b88` | `0x98` / 152 bytes | Function-shaped helper body, standard frame setup, ends with `ret 4` at `0x004b7b85`. |
| `0x004b7b88-0x004b7b90` | `0x8` / 8 bytes | All `0xcc` internal padding. |
| `0x004b7b90-0x004b7c21` | `0x91` / 145 bytes | Function-shaped helper body, standard frame setup, ends with `ret 4` at `0x004b7c1e`. |
| `0x004b7c21-0x004b7c30` | `0xf` / 15 bytes | All `0xcc` padding before the next modeled helper at `0x004b7c30`. |

Fresh PE bytes agree with the target's prior live IDA boundary correction: the `04 00` operands of both `ret 4` instructions belong to the helper bodies, not to padding.

IDA status remains raw/unmodeled in the current docs: repeated `lookup_funcs` checks reported no function object at `0x004b7af0` or `0x004b7b90`, while adjacent `0x004b78d0`, `0x004b7910`, and `0x004b7c30` are modeled. The fresh PE scan does not change IDA's database state, but it proves the bytes are self-contained function bodies.

## Corrected Helper Semantics

### `0x004b7af0-0x004b7b88`

Disassembly facts:

- `ecx` is the source `RectBounds`.
- `[ebp+8]` is the caller-provided output `RectBounds *`.
- `eax` is set to the output pointer at `0x004b7b3e` and remains the return value.
- Width is `right - left`; height is `bottom - top`.
- `0x0061a880` bytes are `00 00 80 3e`, float `0.25f`.
- `0x006104b0` bytes are `00 00 00 3f`, float `0.5f`.
- Left and top use `sourceEdge + span * 0.25f + 0.5f` before `cvttss2si`.
- Right and bottom use `sourceEdge - span * 0.25f` before `cvttss2si`.

Best source name: `RectBounds::InsetByQuarter`. The operation insets each side by one quarter of the current span, producing a half-size rectangle centered with the observed left/top rounding bias.

### `0x004b7b90-0x004b7c21`

Disassembly facts:

- `ecx` is the source `RectBounds`.
- `[ebp+8]` is the caller-provided output `RectBounds *`.
- `eax` is set to the output pointer at `0x004b7bde` and remains the return value.
- The helper loads `0x006104b0 == 0.5f` once into `xmm2`.
- Width and height are multiplied by `0.5f`, not `0.25f`.
- Left and top use `sourceEdge - span * 0.5f - 0.5f` before `cvttss2si`.
- Right and bottom use `sourceEdge + span * 0.5f` before `cvttss2si`.

Best source name: `RectBounds::OutsetByHalf`. The current target's `OutsetByQuarter` row is stale and should be corrected.

## Reachability / Liveness

Fresh section-aware PE scan results:

- Whole-file literal pointer scan found zero little-endian hits for `0x004b7af0`.
- Whole-file literal pointer scan found zero little-endian hits for `0x004b7b90`.
- Whole-file RVA scan found zero little-endian hits for `0x000b7af0`.
- Whole-file RVA scan found zero little-endian hits for `0x000b7b90`.
- Executable-section branch scan found no direct rel8/rel32 branch or call target to `0x004b7af0` or `0x004b7b90`.
- Executable-section branch scan found no direct branches or calls from outside into either helper body interior.

Existing target IDA evidence also reports no `xrefs_to` or `callers` for both raw starts. The broader liveness conclusion is now stronger: these helpers are not ordinary directly called code, not vtable slots, and not address-taken through a literal pointer table in the file.

The best explanation is retained but currently unused source-authored member code. This pattern is already present in the surrounding RectBounds family: [UID:00022G] has four raw method-shaped bodies with no direct xrefs between modeled RectBounds predicates, while the same page still treats them as source-authored RectBounds methods because their prologues, signatures, layout use, and neighborhood are class-method shaped. `00022H` is the same kind of raw body island, with stronger byte boundaries and now a clean no-pointer/no-branch PE scan.

Rejected liveness explanations:

- Virtual method or vtable route: rejected. `RectBounds` is documented as a POD-style helper with no confirmed vtable, and no literal start pointers were found.
- Callback or function-pointer table: rejected on current evidence. VA/RVA pointer scans found no entries.
- Compiler/runtime glue: rejected. The bodies operate on the project-specific `RectBoundsLayout` fields and float geometry constants; they are not thunks, destructors, EH helpers, CRT routines, or switch tables.
- Adjacent fallthrough: rejected. `0xcc` padding separates the helpers from previous, middle, and next code.
- Inline-only source: rejected as the exact explanation for these bytes. These are out-of-line function bodies. They may originate from source methods that were also inlineable elsewhere, but this binary contains retained out-of-line copies.

## Ownership / Emitter Ranking

### 1. `RectBounds` class methods - selected

Evidence:

- Both helpers use `ecx` as the source object and one stack argument as an output pointer, then return the output pointer in `eax`.
- Both use the exact four-int `RectBoundsLayout` field order.
- The helpers sit between class-style RectBounds methods and free geometry helpers.
- Neighbor [UID:00015R] already uses class owner/emitter `0000BU` for the modeled member-style `RectBoundsInset` helper at `0x004b7910`.
- The class page already lists the pair as `RectBounds` methods; only the second name/scale and metadata route need correction.

Recommended metadata:

```text
CANONICAL_OWNER:0000BU
EMITTER_UIDS:0000BU
```

The class emitter still lands in `auto-generated/NexusTK/ui/core/RectBounds.cpp` through the existing `RectBounds` file route, matching `00015R`.

### 2. File-local helpers in `RectBounds.cpp` - plausible fallback, not selected

A source form such as `static RectBounds *InsetByQuarter(const RectBounds *src, RectBounds *out)` could express the behavior. It is less likely because the binary calling convention is `__thiscall`-shaped, not ordinary cdecl/fastcall free-helper shaped, and the immediate neighborhood is member-method shaped.

If the supervisor chooses not to change owner metadata yet, keep `0000N2` but still add the C++ as class-like helper declarations in the `RectBounds` source family. Do not leave the owner question as a passive blocker.

### 3. Free/static geometry utilities outside `RectBounds.cpp` - rejected for this pass

The next page [UID:00015S] contains cdecl-style free helpers such as `InitRectBounds`, `IntersectRects`, and `PointInRect`. `00022H` differs: it uses `ecx` as a source object and returns an output pointer. There is no evidence for a separate geometry source file or non-RectBounds owner.

### 4. Compiler-generated or runtime code - rejected

No vtable, RTTI, scalar deleting destructor, switch table, import thunk, or CRT pattern is present. The code is source-authored rectangle math.

## First-Draft C++

Recommended `RECONSTRUCTION_CPP` body:

```cpp
RectBounds *RectBounds::InsetByQuarter(RectBounds *outBounds) const
{
    const float quarterWidth = static_cast<float>(this->right - this->left) * 0.25f;
    const float quarterHeight = static_cast<float>(this->bottom - this->top) * 0.25f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) + quarterWidth + 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) + quarterHeight + 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) - quarterWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) - quarterHeight);
    return outBounds;
}

RectBounds *RectBounds::OutsetByHalf(RectBounds *outBounds) const
{
    const float halfWidth = static_cast<float>(this->right - this->left) * 0.5f;
    const float halfHeight = static_cast<float>(this->bottom - this->top) * 0.5f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) - halfWidth - 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) - halfHeight - 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) + halfWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) + halfHeight);
    return outBounds;
}
```

Notes:

- `static_cast<int>(float)` is the closest source expression for the observed `cvttss2si` truncation.
- Do not add empty caller guards or null output checks; the binary has none.
- Do not make the helpers mutating `void` methods; both bodies preserve `eax` as the output pointer return.
- The first body uses a dedicated `0.25f` constant. The second body uses `0.5f` as both the half-scale multiplier and the top/left outward rounding bias.

## Recommended Target Doc Changes

Metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current status owner wording with:

```markdown
- Disposition: reconstructable shared `RectBounds` value-object methods.
- Current source-owner state: source-authored `RectBounds` class-method pair retained in the binary without direct caller or pointer-table reachability.
- Proposed source file: [UID:0000N2][RectBounds](by-file/RectBounds.md) RectBounds.
- Primary class and direct owner: [UID:0000BU][RectBounds](by-class/RectBounds.md) RectBounds.
- Confidence: strong for behavior, byte boundaries, class-method shape, and source-family ownership; medium-high for exact original source spellings because no direct call site recovers the names.
```

Replace the covered rows with:

```markdown
| Range | Current/proposed name | IDA status | Notes |
| --- | --- | --- | --- |
| `0x004b7af0-0x004b7b88` | `RectBounds::InsetByQuarter(RectBounds *outBounds) const` | raw function-shaped code | Writes an output rectangle inset by one quarter of the source width/height. Left/top add `0.25f * span + 0.5f` before truncation; right/bottom subtract `0.25f * span`; returns `outBounds`; ends with full `retn 4` at `0x004b7b85-0x004b7b87`. |
| `0x004b7b90-0x004b7c21` | `RectBounds::OutsetByHalf(RectBounds *outBounds) const` | raw function-shaped code | Writes an output rectangle expanded outward by one half of the source width/height. Left/top subtract `0.5f * span + 0.5f`; right/bottom add `0.5f * span`; returns `outBounds`; ends with full `retn 4` at `0x004b7c1e-0x004b7c20`. |
```

Add this source-quality evidence note:

```markdown
- 2026-06-19 B001 PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed the exact byte ranges and padding: `0x004b7ae8-0x004b7af0` is 8 bytes of `0xcc`, first helper `0x004b7af0-0x004b7b88` is `0x98` / 152 bytes (Verified with `int_convert.py`), `0x004b7b88-0x004b7b90` is 8 bytes of `0xcc`, second helper `0x004b7b90-0x004b7c21` is `0x91` / 145 bytes (Verified with `int_convert.py`), and `0x004b7c21-0x004b7c30` is 15 bytes of `0xcc`.
- The same PE scan found no literal VA/RVA pointer hits for `0x004b7af0` or `0x004b7b90`, no direct rel8/rel32 branch or call to either helper start, and no direct outside branch/call into either helper body. Treat the no-xref state as retained unused source-authored member code, not as a callback/vtable route.
- `0x0061a880` bytes are `00 00 80 3e` (`0.25f`) and are used by the first helper. `0x006104b0` bytes are `00 00 00 3f` (`0.5f`) and the second helper uses it as the half-scale multiplier as well as the left/top rounding bias. The previous `OutsetByQuarter` wording is stale.
```

Replace the score rationale with:

```markdown
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 89 | The page has exact start/end/padding bytes, corrected first/second helper lengths, raw function status, instruction-level behavior, constant values, output-pointer return evidence, no-callee state, no direct xref/caller evidence, fresh PE-level no pointer/branch route scans, adjacent RectBounds method context, selected class owner/emitter route, rejected alternatives, and first-draft C++. |
| Confidence | 90 | Behavior, bytes, layout, class-method shape, and RectBounds source ownership are strongly supported by existing live IDA docs plus fresh PE disassembly/scans. Confidence remains below final-audit levels because both starts are still raw in IDA, no caller recovers the original names, and the exact original spelling could have been `MakeHalfSize`/`MakeDoubleSize` rather than the selected edge-operation names. |
```

Insert the first-draft C++ block from this report into the target `RECONSTRUCTION_CPP CODE` section.

Do not rename the target file in the first implementation callback unless the supervisor explicitly wants file churn. If a later rename pass is approved, `RectBoundsHalfScaleHelpers` or `RectBoundsScaleHelpers` would be less misleading than `RectBoundsQuarterScaleHelpers`.

## Recommended Support-Doc Updates

`by-file/RectBounds.md`:

```markdown
| [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers | `0x004b7af0-0x004b7c21` | Raw `RectBounds` class-method pair that writes a quarter-inset/half-size rectangle and a half-outset/double-size rectangle into caller-provided outputs; fresh PE scan found no direct pointer or branch route, so current liveness is retained unused source-authored member code. |
```

Also update the evidence note that currently says "quarter-scale helpers" to mention `InsetByQuarter` and `OutsetByHalf`, with the `0.25f` / `0.5f` correction.

`by-class/RectBounds.md`:

```markdown
| `InsetByQuarter(RectBounds *outBounds) const` / `OutsetByHalf(RectBounds *outBounds) const` | `0x004b7af0-0x004b7c21` | Raw member-style helper pair. The first insets by one quarter on each side and returns a half-size rectangle; the second outsets by one half on each side and returns a double-size rectangle. Both return the output pointer. |
```

Add that `00022H` should now be class-owned/emitted through `0000BU`, matching the nearby [UID:00015R] member-style `RectBoundsInset` page.

`by-type/by-struct/RectBoundsLayout.md`:

Replace the current quarter-scale semantics bullet with:

```markdown
- `0x004b7af0` / `RectBounds::InsetByQuarter` derives a half-size centered rectangle by insetting each side by `0.25f` of width/height, using `+0.5f` before truncating the left/top edges. `0x004b7b90` / `RectBounds::OutsetByHalf` derives a double-size rectangle by outsetting each side by `0.5f` of width/height, using `-0.5f` before truncating the left/top edges. Both write the same four-int `left, top, right, bottom` output layout.
```

`by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`:

Update the "next related helper island" and evidence wording from "quarter-scale helpers" to "quarter-inset/half-outset class-method pair", and mention that `00022H` is recommended class-owned (`0000BU`) rather than file-owned.

`by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`:

Update the "previous raw helper island" and evidence wording to say the preceding island is a member-style `RectBounds` output helper pair, not part of the cdecl-style free geometry helper island, and correct `OutsetByQuarter` to `OutsetByHalf`.

`by-memory/-ignored.md`:

The padding entry is correct but can be clarified without changing ranges:

```markdown
- `0x004b7ae8-0x004b7af0`, `0x004b7b88-0x004b7b90`, and `0x004b7c21-0x004b7c30` - alignment padding around `RectBounds` scale helpers (`InsetByQuarter` / `OutsetByHalf`).
```

`auto-generated/-ag-memory-coverage.md` and generated source should update through the normal validator/autogen workflow after target metadata/C++ are implemented. No manual edit is recommended in this B report.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made. Recommended future updates if the supervisor wants IDA cleanup:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004b7af0` | If a function is created, name/comment as `RectBounds::InsetByQuarter(RectBounds *outBounds) const` / `RectBounds_InsetByQuarter`. | High |
| `0x004b7b90` | If a function is created, name/comment as `RectBounds::OutsetByHalf(RectBounds *outBounds) const` / `RectBounds_OutsetByHalf`. | High |
| `0x0061a880` | Comment as float constant `0.25f`, locally used by `RectBounds::InsetByQuarter`; avoid claiming RectBounds-private ownership because it sits in shared `.rdata`. | High |
| `0x006104b0` | Comment as shared float constant `0.5f`, used here as rounding bias and half-scale multiplier, and elsewhere as a generic float bias. | High |
| `0x004b7ae8-0x004b7af0` | Alignment padding before first helper. | High |
| `0x004b7b88-0x004b7b90` | Alignment padding between helpers. | High |
| `0x004b7c21-0x004b7c30` | Alignment padding before `InitPointPair` at `0x004b7c30`. | High |

Do not create a vtable route, callback table, or standalone source module for these helpers without new evidence.

## Open Questions And Attempted Resolution

1. Exact original method names.
   - Checked current target, class/file/type docs, adjacent RectBounds method names, PE disassembly, and local documentation search for similar "HalfSize", "DoubleSize", "ByHalf", and "ByQuarter" names.
   - Best answer: use `InsetByQuarter` and `OutsetByHalf`. The observed edge math supports those names directly. `MakeHalfSize` / `MakeDoubleSize` remain conceptual alternatives but are not better supported by local naming style.

2. Why no direct callers or xrefs exist.
   - Checked existing IDA `xrefs_to`/`callers` notes, whole-file VA/RVA pointer scans, and executable-section branch/call scans to starts and interiors.
   - Best answer: retained unused source-authored member methods. Address-taken/vtable/callback explanations are currently unsupported.

3. Whether these are class methods or file-local/free helpers.
   - Checked calling convention, output pointer return, RectBounds layout use, adjacent class-method island, and `00015R` class-owned precedent.
   - Best answer: class methods. File-local static helpers are the fallback only if the supervisor declines the metadata owner change.

4. Whether final C++ is blocked.
   - Checked current by-structure gate, autogen route, current empty marker, owner/emitter validity, and function semantics.
   - Best answer: not blocked. Add first-draft C++ now. The missing direct xrefs affect liveness confidence but do not make this no-code.

5. Whether the target/page name should change.
   - Checked current target path and support links.
   - Best answer: leave the path stable for this implementation unless the supervisor explicitly approves a rename. Correct prose and row names now; optionally rename in a later link-maintenance pass.

## Exact Coverage-Report Replacement Row

Do not edit `by-memory/-coverage-report.md` in this B-agent report. If the supervisor accepts the implementation, replace the current `00022H` row with:

```text
    - [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) 0x004b7af0-0x004b7c21 | raw-function-cluster | RectBoundsQuarterScaleHelpers : reconstructable : 89% : strong : B001 source-quality PE scan reconfirms exact raw helper bodies and padding at 0x004b7ae8-0x004b7af0, 0x004b7b88-0x004b7b90, and 0x004b7c21-0x004b7c30; first helper 0x004b7af0-0x004b7b88 is RectBounds::InsetByQuarter with 0.25f scale and output-pointer return, second helper 0x004b7b90-0x004b7c21 is corrected to RectBounds::OutsetByHalf using 0.5f scale, no VA/RVA pointer hits or direct branch/call routes to starts/interiors were found, retained unused source-authored class-method code is the best liveness explanation, owner/emitter should be RectBounds class 0000BU, and first-draft C++ is ready.
```

If a later rename pass changes the target file name, update the link label/path in the coverage row at that time.

## Validation Commands Needed

After implementation edits, run from `E:\NTK\GhidraBridge`:

> Executable block R001 was removed from this report and preserved verbatim in [00022H-RectBoundsQuarterScaleHelpers-source-quality-removed.md](00022H-RectBoundsQuarterScaleHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

`by-memory/-coverage-report.md` validation should be run only after the supervisor applies or authorizes the coverage-row replacement. B001 must not edit that file under the current assignment.

If live IDA is available during implementation review, recommended spot checks are:

```text
lookup_funcs 0x004b7ae8 0x004b7af0 0x004b7b88 0x004b7b90 0x004b7c21 0x004b7c30
get_bytes 0x004b7ae8 size 0x148
disasm 0x004b7af0
disasm 0x004b7b90
xrefs_to 0x004b7af0 0x004b7b90 0x0061a880 0x006104b0
callers 0x004b7af0 0x004b7b90
```

Expected IDA result remains: no modeled functions at the two raw starts, no callers/xrefs to the starts, constants at `0x0061a880 == 0.25f` and `0x006104b0 == 0.5f`, and the exact `ret 4` endpoints recorded above.

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

- Update target score to `89/90`.
- Change owner/emitter to `0000BU`.
- Correct `OutsetByQuarter` to `OutsetByHalf`.
- Add fresh PE byte/no-pointer/no-branch evidence.
- Add the first-draft C++ body.
- Update support docs listed above.
- Update the coverage row only after supervisor approval.

Do not:

- edit `by-memory/-coverage-report.md` during this report-only pass,
- rename the target file unless the supervisor explicitly asks for link churn,
- route these helpers through a callback/vtable owner,
- leave the second helper described as quarter-scale,
- leave final C++ blank after implementation acceptance.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00022H-RectBoundsQuarterScaleHelpers-source-quality.md`.
- Modified: none.
- Target/support by-* docs edited: none.
- `by-memory/-coverage-report.md` edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00022H-RectBoundsQuarterScaleHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00022H"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022H-RectBoundsQuarterScaleHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00022H-RectBoundsQuarterScaleHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
