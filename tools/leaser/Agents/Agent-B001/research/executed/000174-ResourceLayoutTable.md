## Final Report / Current Recommendation

Target: [UID:000174] `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`

Current recommendation: keep `000174` parent blank and `RECONSTRUCTABLE:FALSE` as a non-emitting mixed inventory/container. Do not assign the broad aggregate to ResourceLayoutTable, ImageLib, ImageLoaders, or ImageFrameTable. Exact child pages now carry the direct ownership decisions where evidence supports assignment.

Recommended status/classification: `reviewed-split-repaired-non-emitting-mixed-inventory`.

Confidence: high for the mixed-container decision, `88/91` in the page header after validator application.

Concrete next action: supervisor can accept/archive B001-023 if the manual review agrees with the split. A-agents should use the exact children rather than the broad aggregate for future source ownership or C++ reconstruction.

Report state: final.

## Final Child Decisions

`000174` final state:
- `COMPLETION:88`
- `CONFIDENCE:91`
- `RECONSTRUCTABLE:FALSE`
- `AUTOGEN_PARENT_UID:` blank
- Reason: the range spans ResourceLayout class methods, file-level ResourceLayout raw helpers, ImageLoaders decode wrappers, ImageFrameTable helpers, and padding. A single direct source owner would be misleading.

`0002KQ` `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`:
- Final state: `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000N5] `by-file/ResourceLayoutTable.md`, position `30`.
- Recommendation: keep assigned to the file-level ResourceLayoutTable raw-helper grouping, not to the ResourceLayoutTable class and not to UserLookPane.
- Evidence summary: IDA confirms a two-argument `__stdcall` raw-buffer helper with one UserLook caller at `0x005a0042`; the caller preloads `g_pEPFLib`, but the callee overwrites `ecx` and does not use `this`. The helper parses ResourceLayout-format records, so caller ownership is weaker than file-level ResourceLayout helper ownership.

`0002KT` `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`:
- Final state: `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000N5] `by-file/ResourceLayoutTable.md`, position `40`.
- Recommendation: keep assigned to the file-level ResourceLayoutTable raw-helper grouping, not to the ResourceLayoutTable class and not to HumanImageLib/NewHumanImageLib.
- Evidence summary: IDA confirms a three-argument no-callee `__stdcall` helper that copies the first 16 bytes from 24-byte raw record rows or zeroes the output. Modeled NewHuman and orphan old/new Human callsites are consumers; they do not outweigh address clustering and ResourceLayout record semantics.

