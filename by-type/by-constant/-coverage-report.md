*** UID:0001SC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-type/by-constant Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-type/by-constant`
- Coverage summary: 1 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001SF][DownloaderMessageIds](by-type/by-constant/DownloaderMessageIds.md) : reconstructable : 86% : strong : A004 Batch 097 assigned to [UID:0000JC][FileDownloader](by-file/FileDownloader.md) after live IDA confirmed the `0x0041b110` dispatcher switch, submit-helper boundaries, `0x0041b180` message `10000` queue post, `0x0041b200`/`0x0041b270` queue helper callees, download target helpers, default Thread fallback, and worker-thread-not-socket ownership boundary; final enum-vs-constant spelling remains provisional.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-type/by-constant inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-constant is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
