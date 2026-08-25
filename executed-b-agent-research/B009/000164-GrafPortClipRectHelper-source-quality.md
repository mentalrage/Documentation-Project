** TARGET-REPORT-UID:000164 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000164] GrafPort clip-rect helper source-quality report

Agent: Agent-B009  
Assignment: `B009-report-000164-grafport-clip-rect-helper-20260625`  
Mode: report-only first pass  
Target: `by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md`  
Recommended target filename: `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`

## Recommendation

Update [UID:000164] from a blank emitting marker to a formal first-draft GrafPort method. The function is modeled by IDA, has a stable one-argument `thiscall` shape, has 44 direct code xrefs in the current IDB, and is already used as `GetClipRect` by accepted GrafPort formal C++ in [UID:000168] and [UID:000169]. The prior "method/field names are not at 95/95" blocker is stale under the current code-entry rule.

Recommended metadata:

| Field | Recommended value |
| --- | --- |
| UID | `000164` |
| Completion | `89` |
| Confidence | `91` |
| Canonical owner | `00005V` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `00005V` |
| Emitter position optional | blank |
| Formal C++ disposition | populate the exact insertion text below |

The recommended source-facing name is `GrafPort::GetClipRect`. Keep `RankingEventListPane::GetClipRect` only as generated-owner pollution evidence; the direct owner is [UID:00005V] `GrafPort`, emitted through [UID:0000JR] `GrafPort.cpp`.

## Exact formal C++ insertion text

