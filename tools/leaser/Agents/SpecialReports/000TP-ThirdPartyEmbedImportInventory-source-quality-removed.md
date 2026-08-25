<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\SpecialReports\000TP-ThirdPartyEmbedImportInventory-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000TP-ThirdPartyEmbedImportInventory-source-quality.md](000TP-ThirdPartyEmbedImportInventory-source-quality.md)
- Source report SHA256 before cleanup: `5CCDB68938EEFCDFF619ED2DBC4FF8E0C564056FCA64EAAD4E1E2DE827CC7979`
- Cleanup generated: `2026-08-11T12:47:19Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `333-456`
- Original language: `powershell`
- Block SHA256: `411FCFD3141951EA16B10BB088983A1CEC51AD8130FA7681BC46AF49FF8962F6`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00448520-0x00448557.LodePNGStateDestructors.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003750, command_timestamp 2026-06-27T03:53:44-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-class\LodePNGState.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003751, command_timestamp 2026-06-27T03:54:02-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LodePNG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003752, command_timestamp 2026-06-27T03:54:20-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004460f0-0x004461f6.LodePngStateInit.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003753, command_timestamp 2026-06-27T03:54:38-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003755, command_timestamp 2026-06-27T04:00:37-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003757, command_timestamp 2026-06-27T04:02:54-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003758, command_timestamp 2026-06-27T04:02:54-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00405060-0x00405c77.LibJpegMemoryManager.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003759, command_timestamp 2026-06-27T04:02:55-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x004011a1.LibJpegErrorManager.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003793, command_timestamp 2026-06-27T04:44:12-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003794, command_timestamp 2026-06-27T04:44:28-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003795, command_timestamp 2026-06-27T04:44:43-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401b00-0x0040391f.LibJpegMarkerReader.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003807, command_timestamp 2026-06-27T05:07:22-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003808, command_timestamp 2026-06-27T05:07:32-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004049c0-0x00404a5c.LibJpegCommonApi.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003809, command_timestamp 2026-06-27T05:07:41-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00405c80-0x004063c8.LibJpegDecompressMaster.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003810, command_timestamp 2026-06-27T05:07:50-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004064a0-0x00406d90.LibJpegMarkerWriter.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003811, command_timestamp 2026-06-27T05:08:00-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00406d90-0x00406e46.LibJpegCompressMasterInit.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003812, command_timestamp 2026-06-27T05:08:09-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003813, command_timestamp 2026-06-27T05:08:18-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003814, command_timestamp 2026-06-27T05:08:28-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003832, command_timestamp 2026-06-27T05:23:34-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004075c0-0x00408a58.LibJpegDecompressMainController.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003834, command_timestamp 2026-06-27T05:23:44-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00408a60-0x004090b0.LibJpegHuffmanDecoder.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003835, command_timestamp 2026-06-27T05:23:54-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004090b0-0x00409e0f.LibJpegProgressiveHuffmanDecoder.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003836, command_timestamp 2026-06-27T05:24:03-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00409e10-0x0040a0a5.LibJpegInverseDctManager.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003837, command_timestamp 2026-06-27T05:24:12-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040a0d0-0x0040a436.LibJpegDecompressPostController.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003838, command_timestamp 2026-06-27T05:24:21-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003839, command_timestamp 2026-06-27T05:24:29-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003840, command_timestamp 2026-06-27T05:24:38-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040a440-0x0040abb2.LibJpegUpsampler.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003851, command_timestamp 2026-06-27T05:37:01-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040abc0-0x0040b221.LibJpegColorDeconverter.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003852, command_timestamp 2026-06-27T05:37:10-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040b230-0x0040b820.LibJpegMergedUpsampler.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003853, command_timestamp 2026-06-27T05:37:19-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040b820-0x0040cc1f.LibJpegOnePassColorQuantizer.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003854, command_timestamp 2026-06-27T05:37:28-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040cc20-0x0040d864.LibJpegTwoPassColorQuantizer.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003855, command_timestamp 2026-06-27T05:37:36-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x0040d870-0x0040d9f9.LibJpegCompressMainController.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003856, command_timestamp 2026-06-27T05:37:46-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003857, command_timestamp 2026-06-27T05:37:55-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003858, command_timestamp 2026-06-27T05:38:04-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004111d0-0x00411951.LibJpegColorConverter.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003882, command_timestamp 2026-06-27T06:11:55-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00411960-0x004124b8.LibJpegCompressMasterController.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003883, command_timestamp 2026-06-27T06:12:06-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004124c0-0x00412aaf.LibJpegIntegerInverseDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003884, command_timestamp 2026-06-27T06:12:16-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00412ab0-0x00412f62.LibJpegFastIntegerInverseDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003885, command_timestamp 2026-06-27T06:12:25-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00412f70-0x004133a4.LibJpegFloatInverseDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003886, command_timestamp 2026-06-27T06:12:35-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003887, command_timestamp 2026-06-27T06:12:45-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003889, command_timestamp 2026-06-27T06:12:54-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004133b0-0x004139ce.LibJpegReducedInverseDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003899, command_timestamp 2026-06-27T06:23:45-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004139d0-0x00413dc8.LibJpegIntegerForwardDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003900, command_timestamp 2026-06-27T06:23:56-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00413dd0-0x00414011.LibJpegFastIntegerForwardDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003901, command_timestamp 2026-06-27T06:24:05-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00414020-0x00414283.LibJpegFloatForwardDct.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003902, command_timestamp 2026-06-27T06:24:15-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003903, command_timestamp 2026-06-27T06:24:25-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003904, command_timestamp 2026-06-27T06:24:35-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00414820-0x004158aa.ZlibDeflateWorkers.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003780, command_timestamp 2026-06-27T04:29:24-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003781, command_timestamp 2026-06-27T04:29:38-04:00, exit 0, ok:1, generated_refresh:completed; duplicate_path_conflict 00041N maps to by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md, projected_path_skip
python .\tools\validator.py --mode file --file by-memory\0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003783, command_timestamp 2026-06-27T04:29:54-04:00, exit 0, ok:1, generated_refresh:completed; duplicate_path_conflict 00041O maps to by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md, projected_path_skip
python .\tools\validator.py --mode file --file by-file\Zlib.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003784, command_timestamp 2026-06-27T04:30:08-04:00, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00424630-0x00428b4b.JsonCppValueCore.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003998, command_timestamp 2026-06-27T08:28:21-04:00, exit 0, ok:1, generated_refresh:completed; ValueCore remains blank because `json_valueiterator.inl` is not validator-importable
python .\tools\validator.py --mode file --file by-memory\0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md --apply --queue-timeout 240 --wait-generated
# command_id 000000003999, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004000, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004001, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00431d50-0x00431f1c.JsonCppOurReaderParse.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004002, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004003, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x004417e0-0x00441d24.JsonCppValidReaderKeys.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004004, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-memory\0x00441d30-0x00442084.JsonCppValidWriterKeys.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004005, sequential validator loop, exit 0, ok:1, generated_refresh:completed
python .\tools\validator.py --mode file --file by-file\JsonCpp.md --apply --queue-timeout 240 --wait-generated
# command_id 000000004006, sequential validator loop, exit 0, ok:1, generated_refresh:completed; generated JsonCpp.cpp refreshed at 2026-06-27T08:29:41-04:00
```