Created/repaired ImageDecode children:
- [UID:00032P] `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`: new/finished exact PNG-file helper, `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000K3] `ImageLoaders`. IDA shows raw unmodeled body, LodePNG file front end `0x00443c40`, EPFTileContext allocation/finalization, RGBA-to-RGB565 plus alpha-plane conversion, and no direct xrefs.
- [UID:00032O] `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`: new/finished exact PNG-resource helper, `86/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000K3] `ImageLoaders`. IDA shows `sub_4D0D90`, DAT/file-buffer staging, LodePNG memory front end `0x00443b40`, EPFTileContext conversion, cleanup, and no direct xrefs.
- [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`: expanded/renamed aggregate, `85/88`, parent [UID:0000K3] `ImageLoaders`, now covers ZPF/FPF, raw FPF, JPF, BMP, raw JPEG, PNG-file, and PNG-resource wrappers.
- Existing wrapper children touched by path repair and strict-gate refresh: `0002TJ`, `0002TK`, `0002TL`, `0002TM`, `0002TN`; all now validate at or above `85/85` and remain parented to [UID:0000K3] `ImageLoaders`.

Repaired ImageFrameTable children:
- [UID:00031T] `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`: repaired from below gate to `85/88`, parent [UID:0000K1] `ImageFrameTable`, position `40`. IDA shows raw unmodeled prologue/`ret 0x0c`, 24-byte frame-record stride, two payload-span allocations/copies, and no xrefs.
- [UID:00031U] `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`: repaired from below gate to `85/88`, parent [UID:0000K1] `ImageFrameTable`, position `50`. IDA shows raw unmodeled prologue/`ret 0x0c`, 24-byte frame-record stride, one 16-byte `movups` copy, no callees, and no xrefs.
- [UID:000176] `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`: repaired to `85/89` as a reconstructable routing/index page and updated to remove the stale "child pages needed/leaser blocked" wording. It remains parent blank because `0002P5` `DestroyOwnedImageBlock` is still a separate cleanup-owner question.

Every reconstructable B001-023 child I touched is now defensibly at or above `85/85`.

## Changed Files

Primary target and split docs:
- `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`
- `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`
- `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`
- `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
- `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`
- `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`
- `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`
- `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`
- `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`
- `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md`
- `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`
- `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md`
- `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`
- `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`

Parent/source docs and manual reports:
- `by-file/ImageLoaders.md`
- `by-file/ResourceLayoutTable.md`
- `by-file/ImageFrameTable.md`
- `by-file/ImageLib.md`
- `by-class/ResourceLayoutTable.md`
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-project-structure/proposed-source-tree.md`

B001-023 supervisor review-fix files:
- `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`
- `by-memory/-coverage-report.md`
- `by-project-structure/proposed-source-tree.md`
- `tools/leaser/Agents/Agent-B001/research/000174-ResourceLayoutTable.md`

Path-only references repaired after the `000175` range rename:
- `by-file/LibJPEG.md`
- `by-file/MainMenuPane.md`
- `by-file/MiniMap.md`
- `by-file/ProfileStorage.md`
- `by-file/UserLookPane.md`
- `by-global/ImageDecodeJpegEoiMarker.md`
- `by-meta/client_profile_storage.md`
- `by-meta/client_libraries.md`
- `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`
- `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md`
- `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
- `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`
- `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`
- `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md`
- `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`
- `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`

Agent artifacts:
- `tools/leaser/Agents/Agent-B001/research/000174-ResourceLayoutTable.md`
- `tools/leaser/Agents/Agent-B001/validation-logs/B001-023-final/summary.csv`
- `tools/leaser/Agents/Agent-B001/validation-logs/B001-023-final/summary-rerun.csv`
- per-file validator logs under `tools/leaser/Agents/Agent-B001/validation-logs/B001-023-final/`

Validator-managed files may also have been refreshed by `validator.py --apply` (not manually edited), including `tools/validator.ini` and auto-generated coverage/output files.

## Validator Results

Validation command pattern used:

```powershell
python tools/validator.py --mode file --file <path> --apply
```

Completed validator batch 1:
- Summary file: `tools/leaser/Agents/Agent-B001/validation-logs/B001-023-final/summary.csv`
- Files validated: 43
- Result: every row `Exit=0`, `Ok=1`, `MissingRef=0`

Completed validator batch 2 after strict-gate refresh:
- Summary file: `tools/leaser/Agents/Agent-B001/validation-logs/B001-023-final/summary-rerun.csv`
- Files validated: 9
- Result: every row `Exit=0`, `Ok=1`, `MissingRef=0`

Completed targeted validator batch 3 after supervisor review fixes:
- `python tools/validator.py --mode file --file by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md --apply`: exit `0`, scanned markdown files `1`, `ok: 1`, last used UID `00032P`.
- `python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply`: exit `0`, scanned markdown files `1`, `ok: 1`, last used UID `00032P`.
- `python tools/validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply`: exit `0`, scanned markdown files `1`, `ok: 1`, last used UID `00032P`.
- Review-fix content: `000176` now reports `85/89`, the manual memory coverage row now reports `85%`, and the ImageLoaders source-tree rationale now uses the corrected `0x004d05f0-0x004d0f4a` helper span.

Files still needing validation: none known for B001-023. Remaining legacy pre-PNG ImageDecodeWrappers range references are historical/generated context: generated resolver output such as `project-level/-resolved.md` was not edited directly, and `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` retains old-range mentions only inside its change-history notes.

## Supporting Research

IDA-backed boundary inventory for `0x004d0120-0x004d182f`:
- Modeled functions: `0x004d0120`, `0x004d02f0`, `0x004d03a0`, `0x004d04d0`, `0x004d0530`, `0x004d05a0`, `0x004d05f0`, `0x004d07b0`, `0x004d09b0`, `0x004d0a90`, `0x004d0d90`, `0x004d0f50`, `0x004d15d0`, `0x004d1600`, `0x004d1730`, `0x004d1780`, and `0x004d17c0`.
- Raw source-looking helper bodies without IDA function objects: `0x004d0730-0x004d07a3`, `0x004d0c60-0x004d0d89`, `0x004d1660-0x004d1704`, and `0x004d1710-0x004d172d`.
- Key padding/alignment spans documented in `by-memory/-ignored.md`: ResourceLayout local padding, ImageDecode wrapper padding including `0x004d0c58-0x004d0c60`, `0x004d0d89-0x004d0d90`, `0x004d0f4a-0x004d0f50`, and ImageFrameTable padding including `0x004d1704-0x004d1710`, `0x004d172d-0x004d1730`.

Ownership alternatives rejected for `000174`:
- `ResourceLayoutTable` class: correct for exact class methods, too narrow for ImageLoaders/ImageFrameTable children and raw non-method helpers.
- `ImageLib`: owns the broader singleton/facet context, but assigning the whole aggregate would absorb unrelated ImageLoaders and ImageFrameTable code.
- `ImageLoaders`: correct for `000175` and decode children, wrong for ResourceLayout and ImageFrameTable spans.
- `ImageFrameTable`: correct for `000176` exact frame helpers and `00031T/00031U`, wrong for ResourceLayout/ImageDecode spans.

Residual caveats:
- `0002P5` `DestroyOwnedImageBlock` remains a separate cleanup-owner question under the ImageFrameTable neighborhood. It is not resolved by B001-023 and is not assigned through the broad `000174` aggregate.
- Original source spelling for several helpers remains inferred, so C++ bodies stay blank even where child ownership is now assignment-quality.