This is the exact text to insert between the target `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines:

```cpp
void GrafPort::GetClipRect(RectBounds *outClipRect)
{
    Region effectiveClip;

    effectiveClip.CopyRectFrom(&m_exposedRegion);

    if (!m_clipRegion.IsEmpty()) {
        effectiveClip.IntersectWith(&m_clipRegion);
    }

    RectBounds surfaceBounds = m_surfaceContext.bounds;
    effectiveClip.IntersectWithRect(&surfaceBounds);
    effectiveClip.GetRect(outClipRect);
}
```

Field-name basis:

| Binary state | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `this+0x04` | `m_exposedRegion` | Constructor builds a `Region` at `this+4`; `UpdateRenderRegion` mutates it with Region union/subtract operations as the exposed/dirty render region; `GetClipRect` copies it before applying optional clip and surface bounds. Existing GrafPort class/file docs describe this as exposed/dirty region state. |
| `this+0x54` | `m_clipRegion` | Existing [UID:00016A] formal C++ and GrafPort class docs use this accepted name; the target calls the empty predicate and intersects it only when non-empty. |
| `this+0x2c` | `m_surfaceContext.bounds` | Accepted [UID:000169] and [UID:0003XE] evidence identify `+0x2c/+0x30` as the embedded surface context bounds/origin fields. |

The `m_exposedRegion` spelling is still an inferred private member name, not symbol-proven. That limitation should cap the score below final-source quality, but it should not keep the emitter blank: the field type, offset, and role are supported by constructor, `UpdateRenderRegion`, target body, and current support docs.

## Current MCP evidence

Current IDA MCP session checked on 2026-06-25:

- `idb_list`: active database `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status `ok`, module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x004b96c0` resolves to `sub_4B96C0`, size `0xa8`; `0x004b9765` and `0x004b9767` resolve inside that same function; `0x004b9768` and `0x004b9770` are not function starts. Predecessor checks still resolve `0x004b95e0` and `0x004b96a0`; successor modeled release helper begins at `0x004b97d0`.
- `disasm 0x004b96c0`: 67 instructions including compiler EH/security-cookie lines; main body returns with `retn 4` at `0x004b9765`, so the final byte is `0x004b9767` and the correct exclusive end is `0x004b9768`.
- `make_signature_for_range 0x004b96c0-0x004b9768`: unique full-function signature. `make_signature_for_range 0x004b9768-0x004b9770`: eight `0xcc` bytes, confirming padding after the function.
- `xrefs_to 0x004b96c0`: 44 direct code refs, no truncation. Representative callers include nearby GrafPort drawing helpers `0x004ba450` and `0x004ba540`, surface/render callbacks, UI controls, and text paths.
- `callees 0x004b96c0`: Region/Motion helpers `0x00554680`, `0x00554760`, `0x005546f0`, `0x005547a0`, `0x005547e0`, `0x00554ae0`, base cleanup `0x004f4a90`, and compiler security-cookie check.

Current decompile of the target:

- Constructs a stack `Region` through `0x00554680`.
- Copies receiver `this+0x04` Region state through `0x00554760`.
- Tests `this+0x54` through `0x005546f0`; when non-empty, intersects through `0x005547a0`.
- Copies the raw `RectBounds` at `this+0x2c` into a stack local, then calls `0x005547e0`.
- Copies the final Region rectangle to the caller output through `0x00554ae0`.
- Tears down the local Region base through `0x004f4a90`.

Current helper decompiles:

| Helper | Current behavior |
| --- | --- |
| `0x00554680` | Constructs `Region`, stores the Region vtable, and clears the stored rectangle. |
| `0x00554760` | Copies another Region/Motion-style object's stored rect, or clears on empty input. |
| `0x005546f0` | Returns whether the stored rect is empty. |
| `0x005547a0` | Intersects the local Region/Motion rect with another object rect through `0x004b7cc0`. |
| `0x005547e0` | Intersects a raw caller rect with the local Region/Motion rect and stores the result back into the local rect. Current source-facing role is `IntersectWithRect` for this target. |
| `0x00554ae0` | Copies the stored rect to caller output. |
| `0x004f4a90` | Resets the local object to the `LObject` vtable during teardown. |

Current GrafPort constructor evidence:

- `0x004b8bf0` constructs a Region at `this+0x04`, initializes the embedded surface context at `this+0x1c`, constructs `m_clipRegion` at `this+0x54`, clears `m_surfaceContext.bounds` at `this+0x2c`, clears `m_visibleBounds` at `this+0x44`, and initializes draw-state fields.
- `0x004b8e20` `UpdateRenderRegion` uses `lea ecx,[this+4]` repeatedly with Region union/subtract helpers, supporting `m_exposedRegion`/dirty-region wording for `this+0x04`.

## Source-facing decisions

| Question | Decision | Rationale |
| --- | --- | --- |
| Source method name | `GetClipRect` | Accepted formal C++ in [UID:000168] and [UID:000169] calls this helper as `GetClipRect`; generated `RankingEventListPane` ownership is caller-biased, but the method name itself matches the helper role. |
| Owner/emitter | owner `00005V`, emitter `00005V` | The function reads only GrafPort receiver fields and is called broadly by render/UI/text paths; [UID:00005V] and [UID:0000JR] already clear the direct-parent route. |
| Formal C++ | populate | The modeled function is reached, exact, source-authored, and has a stable body. A blank emitter is not justified. |
| Filename/range | rename to half-open `0x004b96c0-0x004b9768.GrafPortGetClipRect.md` | Current function size is `0xa8`; `0x004b9768` is the exclusive end and `0x004b9768-0x004b9770` is padding. |
| `0x005547e0` role | target-local source role `IntersectWithRect` | Live decompile shows it intersects a raw rect with the local Region/Motion rect and stores into the local rect. Older `GetNormalizedRect` wording is too vague for this target but not a C++ blocker. |

Rejected routes:

- Keep blank formal C++: rejected because [UID:000164] is modeled, reached, exact, reconstructable, and emitting through a valid parent.
- Treat as `RankingEventListPane`: rejected as caller-biased generated output; caller fan-in and receiver state prove GrafPort ownership.
- Convert to non-emitting split/index metadata: rejected because the exact function has 44 direct xrefs and is not a raw no-entry clone. The raw `0x004b9770` successor remains separate in [UID:0003XC].
- Keep legacy filename suffix: rejected because the project uses exclusive-end range filenames for current source-bearing pages, and current MCP confirms `0x004b9768` is the end boundary.

## Proposed target/support edits

Target [UID:000164]:

1. Rename the file to `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`.
2. Update the title to `0x004b96c0-0x004b9768 GrafPort GetClipRect`.
3. Keep `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank emitter position.
4. Raise to `COMPLETION:89`, `CONFIDENCE:91`.
5. Insert the formal C++ block from this report.
6. Replace the stale "final C++ remains blank because ... 95/95" wording with the current source-facing decision.
7. Correct body wording from "normalizes the draw rectangle" to "intersects the effective region with `m_surfaceContext.bounds` through the `0x005547e0` raw-rect intersection wrapper."
8. Add the current 2026-06-25 MCP evidence and constructor/UpdateRenderRegion support facts.

Support docs:

| File | Recommended action |
| --- | --- |
| `by-class/GrafPort.md` | Update the [UID:000164] link/filename, name it `GrafPort::GetClipRect`, record the formal C++ readiness, and clarify `this+0x04` as exposed/dirty Region state rather than an unresolved blocker. |
| `by-file/GrafPort.md` | Update the draw-state/accessor range end from legacy `0x004b9767` wording to exclusive `0x004b9768`; update the [UID:000164] link/name and note that it now emits formal C++. |
| `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md` | Update the [UID:000164] cross-reference path after the rename only; no metadata change needed. |
| `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md` | Update the [UID:000164] cross-reference path after the rename only; no metadata change needed. |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | Optional support clarification: note that `0x005547e0` acts as a raw-rect intersection wrapper in the GrafPort clip path. No ownership or metadata change recommended. |
| `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md` | Update predecessor link after the rename only; keep its raw no-entry `0x004b9770` no-code proof unchanged. |

Generated files, manual coverage reports, validator state/cache, and IDA database files should not be edited manually. Let scoped validators refresh generated output after the supervisor accepts this report and sends an implementation callback.

