*** UID:0000HD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ignored File/Module Candidates

Use this file to list confirmed source-file candidates that should not become NexusTK-owned reconstruction files.

Add entries for compiler/runtime modules, third-party libraries that should be vendored separately, stale generated files, or placeholder files that later evidence proves should remain excluded. Include the candidate file name, reason, evidence, and replacement location.

## Ignored Entries

- `ThreadSafeNodeList.cpp` - generated one-class source split for the `0x004b14c0` locked intrusive push helper; ignore as a standalone original file unless future non-allocator constructor/destructor evidence appears. Evidence: IDA MCP confirms the surrounding allocator island and string/object pool xrefs, while current docs identify `PoolAllocator::Free` as the stronger source owner. Replacement owner: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), with alias notes in [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md).
