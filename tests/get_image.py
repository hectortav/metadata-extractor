if __name__ == '__main__':
    if __package__ is None:
        import sys
        sys.path.append('.')
        from metadata_from_url import metadata
    else:
        from ..metadata_from_url import metadata

    print("~~~case 1~~~")
    meta = metadata("https://interestingengineering.com/canada-is-banning-internal-combustion-engines-but-what-about-the-cold")
    if meta:
        if "twitter:image" in  meta:
            print(meta["twitter:image"])
    else:
        print("No metadata collected")
    print("~~~case 2~~~")
    meta = metadata("https://dinterestingengineering.com")
    if meta:
        if "twitter:image" in  meta:
            print(meta["twitter:image"])
    else:
        print("No metadata collected")