## Implementation checklist

- [x] Acquire short leases for the target and listed support docs only after supervisor implementation callback. Proof: B009 leased the target/support edit batch immediately before editing, then leased the immediate stale-link cleanup docs found during rename propagation before editing them; after validation, `python .\tools\leaser\leaser.py B009 unlease` reported `B009: No active leases`, and `tools/leaser/Agents/current_leases.md` had no B009 rows.
- [x] Rename [UID:000164] to the half-open filename and update internal title/link text. Proof: old path `by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md` no longer exists; new path `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md` exists; target validator command `000000001514` applied the [UID:000164] path update.
- [x] Populate [UID:000164] metadata as `89/91`, owner/emitter `00005V`, reconstructable true, blank emitter position. Proof: target header now has `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, and blank emitter position; validator command `000000001514` recorded completion/confidence/owner updates.
- [x] Insert the exact formal C++ block from this report. Proof: `GrafPort::GetClipRect(RectBounds *outClipRect)` now appears in `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`; target validator command `000000001514` exited `0` with `ok: 1`.
- [x] Replace stale no-code/95-gate language with current MCP evidence and source-facing naming decisions. Proof: target Status, Ownership, Score, and evidence sections now use the 2026-06-25 MCP facts, reject the stale blank-C++ route, and keep only historical before/route-rejection references.
- [x] Update GrafPort class/file support links and the cross-reference paths in direct consumers. Proof: `by-class/GrafPort.md`, `by-file/GrafPort.md`, `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`, `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`, and `by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md` were updated; extra stale rename links were cleaned in `FittingRoomScrollPaneOnDraw`, `DrawContextBrushHandleHelpers`, and the two software fill callback pages.
- [x] Optionally clarify [UID:0001FW] `0x005547e0` target-local role without changing Region/Motion ownership. Proof: `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` now documents the raw-rect intersection role for the GrafPort clip path, with metadata unchanged; validator command `000000001523` exited `0` with `ok: 1`.
- [x] Run scoped validators for the changed by-* files only. Proof: validators completed with `exit 0` and `ok: 1` for commands `000000001514`, `000000001516`, `000000001517`, `000000001519`, `000000001520`, `000000001522`, `000000001523`, `000000001524`, `000000001525`, `000000001527`, and `000000001528`, all with `--apply --queue-timeout 240 --wait-generated`.
- [x] Release leases immediately after the edit/validator batch. Proof: post-batch `python .\tools\leaser\leaser.py B009 unlease` returned `B009: No active leases`; `current_leases.md` contains no B009 row.
- [x] Do not manually edit generated reports, auto-generated source, manual `-coverage-report.md`, validator state/cache, or IDA DB. Proof: manual edits were limited to by-* docs and this B009 research report; validator-owned generated refreshes and UID link propagation were allowed side effects, including command `000000001525` touching `by-memory/-coverage-report.md` as a validator side effect.

Implementation callback proof, 2026-06-25:

- IDA MCP availability was confirmed before implementation: `initialize` and `tools/list` returned HTTP 200, with `server_health`, `lookup_funcs`, `decompile`, and `disasm` available.
- Stale-reference scan after edits found no remaining old target path outside the target's own historical "Before" note; `Test-Path` returned `False` for the old path and `True` for the renamed target.
- Scoped validators:
  - `000000001514` at `2026-06-25T13:48:11-04:00`: target `by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001516` at `2026-06-25T13:48:48-04:00`: `by-class/GrafPort.md`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001517` at `2026-06-25T13:49:09-04:00`: `by-file/GrafPort.md`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001519` at `2026-06-25T13:49:28-04:00`: `GrafPortDrawRectFrame`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001520` at `2026-06-25T13:49:49-04:00`: `CompositePixels16`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001522` at `2026-06-25T13:50:07-04:00`: `GrafPortEffectiveClipAndBackingRelease`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001523` at `2026-06-25T13:50:28-04:00`: `RegionAndMotionRect`, exit `0`, `ok: 1`, generated refresh completed.
  - `000000001524`, `000000001525`, `000000001527`, and `000000001528`: extra old-link cleanup pages, exit `0`, `ok: 1`, generated refresh completed.

Expected validator commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000164-GrafPortClipRectHelper-source-quality-removed.md](000164-GrafPortClipRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the Region/Motion validator only if the optional support clarification is implemented.

## Report-only scope

No by-* docs, generated files, coverage reports, validator state/cache, or IDA database files were edited by this report-only pass. No leases were taken because this pass only created the Agent-B009 research report. No validators were run because implementation is supervisor-gated.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/000164-GrafPortClipRectHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/000164-GrafPortClipRectHelper-source-quality.md","timestamp":"2026-06-25T14:01:52","uid":"000164"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000164-GrafPortClipRectHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/000164-GrafPortClipRectHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000164"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
